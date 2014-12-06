#include <stdio.h>
#include <stdlib.h>
#include "basefont.h"
#include "operfont.h"

BaseFont::BaseFont(void *font, int n, bool internal, int w, int h)
{
    FILE *fontfile;
    size_t filesize;
    int count;
    char *offset;

    _data = NULL;
    _addr = NULL;
    _buffer = NULL;
    _width = w;
    _height = h;
    _size = w * h / 8;
    _num = n;
    _internal = internal;

    if ((_addr = new void *[_num]) == NULL) {
        _errorcode = ERR_OUTOFMEM;
        return;
    }

    if ((_buffer = (void *)(new char[_size])) == NULL) {
        _errorcode = ERR_OUTOFMEM;
        return;
    }

    if (_internal) {
        strcpy(_fontname, "INTERNAL");
        _data = font;
    } else {
        strcpy(_fontname, (char *)font);
        if ((_data = (void *)(new char[_size * _num])) == NULL) {
            _errorcode = ERR_OUTOFMEM;
            return;
        }

        if ((fontfile = fopen(_fontname, "rb")) == NULL) {
            _errorcode = ERR_NOTFOUND;
            return;
        }

        fseek(fontfile, 0, SEEK_END);
        filesize = ftell(fontfile);
        rewind(fontfile);

        if (filesize < _num * _size) {
            _errorcode = ERR_WRONGSIZE;
            fclose(fontfile);
            return;
        }

        if (!fread(_data, _size, _num, fontfile)) {
            _errorcode = ERR_READERROR;
            fclose(fontfile);
            return;
        }
        fclose(fontfile);
    }

    offset = (char *)_data;
    for (count = 0; count < _num; count++) {
        _addr[count] = (void *)offset;
        offset += _size;
    }
    _errorcode = NOERROR;
}

BaseFont::~BaseFont()
{
    if (_data && !_internal) {
        delete[] _data;
        _data = NULL;
    }
    if (_addr) {
        delete[] _addr;
        _addr = NULL;
    }
    if (_buffer) {
        delete[] _buffer;
        _buffer = NULL;
    }
}

virtual void *BaseFont::combine(hancode_t code)
{
    cpyfont(_buffer, _addr[code.code], _size);
    return _buffer;
}

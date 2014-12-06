#include <stdio.h>
#include "hdisp.h"

HDisplay::HDisplay()
{
    setmode(GR_default_graphics, 0, 0);
}

HDisplay::HDisplay(int w, int h)
{
    setmode(GR_width_height_graphics, w, h);
}

HDisplay::~HDisplay()
{
    setmode(GR_default_text,0,0);
}

void HDisplay::puterr(const char *message, int status)
{
    lowsetmode(GR_default_text, 0, 0, 0);
    fputs(message, stderr);
    exit(status);
}

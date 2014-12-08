#include <avr/pgmspace.h>
#include "../Core/Framebuffer.h"

class UI {
public:
    UI();

    void renderSplash();
    void renderSolderingScreen();
    void renderRemoteModeScreen();
    
    uint8_t status = 0;

    enum {
    	IDLE = 0,
    	HEATING = 1,
    	READY = 2
    };
private:
    Framebuffer framebuffer;
};

static const uint8_t PROGMEM bmp_screen_connected[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xc,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1e,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3e,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7e,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x31,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x7b,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xe0,0x38,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xc0,0x7c,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0xff,0x80,0xfc,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0x81,0xf8,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xc3,0xf0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xe7,0xe0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1f,0x87,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3f,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7e,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7c,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x78,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x10,
0x84,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x10,
0x82,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x10,
0x82,0x0,0x0,0x0,0x0,0x10,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x10,
0x82,0x7,0x17,0x38,0x1e,0x7c,0x38,0x1,0xc3,0xc2,0xe7,0xcb,0x1e,0x10,
0x84,0x8,0x99,0xcc,0x21,0x10,0x44,0x2,0x24,0x23,0x11,0xc,0xa1,0x10,
0xf8,0x10,0x50,0x84,0x40,0x90,0x82,0x4,0x8,0x12,0x9,0x8,0x40,0x90,
0x88,0x1f,0xd0,0x84,0x40,0x90,0xfe,0x4,0x8,0x12,0x9,0x8,0x40,0x90,
0x84,0x10,0x10,0x84,0x40,0x90,0x80,0x4,0x8,0x12,0x9,0x8,0x40,0x90,
0x82,0x10,0x10,0x84,0x40,0x90,0x80,0x4,0x8,0x12,0x9,0x8,0x40,0x90,
0x81,0x8,0x50,0x84,0x21,0x10,0x42,0x2,0x24,0x22,0x9,0x8,0x21,0x10,
0x80,0x87,0x90,0x84,0x1e,0xe,0x3c,0x1,0xc3,0xc2,0x8,0xe8,0x1e,0x10
};

static const uint8_t PROGMEM bmp_ready[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0x3f,0xff,0xff,0xff,0xff,0xf8,0x3f,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xfb,0xdf,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xdf,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xdc,0x78,0xf9,0x6f,0xbf,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xbb,0xb7,0x76,0x6f,0xbf,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xf8,0x77,0xbf,0x6f,0x77,0x7f,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0x70,0x38,0x6f,0x77,0x7f,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xb7,0xf7,0x6f,0x7a,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xdb,0xf7,0x76,0x7a,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xfb,0xec,0x38,0x39,0x7d,0xff,0xff,0xff,0xff,0xff,0xfe,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xfc,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xff,0xf0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

static const uint8_t PROGMEM bmp_heating[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0x3f,0xff,0xff,0xff,0xff,0xdf,0xbf,0xff,0xfd,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xdf,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xbf,0xff,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xb8,0xe3,0xd,0xa7,0xcb,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xc0,0x37,0x5d,0xbd,0x9b,0xb3,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xaf,0x7d,0xbd,0xbb,0x7b,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xa0,0x61,0xbd,0xbb,0x7b,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xaf,0xdd,0xbd,0xbb,0x7b,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xb7,0xdd,0xbd,0xbb,0xb3,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xdf,0xb8,0x60,0xcd,0xbb,0xcb,0xff,0xff,0xff,0xff,0xfe,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7b,0xff,0xff,0xff,0xff,0xfc,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xf0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

static const uint8_t PROGMEM bmp_idle[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xff,0xdc,0xf,0x7e,0x7,0xff,0xff,0xff,0xff,0xff,0xfc,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xf7,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xf,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xfb,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x7f,0xff,0xff,0xff,0xff,0xff,0xdd,0xf7,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
0x3f,0xff,0xff,0xff,0xff,0xff,0xdc,0xf,0x2,0x7,0xff,0xff,0xff,0xff,0xff,0xfc,
0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0
};

static const uint8_t PROGMEM bmp_splash[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfe,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfe,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfe,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfc,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfc,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfc,0x0,0x3f,0xff,0xfc,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xfc,0x0,0x3f,0xff,0xfb,0xdf,0xff,0xbf,0xfb,0xff,0xff,0xbf,0xff,0xff,0xff,
0xff,0xfc,0x0,0x3f,0xff,0xf7,0xff,0xff,0xbf,0xfb,0xff,0xff,0xbf,0xff,0xff,0xff,
0xff,0xf8,0x0,0x7f,0xff,0xf7,0xff,0xff,0xbf,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xf8,0x0,0x7f,0xff,0xf7,0xff,0xff,0xbf,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xf8,0x0,0x7f,0xff,0xf7,0xff,0x7,0xbf,0xb,0xe3,0xf9,0xfe,0x1f,0xff,0xff,
0xff,0xf8,0x0,0xff,0xff,0xf9,0xfe,0xfb,0xbc,0xf3,0x9d,0xd6,0xb9,0xef,0x81,0xff,
0xff,0xf0,0x0,0xff,0xff,0xfe,0x3d,0xfd,0xbd,0xfb,0xbe,0xcf,0xbb,0xf7,0x77,0xff,
0xff,0xf0,0x1,0xfe,0x7,0xff,0x9d,0xfd,0xbb,0xfb,0x7e,0xdf,0xbb,0xf6,0xfb,0xff,
0xff,0xf0,0x1,0xe0,0x7,0xff,0xed,0xfd,0xbb,0xfb,0x0,0xdf,0xbb,0xf6,0xfb,0xff,
0xff,0xf0,0x0,0x0,0xf,0xff,0xed,0xfd,0xbb,0xfb,0x7f,0xdf,0xbb,0xf6,0xf7,0xff,
0xff,0xe0,0x0,0x0,0xf,0xff,0xed,0xfd,0xbb,0xfb,0x7f,0xdf,0xbb,0xf7,0x77,0xff,
0xff,0xe0,0x0,0x0,0x1f,0xff,0xed,0xfd,0xbd,0xfb,0xbf,0xdf,0xbb,0xf7,0x8f,0xff,
0xff,0xe0,0x0,0x0,0x1f,0xf7,0xde,0xfb,0xbc,0xf3,0x9e,0xdf,0xbb,0xf7,0x3f,0xff,
0xff,0xe0,0x0,0x0,0x3f,0xf8,0x3f,0x7,0xbf,0xb,0xe1,0xdf,0xbb,0xf7,0x7f,0xff,
0xff,0xc0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3,0xff,
0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xfd,0xff,
0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xfd,0xff,
0xff,0xc0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xf9,0xff,
0xff,0x80,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7,0xff,
0xff,0x80,0x1e,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0x81,0xfe,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xdf,0xfe,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xfc,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xfc,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xfc,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xfc,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,
0xff,0xff,0xf8,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,
0xff,0xff,0xf8,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,
0xff,0xff,0xf8,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,0xff,
0xff,0xff,0xf8,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,0x78,0x3f,0xf,0xff,
0xff,0xff,0xf0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x75,0xb7,0xdc,0xf7,0xff,
0xff,0xff,0xf0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x73,0xef,0xed,0xfb,0xff,
0xff,0xff,0xf0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xef,0xed,0xfb,0xff,
0xff,0xff,0xf0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xef,0xed,0xfb,0xff,
0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xef,0xed,0xfb,0xff,
0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xef,0xed,0xfb,0xff,
0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xef,0xed,0xfb,0xff,
0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xf7,0xdd,0xfb,0xff,
0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x77,0xf8,0x3d,0xfb,0xff,
0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xcf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};
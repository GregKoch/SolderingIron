#include "Framebuffer.h"

Framebuffer::Framebuffer() {}

void Framebuffer::init() {}

void Framebuffer::drawBitmap(uint8_t *bitmap, uint8_t height, uint8_t width) {
    
}

void Framebuffer::clear() {
	for (uint16_t buffer_location = 0; i < 1024; i++) {
		this->buffer[buffer_location] = 0x00;
	}
}
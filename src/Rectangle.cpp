#include "Rectangle.h"

rectangle::rectangle() {
	x1 = 0;
	y1 = 0;
	width = 0;
	height = 0;
	color = Color8u(0,0,0);
	pixels = NULL;
	kSurfaceSize = 1024;
}

void rectangle::set(int set_x1, int set_y1, int set_width, int set_height, Color8u set_color, uint8_t* set_pixels) {
	x1 = set_x1;
	y1 = set_y1;
	width = set_width;
	height = set_height;
	color = set_color;
	pixels = set_pixels;
}

void rectangle::draw() {
	for (int y = x1; y < (y1 + height); y++) {
		for (int x = x1; x < (x1 + width); x++) {
				int index = 4*(x+y*kSurfaceSize);
				pixels[index] = color.r;
				pixels[index+1] = color.g;
				pixels[index+2] = color.b;
		}
	}
}
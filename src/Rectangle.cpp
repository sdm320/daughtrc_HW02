#include "Rectangle.h"

rectangle::rectangle() {
	x1 = 0;
	y1 = 0;
	width = 0;
	height = 0;
	color = Color8u(0,0,0);
}

void rectangle::set(int set_x1, int set_y1, int set_width, int set_height, Color8u set_color) {
	x1 = set_x1;
	y1 = set_y1;
	width = set_width;
	height = set_height;
	color = set_color;
}
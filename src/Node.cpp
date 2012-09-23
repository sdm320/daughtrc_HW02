#include "Node.h"

Node::Node(int x_coord, int y_coord, int length, float red, float green, float blue){
	next_ = this;
	x = x_coord;
	y = y_coord;
	length = length;
	r = red;
	g = green;
	b = blue;

}

Node::~Node(void)
{
}
#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "Shape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class rectangle : public Shape {
  public:
	  rectangle();
	  int x1, y1, width, height;
	  Color8u color;
	  void set(int set_x, int set_y, int set_width, int set_height, Color8u set_color);
};
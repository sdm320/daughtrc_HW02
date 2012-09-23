#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Node.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class daughtrc_HW02App : public AppBasic {
  public:

	//variables
	Node* sentinel;
	Surface* mySurface_;
	uint8_t* myPixels_;

	//methods
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	void drawSquare(uint8_t* pixels, Node* node_to_print);
	static void clear(uint8_t* pixels);

  private:
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	static const int kSurfaceSize=1024;

};

//set window size
void daughtrc_HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void daughtrc_HW02App::setup()
{
	//initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,true);
	myPixels_ = (*mySurface_).getData();
	clear(myPixels_);

	//establish the start of the linked list
	sentinel = &Node(100,100,100,0.0f,0.0f,0.0f);

	//draw the sentinel
	drawSquare(myPixels_, sentinel);
}

void daughtrc_HW02App::clear(uint8_t* pixels){
	Color c = Color(250.0f,250.0f,250.0f);
	for(int y = 0; y < kSurfaceSize; y++){
		for(int x = 0; x < kSurfaceSize; x++){
			int index = 3*(x + y*kAppWidth);
			pixels[index] = c.r;
			pixels[index+1] = c.g;
			pixels[index+2] = c.b;
		}
	}
}

void daughtrc_HW02App::drawSquare(uint8_t* pixels, Node* node_to_print)
{
	//initialize a new color
	Color c = Color(node_to_print->r,node_to_print->g,node_to_print->b);

	//do some invalid data checking
	if (node_to_print->length < 0) return;

	for (int y = node_to_print->y; y < node_to_print->length; y++) {
		for (int x = node_to_print->x; x < node_to_print->length; x++) {
			//check to make sure the square isn't being printed off the app
			if (x < 0 || y < 0 || x > kAppWidth || y > kAppHeight) continue;
			//change pixel color
			int index = 3 * (x + y * kSurfaceSize);
			pixels[index] = c.r;
			pixels[index+1] = c.g;
			pixels[index+2] = c.b;
		}
	}
}


void daughtrc_HW02App::mouseDown( MouseEvent event )
{
}

void daughtrc_HW02App::update()
{
}

void daughtrc_HW02App::draw()
{
	// clear out the window with white
	//gl::clear( Color( 250.0, 250.0, 250.0 ) ); 
	gl::draw(*mySurface_);
}

CINDER_APP_BASIC( daughtrc_HW02App, RendererGl )

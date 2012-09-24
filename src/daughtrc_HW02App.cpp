#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "Shape.h"
#include "daughtrc_HW02.h"
#include "Rectangle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class daughtrc_HW02App : public AppBasic {
  public:

	//methods
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	void drawRectangle(uint8_t* pixels, rectangle* rectangle);
	static void clear(uint8_t* pixels);

  private:
	static const int kAppWidth=1024;
	static const int kAppHeight=700;
	static const int kSurfaceSize=1024;

	//variables
	Surface* mySurface_;
	uint8_t* myPixels_;
	rectangle* rectangle_;
	rectangle* rectangle2;
	rectangle* rectangle3;
	rectangle* rectangle4;

	//create linked list
	node* sentinel;
	node* currentNode;

	int count;
};

//set window size
void daughtrc_HW02App::prepareSettings(Settings* settings)
{
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void insertAfter(node* insertHere, rectangle* new_rectangle)
{
	node* new_node = new node;
	new_node->data = new_rectangle;
	new_node->next_ = insertHere->next_;
	new_node->previous_ = insertHere;
	insertHere->next_->previous_ = new_node;
	insertHere->next_ = new_node;
}

void daughtrc_HW02App::setup()
{
	//initialize mySurface_
	mySurface_ = new Surface(kSurfaceSize,kSurfaceSize,true);
	myPixels_ = (*mySurface_).getData();
	clear(myPixels_);

	//set up first node
	sentinel = new node;
	rectangle_ = new rectangle();
	rectangle_->set(0,0,128,128,Color8u(0,0,0),myPixels_);
	sentinel->data = rectangle_;
	sentinel->next_ = sentinel;
	sentinel->previous_ = sentinel;
	sentinel->data->draw();

	//add a rectangle
	rectangle2 = new rectangle();
	rectangle2->set(128,128,128,128,Color8u(0,0,0),myPixels_);
	insertAfter(sentinel, rectangle2);
	rectangle3 = new rectangle();
	rectangle3->set(256,256,128,128,Color8u(0,0,0),myPixels_);
	insertAfter(sentinel, rectangle3);
	rectangle4 = new rectangle();
	rectangle4->set(256,0,128,128,Color8u(0,0,0),myPixels_);
	insertAfter(sentinel, rectangle4);
;
	count = 0;
	while (count != 5) {
		sentinel->data->draw();
		sentinel = sentinel->next_;
		count++;
	}


}

void daughtrc_HW02App::clear(uint8_t* pixels){
	Color c = Color(250.0,250.0,250.0);
	for(int y = 0; y < kSurfaceSize; y++){
		for(int x = 0; x < kSurfaceSize; x++){
			int index = 4*(x + y*kAppWidth);
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
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
	rectangle* rectangle5;
	rectangle* rectangle6;
	rectangle* rectangle7;
	rectangle* rectangle8;

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

void reverse(node* sentinel)
{
	node* cur = sentinel;
	do{
		node* temp = cur->next_; // Swap next and prev
		cur->next_ = cur->previous_;
		cur->previous_ = temp;
		cur = cur->previous_; // prev is the new next
	}while(cur != sentinel);
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
	rectangle_->set(0,0,128,128,Color8u(200,20,125),myPixels_);
	sentinel->data = rectangle_;
	sentinel->next_ = sentinel;
	sentinel->previous_ = sentinel;

	//add a rectangle
	rectangle2 = new rectangle();
	rectangle2->set(256,0,128,128,Color8u(25,75,100),myPixels_);
	insertAfter(sentinel, rectangle2);
	rectangle3 = new rectangle();
	rectangle3->set(128,128,128,128,Color8u(100,20,250),myPixels_);
	insertAfter(sentinel, rectangle3);
	rectangle4 = new rectangle();
	rectangle4->set(384,128,128,128,Color8u(175,45,10),myPixels_);
	insertAfter(sentinel, rectangle4);
	rectangle5 = new rectangle();
	rectangle5->set(512,0,128,128,Color8u(126,0,0),myPixels_);
	insertAfter(sentinel, rectangle5);
	rectangle6 = new rectangle();
	rectangle6->set(640,128,128,128,Color8u(0,200,0),myPixels_);
	insertAfter(sentinel, rectangle6);
	rectangle7 = new rectangle();
	rectangle7->set(768,0,128,128,Color8u(0,0,110),myPixels_);
	insertAfter(sentinel, rectangle7);
	rectangle8 = new rectangle();
	rectangle8->set(896,128,128,128,Color8u(150,25,250),myPixels_);
	insertAfter(sentinel, rectangle8);

	reverse(sentinel);

	count = 0;
	while (count != 9) {
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
	if (event.isLeftDown()) {
		reverse(sentinel);
		count = 0;
	    while (count != 9) {
			sentinel->data->draw();
			sentinel = sentinel->next_;
			count++;
		}
	}		
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
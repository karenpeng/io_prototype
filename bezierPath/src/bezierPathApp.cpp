#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "content.h"
#include <iostream>
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Path2dApp : public AppBasic {
 public:

	void prepareSettings(Settings *settings );
  void setup();
  void update();
	void draw();
  
  //list<Content*> mContents;
  vector<Content> mContents;
  Thread thread = Thread();
  int frameCount = 0;
};

void Path2dApp::prepareSettings( Settings *settings ){
  settings->setWindowSize( 1400, 800 );
  settings->setFrameRate( 60.0f );
}

void Path2dApp::setup(){
  thread.setup();
}


void Path2dApp::update(){
  
  thread.update();
  
  if(frameCount == 0 || frameCount % 600 == 0){
    mContents.push_back( Content(Vec3f(1800,randFloat(400,500),randFloat(-2,2))));
  }
  
  frameCount ++;
  
  for(int i=0; i< mContents.size();i++){
    mContents[i].seek(thread.mPoints);
    mContents[i].update();
  }
  
}

void Path2dApp::draw()
{
	gl::clear( Color( 0.9f, 0.9f, 0.9f ) );
	gl::enableAlphaBlending();

  thread.draw();
	 
  for(int i=0; i< mContents.size();i++){
    mContents[i].draw();
  }
}


CINDER_APP_BASIC( Path2dApp, RendererGl )

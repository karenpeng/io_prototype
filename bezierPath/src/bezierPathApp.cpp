#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "content.h"
#include "Particle Controller.h"
#include <iostream>
#include <vector>

#define NUM_PARTICLES_PER_FRAME 4

#define   windowWidth 1600
#define   windowHeight 900

using namespace ci;
using namespace ci::app;
using namespace std;

class Path2dApp : public AppBasic {
 public:

	void prepareSettings(Settings *settings );
  void setup();
  void update();
	void draw();
  
  list<Content*> mContents;
  Thread thread = Thread();
private:
  ParticleController *controller;
  
  Perlin mPerlin;
  Vec2i mousePosition;
  Vec2i mouseVelocity;
  double mLastTime;
  int frameCount = 0;
};

void Path2dApp::prepareSettings( Settings *settings ){
  settings->setWindowSize( windowWidth, windowHeight );
  settings->setFrameRate( 60.0f );
}

void Path2dApp::setup(){
  thread.setup();
  controller = new ParticleController();
  controller->setup();
  mPerlin = Perlin();
}


void Path2dApp::update(){
  
  cout<<thread.mPoints.size()<<endl;

  if(frameCount % 10 == 0){
  controller->addParticles(NUM_PARTICLES_PER_FRAME, Vec2f(randFloat(0,windowWidth),randFloat(windowHeight*3/8,windowHeight*5/8)), Vec2f(randFloat(),randFloat()));
  }
  thread.update();
  
  if(frameCount == 0 || frameCount % 600 == 0){
    Content *c = new Content(Vec3f(windowWidth+200,randFloat(windowHeight/4, windowHeight*3/4),randFloat(-2,2)));
    mContents.push_back(c);
  }
  
  frameCount ++;
  
  for(std::list<Content*>::iterator i = mContents.begin(); i!= mContents.end();){
    
    Content *c = (*i);
    if(c->die()){
      i = mContents.erase(i);
      delete c;
    }else{
      c->seek(thread.mPoints);
      c->update();
      ++i;
    }
  }
  
  double currentTime = app::getElapsedSeconds();
  double deltaTime = currentTime - mLastTime;
  float delta = (float)app::getFrameRate() / (1.0 / deltaTime);
  
  mLastTime = currentTime;
  
	this->controller->update(delta,  mPerlin);
  
}

void Path2dApp::draw()
{
	gl::clear( Color( 0.96f, 0.96f, 0.96f ) );
	gl::enableAlphaBlending();

  thread.draw();
  
  gl::pushMatrices();
  this->controller->draw();
  gl::popMatrices();
	 
  for(std::list<Content*>::iterator i = mContents.begin(); i!= mContents.end(); i++){
    Content *c = (*i);
    c->draw();
  }
}


CINDER_APP_BASIC( Path2dApp, RendererGl )

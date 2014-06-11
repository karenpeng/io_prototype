#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
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
  int frameCount = 0;
};

void Path2dApp::prepareSettings( Settings *settings ){
  settings->setWindowSize( 1400, 800 );
  settings->setFrameRate( 60.0f );
}

void Path2dApp::setup(){
  //Content* c = new Content(Vec3f(1300,randFloat(200,600),randFloat(-2,2)));
  //mContents.push_back(c);
  //cout<< "here" <<endl;
}


void Path2dApp::update(){
  if(frameCount == 0 || frameCount % 600 == 0){
//    Content* c = new Content(Vec3f(1300,randFloat(200,600),randFloat(-2,2)));
//    mContents.push_back(c);
    
    mContents.push_back( Content(Vec3f(1500,randFloat(100,600),randFloat(-2,2))));
    //cout<< "there" <<endl;

  }
  
  frameCount ++;
  
//  for(std::list<Content*>::iterator i = mContents.begin(); i != mContents.end();){
//    Content* c = (*i);
//    if(c->die()){
//      i = mContents.erase(i);
//      delete c;
//    }else{
//      c->update();
//      ++i;
//    }
//  }
  for(int i=0; i< mContents.size();i++){
    //Content c = mContents[i];
    //if(c.die()){
      //mContents.erase(i);
    //}else{
    //  c.update();
      //cout<< c.mLocation<<endl;
    //}
    mContents[i].update();
  }
  
}

void Path2dApp::draw()
{
	gl::clear( Color( 0.9f, 0.9f, 0.9f ) );
	gl::enableAlphaBlending();
	 
//  for(std::list<Content*>::iterator j = mContents.begin(); j != mContents.end();){
//    (*j)->draw();
//    }
  for(int i=0; i< mContents.size();i++){
    //Content c = mContents[i];
    //gl::pushMatrices();
    //c.draw();
    mContents[i].draw();
    //gl::popMatrices();
  }
}


CINDER_APP_BASIC( Path2dApp, RendererGl )

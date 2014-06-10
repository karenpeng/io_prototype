#include "cinder/app/AppBasic.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "content.h"

#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Path2dApp : public AppBasic {
 public:
	//Path2dApp() : mTrackedPoint( -1 ) {}
	

	void prepareSettings(Settings *settings );
  void setup();
  void update();
	void draw();
  
  vector<Content> mContents;
	
	Path2d	mPath;
	//int		mTrackedPoint;
  int frameCount = 0;
  float initX = 800;
  Vec2f prePoint = Vec2f(initX,100);
  Vec2f ranPoint;
};

void Path2dApp::prepareSettings( Settings *settings ){
  settings->setWindowSize( 1200, 800 );
  settings->setFrameRate( 60.0f );
}

void Path2dApp::setup(){
  mContents = vector<Content>();
  mContents.push_back(Content(prePoint));
  mPath.moveTo( mContents[0].mLocation );
  initX -= randFloat(10,200);
}

void Path2dApp::update(){
  frameCount ++;
  if(frameCount % 120 == 0){
    ranPoint = Vec2f(initX,randFloat(100,500));
    mContents.push_back(Content(ranPoint));
    float deltaX = prePoint.x - ranPoint.x;
    initX -= randFloat(10,200);
    
    mPath.curveTo(Vec2f(ranPoint.x+deltaX/3,prePoint.y), Vec2f(ranPoint.x+deltaX*2/3,ranPoint.y),  ranPoint);
    prePoint = ranPoint;
  }
  
  for(int i = 0; i< mContents.size();i++){
    mContents[i].update();
  }
}

void Path2dApp::draw()
{
	gl::clear( Color( 0.0f, 0.1f, 0.2f ) );
	gl::enableAlphaBlending();
	
	// draw the control points
  if(!mPath.empty()){
	gl::color( Color( 1, 1, 0 ) );
	for( size_t p = 0; p < mPath.getNumPoints(); ++p )
		gl::drawSolidCircle( mPath.getPoint( p ), 2.5f );


	gl::color( Color( 1.0f, 0.5f, 0.25f ) );
	gl::draw( mPath );
  }
  
  for(int i=0;i<mContents.size();i++){
    mContents[i].draw();
  }
}


CINDER_APP_BASIC( Path2dApp, RendererGl )

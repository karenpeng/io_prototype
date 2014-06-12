//
//  Thread.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//

#include "cinder/Vector.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "Thread.h"

#define   windowWidth 1600
#define   windowHeight 900

using namespace ci;
using namespace std;

Thread::Thread(){
  
}


void Thread::setup(){
  for(int i=0;i<5;i++){
    mPoints.push_back(Vec2f(i*windowWidth/2, randFloat(200,600)));
  }
  noiseOff = randFloat(0,10);
}

void Thread::update(){
  
  for(int j =0;j<mPoints.size();j++){
    mPoints[j].y = noise.fBm(mPoints[j].x*0.0005, noiseOff)*windowWidth/3 + 400;
    noiseOff += 0.000001 ;
    mPoints[j].x -- ;
  }
  
  //if the point is too left from the screen, put it to the right of the screen
  if(mPoints[0].x < -windowWidth / 2){
    mPoints[0].x = 4 * windowWidth / 2;
    Vec2f copyPoint0 = mPoints[0];
    //swap the order
    for(int k =0;k<mPoints.size()-1;k++){
      mPoints[k] = mPoints[k+1];
    }
    mPoints[mPoints.size()-1] = copyPoint0;
  }

  for(int i =0;i<mPoints.size()-1;i++){
    
   if(i == 0){
      mPath.clear();
      mPath.moveTo(mPoints.at(0));
    }
    Vec2f prePoint = mPoints.at(i);
    Vec2f curPoint = mPoints.at(i+1);
    float deltaX = curPoint.x - prePoint.x;
    //float deltaY = curPoint.y - prePoint.y;    
    mPath.curveTo(Vec2f(prePoint.x+deltaX/2,prePoint.y), Vec2f(curPoint.x-deltaX/2,curPoint.y),Vec2f(curPoint));
  }
  
}

void Thread::draw(){
  if(!mPath.empty()){
    gl::color( Color( 1, 1, 0 ) );
    for( size_t p = 0; p < mPath.getNumPoints(); ++p ){
      gl::drawSolidCircle( mPath.getPoint( p ), 2.5f );
    }
    gl::color( Color( 0.8f, 0.8f, 0.8f ) );
    gl::draw( mPath );
  }
}

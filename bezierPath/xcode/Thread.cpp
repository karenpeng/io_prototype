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

using namespace ci;
using namespace std;

Thread::Thread(){
  
}

//Thread::Thread(int apointNumber){
//  //pointNumber = apointNumber;
//}

void Thread::setup(){
  for(int i=0;i<7;i++){
    mPoints.push_back(Vec2f(i*400-300, randFloat(300,500)));
  }
  noiseOff = randFloat(0,10);
  noiseOff1 = randFloat(0,10);
}

void Thread::update(){
  //noise1 = Perlin();
 // for(vector<Vec2f>::iterator it = mPoints.begin(); it != mPoints.end(); ++it){
 // Vec2f p = *it;
  for(int j =0;j<mPoints.size()-1;j++){
    
    //float newY = noise.fBm(noiseOff)*200+200;
    //mPoints[j].y = newY;
    
    //float oldY = mPoints[j].y;
    
    mPoints[j].y = noise.fBm(mPoints[j].x, noiseOff)*400 + 400;
    
    //mPoints[j].y = noise.fBm(mPoints[j].x, noiseOff)*400+sin(mPoints[j].x+noiseOff1)*400+200;
    
    //mPoints[j].y = sin(mPoints[j].x+noiseOff1)*400+200;
    
    noiseOff += 0.0001 ;
    noiseOff1 += 0.001;
  }
  
  for(int i =0;i<mPoints.size()-1;i++){
//  for(vector<Vec2f>::iterator it = mPoints.begin(); it != mPoints.end(); ++it){
  
//    Vec2f currentPoint = *it;
//    Vec2f nextPoint = *(it + 1);
    
   if(i == 0){
      mPath.clear();
      mPath.moveTo(mPoints.at(0));
    }
    Vec2f prePoint = mPoints.at(i);
    Vec2f curPoint = mPoints.at(i+1);
    float deltaX = curPoint.x - prePoint.x;
    mPath.curveTo(Vec2f(prePoint.x+deltaX/2,prePoint.y), Vec2f(curPoint.x-deltaX/2,curPoint.y),Vec2f(curPoint));
    
    if(i==mPoints.size()-2){
      //mPath.close();
    }
  }
  
}

void Thread::draw(){
  if(!mPath.empty()){
    gl::color( Color( 1, 1, 0 ) );
//    for( size_t p = 0; p < mPath.getNumPoints(); ++p ){
//      gl::drawSolidCircle( mPath.getPoint( p ), 2.5f );
//    }
    gl::color( Color( 0.7f, 0.7f, 0.7f ) );
    gl::draw( mPath );
  }
}

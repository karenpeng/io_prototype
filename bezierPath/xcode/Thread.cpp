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
  for(int i=0;i<11;i++){
    mPoints.push_back(Vec2f(i*140, randFloat(300,500)));
  }
}

void Thread::update(){
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
    mPath.curveTo(Vec2f(prePoint.x+deltaX/3,prePoint.y), Vec2f(curPoint.x-deltaX/3,curPoint.y),Vec2f(curPoint));
    
    if(i==mPoints.size()-2){
      //mPath.close();
    }
  }
  
}

void Thread::draw(){
  if(!mPath.empty()){
    gl::color( Color( 1, 1, 0 ) );
    for( size_t p = 0; p < mPath.getNumPoints(); ++p ){
      //gl::drawSolidCircle( mPath.getPoint( p ), 2.5f );
      gl::color( Color( 0.4f, 0.4f, 0.4f ) );
      gl::draw( mPath );
    }
  }
}

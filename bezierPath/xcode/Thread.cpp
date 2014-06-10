//
//  Thread.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//

#include "Thread.h"
#include "cinder/Vector.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Rect.h"

using namespace ci;
using namespace std;

Thread::Thread(){
  
}

//Thread::Thread(int apointNumber){
//  //pointNumber = apointNumber;
//}

void Thread::setup(){
  for(int i=0;i<100;i++){
    mPoints.push_back(Vec2f(i*12, randFloat(300,500)));
  }
}

void Thread::update(){
  for(int i =0;i<mPoints.size()-1;i++){
    if(i==0){
      mPath.moveTo(mPoints[0]);
    }
    Vec2f prePoint = mPoints[i];
    Vec2f curPoint = mPoints[i+1];
    float deltaX = prePoint.x - curPoint.x;
    mPath.curveTo(Vec2f(prePoint.x+deltaX/3,prePoint.y), Vec2f(curPoint.x+deltaX*2/3,curPoint.y),Vec2f(curPoint));
  }
  
}

void Thread::draw(){
  if(!mPath.empty()){
    gl::color( Color( 1, 1, 0 ) );
    for( size_t p = 0; p < mPath.getNumPoints(); ++p )
      gl::drawSolidCircle( mPath.getPoint( p ), 2.5f );
    
    
    gl::color( Color( 1.0f, 0.5f, 0.25f ) );
    gl::draw( mPath );
  }
}

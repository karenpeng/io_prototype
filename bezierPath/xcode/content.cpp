//
//  content.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "content.h"
#include "cinder/Rect.h"
#include <vector>

using namespace ci;
using namespace std;

Content::Content(){
}

Content::Content( Vec3f loc){
  mLocation = loc;
  mVelocity = Vec3f(randFloat(-0.6,-0.5),randFloat(-0.1,0.1),0);
  w = randFloat(200,340);
  h = randFloat(300,540);
  Rectf block;
  block = Rectf(0,0,w,h);
  seekIndex = 6;
  attracted = false;
}

bool Content::die(){
  return mLocation.x < -w/2;
}

void Content::seek(vector<Vec2f> aPoints){

  float disX = mLocation.x - aPoints[seekIndex].x;
  cout<< disX<<endl;
  if(disX > 0){
    Vec2f dir = aPoints[seekIndex] - Vec2f(mLocation.x, mLocation.y);
    mLocation += 0.0002 * Vec3f(dir.x,dir.y,0);
    attracted = true;
  }else{
    seekIndex --;
    attracted = false;
  }
}

void Content::update(){
  mVelocity += mAccerleration;
  mLocation += mVelocity;
  block = Rectf(mLocation.x-w/2,mLocation.y-h/2,mLocation.x+w/2,mLocation.y+h/2);
  mAccerleration = Vec3f(0,0,0);
}

void Content::draw(){
//  if(!attracted){
  gl::color(1.0f,1.0f,1.0f);
//  }else{
//  gl::color(0.9f,0.0f,1.0f);
//  }
  gl::pushMatrices();
  //gl::translate(Vec3f (mLocation.x, mLocation.y, mLocation.z));
  gl::drawSolidRect(block);
  glLineWidth(2.0);
  gl::color( 0.8f, 0.8f, 0.8f );
  gl::drawStrokedRect(block);
  gl::popMatrices();
}

//
//  content.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//
#include "cinder/Vector.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "content.h"
#include "cinder/Rect.h"

using namespace ci;
Content::Content(){

}

Content::Content( Vec2f loc){

  mLocation = loc;
  mVelocity = Vec2f(-0.6,0);
  w = randFloat(100,200);
  h = randFloat(20,200);
  Rectf block;
}

void Content::setup(){

}

void Content::update(){
  mLocation += mVelocity;
  block = Rectf(mLocation.x-w/2,mLocation.y-h/2,mLocation.x+w/2,mLocation.y+h/2);
}

void Content::draw(){
  gl::color(0.5f,1.0f,1.0f);
  gl::drawSolidRect(block);
}

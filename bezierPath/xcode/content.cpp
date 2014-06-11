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

using namespace ci;
using namespace std;

Content::Content(){
}

Content::Content( Vec3f loc){
  mLocation = loc;
  mVelocity = Vec3f(randFloat(-0.6,-0.2),0,0);
  w = randFloat(300,600);
  h = randFloat(200,300);
  Rectf block;
  block = Rectf(0,0,w,h);;
}

bool Content::die(){
  return mLocation.x < -w/2;
}

void Content::update(){
  mLocation += mVelocity;
  block = Rectf(mLocation.x-w/2,mLocation.y-h/2,mLocation.x+w/2,mLocation.y+h/2);
  cout<< mLocation<<endl;

}

void Content::draw(){
  gl::color(1.0f,1.0f,1.0f);
  gl::pushMatrices();
  //gl::translate(Vec3f (mLocation.x, mLocation.y, mLocation.z));
  gl::drawSolidRect(block);
  glLineWidth(2.0);
  gl::color( 0.8f, 0.8f, 0.8f );
  gl::drawStrokedRect(block);
  gl::popMatrices();
}

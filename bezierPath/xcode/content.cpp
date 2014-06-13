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
#include "cinder/CinderMath.h"
#include <vector>

#define   windowWidth 1200
#define   windowHeight 700

using namespace ci;
using namespace std;

Content::Content(){
}

Content::Content( Vec3f loc){
  mLocation = loc;
  mVelocity = Vec3f(randFloat(-2.0,-1.6),randFloat(-0.1,0.1),0);
  w = randFloat(200,340);
  h = randFloat(300,540);
  Rectf block;
  block = Rectf(0,0,w,h);
  seekIndex = 4;
  attracted = false;
  maxSpeed = 0.002f;
}

bool Content::die(){
  return mLocation.x < -w/2;
}

Vec2f Content::seek(vector<Vec2f> aPoints){
  
  float minDis= windowWidth * 2;
  for(int i = aPoints.size()-1; i >= 0; i--){
    float dis = aPoints[i].distance( Vec2f(mLocation.x, mLocation.y) );
    if(dis < minDis) {
      seekIndex = i;
      minDis = dis;
    }
  }

  Vec2f dir = aPoints[seekIndex] - Vec2f(mLocation.x, mLocation.y);
  Vec2f steer = dir - Vec2f( mVelocity.x, mVelocity.y );
  steer.safeNormalize();
  //steer.x = constrain(steer.x, -1.2f, -0.4f);
  steer *= maxSpeed;
  steer.x = randFloat(-0.002, -0.0006);
  attracted = true;
  return steer*0.5;

}

void Content::addForce(Vec2f force){
  mAccerleration += Vec3f(force.x,force.y,0);
}

void Content::update(){
  mVelocity += mAccerleration;
  mLocation += mVelocity;
  mLocation.y = constrain( mLocation.y, 100.0f, windowHeight-200.0f );
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

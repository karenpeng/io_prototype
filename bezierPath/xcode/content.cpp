//
//  content.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//
#include "cinder/app/App.h"
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "content.h"
#include "cinder/Rect.h"
#include "cinder/CinderMath.h"
#include <vector>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/Area.h"

#define   windowWidth 1280
#define   windowHeight 1280*7/12

using namespace ci;
using namespace ci::app;
using namespace std;

Content::Content(){
}

Content::Content( Vec3f loc, int postIndex){
  mLocation = loc;

  mVelocity = Vec3f(randFloat(-0.8,-0.74),randFloat(-0.1,0.1),0);
  w = randFloat(200,340);
  h = randFloat(300,540);
  Rectf block;
  block = Rectf(0,0,w,h);
  seekIndex = 4;
  attracted = false;
  maxSpeed = 0.002f;
  angle = 20.0f;

  string names[7] = {
    "post_image_square.png",
    "post_image_tall.png",
    "post_image_wide.png",
    "post_text_01.png",
    "post_text_02.png",
    "post_text_03.png",
    "post_text_04.png"
  };
  
  mImage = gl::Texture( loadImage( ci::app::loadResource( names[postIndex] ) ) );
  w = mImage.getWidth();
  h = mImage.getHeight();  
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
  steer.x = 0;
  attracted = true;
  return steer*0.1;

}

void Content::addForce(Vec2f force){
  mAccerleration += Vec3f(force.x,force.y,0);
}

void Content::update(){
  mVelocity += mAccerleration;
  mLocation += mVelocity;
  mLocation.y = constrain( mLocation.y, 100.0f, windowHeight-300.0f );
  block = Rectf((float)mLocation.x-w/2,(float)mLocation.y-h/2,(float)mLocation.x+w/2,(float)mLocation.y+h/2);
  mAccerleration = Vec3f(0,0,0);
  if(mLocation.x< windowWidth ){
    angle -= 0.1;
    if(angle<= 0.0f) angle = 0.0f;
  }
}

void Content::draw(){
  gl::enableAlphaBlending();
//  if(!attracted){
  gl::color(1.0f,1.0f,1.0f);
//  }else{
//  gl::color(0.9f,0.0f,1.0f);
//  }
  gl::pushMatrices();
//  gl::translate(Vec2f (-mLocation.x,-mLocation.y));
//  gl::translate(Vec2f (w/2, h/2));
//  gl::rotate(Vec3f(0, angle, 0));
//  gl::translate(Vec2f (-w/2, -h/2));
//  gl::translate(Vec2f (mLocation.x,mLocation.y));
//  gl::drawSolidRect(block);
//  glLineWidth(2.0);
//  gl::color( 0.8f, 0.8f, 0.8f );
    gl::draw( mImage, block );
//  gl::drawStrokedRect(block);
//  gl::translate(Vec2f (-mLocation.x,-mLocation.y));
  gl::popMatrices();
}

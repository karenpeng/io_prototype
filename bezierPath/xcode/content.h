//
//  content.h
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//

#ifndef __bezierPath__content__
#define __bezierPath__content__
#include <iostream>
#include <vector>
#include "cinder/Vector.h"
#include "cinder/Rect.h"
#include "Thread.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#endif /* defined(__bezierPath__content__) */


using namespace ci;
using namespace std;

class Content{
public:
  Content();
  Content(Vec3f loc, int postIndex);
  Vec3f mLocation;
  Vec3f mVelocity;
  Vec3f mAccerleration;
  Rectf block;
  bool die();
  void update();
  Vec2f seek(vector<Vec2f> aPoints);
  void addForce(Vec2f aForce);
  void draw();
  int seekIndex;
  bool attracted;
  float maxSpeed;
  float angle;
  gl::Texture mImage;
  int32_t w;
  int32_t h;
//  float w;
//  float h;
};


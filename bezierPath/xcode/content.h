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
#include "cinder/Vector.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Rect.h"
#endif /* defined(__bezierPath__content__) */


using namespace ci;
//using namespace ci::app;

class Content{
public:
  Content();
  Content(Vec2f loc);
  Vec2f mLocation;
  Vec2f mVelocity;
  float w;
  float h;
  Rectf block;
  void setup();
  void update();
  void draw();
  
};


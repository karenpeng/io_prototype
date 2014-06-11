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
#include "cinder/Rect.h"
#endif /* defined(__bezierPath__content__) */


using namespace ci;

class Content{
public:
  Content();
  Content(Vec3f loc);
  Vec3f mLocation;
  Vec3f mVelocity;
  float w;
  float h;
  Rectf block;
  bool die();
  void update();
  void draw();
  
};


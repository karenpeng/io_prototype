//
//  Thread.h
//  bezierPath
//
//  Created by Karen Peng on 6/10/14.
//
//

#ifndef __bezierPath__Thread__
#define __bezierPath__Thread__

#include <iostream>
//#include "cinder/Thread.h"
#include "cinder/Vector.h"
#include "cinder/Path2d.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#endif /* defined(__bezierPath__Thread__) */

using namespace ci;
using namespace std;

class Thread{
  public:
  Thread();
  vector <Vec2f> mPoints;
  Path2d mPath;
  int pointNumber;
  void setup();
  void update();
  void draw();
  
};

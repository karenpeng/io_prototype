//
//  Particle Controller.h
//  bezierPath
//
//  Created by Karen Peng on 6/12/14.
//
//

#ifndef __bezierPath__Particle_Controller__
#define __bezierPath__Particle_Controller__

#include <iostream>

#endif /* defined(__bezierPath__Particle_Controller__) */

#include "cinder/Perlin.h"
#include "Particle.h"
#include <list>

using namespace ci;
using namespace std;

class ParticleController {
public:
  void setup();
  void update(float delta, Perlin &perlin, vector<Vec2f> aPoints);
  void draw();
  void addParticles(int amt, const Vec2f &position, const Vec2f &velocity);
  void removeParticles(int amt);
  
  list<Particle*> mParticles;
};
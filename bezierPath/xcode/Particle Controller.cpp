//
//  Particle Controller.cpp
//  bezierPath
//
//  Created by Karen Peng on 6/12/14.
//
//

#include "Particle Controller.h"

#include "cinder/CinderMath.h"
#include "cinder/Rand.h"

#define SPRAY 128.0f
#define MAX_VELOCITY 16.0f
#define LEFTDRIFT 3.0f

void ParticleController::setup() {
}

void ParticleController::addParticles(int amt, const Vec2f &position, const Vec2f &velocity) {
  Vec2f clampedVelocity = Vec2f(cinder::math<float>::clamp(velocity.x, -MAX_VELOCITY, MAX_VELOCITY),
                                cinder::math<float>::clamp(velocity.y, -MAX_VELOCITY, MAX_VELOCITY));
  int max = amt;
  
  for (int i = 0; i < max; i++) {
    
    Vec2f offset = SPRAY * powf(Rand::randFloat(), 3.0f) * Rand::randVec2f();
    Vec2f vel = clampedVelocity * 0.5 + randVec2f();
    vel.x -= LEFTDRIFT;
    
    Particle *p = new Particle();
    p->setup(position + offset, vel);
    
    mParticles.push_back(p);
  }
}

void ParticleController::update(float delta, Perlin &perlin, vector<Vec2f> aPoints ) {
  for (std::list<Particle*>::iterator i = mParticles.begin(); i != mParticles.end();) {
    Particle *p = (*i);
    if (p->mIsDead) {
      i = mParticles.erase(i);
      delete p;      
    } else {
      p->update(delta, perlin);
      Vec2f seekForce= p->seek((aPoints));
      p->addForce(seekForce);
      ++i;
    }
  }
}

void ParticleController::draw() {
  for (std::list<Particle*>::iterator p = mParticles.begin(); p != mParticles.end(); p++) {
    (*p)->draw();
  }
}

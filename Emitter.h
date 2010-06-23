#ifndef _Emitter
#define _Emitter

/*
 *  Emitter.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 6/14/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

//#include "ofMain.h"
#include <vector>
#include "Particle.h"
#include "Agent.h"

class Emitter : public Agent {
public:
	
	Emitter(bool _recycles, int _timeToLive, ofxVec3f _tPos);
	void create(int numParticles);
	void destroy();
	void addParticle(Agent *_tAgent);
	void killParticle();
	void update();
	void draw();
	bool isDead();

	vector <Agent*> agentContainer;
	bool recycles;
};

#endif
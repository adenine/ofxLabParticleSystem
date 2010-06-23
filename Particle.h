#ifndef _Particle
#define _Particle

/*
 *  Particle.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 6/14/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

//#include "ofMain.h"
#include "ofxVectorMath.h"
#include "Agent.h"

/*
#include "Quad.h"
#include "Quart.h"
#include "Quint.h"
#include "Sine.h"
#include "Linear.h"
#include "Expo.h"
#include "Elastic.h"
#include "Cubic.h"
#include "Circ.h"
#include "Bounce.h"
#include "Back.h"
*/

class Particle : public Agent {
public:

	
	Particle(ofxVec3f pos, int _timeToLive);
	virtual ~Particle(){};
	void update();
	void draw();
	//bool isDead();
	void recycle();
	
	
	//Particle *pParticle;
	
	//ofxVec3f pt;
	

	//string sampleText;
	//TypeTools *typeUtil;
	//vector <string> textLines;
	
};

#endif
#ifndef SPRING_H
#define SPRING_H

/*
 *  Spring.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/11/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "ofxVectorMath.h"
#include "Particle.h"

class Spring {
	
public:
	
	Spring();
	
	Particle * particleA;
	Particle * particleB;
	
	float distance;
	float springiness;	 // this is the k, springiness constant
	
	void update();
	void draw();
	
	
};


#endif

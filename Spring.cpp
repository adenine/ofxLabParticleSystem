/*
 *  Spring.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/11/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "Spring.h"

//---------------------------------------------------------------------
Spring::Spring(){
	particleA = NULL;
	particleB = NULL;
}

//---------------------------------------------------------------------
void Spring::update(){
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	
	ofxVec3f pta = particleA->pos;
	ofxVec3f ptb = particleB->pos;
	
	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofxVec3f frcToAdd = (pta-ptb).normalized() * springForce;
	
	particleA->addForce(frcToAdd);
	particleB->addForce(-frcToAdd);
}


//---------------------------------------------------------------------
void Spring::draw(){
	
	if ((particleA == NULL) || (particleB == NULL)){
		return;
	}
	//ofEnableAlphaBlending();
	ofSetColor(255, 255, 255, 10);
	ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
	//ofDisableAlphaBlending();
}


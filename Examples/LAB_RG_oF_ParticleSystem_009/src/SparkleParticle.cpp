/*
 *  SparkleParticle.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/5/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "SparkleParticle.h"

SparkleParticle::SparkleParticle(ofxVec3f _pos, int _timeToLive) {
	origPos = _pos;
	pos = origPos;
	
	float tRan = ofRandom(10,100);
	myWidth = tRan;
	myHeight = tRan;
	
	timeToLive = _timeToLive;
	timeStarted = ofGetElapsedTimeMillis();
	
	alpha = 200;
}

void SparkleParticle::update() {
	vel = vel + acc;
	pos = pos + vel;
}

void SparkleParticle::draw() {
	
	glPushMatrix();
	glTranslated((pos.x - (myWidth/2)), (pos.y - (myHeight/2)), pos.z);	
	ofSetColor(255, ofRandom(120,255),  ofRandom(120,255));
	glEnable( GL_BLEND );
	ofCircle(0,0,myWidth);
	glPopMatrix();
	
}

void SparkleParticle::recycle() {
	pos = origPos;	
}
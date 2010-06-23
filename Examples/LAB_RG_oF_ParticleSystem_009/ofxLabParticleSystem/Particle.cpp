/*
 *  Particle.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 6/14/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "Particle.h"
#include <iostream>


Particle::Particle(ofxVec3f _pos, int _timeToLive) {
	origPos = _pos;
	pos = origPos;
	
	float tRan = ofRandom(10,100);
	myWidth = tRan;
	myHeight = tRan;

	timeToLive = _timeToLive;
	timeStarted = ofGetElapsedTimeMillis();
	
	alpha = 200;
	
	cout<<"MADE A PARTICLE"<<endl;
	// load an image to use
	//crystalImage.loadImage("glitter.png");
}

void Particle::update() {
	vel = vel + acc;
	pos = pos + vel;
	//cout<<"IT WORKED"<<endl;
	//cout<<"test "<<acc.x<<endl;
	//cout<<"pos: "<<pos.x<<endl;
}

void Particle::draw() {

	glPushMatrix();
	glTranslated((pos.x - (myWidth/2)), (pos.y - (myHeight/2)), pos.z);
	//cout<<"IT WORKED"<<endl;
	
	ofSetColor(255, ofRandom(120,255),  ofRandom(120,255));
	glEnable( GL_BLEND );
	//crystalImage.draw(0,0, myWidth, myHeight);
	ofCircle(0,0,myWidth);

	glPopMatrix();
	
}

void Particle::recycle() {
	pos = origPos;	
}
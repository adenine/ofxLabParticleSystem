/*
 *  Emitter.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 6/14/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 *
 */

#include "emitter.h"
#include <iostream>
//#include "Agent.h"

Emitter::Emitter(bool _recycles, int _timeToLive, ofxVec3f _tPos) {
	origPos = _tPos;
	pos = origPos;
	recycles = _recycles;
	
	timeToLive = _timeToLive;
	timeStarted = ofGetElapsedTimeMillis();

	cout<<"CREATING AN EMITTER"<<endl;
	//create(_numParticles);
	
}

void Emitter::addParticle(Agent *_tAgent) {
	
	//tempParticle = new Particle(pos, timeToLive);
	// push onto the vector stack
	agentContainer.push_back(_tAgent);
	//cout<<"added a partcle"<<endl;
	 
}


void Emitter::update() {

	// Make sure we delete the particles if we need to
	for(int i =0; i<agentContainer.size(); i++) {
		
		agentContainer[i]->update();
		
		/*
		if (particleContainer[i]->isDead() == true) {
			// kill it
			cout<<"Is dead"<<endl;
			
			
			//delete particleContainer[i];
			//particleContainer.erase(particleContainer.begin()+i);
			
			//particleContainer[i]->recycle();
		}
		*/
		
	}
	
	cout <<"IAM EMITTER"<<endl;

}

void Emitter::draw() {
	for(int i =0; i<agentContainer.size(); i++) {
		agentContainer[i]->draw();
	}
}

/*
void Emitter::create(int numParticles) {
	for (int i=0; i<numParticles; i++) {
		addParticle();
	}
}
 */

void Emitter::destroy() {
	for(int i =0; i<agentContainer.size(); i++) {
		cout<<"DELETED HERE"<<endl;
		//delete particleContainer[i];
		//particleContainer.erase(particleContainer.begin()+i);
	}
}

void Emitter::killParticle() {
	
}

bool Emitter::isDead() {
	// if it never dies then we don't have to check it has timed out.
	/*
	if (recycles == true) {
		if (ofGetElapsedTimeMillis() > timeStarted + timeToLive ) {
			cout<<"DESTROYED!"<<endl;
			destroy();
			return true;
		} else {
			return false;
		}
	}
	*/
}


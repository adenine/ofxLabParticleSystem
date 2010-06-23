/*
 *  Agent.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/5/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "Agent.h"

Agent::Agent() {
	damping = 0.2f;
}

bool Agent::isDead() {
	if (ofGetElapsedTimeMillis() > timeStarted + timeToLive ) {
		return true;
	} else {
		return false;
	}
}

void Agent::draw() {
	//this->resetForce();
	//cout<<"UPDATED"<<endl;
}

void Agent::update() {
	this->resetForce();
	//cout<<"UPDATED"<<endl;
}

void Agent::resetForce() {
    // we reset the forces every frame
    acc.set(0,0,0);
	//cout<<"reset force"<<endl;
}

void Agent::addForce(ofxVec3f _force) {
	acc.x = acc.x + _force.x;
    acc.y = acc.y + _force.y;
	acc.z = acc.z + _force.z;
	//cout<<"Added Force 2"<<endl;
}

void Agent::addScale(float _scale) {
	if	(myWidth > 5.0) {
		myWidth *= _scale;
		myHeight *= _scale;
	}
	//cout<<"Added Scale"<<endl;
}


void Agent::addRepulsionForce(ofxVec3f _rforce, float radius, float scale) {
    
	// ----------- (1) make a vector of where this position is: 
	
	ofxVec3f posOfForce;
	posOfForce.set(_rforce);
	
	// ----------- (2) calculate the difference & length 
	
	ofxVec3f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
		acc.x = acc.x + diff.x * scale * pct;
        acc.y = acc.y + diff.y * scale * pct;
		acc.z = acc.z + diff.z * scale * pct;
    }
}


void Agent::addAttractionForce(Agent & p, float radius, float scale) {
	
	// ----------- (1) make a vector of where this particle p is: 
	ofxVec3f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y,p.pos.z);
	
	// ----------- (2) calculate the difference & length 
	
	ofxVec3f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		acc.x = acc.x - diff.x * scale * pct;
        acc.y = acc.y - diff.y * scale * pct;
		acc.z = acc.z - diff.z * scale * pct;
		p.acc.x = p.acc.x + diff.x * scale * pct;
        p.acc.y = p.acc.y + diff.y * scale * pct;
		p.acc.z = p.acc.z + diff.z * scale * pct;
    }
	
}


void Agent::bounceOffWalls() {
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}


void Agent::setInitialCondition(ofxVec3f ps, ofxVec3f vs) {
    pos.set(ps.x,ps.y,ps.z);
	vel.set(vs.x,vs.y,vs.z);
}

void Agent::addDampingForce() {
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    acc.x = acc.x - vel.x * damping;
    acc.y = acc.y - vel.y * damping;
	acc.z = acc.z - vel.z * damping;
}

bool Agent::checkCollision(int _x, int _y) {
	// this is just a rough check for the the quad of the shape
	// you can override it if you need something more specific
	bool tVal = false;
		// if it is in the button range then set the state (radio?)
		if (_x > pos.x && _x < pos.x + myWidth) {
			// we are in the right width
			float tTop = pos.y;
			float tBottom = pos.y + myHeight;
			//cout <<"tTop: "<<tTop<<" Tbottom: "<<tBottom<<endl;
			if ((_y > tTop) && (_y < tBottom)) {
				// we are in the right height
				cout <<"YOU CLICKED ON ME: "<<pos.x<<endl;
				tVal = true;
				//ofxVec3f tVec(ofRandom(0,5.5), ofRandom(0,5.5), 0);
				//addScale(4);	
			} 
		} 
	return tVal;
}


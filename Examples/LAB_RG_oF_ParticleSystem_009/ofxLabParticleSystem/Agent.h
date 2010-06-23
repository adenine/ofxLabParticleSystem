#ifndef _AGENT
#define _AGENT

/*
 *  Agent.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/5/08.
 *  Copyright 2008 Lab at Rockwell Group. All rights reserved.
 *
 */

#include "ofMain.h"
#include "ofxVectorMath.h"

class Agent {

public:
	ofxVec3f pos;
	ofxVec3f vel;
	ofxVec3f acc;
	ofxVec3f origPos;
	
	int elapsedTime; 
	int timeStarted;
	int timeToLive;
	int myID;
	
	float myWidth, myHeight, myDepth;
	float origWidth, origHeight, origDepth;
	float alpha;
	bool isVisible;
	float damping;
	
	Agent();
	bool isDead();
	
	// Behavior Functions
	virtual void draw();
	void addForce(ofxVec3f _force);
	void addScale(float _scale);
	virtual void update();
	void resetForce();
	void bounceOffWalls();
	void addRepulsionForce(ofxVec3f _rforce, float radius, float scale);
	void addAttractionForce(Agent & p, float radius, float scale);
	void setInitialCondition(ofxVec3f ps, ofxVec3f vs);
	void addDampingForce();
	bool checkCollision(int _x, int _y);
};

#endif
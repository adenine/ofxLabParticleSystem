/*
 *  ButtonAgent.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/25/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "ButtonAgent.h"

ButtonAgent::ButtonAgent() {

}

ButtonAgent::ButtonAgent(float _x, float _y, int _myID, bool _isVisible, char * _title) {
	origPos.x = _x;
	origPos.y = _y;
	pos.y = origPos.y;
	isVisible = _isVisible;
	title = _title;
	myID = _myID;
	myWidth = 70;
	myHeight = 30;
}

void ButtonAgent::update() {

}

void ButtonAgent::draw() {
	if (isVisible == true) {
		ofSetColor(100,100,100);
		int spaceBuffer = 25;
		pos.x = origPos.x + (myID * myWidth) + (myID * spaceBuffer);
		ofRect(pos.x, pos.y, myWidth, myHeight);
		ofSetColor(255,255,255);
		ofDrawBitmapString(title, pos.x+3, pos.y+myHeight/1.5);
	}
}

void ButtonAgent::up() {

}

void ButtonAgent::down() {

}


void ButtonAgent::over() {

}


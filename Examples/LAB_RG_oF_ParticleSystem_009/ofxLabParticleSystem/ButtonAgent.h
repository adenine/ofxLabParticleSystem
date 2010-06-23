#ifndef _BUTTONAGENT
#define _BUTTONAGENT

/*
 *  ButtonAgent.h
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/25/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

//#include "ofMain.h"
#include "Agent.h"

class ButtonAgent : public Agent {
public:
	char * title;
	ButtonAgent();
	ButtonAgent(float _x, float _y, int _myID, bool _isVisible, char * _title);
	void update();
	void draw();
	void up();
	void down();
	void over();
private:

};

#endif
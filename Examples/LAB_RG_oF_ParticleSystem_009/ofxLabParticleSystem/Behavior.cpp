/*
 *  Behavior.cpp
 *  openFrameworks
 *
 *  Created by Joshua Walton on 12/6/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "Behavior.h"

Behavior::Behavior() {
	
}

void Behavior::apply() {

}

/*-------------------------------------------------------*/

AddForce::AddForce(ofxVec3f _force) {
		force = _force;
}

void AddForce::apply(ofxVec3f * _acc) {
	//_acc.x = _acc.x + force.x;
    //_acc.y = _acc.y + force.y;
	//_acc.z = _acc.z + force.z;
	//return _acc;
}
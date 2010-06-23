#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);

	Emitter *tempEmitter;
	ofxVec3f *tVec = new ofxVec3f(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0);
	tempEmitter = new Emitter(false, 10000, *tVec);
	for (int i=0; i<500; i++) {
		SparkleParticle *tempParticle;
		ofxVec3f tPos(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0);
		tempParticle = new SparkleParticle(tPos, 1000);
		tempEmitter->addParticle(tempParticle);
	}
	tEmitters.push_back(tempEmitter);
	
}

//--------------------------------------------------------------
void testApp::update(){

	for (int j=0; j<tEmitters.size(); j++) {
		// put stuff in here to manipulate each particle
		for (int k=0; k < tEmitters[j]->agentContainer.size(); k++) {
			
		}
		
		tEmitters[j]->update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int j=0; j<tEmitters.size(); j++) {
		tEmitters[j]->draw();
	}
	 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


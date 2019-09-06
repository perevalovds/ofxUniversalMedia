#include "ofApp.h"
#include "ofxUniversalMediaVideo.h"
#include "ofxUniversalMediaVideoWMF.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//We set higher frame rate to see all frames of 30-fps video
	//because current approach not sync with our screen updates
	ofSetFrameRate(55);	
	
	video1 = new ofxUniversalMediaVideo();
	video2 = new ofxUniversalMediaVideoWMF();

	video1->load("video-ofxShadertoy.mp4");
	video2->load("video-ofxShadertoy.mp4");

	//video1->setLoop(true);
	//video2->setLoop(true);
	
	bool looped = true;
	video1->play(looped);
	video2->play(looped);

}

//--------------------------------------------------------------
void ofApp::update(){
	video1->update();
	video2->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	float w = ofGetWidth();
	float h = ofGetHeight();
	video1->draw(0, 0, w / 2, h / 2);
	video2->draw(w/2, 0, w / 2, h / 2);

	ofDrawBitmapStringHighlight("DirectShow player", 20, 20);
	ofDrawBitmapStringHighlight("WMF player", w/2 + 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

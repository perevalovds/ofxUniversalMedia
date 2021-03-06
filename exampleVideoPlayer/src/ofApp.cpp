#include "ofApp.h"
#include "ofxUniversalMediaVideo.h"
#include "ofxUniversalMediaVideoWMF.h"
#include "ofxUniversalMediaImage.h"
#include "ofxUniversalMediaImageTurboJpeg.h"
#include "ofxUniversalMediaVideoHap.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//We set higher frame rate to see all frames of 30-fps video
	//because current approach not sync with our screen updates
	ofSetFrameRate(55);	
	
	video[0] = new ofxUniversalMediaVideo();		//DirectShow using standard oF's ofVideoPlayer (in Windows)
	video[1] = new ofxUniversalMediaVideoWMF();		//WMF (only for Windows)
	//video[2] = new ofxUniversalMediaImage();		//Image sequence decoded using standard oF's ofTexture
	video[2] = new ofxUniversalMediaImageTurboJpeg();		//Image sequence decoded using TurboJpeg

	video[3] = new ofxUniversalMediaVideoHap();		//HAPQ player


	cout << "Load ofVideoPlayer video..." << endl;
	bool res = video[0]->load("video-ofxShadertoy.mp4");
	if (!res) cout << "Error!" << endl;

	cout << "Load WMF video..." << endl;
	res = video[1]->load("video-ofxShadertoy.mp4");
	if (!res) cout << "Error!" << endl;

	cout << "Loading image sequence..." << endl;
	res = video[2]->load_image_sequence("sequence_25_fps", 25, ofxUniversalMediaImage::Decode_None);
	if (!res) cout << "Error!" << endl;

	cout << "Loading HAPQ video..." << endl;
	res = video[3]->load("video_HAPQ.mov");		//NOTE: HAPQ uses shader for draw, so if you need to pass it via your own shader, at the first draw to FBO
	if (!res) cout << "Error!" << endl;
	cout << "... finished" << endl;


	bool looped = true;
	for (int i = 0; i < n; i++) {
		video[i]->play(looped);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < n; i++) {
		video[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	float w = ofGetWidth();
	float h = ofGetHeight();
	for (int i = 0; i < n; i++) {
		int x = w / 2 * (i % 2);
		int y = h / 2 * (i / 2);
		video[i]->draw(x, y, w / 2, h / 2);
	}

	ofDrawBitmapStringHighlight("DirectShow player", 20, 20);
	ofDrawBitmapStringHighlight("WMF player", w/2 + 20, 20);
	ofDrawBitmapStringHighlight("FreeImage sequence", 20, h/2 + 20);
	ofDrawBitmapStringHighlight("HAPQ video player", 20 + w / 2, h / 2 + 20);
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

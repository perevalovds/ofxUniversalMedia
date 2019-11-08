#pragma once

/*
ofxUniversalMediaSound - sound player using standard ofSoundPlayer class.

NOTE: your must call ofSoundUpdate() once, in ofApp::update or somethere!

*/

#include "ofMain.h"
#include "ofxUniversalMedia.h"


struct ofxUniversalMediaSound: public ofxUniversalMedia {
	virtual bool has_image() { return false; }
	virtual bool has_sound() { return true; }

	virtual bool load(string file_name);
	virtual void close();

	virtual void update();
	virtual void set_volume(float v);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

	
protected:
	ofSoundPlayer sound;

	int playing_ = 0;

};


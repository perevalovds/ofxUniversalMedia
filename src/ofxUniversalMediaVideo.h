#pragma once

/*
ofxUniversalMediaVideo - video player using DirectShow in Windows and others 
- related to oF standard ofVideoPlayer class.

ofxUniversalMediaVideo class utilizes standard ofVideoPlayer class.
In Windows, it uses DirectShow method and loads all video to CPU, so loops work smoothly.
Also, it CPU-intensive. It supports MPG4 (after installing K-lite codecs pack).

Requirements: K-Lite codecs pack for playing MPG4 videos.

*/

#include "ofMain.h"
#include "ofxUniversalMedia.h"


struct ofxUniversalMediaVideo: public ofxUniversalMedia {
	virtual bool has_image() { return true; }
	virtual bool has_sound() { return true; }

	virtual bool load(string file_name);
	virtual void close();

	virtual void update();
	virtual void draw(float x, float y, float w, float h);
	virtual void set_volume(float v);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

	virtual int width() { return video.getWidth(); }
	virtual int height() { return video.getHeight(); }

protected:
	ofVideoPlayer video;

	int playing_ = 0;

};


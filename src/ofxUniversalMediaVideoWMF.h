#pragma once

/*
ofxUniversalMediaVideoWMF - video player using WFM (Windows).

ofxUniversalMediaVideoWMF class uses ofWMFVideoPlayer addon; it's based on Windows Media Foundation API,
so it gives fast and smooth playing because it's modern Windows method for playing videos using GPU, 
when available.

It's current oF impementation is not super perfect, and as a result, 
it's not very well syncing and not good for looping videos
(seems it skips the last frame and sometimes freeze and drop frames).
Also, currently it streams videos from disk, so may work slow when playing many videos simultaneously.
But, it works on GPU and fits well for situations when syncing is not so important.
It supports MP4.

Requirements: Windows OS and ofxWMFVideoPlayer addon.

*/

#include "ofMain.h"
#include "ofxUniversalMedia.h"
#include "ofxWMFVideoPlayer.h"


struct ofxUniversalMediaVideoWMF: public ofxUniversalMedia {
	
	virtual bool load(string file_name);


	virtual void close();

	virtual void update();
	virtual void draw(float x, float y, float w, float h);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

protected:
	ofxWMFVideoPlayer video;	

	int playing_ = 0;


};


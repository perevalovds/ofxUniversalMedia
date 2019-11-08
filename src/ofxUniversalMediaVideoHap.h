#pragma once

/*
*ofxUniversalMediaVideoHAP - video player using HAP (currently HAPQ) codec.

ofxUniversalMediaVideoHAP class uses ofxHapPlayer; it's allows to work with very big image sizes
and is super fast because uses HAP (currently HAPQ - see note) codec,
intended for GPU efficience video playing.
For using it you must to encode your videos to HAP (currently HAPQ) format.

HAP files are huge, so it's proposed to use them with SSD drives.

Requirements: ofxHapPlayer addon for HAP support (I tested it on my fork of the addon).

For encoding your videos to HAP/HAPQ, you can get HAP codec for Windows and Mac OS
at "hap-qt-codec" repo or in my fork of **ofxHapPlayer** addon.

NOTE: currently ofxUniversalMediaVideoHAP supports HAPQ codec (not HAP), because it gets better image quality.
Remember, that drawing HAPQ requires passing via ofxHapPlayer's shader, so
in the class it's enabled at each draw() automatically by default.
Hence, if you need to pass it via your own shader, at the first draw to FBO

*/

#include "ofMain.h"
#include "ofxUniversalMedia.h"
#include "ofxHapPlayer.h"


struct ofxUniversalMediaVideoHap: public ofxUniversalMedia {
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
	ofxHapPlayer video;

	int playing_ = 0;

};


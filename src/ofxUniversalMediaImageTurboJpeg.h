#pragma once

/*
ofxUniversalMediaImageTurgoJpeg - image and image sequence supporting JPEG images decoding with TurboJpeg.

ofxUniversalMediaImageTurgoJpeg class utilizes ofxTurboJpeg addon for reading and decoding JPEG images;
it's based on ofxTurboJpeg and decodes JPEGS very fast compared with ofxUniversalMediaImage,
so if you are using JPEG image sequences, in any case it's better choise that **ofxUniversalMediaImage**.
But JPEG doesn't support alpha-channel, so for sequences with alpha-channel you need to use **ofxUniversalMediaImage**.

It's appropriate for using as video player, but you must to encode your videos to JPEG image sequences, without audio.

Requirements: ofxTurboJpeg addon.

*/

#include "ofMain.h"
#include "ofxUniversalMediaImage.h"
#include "ofxTurboJpeg.h"


struct ofxUniversalMediaImageTurboJpeg: public ofxUniversalMediaImage {
	

protected:
	//We only need to reimplement image decoding from ofxUniversalMediaImage
	virtual bool load_texture(ofTexture &texture, const string &file_name);
	virtual bool load_texture(ofTexture &texture, const ofBuffer &buffer);
	virtual bool load_pixels(ofPixels &pixels, const string &file_name);

	ofxTurboJpeg turbo_;	//NOTE: each image sequence create TurboJpeg decompressor instance with DLL

	ofPixels pix_temp_;	//used for decoding	//TODO need to clear this memory if not used

};


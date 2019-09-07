#include "ofxUniversalMediaImageTurboJpeg.h"

//--------------------------------------------------------------
bool ofxUniversalMediaImageTurboJpeg::load_texture(ofTexture &texture, const string &file_name) {
	bool res = turbo_.load(pix_temp_, file_name);
	if (res) {
		texture.loadData(pix_temp_);

		//NOTE: can be allocated from previous... 
		//but we don't call texture.clear(), because want for faster works
		return texture.isAllocated();
	}
	return false;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImageTurboJpeg::load_texture(ofTexture &texture, const ofBuffer &buffer) {
	bool res = turbo_.load(pix_temp_, buffer);
	if (res) {
		texture.loadData(pix_temp_);

		//NOTE: can be allocated from previous... 
		//but we don't call texture.clear(), because want for faster works
		return texture.isAllocated();
	}
	return false;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImageTurboJpeg::load_pixels(ofPixels &pixels, const string &file_name) {
	return turbo_.load(pixels, file_name);
}

//--------------------------------------------------------------

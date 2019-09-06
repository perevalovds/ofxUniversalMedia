#include "ofxUniversalMediaImage.h"


//--------------------------------------------------------------
bool ofxUniversalMediaImage::load(string file_name) {
	bool res = ofLoadImage(texture, file_name);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки изображения " + file_name, ofColor(255, 0, 0));
	}
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::close() {
	if (loaded) {
		texture.clear();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::update() {

}

//--------------------------------------------------------------
void ofxUniversalMediaImage::draw(float x, float y, float w, float h) {
	if (loaded) {
		texture.draw(x, y, w, h);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::play(bool looped) {

}

//--------------------------------------------------------------
void ofxUniversalMediaImage::stop() {

}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::finished() {
	return false;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::load_image_sequence(string folder_name, float frame_rate, int decode_method) {
	//decode_method = Decode_None, Decode_To_CPU, Decode_To_GPU

	return true;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::set_manual_mode(bool manual) {
	return true;
}

//--------------------------------------------------------------

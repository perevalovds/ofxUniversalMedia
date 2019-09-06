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
void ofxUniversalMediaImage::update(float dt) {

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

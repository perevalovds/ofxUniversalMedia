#include "ofxUniversalMediaVideoHap.h"


//--------------------------------------------------------------
bool ofxUniversalMediaVideoHap::load(string file_name) {
	bool res = video.load(file_name);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки видео " + file_name, ofColor(255, 0, 0));
	}
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoHap::close() {
	if (loaded) {
		video.close();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoHap::update() {
	if (loaded && playing_) {
		video.update();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoHap::draw(float x, float y, float w, float h) {
	if (loaded) {
		//enabling shader for HAPQ playing
		ofShader *shader = video.getShader();
		if (shader) {
			shader->begin();
		}
		video.draw(x, y, w, h);
		if (shader) {
			shader->end();
		}
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoHap::play(bool looped) {
	if (loaded) {
		//Запускаем, если только сейчас не играет
		if (!playing_) {
			playing_ = 1;
			video.setPosition(0);
			video.play();
		}
		//А состояние петли меняем в любом случае, даже если уже воспроизводится
		if (looped) video.setLoopState(OF_LOOP_NORMAL);
		else video.setLoopState(OF_LOOP_NONE);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoHap::stop() {
	if (loaded && playing_) {
		playing_ = 0;
		video.stop();
		//MLOG("Stop video", ofColor(0, 0, 255));
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaVideoHap::finished() {
	if (loaded && playing_) {
		return video.getIsMovieDone();
	}
	return true;
}

//--------------------------------------------------------------

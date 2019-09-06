#include "ofxUniversalMediaVideoWMF.h"

//--------------------------------------------------------------
bool ofxUniversalMediaVideoWMF::load(string file_name) {
	if (!video._player) {
		//MLOG("Ошибка, WFM-плеер не создан, используйте режим DSHOW", ofColor(255,0,0));
		return false;
	}
	bool res = video.loadMovie(file_name);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки видео " + file_name, ofColor(255, 0, 0));
	}
	return res;
}


//--------------------------------------------------------------
void ofxUniversalMediaVideoWMF::close() {
	if (loaded) {
		video.close();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoWMF::update() {
	if (loaded && playing_) {
		video.update();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoWMF::draw(float x, float y, float w, float h) {
	if (loaded) {
		video.draw(x, y, w, h);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoWMF::play(bool looped) {
	if (loaded) {
		//Состояние петли меняем в любом случае, даже если уже воспроизводится
		if (looped) video.setLoop(true);
		else video.setLoop(false);
		//Запускаем, если только сейчас не играет
		if (!playing_) {
			playing_ = 1;
			//video.setPosition_sec(0);
			video.play();
		}
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideoWMF::stop() {
	if (loaded && playing_) {
		playing_ = 0;
		video.stop();
		//MLOG("Stop video", ofColor(0, 0, 255));
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaVideoWMF::finished() {
	if (loaded && playing_) {
		return video.isPaused() || video.isStopped();
	}
	return true;
}

//--------------------------------------------------------------

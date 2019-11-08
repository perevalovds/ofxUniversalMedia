#include "ofxUniversalMediaSound.h"


//--------------------------------------------------------------
bool ofxUniversalMediaSound::load(string file_name) {
	bool res = sound.load(file_name);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки звука " + file_name, ofColor(255, 0, 0));
	}
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaSound::close() {
	if (loaded) {
		sound.unload();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaSound::update() {
	if (loaded && playing_) {
	//NOTE: your must call ofSoundUpdate() once, in ofApp::update or somethere!
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaSound::set_volume(float v) {
	if (loaded) {
		sound.setVolume(v);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaSound::play(bool looped) {
	if (loaded) {
		//Запускаем, если только сейчас не играет
		if (!playing_) {
			playing_ = 1;
			sound.setLoop(looped);
			sound.play();
		}
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaSound::stop() {
	if (loaded && playing_) {
		playing_ = 0;
		sound.stop();
		//MLOG("Stop video", ofColor(0, 0, 255));
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaSound::finished() {
	if (loaded && playing_) {
		return !sound.getIsPlaying();
	}
	return true;
}

//--------------------------------------------------------------

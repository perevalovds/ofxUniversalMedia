#include "ofxUniversalMediaVideo.h"


//--------------------------------------------------------------
bool ofxUniversalMediaVideo::load(string file_name) {
	return load(file_name, true);
}

//--------------------------------------------------------------
bool ofxUniversalMediaVideo::load(string file_name, bool preload) {
	preload_ = preload;
	file_name_ = file_name;
	loaded = false;
	if (preload_) {
		return load_internal();
	}
	else {
		return true;
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaVideo::load_internal() {
	//cout << "loading  " << file_name_ << endl;

	bool res = video.load(file_name_);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки видео " + file_name, ofColor(255, 0, 0));
	}
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::close() {
	if (loaded) {
		video.close();
		loaded = 0;
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::update() {
	if (loaded && playing_) {
		video.update();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::draw(float x, float y, float w, float h) {
	if (loaded) {
		video.draw(x, y, w, h);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::set_volume(float v) {
	if (loaded) {
		video.setVolume(v);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::play(bool looped) {
	if (!preload_) {
		load_internal();
	}

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
void ofxUniversalMediaVideo::stop() {
	if (loaded && playing_) {
		playing_ = 0;
		video.stop();
		//MLOG("Stop video", ofColor(0, 0, 255));

		if (!preload_) {
			close();
		}
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaVideo::finished() {
	if (loaded && playing_) {
		return video.getIsMovieDone();
	}
	return true;
}

//--------------------------------------------------------------

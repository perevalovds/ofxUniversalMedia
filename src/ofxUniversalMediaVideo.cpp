#include "ofxUniversalMediaVideo.h"


//--------------------------------------------------------------
bool ofxUniversalMediaVideo::load(string file_name) {
	bool res = video.load(file_name);
	loaded = res;
	if (!res) {
		//MLOG("������ �������� ����� " + file_name, ofColor(255, 0, 0));
	}
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::close() {
	if (loaded) {
		video.close();
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaVideo::update(float dt) {
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
void ofxUniversalMediaVideo::play(bool looped) {
	if (loaded) {
		//���������, ���� ������ ������ �� ������
		if (!playing_) {
			playing_ = 1;
			video.setPosition(0);
			video.play();
		}
		//� ��������� ����� ������ � ����� ������, ���� ���� ��� ���������������
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

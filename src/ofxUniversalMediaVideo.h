#pragma once

//Медиа - видео, DirectShow
//По сравнению с WMF, использует больше CPU, чем GPU, но работает "на любых" видеокартах

#include "ofMain.h"
#include "ofxUniversalMedia.h"


//Абстрактный класс
struct ofxUniversalMediaVideo: public ofxUniversalMedia {
	virtual bool load(string file_name);
	virtual void close();

	virtual void update();
	virtual void draw(float x, float y, float w, float h);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

protected:
	ofVideoPlayer video;

	int playing_ = 0;

};


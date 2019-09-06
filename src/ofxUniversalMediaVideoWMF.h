#pragma once

//Медиа - видео, WMF
//Работает на GPU, когда это возможно, наиболее быстрый

#include "ofMain.h"
#include "ofxUniversalMedia.h"
#include "ofxWMFVideoPlayer.h"


//Абстрактный класс
struct ofxUniversalMediaVideoWMF: public ofxUniversalMedia {
	
	virtual bool load(string file_name);


	virtual void close();

	virtual void update(float dt);
	virtual void draw(float x, float y, float w, float h);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

protected:
	ofxWMFVideoPlayer video;	

	int playing_ = 0;


};


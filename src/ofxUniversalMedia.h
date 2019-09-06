#pragma once

//Абстрактный медиа - изображение или видео

#include "ofMain.h"

static const int ofxUniversalMedia_Type_Empty = 0;
static const int ofxUniversalMedia_Type_Image = 1;
static const int ofxUniversalMedia_Type_Video = 2;


//Абстрактный класс
struct ofxUniversalMedia {
	ofxUniversalMedia() {}
	virtual bool load(string file_name) { return true; }
	virtual void close() {}

	virtual void update() {}
	virtual void draw(float x, float y, float w, float h) {}

	virtual void play(bool looped) {}
	virtual void stop() {}
	virtual bool finished() { return true; }

	bool is_loaded() { return loaded; }

protected:
	//Тип контента
	int type = ofxUniversalMedia_Type_Empty;

	int loaded = 0;
};


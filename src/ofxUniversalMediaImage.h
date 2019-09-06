#pragma once

//Медиа - изображение 

#include "ofMain.h"
#include "ofxUniversalMedia.h"


//Абстрактный класс
struct ofxUniversalMediaImage: public ofxUniversalMedia {
	virtual bool load(string file_name);
	virtual void close();

	virtual void update();
	virtual void draw(float x, float y, float w, float h);

	virtual void play(bool looped);
	virtual void stop();
	virtual bool finished();

protected:
	ofTexture texture;

};


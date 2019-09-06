#pragma once

//Медиа - изображение 

#include "ofMain.h"
#include "ofxUniversalMedia.h"


//Абстрактный класс
struct ofxUniversalMediaImage: public ofxUniversalMedia {
	virtual bool load(string file_name);	//load one image

	virtual void close();

	virtual void update();
	virtual void draw(float x, float y, float w, float h);

	virtual void play(bool looped);	  //if not 
	virtual void stop();
	virtual bool finished();

	//------------------------------------------------------------
	//Related to image sequences
	virtual bool load_image_sequence(string folder_name, float frame_rate, int decode_method);
	//decode_method = Decode_None, Decode_To_CPU, Decode_To_GPU

	//manual mode moves to the next frame on each update call
	//it returns false if not implemented

	//Most useful for image sequences to have full control on it
	virtual bool set_manual_mode(bool manual);

protected:
	ofTexture texture;

};


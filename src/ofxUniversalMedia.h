#pragma once

//Abstract media class

#include "ofMain.h"

static const int ofxUniversalMedia_Type_Empty = 0;
static const int ofxUniversalMedia_Type_Image = 1;
static const int ofxUniversalMedia_Type_Video = 2;


struct ofxUniversalMedia {
	ofxUniversalMedia() {}
	virtual bool load(string file_name) { return false; }

	virtual void close() {}

	virtual void update() {}
	virtual void draw(float x, float y, float w, float h) {}

	virtual void play(bool looped) {}
	virtual void stop() {}
	virtual bool finished() { return true; }

	bool is_loaded() { return loaded; }

	//------------------------------------------------------------
	//Related to image sequences

	//Methods for storing images
	static const int Decode_None = 0;	//No decode, just load image files
	static const int Decode_To_CPU = 1;	//Decode to CPU images
	static const int Decode_To_GPU = 2;	//Decode to GPU textures

	virtual bool load_image_sequence(string folder_name, double frame_rate, int decode_method) { return false; }
	//manual mode moves to the next frame on each update call
	//it returns false if not implemented

	//Most useful for image sequences to have full control on it
	virtual bool set_manual_mode(bool manual) { return false; }


protected:
	//Тип контента
	int type = ofxUniversalMedia_Type_Empty;

	int loaded = 0;
};


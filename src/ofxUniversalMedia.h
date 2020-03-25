#pragma once

//Abstract media class

#include "ofMain.h"


struct ofxUniversalMedia {
	ofxUniversalMedia() {}

	//Properties of the media
	virtual bool has_image() { return false; }
	virtual bool has_sound() { return false; }

	//Loading
	virtual bool load(string file_name) { return false; }
	//optional with preloading option:
	virtual bool load(string file_name, bool preload) { return false; }
	virtual void close() {}

	virtual void update() {}
	virtual void draw(float x, float y, float w, float h) {}

	virtual void play(bool looped) {}
	virtual void stop() {}
	virtual bool finished() { return true; }

	bool is_loaded() { return loaded; }
	
	//Getters //NOTE: currently not implemented
	//Related to image
	virtual ofTexture *get_texture() { return NULL; }
	virtual int width() { return 0; }
	virtual int height() { return 0; }

	//Related to sound
	virtual void set_volume(float v) {}


	//------------------------------------------------------------
	//Related to image sequences

	//Methods for storing images
	static const int Decode_None = 0;	//No decode, just load image files
	static const int Decode_To_CPU = 1;	//Decode to CPU images
	static const int Decode_To_GPU = 2;	//Decode to GPU textures

	virtual bool load_image_sequence(string folder_name, double frame_rate, int decode_method) { return false; }
	//manual mode moves to the next frame on each update call
	//it returns false if not implemented

	//set frame rate (currently implemented for image sequances only)
	virtual bool set_frame_rate(float fr_rate) { return false; }


	//Most useful for image sequences to have full control on it
	virtual bool set_manual_mode(bool manual) { return false; }


protected:

	int loaded = 0;
};


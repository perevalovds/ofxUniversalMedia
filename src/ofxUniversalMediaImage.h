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
	virtual bool load_image_sequence(string folder_name, double frame_rate, int decode_method);
	//decode_method = Decode_None, Decode_To_CPU, Decode_To_GPU

	//manual mode moves to the next frame on each update call
	//it returns false if not implemented

	//Most useful for image sequences to have full control on it
	virtual bool set_manual_mode(bool manual);

protected:
	ofTexture texture;


	virtual bool load_sequence(const vector<string> &files, double frame_rate, int decode_method);

	int n_ = 0;

	bool sequence_ = false;
	int decode_ = Decode_None;
	vector<ofBuffer> buff_;	//non-decoded
	vector<ofPixels> pix_;  //CPU decode
	vector<ofTexture> tex_; //GPU decode

	int manual_ = 0;		//manual mode
	int looped_ = 0;
	double frame_rate_ = 30;

	int playing_ = 0;
	float play_time_ = 0;
	int frame_ = -1;			//play frame number

	bool load_frame(int i);
};


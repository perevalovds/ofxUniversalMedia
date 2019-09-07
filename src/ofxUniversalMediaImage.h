#pragma once

/*ofxUniversalMediaImage - image and image sequence supporting any image formats, 
decoding with oF standard method using FreeImage.

ofxUniversalMediaImage class works with images using ofTexture class; it's based on FreeImage for reading and decoding images on CPU.
It's universal. You can store decoded images in GPU, but it consumes much of memory.
You can store encoded images in CPU, but it not super - fast decoded.
Note, **ofxUniversalMediaImageTurgoJpeg** is faster when working with JPEGs, so use it if you work with JPEGs.
But JPEG doesn't support alpha-channel, so for sequences with alpha-channel you need to use **ofxUniversalMediaImage**.

It loads the whole sequence to memory, depending on three options:
* non-decoded file (most memory optimized),
* decoded to CPU images - ofPixels (CPU memory consuming, but not reuired decoding),
* decoded to GPU images - ofTexture (GPU memory consuming, but fastest).

It's appropriate for using as video player, but you must to encode your videos to image sequences, without audio.
*/


#include "ofMain.h"
#include "ofxUniversalMedia.h"



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

	//All decoding is here, it's way to implement TurboJpeg decoding by inheritance
	virtual bool load_texture(ofTexture &texture, const string &file_name);
	virtual bool load_texture(ofTexture &texture, const ofBuffer &buffer);
	virtual bool load_pixels(ofPixels &pixels, const string &file_name);
};


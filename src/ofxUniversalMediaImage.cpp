#include "ofxUniversalMediaImage.h"


//--------------------------------------------------------------
bool ofxUniversalMediaImage::load(string file_name) {
	bool res = ofLoadImage(texture, file_name);
	loaded = res;
	if (!res) {
		//MLOG("Ошибка загрузки изображения " + file_name, ofColor(255, 0, 0));
	}
	sequence_ = false;
	return res;
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::close() {
	if (loaded) {
		texture.clear();

		n_ = 0;
		buff_.clear();
		pix_.clear();
		tex_.clear();

		playing_ = 0;
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::update() {
	if (loaded) {
		if (sequence_) {
			if (playing_) {
				int index;
				if (manual_) {	//in manual mode we just increase frame each update call
					index = frame_+1;
				}
				else {
					float time = ofGetElapsedTimef();
					index = int((double(time) - double(play_time_)) * frame_rate_);	//TODO may be inaccuracies for long times
				}
				if (looped_) {
					index %= n_;
				}
				else {
					index = min(index, n_);	//not n_-1 - to understand play end
				}
				load_frame(index);
			}
		}
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::load_frame(int i) {
	if (loaded) {
		if (i != frame_) {
			frame_ = i;		//we set even errorneous frame - frame_ >= n is required to understand play end
			if (i >= 0 && i < n_) {
				if (decode_ == Decode_None) {
					//return ofLoadImage(texture, buff_[frame_]);
					return load_texture(texture, buff_[frame_]);
				}
				if (decode_ == Decode_To_CPU) {
					texture.loadData(pix_[frame_]);
					//NOTE: can be allocated from previous... 
					//but we don't call texture.clear(), because want for faster works
					return texture.isAllocated();
				}
				if (decode_ == Decode_To_GPU) {
					//nothing to do, we will draw read texture tex_[]
					return true;
				}
			}
		}
	}
	return false;
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::draw(float x, float y, float w, float h) {
	if (loaded) {
		ofTexture *tex = &texture;

		//in sequence if all decoded to GPU - draw it 
		if (sequence_ && decode_ == Decode_To_GPU) {
			tex = &tex_[frame_];
		}

		tex->draw(x, y, w, h);
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::play(bool looped) {
	if (loaded) {
		if (sequence_) {
			looped_ = looped;
			playing_ = 1;
			play_time_ = ofGetElapsedTimef();
			
			frame_ = -1;
			load_frame(0);
		}
	}
}

//--------------------------------------------------------------
void ofxUniversalMediaImage::stop() {
	if (loaded) {
		if (sequence_) {
			playing_ = 0;
		}
	}
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::finished() {
	if (loaded) {
		if (sequence_) {
			if (playing_) {
				if (!looped_) return (frame_ >= n_);
			}
			else {
				return true;
			}
		}
	}
	return false;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::load_image_sequence(string folder_name, double frame_rate, int decode_method) {
	//decode_method = Decode_None, Decode_To_CPU, Decode_To_GPU
	ofDirectory dir;
	int n = dir.listDir(folder_name);
	vector<string> files(n);
	for (int i = 0; i < n; i++) {
		files[i] = dir.getPath(i);
	}
	return load_sequence(files, frame_rate, decode_method);
}


//--------------------------------------------------------------
//All decoding is here, it's way to implement TurboJpeg decoding by inheritance
bool ofxUniversalMediaImage::load_texture(ofTexture &texture, const string &file_name) {
	return ofLoadImage(texture, file_name);
}

bool ofxUniversalMediaImage::load_texture(ofTexture &texture, const ofBuffer &buffer) {
	return ofLoadImage(texture, buffer);
}

bool ofxUniversalMediaImage::load_pixels(ofPixels &pixels, const string &file_name) {
	return ofLoadImage(pixels, file_name);
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::load_sequence(const vector<string> &files, double frame_rate, int decode_method) {
	//decode_method = Decode_None, Decode_To_CPU, Decode_To_GPU

	if (frame_rate <= 0) return false;

	frame_rate_ = frame_rate;

	n_ = files.size();
	loaded = n_ > 0;
	decode_ = decode_method;
	sequence_ = true;

	if (decode_ == Decode_None) {
		buff_.resize(n_);
		bool binary = true;
		for (int i = 0; i < n_; i++) {
			buff_[i] = ofBufferFromFile(files[i], binary); //TODO check success
		}
	}
	if (decode_ == Decode_To_CPU) {
		pix_.resize(n_);
		for (int i = 0; i < n_; i++) {
			load_pixels(pix_[i], files[i]);	//TODO check success
		}
	}
	if (decode_ == Decode_To_GPU) {
		tex_.resize(n_);
		for (int i = 0; i < n_; i++) {
			load_texture(tex_[i], files[i]);	//TODO check success
		}
	}

	frame_ = -1;

	return loaded;
}

//--------------------------------------------------------------
bool ofxUniversalMediaImage::set_manual_mode(bool manual) {
	manual_ = manual;
	
	//return true because we support this mode
	return true;
}

//--------------------------------------------------------------

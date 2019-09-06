#pragma once

#include "ofMain.h"
#include "ofxUniversalMedia.h"

class ofApp : public ofBaseApp{

	public:

		//WMF player's constructor must work after oF app is started, 
		//because player requires initialized OpenGL to work.
		//So, don't declare player object "ofxUniversalMediaVideoWMF video;" 
		//as a global variable.
		//Instead, declare it as a member of ofApp class (or it's member), 
		//or define it as a pointer and use "video = new ofxWMFVideoPlayer()".

		ofxUniversalMedia *video1 = 0;	//Will be DirectShow (in Windows)
		ofxUniversalMedia *video2 = 0;  //Will be WMF (Windows only)

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};

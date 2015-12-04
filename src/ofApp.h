#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        ofVec2f getBezierInterpolate(float p, ofVec2f begin, ofVec2f control, ofVec2f end);
        ofVec3f getBezierInterpolate(float p, ofVec3f begin, ofVec3f control, ofVec3f end);
    
        // 3D
        ofEasyCam easyCam;
        
        // bezie setting
        ofPath path;
        ofPath line;
    
        // GUI
        ofxVec3Slider begin;
        ofxVec3Slider end;
        ofxVec3Slider control;
    
        ofxFloatSlider p;
    
        ofxPanel gui;
    
    
    
    
};

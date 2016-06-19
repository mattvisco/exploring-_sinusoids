#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    private:
        bool animate = false;
        vector<ofPolyline> polylines;
        ofPolyline trackingLine;
        float t = 7.85;
    float noise_t = 0.0;
        ofPoint origin;
        int AMPLITUDE = 200;
        bool dec = false;
        ofPoint trackPoint; // Set off screen so it doesn't show up if tracking not on Ñ hacky, change once classes are implemented
        int POINTTOTRACK =10;
        ofTrueTypeFont time;
        ofPolyline circleOscillatingXY(ofPoint origin, float inc, bool tracking=false);
        ofPolyline circleOscillatingXYPhased(ofPoint origin, float inc);
    
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
		
};

#pragma once

#include "ofMain.h"
#include "CircleSine.h"

class ofApp : public ofBaseApp{

private:
    vector<CircleSine> circleLines;
    ofPolyline trackingLine;
    ofPoint trackPoint; // Set off screen so it doesn't show up if tracking not on Ñ hacky, change once classes are implemented
    int POINTTOTRACK =10;


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

#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    // Line 1
    CircleSine line1;
    line1.setup();
    line1.setPosition(250,300);
    line1.setFrequency(2, 3);
    line1.setPower(10, 5);
    circleLines.push_back(line1);
    
    // Line 2
    CircleSine line2;
    line2.setup();
    line2.setPosition(650,300);
    line2.setRange(0, TWO_PI);
    line2.setSinusoids(sin, cos);
    line2.setFrequency(70, 20);
    circleLines.push_back(line2);
    
    // Line 3
    CircleSine line3;
    line3.setup();
    line3.setPosition(1050,300);
    line3.setResolution(0.001);
    line3.setRange(0, TWO_PI);
    line3.setSinusoids(sin, cos);
    line3.setFrequency(20, 20);
    circleLines.push_back(line3);
    
}
//--------------------------------------------------------------
void ofApp::update(){
    for(auto& line : circleLines) {
        line.update();
    }
}



//--------------------------------------------------------------
void ofApp::draw(){
    for(auto& line : circleLines) {
        line.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // TODO: refine pause and step back — take parameters instead of hardcode
    if(key == 32) {
        for(auto& line : circleLines) {
            line.toggleAnimation();
        }
    }
    if(key == 112) {
        for(auto& line : circleLines) {
            line.toggleLineMode();
        }
    }
    // Add this into the individuals
    else if(key == 356) {
        for(auto& line : circleLines) {
            line.stepBack();
        }
    }
    else if(key == 358) {
        for(auto& line : circleLines) {
            line.stepForward();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // TODO: something triggers trackPoint finding to happen — then run code below
    // TODO: make a new point class that stores the circle objects — find the closest circle object and then call getClosest point (this code below)
    // TODO: circle objects will need a new point class where point store their "count" value — this allows to actually track point
//    ofPoint mouse(x,y);
//    float minDist = 1;
//    float currDist;
//    for(auto& line : polylines) {
//        for(auto& point : line.getVertices()) {
//            currDist = point.distance(mouse);
//            if(currDist < minDist) {
//                minDist = currDist;
//                trackPoint = point;
//            }
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

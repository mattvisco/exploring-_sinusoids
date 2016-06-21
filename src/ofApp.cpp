#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    // Line 1
    CircleSine line1;
    line1.setup();
    line1.setPosition(250,300);
    line1.setFrequency(1, 1);
    line1.setPower(1, 1);
    line1.setXAnimate(false);
    line1.setSinusoids(cos, cos);
    line1.setTrackDot(20);
    circleLines.push_back(line1);
    
    // Line 2
    CircleSine line2;
    line2.setup();
    line2.setPosition(650,300);
    line2.setRange(0, TWO_PI);
    line2.setSinusoids(sin, cos);
    line2.setFrequency(70, 20);
    line2.setTrackDot(100);
    circleLines.push_back(line2);
    
    // Line 3
    CircleSine line3;
    line3.setup();
    line3.setPosition(1050,300);
    line3.setResolution(0.001);
    line3.setRange(0, TWO_PI);
    line3.setSinusoids(sin, sin);
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
    
    if(key == 32) { // space bar
        for(auto& line : circleLines) {
            line.toggleAnimation();
        }
    }
    
    if(key == 112) { // p
        for(auto& line : circleLines) {
            line.toggleLineMode();
        }
    }
    
    if(key == 356) { // Left arrow key
        for(auto& line : circleLines) {
            line.stepBack();
        }
    }
    
    if(key == 358) { // Right arrow key
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

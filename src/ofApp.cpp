#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofTrueTypeFont::setGlobalDpi(72);
    time.load("IQFONT.otf", 32, true, true);}
//--------------------------------------------------------------
void ofApp::update(){
    for(auto& line : polylines) {
        line.clear();
    }
    
    polylines.push_back(circleOscillatingXYPhased(ofPoint(250,300), 0.01));
    polylines.push_back(circleOscillatingXY(ofPoint(650,300), 0.01));
    polylines.push_back(circleOscillatingXY(ofPoint(1050,300), 0.001));
    
    /* Time Ranges I Like:
        31.26 -> 31.56
        7.85 -> 7.87
        12.54 -> 12.59
     */
    // If you want to animate within a specified range change min & max time to range desired
    // If you want to move slower or faster through range change incBy
//    float minTime = 7.85;
//    float minTime = 7.87;
//    float incBy = 0.00005;
//    if(animate) {
//        if(dec){
//            if(t<=minTime) {
//                dec = false;
//                t+=incBy;
//            } else t-=incBy;
//        } else {
//            if(t>minTime) {
//                t-=incBy;
//                dec = true;
//            } else t+=incBy;
//        }
//    }
    if(animate) {
        t+=0.01; // If animating time range comment this out
        noise_t+=0.001;
    }
    
//    else t = 0.0;
}

ofPolyline ofApp::circleOscillatingXY(ofPoint origin, float inc, bool tracking) {
    ofPolyline line;
    int count = 0;
    for(float i = 0; i <= TWO_PI; i+=inc) {
        ofPoint vertex(cos(i) * AMPLITUDE ,sin(i) * AMPLITUDE );
        ofPoint sinAnimation(ofMap(sin((i*70)*t), -1, 1, -1, 1), ofMap(cos((i*20)*t), -1, 1, -1, 1)); // (20, 20) / (70,50)
//        if(animate)
        vertex *= sinAnimation; // add power function
        vertex += origin;
        
        // To add noise into animation uncomment below — you can add noise to x, y, or both — feel free to change the parameters of noise
//        float noise = ofNoise( (noise_t * ofMap(i, 0, TWO_PI, 0, 1)) * 5  );// / 100
//        float yDelt = ofMap(noise, 0,1, -50, 50);
//        vertex.y += yDelt;
//        vertex.x += yDelt;
        
        line.addVertex(vertex);
        if(count == POINTTOTRACK && tracking) {
            trackingLine.addVertex(vertex);
            trackPoint = vertex;
        }
        count++;
    }
    return line;
}

/* Setting I like:
        1. Cool Flower wave thang: (currently set)
            powf( ofMap(cos(i*t*2), -1, 1, 0, 1), 10 ), powf( ofMap(cos(i*t*3), -1, 1, 0, 1), 5 )
            time increments by 0.01
 */
// Currently applying to XY like about but the phase is shifted — starts from -PI instead of 0
// TODO: combine oscillating circle functions once put into a separate class — phase shift can be selected via parameter which will allow for code to be combine
ofPolyline ofApp::circleOscillatingXYPhased(ofPoint origin, float inc) {
    ofPolyline line;
    for(float i = -PI; i < PI; i+=inc) {
        ofPoint vertex(cos(i) * AMPLITUDE, sin(i) * AMPLITUDE);
        // Raising the sinusoidal animation factor by N power collapses points path — each additional power decreases the time b/w min & max ocillation
        ofPoint sinusoidAnimate( powf( ofMap(cos(i*t*2), -1, 1, 0, 1), 10 ), powf( ofMap(cos(i*t*3), -1, 1, 0, 1), 5 ) );
        vertex *= sinusoidAnimate;
        vertex += origin;
        line.addVertex(vertex);
    }
    return line;
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    string timeStr = "Current time:";
    time.drawString(timeStr, 30,30);
    time.drawString(to_string(t), 60,60);
    for(auto& line : polylines) {
        line.draw();
    }
    // Code belows tracks the path of a point
    // To change which point to track change POINTTOTRACK in ofApp.h
    // To change the circle that the tracking point is contained in pass true into circleOscillatingXY of the circle you desire
    // Note: currently only can track one point — if the POINTTOTRACK is to large for the circle being tracked you will not be tracking a point
    ofSetColor(0, 255, 0);
    trackingLine.draw();
    ofSetColor(255, 0, 0);
    ofDrawCircle(trackPoint, 5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // TODO: refine pause and step back — take parameters instead of hardcode
    if(key == 32) animate = !animate;
    else if(key == 356) t -= .01;
    else if(key == 358) t+= .01;}

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
    cout << t << endl;
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

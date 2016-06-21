//
//  CircleSine.cpp
//  playingWithSinusoids
//
//  Created by Matthew Visco on 6/20/16.
//
//

#include "CircleSine.h"

void CircleSine::setup() {
    ofTrueTypeFont::setGlobalDpi(72);
    time.load("IQFONT.otf", 32, true, true);
}

// Add in noise: noise_t+=0.001;
void CircleSine::update() {
    if(animate) {
        if(timeRangeOn) { // If working within a specific time range, oscillate between min & max
            if(decreasing){
                if(frame <= timeRange[1]) {
                    decreasing = false;
                    frame += frameRate;
                } else frame -= frameRate;
            } else {
                if(frame > timeRange[0]) {
                    frame -= frameRate;
                    decreasing = true;
                } else frame += frameRate;
            }
        } else {
            frame += frameRate;
        }
    }
    updateLine();
    timeStrPos[0] = origin.x - radius;
    timeStrPos[1] = origin.y - radius;
}

void CircleSine::updateLine() {
    line.clear();
    for(float i = range[0]; i < range[1]; i+=resolution) {
        ofPoint vertex(cos(i), sin(i));
        vertex *= radius;
        ofPoint sinusoidAnimate( powf( ofMap(sinusoids[0](i*frame*freq[0]), -1, 1, 0, 1), powers[0] ),
                                powf( ofMap(sinusoids[1](i*frame*freq[1]), -1, 1, 0, 1), powers[1] ) );
        vertex *= sinusoidAnimate;
        vertex += origin;
        
        // To add noise into animation uncomment below ‚Äî you can add noise to x, y, or both ‚Äî feel free to change the parameters of noise
        //        float noise = ofNoise( (noise_t * ofMap(i, 0, TWO_PI, 0, 1)) * 5  );// / 100
        //        float yDelt = ofMap(noise, 0,1, -50, 50);
        //        vertex.y += yDelt;
        //        vertex.x += yDelt;
        
        line.addVertex(vertex);
    }
}

void CircleSine::draw() {
    if(lineMode) line.draw();
    else drawPoints();
        time.drawString(TIMESTR, timeStrPos[0] - 30, timeStrPos[1] - 30);
        time.drawString(to_string(frame), timeStrPos[0], timeStrPos[1]);
}

void CircleSine::drawPoints() {
    for(auto& point : line.getVertices()) {
        ofDrawCircle(point, 2);
    }
}

void CircleSine::setPosition(ofPoint point) {
    origin = point;
}

void CircleSine::setPosition(float x, float y) {
    setPosition(ofPoint(x,y));
}

void CircleSine::setSinusoids(Sinusoids x, Sinusoids y) {
    sinusoids[0] = x;
    sinusoids[1] = y;
}

void CircleSine::setFrequency(int x, int y) {
    freq[0] = x;
    freq[1] = y;
}

void CircleSine::setRadius(float rad) {
    radius = rad;
}

void CircleSine::setRange(float start, float end) {
    range[0] = start;
    range[1] = end;
}

void CircleSine::setTimeRange(float start, float end) {
    timeRange[0] = start;
    timeRange[1] = end;
    timeRangeOn = true;
}

void CircleSine::turnOffRangeMode() {
    timeRangeOn = false;
}

void CircleSine::setResolution(float res) {
    resolution = res;
}

void CircleSine::setAnimationSpeed(float rate) {
    frameRate = rate;
}

void CircleSine::setPower(int x, int y) {
    powers[0] = x;
    powers[1] = y;
}

void CircleSine::setAnimate(bool animate) {
    CircleSine::animate = animate;
}

void CircleSine::toggleAnimation() {
    animate = !animate;
}

void CircleSine::stepBack(float t) {
    frame -= t;
}

void CircleSine::stepForward(float t) {
    frame += t;
}

void CircleSine::toggleLineMode() {
    lineMode = !lineMode;
}
//
//  CircleSine.h
//  playingWithSinusoids
//
//  Created by Matthew Visco on 6/20/16.
//
//

#ifndef CircleSine_h
#define CircleSine_h
#include "ofMain.h"

class CircleSine {

    typedef float (*Sinusoids) (float a);
    
private:
    // Contants
    string TIMESTR = "Current Time:";
    // Vars — defaults set
    ofPolyline line;
    bool lineMode = true;
    float range[2] = {-PI, PI};
    ofPoint origin;
    float radius = 200;
    float resolution = 0.01;
    float frameRate = 0.01;
    float frame = 0.0;
    float timeRange[2];
    bool timeRangeOn = false;
    float timeStrPos[2];
    bool decreasing = false;
    bool animXY[2] = {true, true};
    Sinusoids sinusoids[2] = {cos, cos};
    int freq[2] = {1,1};
    int powers[2] = {1,1};
    bool animate = false;
    ofTrueTypeFont time;
    // Tracking Vars
    bool tracking = false;
    int trackPointCount;
    ofPoint trackPoint;
    ofPolyline trackLine;
    
    
    // Methods
    void updateLine();
    void drawPoints();
    ofPoint getSinusoidalAnimation(float point);
    
    
public:
    void setup();
    void update();
    void draw();
    void setPosition(ofPoint point);
    void setPosition(float x, float y);
    ofPoint getPosition();
    void setRadius(float rad);
    void setRange(float start, float end);
    void setTimeRange(float start, float end);
    void turnOffRangeMode();
    void setResolution(float res);
    void setAnimationSpeed(float rate);
    void setSinusoids(Sinusoids x, Sinusoids y);
    void setFrequency(int x, int y);
    void setPower(int x=1, int y=1);
    void setXAnimate(bool animate);
    void setYAnimate(bool animate);
    void setAnimate(bool animate);
    void toggleAnimation();
    void stepBack(float t = 0.01);
    void stepForward(float t = 0.01);
    void toggleLineMode();
    void previewTrackDot(int x, int y);
    void setTrackDot(int pt);
    void setTracking(bool track);
    void toggleTracking();
};

#endif /* CircleSine_h */

//
//  soundMap.h
//  timelineTry2
//
//  Created by Caroline Record on 3/14/14.
//
//

#ifndef timelineTry2_soundMap_h
#define timelineTry2_soundMap_h
#include "ofMain.h"
#include "ofxTimeline.h"
#include "ofxSVG.h"
#include "ofxTLAudioTrack.h"
#include "ofxMidi.h"
#include "ofxClipper.h"


class soundMap{
  
    public:
        // methods
        void update(bool trackIsDetected);
        void draw(int x, int y);
        void keyPress  (int key);
        void exit();
        void playMidi(int channel, int note, int x, int y);
        //constuctor
        soundMap();
    
        int x;
        int y;
    
    float length;
    ofPoint staticPoint;
    ofxTimeline timeline;
    ofxClipper clipper;
    ofxMidiOut midiOut;
    
    private:
        vector<ofPolyline> temp;
        int room; 
        //ofxTimeline timeline;
        // to store the base floor plans
        ofxSVG svgPaths;
        vector<ofPolyline> rooms;
           ofSoundPlayer play;
    
    struct StaticFuzzObject{
        // this shape is contained by which room
        int roomNum = 9;
        // the center
        int posX;
        int posY;
        int width;
        float spreadFactor;
        // 0 to 100 say
        int HighestVolume=100;
        int count =0;
        string toAnimate = "nope";
        ofxXmlSettings xml;
        int clipToRoom =9;
        float muffleFactor;
        ofColor color;
        int duration;
        int timePast;
        bool goTime; 
    };
    
    
    ofxXmlSettings XML;
    void drawFuzzShape(StaticFuzzObject soundBlob);
    float getVolumeFromFuzzShape(int x, int y,  StaticFuzzObject Blob);
    void drawShortSound(StaticFuzzObject &blob, int note );
    void distanceFromShortSound(StaticFuzzObject &blob, int note, int channel, int x, int y );
    void animateFuzz(StaticFuzzObject &blob);
    int startTime;
    bool trackerIsDetected; 
    
    StaticFuzzObject convesation;
    StaticFuzzObject clock;
    StaticFuzzObject kitchenClock;
    StaticFuzzObject fridge;
    StaticFuzzObject showerDrip;
    StaticFuzzObject windowFront;
    StaticFuzzObject windowBack;
    StaticFuzzObject theRattle;
    StaticFuzzObject catPurring;
    StaticFuzzObject skinScratch;
    StaticFuzzObject writing;
    StaticFuzzObject crying;
    StaticFuzzObject showerTime;
    StaticFuzzObject tubDrip;
    StaticFuzzObject mixing;
    StaticFuzzObject rattle;
    StaticFuzzObject kettle;
    StaticFuzzObject appleChop;
    StaticFuzzObject brushTeeth;
    StaticFuzzObject mug1;
    StaticFuzzObject mug2;
    StaticFuzzObject waterPour;
    StaticFuzzObject eggCrack;
    StaticFuzzObject stove;
    
    StaticFuzzObject longCooking;
    StaticFuzzObject humming;
    StaticFuzzObject gwenRun;
    StaticFuzzObject overheardUpstairs;
    StaticFuzzObject dishes;
    StaticFuzzObject sleep; 
    //StaticFuzzObject
    
    
    
        //ofSoundPlayer mySound;
        //mySound.loadSound("beat.mp3");
    void receivedBang(ofxTLBangEventArgs& bang);
    
    
};


#endif

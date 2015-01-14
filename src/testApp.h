#pragma once

#include "ofMain.h"

#include "soundMap.h"
#include "ofxXmlSettings.h" 
#include "ofxOsc.h"
#define PORT 12345


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxXmlSettings xml;
    int lastTagNumber;
    int pointCount;
    int lineCount;
    string xmlStructure;
    int mapToMidi;
    ofxOscReceiver receiver;
    int positionX;
    int positionY;
    
    int millisPast;
    int lastTime; 
    bool isSwitch; 
    
    bool isDetected;
    private:
        soundMap *mySoundMap;
    
        
		
};

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofHideCursor();

    ofLog()<<"hi";
    receiver.setup(PORT);
    mySoundMap = new soundMap();
    lastTagNumber	= 0;
	pointCount		= 0;
	lineCount		= 0;
    mapToMidi =30;
    positionX =-200;
    positionY =-200;
    isDetected = true;
    isSwitch = true;
    lastTime = 0;
   // mySoundMap->setup();
}

//--------------------------------------------------------------
void testApp::update(){
    //ofLog()<<receiver.
    ofHideCursor();
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
		receiver.getNextMessage(&m);
        ofLog()<< "ping";
		// check for mouse moved message
		if(m.getAddress() == "/0/leftPos"){
			// both the arguments are int32's
            if(positionX !=-200 & positionY != -200){
			positionX = ofMap(m.getArgAsInt32(0), 0,1200, 0,600);
			positionY = ofMap(m.getArgAsInt32(1), 0,1600, 0,800);
            }
		}
        if(m.getAddress() == "/0/notDetected"){
            int num =300;
            num = m.getArgAsInt32(0);
            
            if (num >=10){
                if (isSwitch == true){
                    lastTime = ofGetSeconds();
                }
                else if (lastTime-ofGetSeconds() > 1){
                    isDetected =false;
                }
                isSwitch = false;
                
            }
            else if(num <=9){
                isSwitch = true;
                isDetected =true;
                
            }
        }
        
    }
   mySoundMap->update(isDetected);
    //ofHideCursor();
    //ofSetFullscreen(true);
}

//--------------------------------------------------------------
void testApp::draw(){
  mySoundMap->draw(mouseX,mouseY);
   // mySoundMap->draw(positionX,positionY);
    if(positionX ==-200 & positionY == -200){
    positionX=300;
    positionY= 400;
    }
    //ofLog()<< "mouseX; " << mouseX;
    //ofLog()<< "mouseY: " << mouseY;
   //ofLog()<<mapToMidi;
      //mySoundMap->playMidi(1, mapToMidi, mouseX, mouseY);
    //midiOut.sendControlChange(channel, note ,127);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
     mySoundMap->midiOut.sendNoteOn(1, 50,127);
    switch (key) {
        case 'q':
            mapToMidi -=1;
            break;
        case 'w':
            mapToMidi +=1;
            break;
        case 'e':
            mapToMidi -= 5;
            break;
        case 'r':
            mapToMidi +=5;
            break;
        case 't':
            mapToMidi +=10;
            break;
        case 'y':
            mapToMidi -=10;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
/*
    //xml record values
    if( xml.pushTag("STROKE", lastTagNumber) ){
        
		//now we will add a pt tag - with two
		//children - X and Y
        
		int tagNum = xml.addTag("PT");
		xml.setValue("PT:X", x, tagNum);
		xml.setValue("PT:Y", y, tagNum);
		xml.popTag();
	}
 */
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    /*
    xml.clear();
    // start recording xml values in timestamped Doc
    lastTagNumber	= xml.addTag("STROKE");
     */
    //isDetected = !isDetected;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    /*
    // save out values
   // xml.clear();
    string unique = ofGetTimestampString();
    xml.saveFile(unique + ".xml");
    */
    ofLog()<< "x: " << x;
    ofLog()<<"y: "<<y;
}


//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit(){
    mySoundMap->exit();
}
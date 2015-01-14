//
//  soundMap.cpp
//  timelineTry2
//
//  Created by Caroline Record on 3/14/14.
//
//
#include "soundMap.h"

soundMap::soundMap(){

    
    midiOut.listPorts();
    midiOut.openPort(0);
    
    //svgPaths.load("flrPlnDistortededitted5.svg");
    svgPaths.load("flrPlnDistortededitted5copy.svg");
    
    room =9;
    
    //    ofLog()<<room;
    if(room==2){
        // 37 tracks per channel
        // 592
        // we could have up to 74 audio files. 
        //midiOut.sendNoteOn(9, 1, 30);
        //midiOut.sendNoteOn(9, 1, 127);
        //midiOut.se
       //midiOut.sendControlChange(9,85,0);
       //midiOut.sendControlChange(8,85,127);
    }
    timeline.setup(); //registers events
    timeline.setDurationInSeconds(500); //sets time
    timeline.setLoopType(OF_LOOP_NORMAL); //turns the timeline to loop
    
    ofVec2f point;
    point.set( 0, 580 );
    timeline.setOffset(point);
    timeline.addFlags("temporalAudioMarkers");
    ofAddListener(timeline.events().bangFired, this, &soundMap::receivedBang);

    // turn everything off - so nothing is weird
    //midiOut.sendNoteOn(2, 50,50);
    
    
    ofLog()<< "nn";
    midiOut.sendNoteOn(1, 50,50);
    midiOut.sendNoteOn(1, 48,50);
    midiOut.sendNoteOn(1, 49,50);
    midiOut.sendNoteOn(1, 51,50);
    midiOut.sendNoteOn(1, 44,50);
    midiOut.sendNoteOn(1, 45,50);
    midiOut.sendNoteOn(1, 46,50);
    midiOut.sendNoteOn(1, 47,50);
    midiOut.sendNoteOn(1, 40,50);
    midiOut.sendNoteOn(1, 41,50);
    midiOut.sendNoteOn(1, 43,50);
    
    //midiOut.sendNoteOn(1,42,50);
    //midiOut.sendControlChange(1,22,2.5);
    
    // play sound depending on which room
    
    convesation.posX= 150;
    convesation.posY= 150;
    convesation.spreadFactor =  30;
    convesation.width = 10;
    convesation.HighestVolume = 100;
    convesation.toAnimate = "PathTest.xml";
    
    clock.posX = 481;
    clock.posY = 244;
    clock.spreadFactor = 20;
    clock.width = 40;
    clock.HighestVolume = 20;
    clock.clipToRoom = 1;
    clock.muffleFactor = .5;
    clock.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    
    showerDrip.posX = 525;
    showerDrip.posY = 105;
    showerDrip.spreadFactor = 18;
    showerDrip.width = 30;
    showerDrip.clipToRoom =2;
    showerDrip.muffleFactor =.4;
    showerDrip.HighestVolume = 30;
    showerDrip.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    
    kitchenClock.posX = 588;
    kitchenClock.posY = 212;
    kitchenClock.spreadFactor = 30;
    kitchenClock.width =40;
    kitchenClock.clipToRoom =3;
    kitchenClock.muffleFactor =.6;
    kitchenClock.HighestVolume = 50;
    kitchenClock.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));

    fridge.posX = 468;
    fridge.posY = 182;
    fridge.spreadFactor = 4;
    fridge.width =80;
    fridge.clipToRoom =3;
    fridge.muffleFactor =.8;
    fridge.HighestVolume = 40;
    fridge.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));

    windowBack.posX = 658;
    windowBack.posY = 553;
    windowBack.spreadFactor = 15;
    windowBack.width =5;
    windowBack.clipToRoom =3;
    windowBack.muffleFactor =.8;
    windowBack.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    
    windowFront.posX = 0;
    windowFront.posY = 389;
    windowFront.spreadFactor = 20;
    windowFront.width =40;
    windowFront.clipToRoom = 1;
    windowFront.muffleFactor = .5;
    windowFront.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    
    theRattle.posX = 136;
    theRattle.posY = 108;
    theRattle.spreadFactor= 3;
    theRattle.width = 20;
    theRattle.clipToRoom = 1;
    theRattle.muffleFactor =.4;
    theRattle.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    theRattle.duration = 22;
    theRattle.timePast = -1;
    theRattle.goTime = false;
    
    catPurring.posX = 163;
    catPurring.posY = 131;
    catPurring.spreadFactor= 7;
    catPurring.width = 30;
    catPurring.clipToRoom = 1;
    catPurring.muffleFactor =.4;
    catPurring.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    catPurring.duration = 13;
    catPurring.timePast = -1;
    catPurring.goTime = false;
    
    skinScratch.posX = 277;
    skinScratch.posY = 116;
    skinScratch.spreadFactor= 17;
    skinScratch.width = 40;
    skinScratch.clipToRoom = 1;
    skinScratch.muffleFactor =.4;
    skinScratch.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    skinScratch.duration = 24;
    skinScratch.HighestVolume =80;
    skinScratch.timePast = -1;
    skinScratch.goTime = false;
    
    writing.posX = 306;
    writing.posY = 497;
    writing.spreadFactor= 30;
    writing.width = 20;
    writing.clipToRoom = 1;
    writing.muffleFactor =.4;
    writing.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    writing.duration = 243;
    writing.timePast = -1;
    writing.goTime = false;
    
    crying.posX = 277;
    crying.posY = 116;
    crying.spreadFactor= 40;
    crying.width = 20;
    crying.clipToRoom = 1;
    crying.muffleFactor =.5;
    crying.HighestVolume = 60;
    crying.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    crying.duration = 22;
    crying.timePast = -1;
    crying.goTime = false;
    
    showerTime.posX = 712;
    showerTime.posY = 153;
    showerTime.spreadFactor= 70;
    showerTime.width = 20;
    showerTime.clipToRoom = 2;
    showerTime.muffleFactor =.4;
    showerTime.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    showerTime.duration = 733;
    showerTime.timePast = -1;
    showerTime.HighestVolume = 50;
    showerTime.goTime = false;
    
    tubDrip.posX = 712;
    tubDrip.posY = 153;
    tubDrip.spreadFactor= 13;
    tubDrip.width = 20;
    tubDrip.clipToRoom = 2;
    tubDrip.muffleFactor =.4;
    tubDrip.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    tubDrip.duration = 25;
    tubDrip.timePast = -1;
    tubDrip.goTime = false;
    
    mixing.posX = 630;
    mixing.posY = 502;
    mixing.spreadFactor= 35;
    mixing.width = 20;
    mixing.clipToRoom = 3;
    mixing.muffleFactor =.4;
    mixing.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    mixing.duration = 36;
    mixing.timePast = -1;
    mixing.goTime = false;
    
    stove.posX = 532;
    stove.posY = 285;
    stove.spreadFactor= 15;
    stove.width = 30;
    stove.clipToRoom = 3;
    stove.muffleFactor =.4;
    stove.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    stove.duration = 69;
    stove.timePast = -1;
    stove.goTime = false;
    
    eggCrack.posX = 620;
    eggCrack.posY = 489;
    eggCrack.spreadFactor= 30 ;
    eggCrack.width = 40;
    eggCrack.clipToRoom = 3;
    eggCrack.muffleFactor =.4;
    eggCrack.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    eggCrack.duration = 24;
    eggCrack.timePast = -1;
    eggCrack.goTime = false;
    
    appleChop.posX = 607;
    appleChop.posY = 493;
    appleChop.spreadFactor= 40;
    appleChop.width = 20;
    appleChop.clipToRoom = 3;
    appleChop.muffleFactor =.4;
    appleChop.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    appleChop.duration = 79;
    appleChop.timePast = -1;
    appleChop.goTime = false;
    
    //livingRoom mug
    mug1.posX = 247;
    mug1.posY = 492;
    mug1.spreadFactor= 10;
    mug1.width = 40;
    mug1.clipToRoom = 1;
    mug1.muffleFactor =.4;
    mug1.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    mug1.duration = 1;
    mug1.timePast = -1;
    mug1.goTime = false;
    
    //kitchen mug
    mug2.posX = 623;
    mug2.posY = 497;
    mug2.spreadFactor= 7;
    mug2.width = 20;
    mug2.clipToRoom = 3;
    mug2.muffleFactor =.4;
    mug2.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    mug2.duration = 7;
    mug2.timePast = -1;
    mug2.goTime = false;
    
    waterPour.posX =253;
    waterPour.posY = 510;
    waterPour.spreadFactor= 80;
    waterPour.width = 20;
    waterPour.clipToRoom = 1;
    waterPour.muffleFactor =.4;
    waterPour.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    waterPour.duration = 8;
    waterPour.timePast = -1;
    waterPour.goTime = false;
    
    
    kettle.posX = 553;
    kettle.posY = 301;
    kettle.spreadFactor= 30;
    kettle.width = 20;
    kettle.clipToRoom = 2;
    kettle.muffleFactor =.4;
    kettle.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    kettle.duration = 22;
    kettle.timePast = -1;
    kettle.goTime = false;
    
    brushTeeth.posX = 583;
    brushTeeth.posY = 105;
    brushTeeth.spreadFactor= 50;
    brushTeeth.width = 20;
    brushTeeth.clipToRoom = 2;
    brushTeeth.muffleFactor =.4;
    brushTeeth.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    brushTeeth.duration = 22;
    brushTeeth.timePast = -1;
    brushTeeth.goTime = false;
    
    longCooking.posX = 472;
    longCooking.posY = 275;
    longCooking.spreadFactor= 20;
    longCooking.width = 30;
    longCooking.clipToRoom = 3;
    longCooking.HighestVolume = 30;
    longCooking.muffleFactor =.65;
    longCooking.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    longCooking.duration = 537;
    longCooking.timePast = -1;
    longCooking.goTime = false;
    
    humming.posX = 270;
    humming.posY = 430;
    humming.spreadFactor= 70;
    humming.width = 50;
    humming.clipToRoom = 1;
    humming.muffleFactor =.7;
    humming.HighestVolume = 50;
    humming.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    humming.duration = 53;
    humming.timePast = -1;
    humming.goTime = false;
    
    gwenRun.posX = 235;
    gwenRun.posY = 285;
    gwenRun.spreadFactor= 50;
    gwenRun.width = 40;
    gwenRun.clipToRoom = 1;
    gwenRun.muffleFactor =.5;
    gwenRun.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    gwenRun.duration = 4;
    gwenRun.timePast = -1;
    gwenRun.goTime = false;
    
    overheardUpstairs.posX = 686;
    overheardUpstairs.posY = 431;
    overheardUpstairs.spreadFactor= 15;
    overheardUpstairs.width = 20;
    overheardUpstairs.clipToRoom = 3;
    overheardUpstairs.muffleFactor =.9;
    overheardUpstairs.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    overheardUpstairs.duration = 76;
    overheardUpstairs.timePast = -1;
    overheardUpstairs.goTime = false;
    
    dishes.posX = 530;
    dishes.posY = 376;
    dishes.spreadFactor= 30;
    dishes.width = 20;
    dishes.clipToRoom = 3;
    dishes.muffleFactor =.4;
    dishes.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    dishes.duration = 1352;
    dishes.timePast = -1;
    dishes.HighestVolume = 60;
    dishes.goTime = false;
    
    sleep.posX = 298;
    sleep.posY = 205;
    sleep.spreadFactor= 15;
    sleep.width = 20;
    sleep.clipToRoom = 1;
    sleep.muffleFactor =.4;
    sleep.color = ofColor((int)ofRandom(219,249),(int)ofRandom(187,217),(int)ofRandom(187,217));
    sleep.duration = 86;
    sleep.timePast = -1;
    sleep.goTime = false;
    
    int controlNums[28] = {22,23,24,25,26,27,28,29,105,106,107,108,90,102,103,104,86, 87,88,89,31,85,109,110,111,113,114,112};
    for(int i=0; i< 28; i++ ){
        midiOut.sendControlChange(1,controlNums[i],100);
        midiOut.sendControlChange(1,controlNums[i],127);
        midiOut.sendControlChange(1,controlNums[i],0);
        ofLog()<<"hry";
    }
    
    
 }

void getCircleCoords(ofVec2f centre, float radius, vector<ofVec2f> &out) {
	for(float i = 0; i < PI*2; i += PI/200.f) {
		ofVec2f v(radius, 0);
		v.rotateRad(i);
		v += centre;
		out.push_back(v);
	}
}

void drawPoly(vector<ofVec2f> &poly) {
	
	ofBeginShape();
	for(int i = 0; i < poly.size(); i++) {
		//mesh.addVertex(poly[i]);
		ofVertex(poly[i].x, poly[i].y);
	}
	ofEndShape();
}

void soundMap::receivedBang(ofxTLBangEventArgs& bang){
    ofLogNotice("Bang fired from track " + bang.flag);
    if(bang.flag ==  "rattle"){
        ofLog()<< "pimg"; 
        theRattle.goTime =true; 
    }
    else if(bang.flag ==  "catPurring"){
        ofLog()<< "pimg";
        catPurring.goTime =true;
    }
    else if(bang.flag ==  "skinScratch"){
        ofLog()<< "pimg";
        skinScratch.goTime =true;
    }
    else if(bang.flag ==  "writing"){
        ofLog()<< "pimg";
        writing.goTime =true;
    }
    else if(bang.flag ==  "crying"){
        ofLog()<< "pimg";
        crying.goTime =true;
    }
    else if(bang.flag ==  "showerTime"){
        ofLog()<< "pimg";
        showerTime.goTime =true;
    }
    else if(bang.flag ==  "tubDrip"){
        ofLog()<< "pimg";
        tubDrip.goTime =true;
    }
    else if(bang.flag ==  "mixing"){
        ofLog()<< "pimg";
        mixing.goTime =true;
    }
    else if(bang.flag ==  "kettle"){
        ofLog()<< "pimg";
        kettle.goTime =true;
    }
    else if(bang.flag ==  "appleChop"){
        ofLog()<< "pimg";
        appleChop.goTime =true;
    }
    else if(bang.flag ==  "brushTeeth"){
        ofLog()<< "pimg";
        brushTeeth.goTime =true;
    }
    else if(bang.flag ==  "mug1"){
        ofLog()<< "pimg";
        mug1.goTime =true;
    }
    else if(bang.flag ==  "mug2"){
        ofLog()<< "pimg";
        mug2.goTime =true;
    }
    else if(bang.flag ==  "waterPour"){
        ofLog()<< "pimg";
        waterPour.goTime =true;
    }
    else if(bang.flag ==  "eggCrack"){
        ofLog()<< "pimg";
        eggCrack.goTime =true;
    }
    else if(bang.flag ==  "stove"){
        ofLog()<< "pimg";
        stove.goTime =true;
    }
    else if(bang.flag ==  "longCooking"){
        longCooking.goTime =true;
        ofLog()<<"setToTrue";
    }
    else if(bang.flag ==  "humming"){
        humming.goTime =true;
    }
    else if(bang.flag ==  "overheardUpstairs"){
        overheardUpstairs.goTime =true;
    }
    else if(bang.flag ==  "gwenRun"){
        gwenRun.goTime =true;
    }
    else if(bang.flag ==  "dishes"){
        dishes.goTime =true;
    }
    else if(bang.flag ==  "sleep"){
        sleep.goTime =true;
    }
}


void soundMap::update(bool track){
    //ofLog() << "peep";
    trackerIsDetected = track; 
}


void soundMap::animateFuzz( StaticFuzzObject &blob){
    if (blob.toAnimate != "done"){
    if (blob.count ==0 && blob.toAnimate != "nope"){
        blob.xml.loadFile(blob.toAnimate);
        blob.xml.pushTag("STROKE");
        midiOut.sendNoteOn(1, 45,50);
    }
    int numOfPoints = blob.xml.getNumTags("PT");
    if(blob.count < numOfPoints){
        int x = blob.xml.getValue("PT:X",0,blob.count);
        int y = blob.xml.getValue("PT:Y",0,blob.count);
        blob.posX = x;
        blob.posY = y; 
        blob.count += 1;
    }
    else if (blob.count == numOfPoints){
        blob.toAnimate = "done"; 
    }
    }
}

void soundMap::drawFuzzShape(StaticFuzzObject blob){
    if (blob.toAnimate !=  "done"){
        int heighestAlpha = ofMap(blob.HighestVolume, 0, 100, 0, 255);
        float widthIncludingSpread = blob.width* blob.spreadFactor;
        ofEnableAlphaBlending();
        if(blob.clipToRoom == 9){
            int alpha = 0;
            ofSetColor(blob.color,heighestAlpha/4);
            ofEllipse(blob.posX, blob.posY, widthIncludingSpread/1.5 , widthIncludingSpread/1.5);
            ofSetColor(blob.color, heighestAlpha/2);
            ofEllipse(blob.posX, blob.posY, blob.width, blob.width);
        }
        else{
    vector<ofVec2f> littleCircle , bigCircle, roomz;
        getCircleCoords(ofVec2f(blob.posX, blob.posY), blob.width/2, littleCircle);
       
        getCircleCoords(ofVec2f(blob.posX, blob.posY), (widthIncludingSpread/1.5)/2, bigCircle);
        
        //temp =
        //ofLog() << blob.roomNum-1;
        vector< ofPoint > pointsInRoom =  rooms[blob.clipToRoom-1].getVertices();
         
         //svgPaths.paths[blob.roomNum-1]->getOutline()[1].getVertices();
        for (int i=0; i < pointsInRoom.size(); i++){
            ofVec2f point;
            point.x = pointsInRoom[i].x;
            point.y = pointsInRoom[i].y;
            roomz.push_back(point);
        }
        
  
        vector<vector<ofVec2f> > polys;
        polys.push_back(bigCircle);
        polys.push_back(roomz);
        
        vector<vector<ofVec2f> > out;
        clipper.doIntersection(polys, out);
        polys.clear();

        ofSetColor(blob.color,heighestAlpha/4);
        for(int i = 0; i < out.size(); i++) {
            drawPoly(out[i]);
        }
        out.clear();
        
            vector<vector<ofVec2f> > polys2;
            polys2.push_back(littleCircle);
            polys2.push_back(roomz);
            
            vector<vector<ofVec2f> > out2;
            clipper.doIntersection(polys2, out2);
            polys2.clear();
            
            ofSetColor(blob.color, heighestAlpha/2);
            for(int i = 0; i < out2.size(); i++) {
                drawPoly(out2[i]);
            }
            out.clear();
    ofDisableAlphaBlending();
    } 
}
}

void soundMap::playMidi(int channel, int note, int x, int y){
    int pan = ofMap(x, 0, ofGetWidth(), 0, 127);
    midiOut.sendControlChange(channel, note ,pan);
    //midiOut.sendNoteOn(channel, note ,127);
}

float soundMap::getVolumeFromFuzzShape(int x, int y, StaticFuzzObject blob){
    //if (blob.toAnimate !=  "done"){
    float volume;
    if(room != 9 && blob.toAnimate !=  "done" && trackerIsDetected){
    int heighestVol = ofMap(blob.HighestVolume, 0, 100, 0, 127);
    ofVec2f centroidOfBlob;
    ofVec2f trackPoint;
    centroidOfBlob.set(blob.posX, blob.posY);
    trackPoint.set(x,y);
     
    float dist = centroidOfBlob.distance(trackPoint);
    float widthIncludingSpread = blob.width* blob.spreadFactor;
    if(dist > widthIncludingSpread/2){
        volume = 0;
    }
    else if (dist < blob.width/2){
        volume = heighestVol;
    }
    else {
        volume = ofMap(dist, blob.width/2, widthIncludingSpread/2, heighestVol , .1);
    }
        if(room != blob.clipToRoom){
            volume *= blob.muffleFactor;
        }
    }
    else{
        volume=0; 
    }
    return volume;
    
    
}

void soundMap::distanceFromShortSound(StaticFuzzObject &blob, int channel, int note, int xPos, int yPos ){
    if(blob.goTime){
    float volOfRat = getVolumeFromFuzzShape(xPos,yPos,blob);
    midiOut.sendControlChange(channel,note, volOfRat );
    }
}


void soundMap::drawShortSound(StaticFuzzObject &blob, int note ){
    if(blob.goTime){
        if(blob.timePast < blob.duration){
            if(blob.timePast < 0){
                startTime = ofGetUnixTime();
                midiOut.sendNoteOn(1,note,50);
            }
            drawFuzzShape(blob);
            int currentTime = ofGetUnixTime();
            blob.timePast= currentTime - startTime;
            ofLog()<<blob.timePast;
        }
        else{
            blob.goTime =false;
            blob.timePast =-1;
        }
    }
}

void soundMap::draw(int x, int y){
    
    
    room = 9;
    for(int i=0; i < svgPaths.paths.size(); i++){
        temp = svgPaths.paths[i]->getOutline();
        rooms.push_back(temp[0]);
        if(temp[0].inside(x, y)){
            room =i;
            room +=1;
            break;
        }
        else{
            
        }
        temp.clear();
    }
    
    
    ofEllipse(x, y, 20, 20);
    for(int i=0; i < rooms.size(); i++){
        // set color to white. so that it isn't always changing.
        ofSetColor(234,202,202);
        rooms[i].draw();
    }
    
    

    
   drawFuzzShape(clock);
    //drawFuzzShape(convesation);
    drawFuzzShape(showerDrip);
    drawFuzzShape(kitchenClock);
    drawFuzzShape(fridge);
    drawFuzzShape(windowBack);
    drawFuzzShape(windowFront);
    drawFuzzShape(catPurring);
    float volOfCat = getVolumeFromFuzzShape(x, y, catPurring);
    midiOut.sendControlChange(1,30, volOfCat);
    
    // trigger note, channel, control Midi 
    
    drawShortSound(skinScratch,36);
    distanceFromShortSound(skinScratch,1,105,x,y);
    drawShortSound(writing,37);
    distanceFromShortSound(writing, 1, 106, x, y);
    drawShortSound(crying,38);
    distanceFromShortSound(crying, 1, 107, x, y);
    drawShortSound(showerTime,39);
    distanceFromShortSound(showerTime, 1, 108, x, y);
    drawShortSound(tubDrip,44);
    distanceFromShortSound(tubDrip, 1, 90, x, y);
    drawShortSound(mixing,33);
    distanceFromShortSound(mixing, 1, 102, x, y); 
    drawShortSound(kettle,34);
    distanceFromShortSound(kettle, 1, 103, x, y);
    drawShortSound(appleChop,35);
    distanceFromShortSound(appleChop, 1, 104, x, y);
    drawShortSound(brushTeeth,28);
    distanceFromShortSound(brushTeeth, 1, 86, x, y);
    drawShortSound(mug1,29);
    distanceFromShortSound(mug1, 1, 87, x, y);
    drawShortSound(mug2,30);
    distanceFromShortSound(mug2, 1, 88, x, y);
    drawShortSound(waterPour,31);
    distanceFromShortSound(waterPour, 1, 89, x, y);
    drawShortSound(eggCrack,24);
    distanceFromShortSound(eggCrack, 1, 31, x, y);
    drawShortSound(stove,25);
    distanceFromShortSound(stove, 1, 85, x, y);
    
    drawShortSound(longCooking,26);
    distanceFromShortSound(longCooking, 1, 109, x, y);
    drawShortSound(humming,27);
    distanceFromShortSound(humming, 1, 110, x, y);
    drawShortSound(gwenRun,20);
    distanceFromShortSound(gwenRun, 1, 111, x, y);
    drawShortSound(overheardUpstairs,21);
    distanceFromShortSound(overheardUpstairs, 1, 112, x, y);
    drawShortSound(dishes,22);
    distanceFromShortSound(dishes,1, 113, x, y);
    drawShortSound(sleep,23);
    distanceFromShortSound(sleep, 1, 114, x, y);
    
    
    
    //midiOut.sendNoteOn(1,42,50);
    //drawFuzzShape(catPurring);
    //drawFuzzShape(skinScratch);

    
 
    
    float volOfChew = getVolumeFromFuzzShape(x,y,convesation);
    midiOut.sendControlChange(1,23, volOfChew);
    
    float vol = getVolumeFromFuzzShape(x, y, clock);
    midiOut.sendControlChange(1,22, vol);
    
    float volOfShower = getVolumeFromFuzzShape(x,y,showerDrip);
    midiOut.sendControlChange(1,24, volOfShower);
    
    float volOfKitchenClock = getVolumeFromFuzzShape(x, y, kitchenClock);
    midiOut.sendControlChange(1,25, volOfKitchenClock);
    
    float volOfFridge = getVolumeFromFuzzShape(x, y, fridge);
    midiOut.sendControlChange(1,26, volOfFridge);
    
    float volOfBackWindow = getVolumeFromFuzzShape(x, y, windowBack);
    midiOut.sendControlChange(1,27, volOfBackWindow);
    float volOfFrontWindow = getVolumeFromFuzzShape(x, y, windowFront);
    midiOut.sendControlChange(1,28, volOfFrontWindow);
    
   
    //midiOut.sendNoteOn(1, 1,50);
   // midiOut.sendControlChange(1, 3, 127);
   
    //ofLog() << "room: " << room;
    if(trackerIsDetected){
    if(room == 1){
        midiOut.sendControlChange(1, 9, 127);
        midiOut.sendControlChange(1, 14, 127);
        midiOut.sendControlChange(1, 15, 127);
        
        midiOut.sendControlChange(1, 3, 0);
    }
   
    else if (room == 2){
        midiOut.sendControlChange(1, 9, 0);
        midiOut.sendControlChange(1, 14, 127);
        midiOut.sendControlChange(1, 15, 127);
        
        midiOut.sendControlChange(1, 3, 127);
        
    }
    else if (room == 3){
        midiOut.sendControlChange(1, 9, 127);
        midiOut.sendControlChange(1, 14, 0);
        midiOut.sendControlChange(1, 15, 127);
        
        midiOut.sendControlChange(1, 3, 127);
    }
    else if (room == 4){
        midiOut.sendControlChange(1, 9, 127);
        midiOut.sendControlChange(1, 14, 127);
        midiOut.sendControlChange(1, 15, 0);
        
        midiOut.sendControlChange(1, 3, 127);
    }
    else{
        midiOut.sendControlChange(1, 9, 127);
        midiOut.sendControlChange(1, 14, 127);
        midiOut.sendControlChange(1, 15, 127);
        
        midiOut.sendControlChange(1, 3, 127);
        //ofLog()<<"mm";
    }
    }
    else{
        midiOut.sendControlChange(1, 9, 127);
        midiOut.sendControlChange(1, 14, 127);
        midiOut.sendControlChange(1, 15, 127);
        midiOut.sendControlChange(1, 3, 127);
    }

    timeline.draw();
}


void soundMap::exit(){
    //midiOut.closePort();
}
OfSoundMapping
==========

![Screenshot](https://github.com/crecord/OfSoundMapping/blob/master/screen.jpg)


(a video)[https://www.youtube.com/watch?v=vVhsMn0sYM0&feature=youtu.be] of the sound maps in action. It is really subtle - so wear headphones.

Description
-----------

An [openFrameworks](http://www.openframeworks.cc/) project that receives postion data and transforms it into sound. The application allows users to create a detailed soundscape of a space. 

The features:
 - loading in a SVG floor plan and assign sounds to each room. Note that the sounds will clip to their given room. 
 - create circular regions of sound within the rooms. 
 - set muffle factors for those sounds so that are still audible but muffled for other rooms.
 - additionally, set volume, and size, and position of each region of sound. 
 - trigger regions of sounds to occur at different times within an editable timeline.
 - animate regions of sound to move about the space. 
 - can be set to explore the sound map through the mouse or via 


Dependencies 
------------

Be warned that this project has a lot of dependencies, it is not documented that well, and you need to do some midi mapping labor to make it work. First of all you need [openFrameworks](http://www.openframeworks.cc/). 
And the following ofxAddons: 

ofxXmlSettings
ofxMSATimer
ofxRange
ofxTextInputField
ofxTimecode
ofxTimeline
ofxTween
ofxtweener
ofxSVG
ofxMidi


You are also going to need Ableton Live and a midi mapping software - I recommend MIDI Patchbay, but others should work as well. An example Ableton Live and Midi file are provided in the Bin folder. 
The midi mapping process is currently very laborious. 

This was originally used with my OfTracking project, so you can check that out if you need a precise way to get indoor positon data. 


This was last tested on a 10.9.5 mac with Xcode 5.1.1 and OF 0.8.1


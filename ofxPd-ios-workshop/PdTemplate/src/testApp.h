/*
 * PdTemplate: A simple ofxPd template
 * Use ofxPd https://github.com/danomatika/ofxPd
 * Created by janetyc on 2013/08/10.
 */

#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "AppCore.h"

class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);

	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	
	// audio callbacks
	void audioReceived(float * input, int bufferSize, int nChannels);
	void audioRequested(float * output, int bufferSize, int nChannels);

	AppCore core;
};



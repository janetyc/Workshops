/*
 * PdTemplate: A simple ofxPd template
 * Use ofxPd https://github.com/danomatika/ofxPd
 * Created by janetyc on 2013/08/10.
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

	// register touch events
	ofRegisterTouchEvents(this);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	// iOSAlerts will be sent to this
	//ofxiOSAlerts.addListener(this);
	ofxiPhoneAlerts.addListener(this);
    
	// set landscape
	//ofSetOrientation(OF_ORIENTATION_90_RIGHT;
	
	ofBackground(0, 0, 0);
	
	// the number if libpd ticks per buffer,
	// used to compute the audio buffer len: tpb * blocksize (always 64)
	int ticksPerBuffer = 8;	// 8 * 64 = buffer len of 512
	
	// setup the app core
	core.setup(2, 1, 44100, ticksPerBuffer);

	// setup OF sound stream
	ofSoundStreamSetup(2, 1, this, 44100, ofxPd::blockSize()*ticksPerBuffer, 3);
}

//--------------------------------------------------------------
void testApp::update() {
	core.update();
}

//--------------------------------------------------------------
void testApp::draw() {
	core.draw();
}

//--------------------------------------------------------------
void testApp::exit() {
	core.exit();
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch) {

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch) {

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch) {

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch) {

}

//--------------------------------------------------------------
void testApp::lostFocus() {

}

//--------------------------------------------------------------
void testApp::gotFocus() {

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning() {

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation) {

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& args) {

}

//--------------------------------------------------------------
void testApp::audioReceived(float * input, int bufferSize, int nChannels) {
	core.audioReceived(input, bufferSize, nChannels);
}

void testApp::audioRequested(float * output, int bufferSize, int nChannels) {
	core.audioRequested(output, bufferSize, nChannels);
}

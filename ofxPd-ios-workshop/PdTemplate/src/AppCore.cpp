/*
 * PdTemplate: A simple ofxPd template
 * Use ofxPd https://github.com/danomatika/ofxPd
 * Created by janetyc on 2013/08/10.
 */

#include "AppCore.h"

//--------------------------------------------------------------
void AppCore::setup(const int numOutChannels, const int numInChannels,
                    const int sampleRate, const int ticksPerBuffer) {

	ofSetFrameRate(60);
	ofSetVerticalSync(true);

	// double check where we are ...
	cout << ofFilePath::getCurrentWorkingDirectory() << endl;

	if(!pd.init(numOutChannels, numInChannels, sampleRate, ticksPerBuffer)) {
		ofLog(OF_LOG_ERROR, "Could not init pd");
        OF_EXIT_APP(1);
	}
    pd.start();
    
	// open patch
	Patch patch = pd.openPatch("pd/pd.pd");
	cout << patch << endl;

}
//--------------------------------------------------------------
void AppCore::sendData(string name, float x)
{
	pd.sendFloat(name, x);
}

//--------------------------------------------------------------
void AppCore::update() {
}

//--------------------------------------------------------------
void AppCore::draw() {
}

//--------------------------------------------------------------
void AppCore::exit() {
}

//--------------------------------------------------------------
void AppCore::audioReceived(float * input, int bufferSize, int nChannels) {
	pd.audioIn(input, bufferSize, nChannels);
}

//--------------------------------------------------------------
void AppCore::audioRequested(float * output, int bufferSize, int nChannels) {
	pd.audioOut(output, bufferSize, nChannels);
}

//--------------------------------------------------------------
void AppCore::print(const std::string& message) {
	cout << message << endl;
}



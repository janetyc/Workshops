/*
 * PdTemplate: A simple ofxPd template
 * Use ofxPd https://github.com/danomatika/ofxPd
 * Created by janetyc on 2013/08/10.
 */

#pragma once

#include "ofMain.h"
#include "ofxPd.h"

// a namespace for the Pd types
using namespace pd;

class AppCore : public PdReceiver, public PdMidiReceiver {

	public:

		// main
		void setup(const int numOutChannels, const int numInChannels,
				   const int sampleRate, const int ticksPerBuffer);
		void update();
		void draw();
		void exit();
		
		// audio callbacks
		void audioReceived(float * input, int bufferSize, int nChannels);
		void audioRequested(float * output, int bufferSize, int nChannels);
		
		// pd message receiver callbacks
		void print(const std::string& message);
		
        // send data to pd
        void sendData(string name, float x);
    
		ofxPd pd;
		
};

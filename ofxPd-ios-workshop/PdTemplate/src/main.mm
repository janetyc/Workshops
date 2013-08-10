/*
 * PdTemplate: A simple ofxPd template
 * Use ofxPd https://github.com/danomatika/ofxPd
 * Created by janetyc on 2013/08/10.
 */

#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main() {

	ofSetupOpenGL(1024, 768, OF_FULLSCREEN);			// <-------- setup the GL context

	ofRunApp(new testApp);
}

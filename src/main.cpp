
#pragma warning(push)
#pragma warning(disable:4100)
#pragma warning(disable:4201)
#pragma warning(disable:4458)
#pragma warning(disable:4505)
#pragma warning(disable:4819)
#include "ofMain.h"
#include "ofApp.h"
#pragma warning(pop)

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

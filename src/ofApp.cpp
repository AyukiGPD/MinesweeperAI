#include "ofApp.h"
#include "MainSystem.h" 

//--------------------------------------------------------------
void ofApp::setup()
{
	_pMainSystem = MainSystem::CreateMainSystem();
	_pMainSystem->setup();
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->draw();
	}
}

//--------------------------------------------------------------
void ofApp::exit()
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->exit();
	}

	_pMainSystem = nullptr;
	MainSystem::ReleaseMainSystem();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->keyPressed(key);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->keyReleased(key);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mouseMoved(x,y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mouseDragged(x, y, button);
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mousePressed(x, y, button);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mouseReleased(x, y, button);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mouseEntered(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->mouseExited(x, y);
	}
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->windowResized(w, h);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->gotMessage(msg);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (_pMainSystem != nullptr)
	{
		_pMainSystem->dragEvent(dragInfo);
	}
}

#include "ofGuiApp.h"
ofGuiApp::ofGuiApp(int port, string file, bool logToFile):
    oscLogger(port, file, logToFile)
{
}

void ofGuiApp::setup(){
    _parameters.setName("Settings");
    _drawGuiBParameter.set("GUI on/off", true);
    _parameters.add(_drawGuiBParameter);
    _parameters.add(oscLogger::_parameters);
    _gui.setup(_parameters);

    ofSetLogLevel(OF_LOG_VERBOSE);
}

void ofGuiApp::update(){
    oscLogger::update();
}

void ofGuiApp::draw(){
    if(_drawGuiBParameter)
    {
        _gui.draw();
    }

}

void ofGuiApp::keyPressed(int key){

}

void ofGuiApp::keyReleased(int key){
    switch(key)
    {
        case 'g': _drawGuiBParameter = !_drawGuiBParameter; break;
        case OF_KEY_LEFT: break;
        case OF_KEY_RIGHT: break;
    }

}

void ofGuiApp::mouseMoved(int x, int y ){

}

void ofGuiApp::mouseDragged(int x, int y, int button){
}

void ofGuiApp::mousePressed(int x, int y, int button){

}

void ofGuiApp::mouseReleased(int x, int y, int button){

}

void ofGuiApp::windowResized(int w, int h){

}

void ofGuiApp::gotMessage(ofMessage msg){

}

void ofGuiApp::dragEvent(ofDragInfo dragInfo){ 

}

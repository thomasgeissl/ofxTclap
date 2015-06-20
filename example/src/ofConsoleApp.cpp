#include "ofConsoleApp.h"
ofConsoleApp::ofConsoleApp(int port, string file, bool logToFile):
    oscLogger(port, file, logToFile)
{
    ofSetLogLevel(OF_LOG_VERBOSE);
}

void ofConsoleApp::setup(){
}

void ofConsoleApp::update(){
    oscLogger::update();
}

void ofConsoleApp::keyPressed(int key){
}

void ofConsoleApp::keyReleased(int key){
}

void ofConsoleApp::gotMessage(ofMessage msg){
}

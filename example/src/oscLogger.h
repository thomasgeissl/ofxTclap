#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class oscLogger
{
public:
    oscLogger(int port, string file, bool logToFile);
    void update();
    ofParameterGroup & getParameters();
protected:
    void onPortChange(int &value);
    void onFileChange(string &value);
    void onLogToFileChange(bool &value);

protected:
    ofxOscReceiver _oscReceiver;
    ofParameterGroup _parameters;
    ofParameter<int> _portParameter;
    ofParameter<bool> _logToFileParameter;
    ofParameter<string> _fileParameter;
};

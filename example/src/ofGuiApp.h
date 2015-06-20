#pragma once

#include <queue>
#include "ofMain.h"
#include "ofxGui.h"
#include "oscLogger.h"

class ofGuiApp :
    public ofBaseApp,
    public oscLogger
{
public:
    ofGuiApp(int port, string file, bool logToFile);
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
private:
    ofxPanel _gui;
    ofParameterGroup _parameters;
    ofParameter<bool> _drawGuiBParameter;

    queue<string> _messages;
};

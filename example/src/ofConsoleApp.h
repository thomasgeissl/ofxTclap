#pragma once

#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "oscLogger.h"

class ofConsoleApp :
    public ofBaseApp,
    public ofAppNoWindow,
    public oscLogger
{
public:
    ofConsoleApp(int port, string file, bool logToFile);
    void setup();
    void update();

    void keyPressed(int key);
    void keyReleased(int key);
    void gotMessage(ofMessage msg);
};

#include "ofMain.h"
#include "ofConsoleApp.h"
#include "ofGuiApp.h"
#include "ofxTclap.h"

int main(int argc, char** argv)
{
    try {  
        // Define the command line object.
        CmdLine cmd("OSC Logger");

        // Define a value argument and add it to the command line.
        ValueArg<string> destinationArg("d","destination","path",false,"osc.log","string");
        ValueArg<int> portArg("p","port","local port",false,8000,"int");
        cmd.add( destinationArg );
        cmd.add( portArg );

        // Define a switch and add it to the command line.
        SwitchArg guiSwitch("g","gui","shows gui", false);
        SwitchArg consoleSwitch("c","console"," log to console", false);
        cmd.add(guiSwitch);
        cmd.add(consoleSwitch);

        cmd.parse(argc, argv);

        if(guiSwitch.getValue())
        {
            ofSetupOpenGL(1024,768,OF_WINDOW);
            ofRunApp(new ofGuiApp(portArg.getValue(), destinationArg.getValue(), !consoleSwitch.getValue()));
        }
        else
        {
            ofAppNoWindow window;
            ofSetupOpenGL(&window,0,0,OF_WINDOW);
            ofRunApp(new ofConsoleApp(portArg.getValue(), destinationArg.getValue(), !consoleSwitch.getValue()));
        }

    } 
    catch (ArgException &e)  // catch any exceptions
    { 
        ofLogError("main")<<e.error()<<" for arg "<<e.argId();
    }
}

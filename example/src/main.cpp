#include "ofLog.h"
#include "ofxTclap.h"

int main(int argc, char **argv)
{
    try
    {
        // Define the command line object.
        CmdLine cmd("OSC Logger");

        // Define a value argument and add it to the command line.
        // h/help is already taken
        ValueArg<std::string> hostArg("i", "host", "host", false, "localhost", "string");
        ValueArg<int> portArg("p", "port", "port", false, 8000, "int");
        cmd.add(hostArg);
        cmd.add(portArg);

        // Define a switch and add it to the command line.
        SwitchArg debugSwitch("d", "debug", "debug mode", false);
        cmd.add(debugSwitch);
        cmd.parse(argc, argv);

        ofLogNotice() << "debug: " << debugSwitch.getValue();
        ofLogNotice() << "host: " << hostArg.getValue();
        ofLogNotice() << "port: " << portArg.getValue();
    }
    catch (ArgException &e) // catch any exceptions
    {
        ofLogError("main") << e.error() << " for arg " << e.argId();
    }
}

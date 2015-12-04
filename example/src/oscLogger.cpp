#include "oscLogger.h"
oscLogger::oscLogger(int port, string file, bool logToFile)
{
    _parameters.setName("Parameters");
    _portParameter.set("Port", port, 0, 10000);
    _fileParameter.set("File", file);
    _logToFileParameter.set("Log to file", logToFile);

    _portParameter.addListener(this, &oscLogger::onPortChange);
    _fileParameter.addListener(this, &oscLogger::onFileChange);
    _logToFileParameter.addListener(this, &oscLogger::onLogToFileChange);

    _parameters.add(_portParameter);
    _parameters.add(_fileParameter);
    _parameters.add(_logToFileParameter);


    _oscReceiver.setup(port);
    if(logToFile)
    {
        ofLogToFile(file);
    }

}


void oscLogger::update(){
    while(_oscReceiver.hasWaitingMessages())
    {
        ofxOscMessage message;
        _oscReceiver.getNextMessage(message);
        string messageS = message.getAddress();
        for(int i = 0; i < message.getNumArgs(); i++)
        {
            //TODO append type and value
        }
        _messageHistory.push_back(messageS);
        while(_messageHistory.size() > 20)
        {
            _messageHistory.pop_front();
        }

    }
}
ofParameterGroup & oscLogger::getParameters()
{
    return _parameters;
}
 
void oscLogger::onPortChange(int &value)
{
    _oscReceiver.setup(value);
}
void oscLogger::onFileChange(string &value)
{
    if(_logToFileParameter)
    {
        ofLogToFile(value);
    }
}
void oscLogger::onLogToFileChange(bool &value)
{
    if(value)
    {
        ofLogToFile(_fileParameter);
    }
    else
    {
        ofLogToConsole();
    }
}
string oscLogger::getSerializedMessageHistory()
{
    string serializedMessageHistory;
    for(auto message : _messageHistory)
    {
        serializedMessageHistory += message;
        serializedMessageHistory += "\n";
    }
    return serializedMessageHistory;
}

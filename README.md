ofxTclap
===

Description
---
ofxTclap is an addon for openframeworks <https://github.com/openframeworks/openframeworks>.
It includes TCLAP <https://github.com/teile/tclap> in an openframeworks project. TCLAP (Templatized C++ Command Line Parser) facilitates parsing command line
arguments in a type independent manner.


Installation
---
```sh
git clone https://github.com/thomasgeissl/ofxTclap.git /path/to/your/openframeworks/addons/ofxTclap
```

Example
---
There is a little osc logger included as an example. 
It is still a work in progress, but the usage of TCLAP is shown in main.cpp file.

Other examples can be found at <https://github.com/eile/tclap/tree/master/examples>.

Known issues
---
* Somehow, I was not able to exclude the tclap/examples. That is why i removed them. Could be a bug in the of makefiles.

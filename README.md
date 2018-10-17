# Intan Stimulation/Recording Controller Software #
_Source code (v1.05)_  

---

## Contents ##
This is a repository for developmental work geared at slight modifications to the Intan RHD2000 and Intan RHS2000 recording and stimulating electrophysiological data acquisition systems. 

---



## About *main.bit* and *okFrontPanel.dll* ##

These two supporting files must reside in the directory with the executable file (i.e., the 'debug'
or 'release' folder generated when the code is compiled).  To find the executable directory on
a Mac, right-click on the IntanRecordingController.app file generated by Qt, select "Show package contents",
and open the "MacOS" directory.  (Note: Some Mac users have reported that these two files must be
placed in the in same directory as the application instead.)

---



## Notes about running and compiling ##

You should also download and install the USB drivers from the Intan Technologies website before
connecting the Intan Recording Controller to a computer.  (They are not included in this zip file.)
However, you can run the Recording Controller software in demonstration mode without installing drivers
or plugging in an interface board.

The C++ source code uses a handful of C++11 features, so g++ users may need to add -std=c++11 to their 
command line or make file.

This code was tested with Qt 4.8.1 and with Qt 5.7.0.

For production code, you should compile a Release build (Visual Studio) or use the optimization flag
-O3 (g++).  Otherwise, the compiled code may not be fast enough to keep up with how fast data streams
from the USB interface board.  This will show up as the FIFO lag becoming very high for debug builds.

(Thanks to Josh Siegle at MIT and Open-Ephys.org for tips on Mac and Linux compilation.) 

---

## Tips ##
_Troubleshooting tips for different OS_

### Linux ###

Copy the libokFrontPanel.so file into the source folder.
Add the following line to the .pro file:  
​	`unix:LIBS += -L./ -l okFrontPanel -ldl`
Run qmake on the .pro file, and then make.



### Mac ###

Intan now provides executables for MacOSX.  However, some users may wish to modify and recompile the
code on a Mac.  This description is based on exprience using a MacBook Pro running MacOSX 12.

1) Install XCode

2) Install Qt Creator and Qt5 (Make sure to install XCode first)

3) Open the project (.pro) file and click "run" in release mode (will not succeed).

4) Inside the build directory, find the .app file that was generated.  Right-click and select "Show
   Package Contents".  Navigate to Contents->MacOS.  Move the "main.bit" and "libokFrontPanel.dylib"
   files to this folder, alongside the executable.

5) Qt Creator should now be able to fully run the program.



### Windows ###

Some Windows users have reported that it is necessary to install Qt with 32-bit support for the 
okFrontPanel DLL to load properly.  But this was with an older version of the Recording Controller source
code that didn't support 64-bit, so it may not apply any more.



---

## License ##

The Intan Stimulation/Recording Controller is free software, and is distributed under the terms of the GNU Lesser
General Public License as published by the Free Software Foundation.  See the license subdirectory
for the complete license.

---

## Recommended C++/Qt Resources ##

The source code is written entirely in C++ using the open-source Qt libraries for multi-platform GUI
support. (The files composing the core RhythmStim API are written in straight C++ without using Qt.)

There are countless books and other online resources related to C++ programming, so these will not
be discussed here. For C++ programmers new to Qt, the best place to start is http://qt-project.org.
We recommend downloading the Qt SDK (Software Design Kit) including Qt Creator, Qt Assistant, and the
latest Qt libraries for the operating system of choice.

The best book we have found for first-time Qt programmers is C++ GUI Programming with Qt 4, Second
Edition, by Jasmin Blanchette and Mark Summerfield (ISBN 0-13-235416-0). Chapters 1-8 and 11-12, along
with Appendices A and B, cover nearly all the aspects of Qt used in the RHD2000 interface GUI. The
library documentation available in the Qt Assistant application is also excellent and indispensable.

---

## Related RHS2000 Documentation ##

The following supporting datasheets provide detailed information on the operation of the Intan Technologies
RHS2000 digital stimulation/amplifier chips and Rhythm Stim interface; they may be found on the Intan Technologies
website, http://www.intantech.com:

* Intan Stimulation/Recording Controller User Guide
* RHS2000 Series Digital Stimulation/Amplifier Interface Chips
* RHS2000 USB/FPGA Interface: RhythmStim
* RHS2000 Stim SPI Cable/Connector Specification
* RHS2000 Application Note: Data File Formats
* RHS2000 Application Note: Adding Stim SPI Cables to a Commutator
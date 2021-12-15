# OpenCV Test
 This repository is just a simple test to work with OpenCV Video Capture
 
 
# How To Build
 
 *Currently this is only available for windows, unless you already have the Linux OpenCV libs installed and know how to setup your compiler flags.*
 
## Prerequisites
 You'll need MinGW64 installed and its path configured.
 
 You'll need a dependency tracker to automatically update any library dependencies. This can be found here: [Install Dependency Tracker](https://github.com/jmscreation/dependency-tracker)
 
## Update Libraries
 Run `deps -update` in the main repository. This updates any required library.

## Build
 Run `.\build.bat` in the main repository. If everything was setup correctly, you should get a "Build Success!"
 

## Troubleshooting
 If you have trouble building or following any of the steps, please check your PATH in your environment variables and make sure you have the following applications:

- `g++.exe` *MinGW bin folder*
- `c++.exe` *MinGW bin folder*
- `git.exe` *Git cmd folder*
- `deps.exe` *Any configured path folder*

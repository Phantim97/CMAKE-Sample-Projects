How to setup bash on Windows 10:

1. Open Settings -> Updates and Security
2. Enable Developer Mode
3. Go to Control Panel
4. Programs -> Turn Windows Features on and off
5. Enable "Windows Subsystem for Linux"
6. Restart
7. Go to Microsoft Store to get Ubuntu
8. Run Ubuntu and make a username
9. Find Bash in C:/Windows/System32/bash.exe
10. Run "sudo apt-get update"
11a. If you have issues with carriage returns in file "\r" then run "sudo apt-get install dos2unix"
11b. dos2unix [file] <- to remove the carriage return
12. Shell does not function 100% and cmake with linux even after "sudo apt-get install cmake" and G++

Note: My bash test failed no matter what I did because the path has spaces I believe

To use in Linux env:
$ mkdir -p build (Makes build folder)
$ cd build
$ cmake ..
$ cmake --build .
$ ctest
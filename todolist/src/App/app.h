#pragma once

#include <iostream>

#ifdef _WIN32
#include <conio.h>
#endif

class App {
private:
    int returnCode{0};
    char currentMotion;

    char getCurrentMotion();
    char getCharacter();

public:
    App();
    ~App();

    int Run();
};

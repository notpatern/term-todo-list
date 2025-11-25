#pragma once

#include "CommandLine/commandLine.h"
#include "../Render/renderer.h"

#ifdef _WIN32
#include <conio.h>
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#endif

class App {
private:
    int returnCode{0};
    char currentMotion;
    CommandLine commandLine{};
    Renderer& renderer = Renderer::getInstance();

    char getCurrentMotion();
    char getCharacter();

public:
    App();
    ~App();

    int Run();
};

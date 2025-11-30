#include "app.h"

App::App() {

}

App::~App() {

}

int App::Run() {
    renderer.Run();
    commandLine.Run(getCharacter());
    return 0;
}

#ifdef _WIN32
char App::getCharacter() {
    return _getch();
}
#endif

#ifdef __linux__
char App::getCharacter() {
    char buf = 0;
    struct termios old = {0};
    struct termios raw = {0};

    if (tcgetattr(0, &old) < 0) {
        perror("tcgetattr()");
    }

    raw = old;
    raw.c_lflag &= ~ICANON;
    raw.c_lflag &= ~ECHO;
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &raw) < 0) {
        perror("tcsetattr ICANON");
    }

    if (read(0, &buf, 1) < 0) {
        perror("read()");
    }

    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }

    return buf;
}
#endif

char App::getCurrentMotion() {
    char result{};

    result = getCharacter();

    if (!(result == 'h' || result == 'j' || result == 'k' || result == 'l')) {
        return result;
    }

    return result;
}

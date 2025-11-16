#include "app.h"

App::App() {

}

App::~App() {

}

int App::Run() {
    currentMotion = getCurrentMotion();
    std::cout << currentMotion << std::endl;
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

    if (tcgetattr(0, &old) < 0) {
        perror("tcsetattr()");
    }

    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0) {
        perror("tcsetattr ICANON");
    }

    if (read(0, &buf, 1) < 0) {
        perror("read()");
    }

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }

    return buf;
}
#endif

char App::getCurrentMotion() {
    char result{};

    result = getCharacter();

    return result;
}

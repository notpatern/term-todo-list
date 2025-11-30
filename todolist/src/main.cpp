#include "App/app.h"
#include <cstdint>
#include <iostream>

void hide_cursor_ansi() {
    std::cout << "\033[?25l" << std::flush;
}

void show_cursor_ansi() {
    std::cout << "\033[?25h" << std::flush;
}

int main(int argc, char *argv[]) {
    uint32_t isRunning = 0;
    App app{};
    hide_cursor_ansi();
    while (!isRunning) {
        isRunning = app.Run();

        if (isRunning != 0) {
            std::cout << "Error code: " << isRunning << "\n\r";
            return isRunning;
        }
    }
    show_cursor_ansi();

    return 0;
}

#include "App/app.h"
#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
    uint32_t isRunning = 0;
    App app{};

    while (!isRunning) {
        isRunning = app.Run();
        if (isRunning != 0) {
            std::cout << "Error code: " << isRunning << "\n\r";
            return isRunning;
        }
    }

    return 0;
}

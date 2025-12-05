#include "renderer.h"
#include "renderable.h"
#include <algorithm>
#include <cstdlib>
#include <string_view>

Renderer::Renderer() {
    getTermDim(terminalDimensions);
    SetFrameBuffer();
}

Renderer::~Renderer() {
    for (int y = 0; y < terminalDimensions.y; y++) {
        delete[] frameBuffer[y];
    }
    delete[] frameBuffer;
}

void Renderer::SetFrameBuffer() {
    frameBuffer = new char*[terminalDimensions.y];
    for (int y = 0; y < terminalDimensions.y; y++) {
        frameBuffer[y] = new char[terminalDimensions.x];

        for (int x = 0; x < terminalDimensions.x; x++) {
            frameBuffer[y][x] = ' ';
        }
    }
}

void Renderer::getTermDim(Vector2<int>& dim) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    dim.x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    dim.y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    dim.x = w.ws_col;
    dim.y = w.ws_row;
#endif
}

void Renderer::FeedFrameBuffer() {
    if (isCmd) {
        frameBuffer[terminalDimensions.y - 1][0] = ':';
    } else {
        frameBuffer[terminalDimensions.y - 1][0] = ' ';
    }

    for (Renderable* renderable : renderables) {
        if (!renderable->getVisible()) {
            continue;
        }

        std::string_view content = renderable->getContent();
        Vector2<int>* position = renderable->getPostition();

        int length = content.length();

        for (int i = 0; i < length; i++) {
            frameBuffer[position->y][position->x + i] = content[i];
        }
    }
}

void Renderer::Run() {
    FeedFrameBuffer();
    Render();
    SetFrameBuffer();
}

void Renderer::Render() {
    for (int y = 0; y < terminalDimensions.y; y++) {
        CursorGoTo(0, y);

        for (int x = 0; x < terminalDimensions.x; x++) {
            std::cout << frameBuffer[y][x];
        }
    }
}

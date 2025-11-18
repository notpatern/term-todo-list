#include "renderer.h"
#include "renderable.h"

Renderer::Renderer() {
    getTermDim(terminalDimensions);
}

Renderer::~Renderer() {

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

void Renderer::Run() {
    for (Renderable* renderable : renderables) {
        if (renderable->getVisible()) {
            Render(renderable);
        }
    }
}

void Renderer::Render(Renderable* renderable) {
    std::cout << renderable->getContent() << "\n\r";
}

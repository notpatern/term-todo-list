#pragma once

#include <algorithm>
#include <vector>
#include "../Utility/Vector2.h"
#include "renderable.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

class Renderer {
private:
    const char* CSI = "\033[";

    Vector2<int> terminalDimensions{};
    std::vector<Renderable*> renderables;
    char** frameBuffer;
    bool isCmd{false};

    void getTermDim(Vector2<int>& dim);
    void SetFrameBuffer();
    void FeedFrameBuffer();
    void Render();

    inline void CursorGoTo(int x, int y) {
        std::cout << CSI << (y+1) << ";" << (x+1) << "H";
    }


public:
    static Renderer& getInstance() {
        static Renderer instance;
        return instance;
    }

    Renderer(Renderer const&) = delete;
    void operator=(Renderer const&) = delete;

    Renderer();
    ~Renderer();

    void Run();

    void AddToRenderQueue(Renderable* renderable) {
        renderables.push_back(renderable);
    }

    void RemoveFromRenderQueue(Renderable* renderable) {
        auto iterator = std::find(renderables.begin(), renderables.end(), renderable);
        renderables.erase(iterator);
    }

    inline Vector2<int> GetTerminalDimensions() {
        return terminalDimensions;
    }

    inline void SetCmdState(bool state) {
        isCmd = state;
    }
};

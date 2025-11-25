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
    Vector2<int> terminalDimensions{};
    std::vector<Renderable*> renderables;
    void getTermDim(Vector2<int>& dim);
    void Render(Renderable* renderable);

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

    Vector2<int> GetTerminalDimensions() {
        return terminalDimensions;
    }
};

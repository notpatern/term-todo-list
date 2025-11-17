#pragma once

#include <memory>
#include <vector>
#include "renderable.h"

class Renderer {
private:
    std::unique_ptr<int> terminalDimensions = std::make_unique<int>();
    std::vector<Renderable*> renderables;

public:
    Renderer();
    ~Renderer();

    void Run();
    void AddToRenderQueue(Renderable* renderable);
    void RemoveFromRenderQueue(Renderable* renderable);
};

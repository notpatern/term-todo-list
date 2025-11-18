#pragma once
#include <string_view>
#include "../Utility/Vector2.h"

class Renderable {
protected:
    int layer{}; /// lower is higher priority
    Vector2<int>* position{};
    std::string_view content;
    bool isVisible{};

public:
    Renderable();
    Renderable(Vector2<int>& pos);
    ~Renderable();

    Vector2<int>* getPostition() {
        return position;
    }

    virtual std::string_view getContent() {
        return content;
    }

    int getLayer() {
        return layer;
    }

    bool getVisible() {
        return isVisible;
    }
};

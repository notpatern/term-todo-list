#pragma once

#include "../Utility/Vector2.h"
#include <string_view>

class Renderable {
private:
    int layer{};
    Vector2<int>* position{};
    std::string_view content;

public:
    Renderable();
    Renderable(Vector2<int>& pos);
    ~Renderable();

    Vector2<int>* getPostition() {
        return position;
    }

    std::string_view getContent() {
        return content;
    }
};

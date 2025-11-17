#include "renderable.h"

Renderable::Renderable() {
    position = new Vector2<int>();
}

Renderable::Renderable(Vector2<int>& pos) {
    position = &pos;
}

Renderable::~Renderable() {
    delete position;
}

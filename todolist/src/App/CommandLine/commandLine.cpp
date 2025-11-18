#include "commandLine.h"
#include "../../Render/renderer.h"

CommandLine::CommandLine() : Renderable() {
    Init();
    Renderer::getInstance().AddToRenderQueue(this);
}

CommandLine::~CommandLine() {
    Renderer::getInstance().RemoveFromRenderQueue(this);
}

void CommandLine::Init() {
    layer = 0;
    isOpened = false;
    isVisible = false;
    buffer = "";
}

void CommandLine::Run(const char character) {
    if (!isOpened) {
        if (character != ':') {
            return;
        }

        Open();
        return;
    }

    if (character == '\n' || character == '\r') {
        Execute();
        return;
    }

    Buffer(character);
}

void CommandLine::Open() {
    isOpened = true;
    isVisible = true;
    content = buffer;
}

void CommandLine::Buffer(const char character) {
    buffer += character;
    content = buffer;
}

void CommandLine::Execute() {
    isVisible = false;
    if (buffer == "e") {
        exit(0);
    }
    Abort();
}

void CommandLine::Abort() {
    Init();
}

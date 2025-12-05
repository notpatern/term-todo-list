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
    position = new Vector2<int>(1, Renderer::getInstance().GetTerminalDimensions().y - 1);
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
    Renderer::getInstance().SetCmdState(true);
    content = buffer;
}

void CommandLine::Buffer(const char character) {
    buffer += character;
    content = buffer;
}

void CommandLine::Execute() {
    isVisible = false;
    if (buffer == "q") {
        exit(0);
    }
    Abort();
}

void CommandLine::Abort() {
    Renderer::getInstance().SetCmdState(false);
    Init();
}

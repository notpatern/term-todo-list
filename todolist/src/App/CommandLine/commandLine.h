#pragma once

#include <string>
#include "../../Render/renderable.h"

class CommandLine : public Renderable {
private:
    std::string buffer{};
    bool isOpened = false;

    void Execute();
    void Buffer(const char character);
    void Open();
    void Abort();
    void Init();

public:
    CommandLine();
    ~CommandLine();

    void Run(const char character);
};

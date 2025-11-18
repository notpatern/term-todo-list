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
    std::string_view getContent() override {
        std::string_view newContent{};
        std::string colon{":"};
        std::string oldContent{content};

        newContent = colon.append(oldContent);
        return newContent;
    }
};

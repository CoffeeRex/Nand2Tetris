#ifndef CODER_H
#define CODER_H

#include <string>

class Coder
{
    public:
        std::string writeDest(std::string instruction);
        std::string writeComp(std::string instruction);
        std::string writeJump(std::string instruction);
};

#endif
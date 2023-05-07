#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>

class Assembler
{
    public:
        void assemble(std::string filename);
    private:
        std::string binconverter(std::string decimal);
};

#endif
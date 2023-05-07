#ifndef PARSER_H
#define PARSER_H

#include "InstructionTypes.h"

#include <string>
#include <vector>
#include <map>

class Parser
{
    public:
        std::vector<std::string> parse(std::string filename);
        std::map<std::string, std::string> symbolTable(std::vector<std::string> instructions);
        InstructionType instructionType(std::string instruction);
        std::string symbol(std::string instruction);
        std::string dest(std::string instruction);
        std::string comp(std::string instruction);
        std::string jump(std::string instruction);
};

#endif
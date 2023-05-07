#include "Parser.h"
#include "InstructionTypes.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> Parser::parse(string filename)
{
    string line;
    ifstream myfile;
    
    myfile.open(filename);

    vector<string> instructions;
    
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            size_t commentstart = line.find("//");

            if (commentstart != string::npos)
            {
                line = line.substr(0, commentstart);
            }

            if (line.size() == 0) continue;

            string instruction = "";

            size_t length = line.size();
            

            for(size_t i = 0; i < length; i++)
            {
                if ((line[i] != ' ') and (line[i] != '\r'))
                {
                    instruction += line[i];
                } 
            }

            if (instruction.size() > 0)
            {
                if (instruction[0] != '\r')
                {
                    //cout << "adding line" << endl;
                    instructions.push_back(instruction);
                }
            }

            else
            {
                //cout << "not adding line" << endl;
            }
        }

        myfile.close();
    }

    return instructions;

}

InstructionType Parser::instructionType(string instruction)
{
    if (instruction[0] == '@')
    {
        return A_INSTRUCTION;
    }

    else if (instruction[0] == '(')
    {
        return L_INSTRUCTION;
    }

    else if (instruction[0] == '0' or instruction[0] == '1' or instruction[0] == '-' or instruction[0] == 'D' or instruction[0] == 'A' or instruction[0] == '!' or instruction[0] == 'M')
    {
        return C_INSTRUCTION;
    }

    else
    {
        return NULL_INSTRUCTION;
    }
}

string Parser::symbol(string instruction)
{
    if (instructionType(instruction) == A_INSTRUCTION)
    {
        size_t length = instruction.size();
        string symb = instruction.substr(1, length - 1);
        return symb;
    }

    else if (instructionType(instruction) == L_INSTRUCTION)
    {
        size_t length = instruction.size();
        string symb = instruction.substr(1, length-2);
        return symb;
    }

    else
    {
        return "";
    }
}

string Parser::dest(string instruction)
{
    size_t eq = instruction.find('=');
    if (eq != string::npos)
    {
        string myDest = instruction.substr(0, eq);

        return myDest;

    }

    else
    {
        return "";
    }
}

string Parser::comp(string instruction)
{
    size_t eq = instruction.find('=');
    if (eq != string::npos)
    {
        size_t semi = instruction.find(';');
        if (semi != string::npos)
        {
            return instruction.substr(eq + 1, semi - eq - 1);
        }

        else
        {
            return instruction.substr(eq + 1);
        }
    }

    else
    {
        size_t semi = instruction.find(';');
        if (semi != string::npos)
        {
            return instruction.substr(0, semi);
        }

        else
        {
            return instruction;
        }
    }
}

string Parser::jump(string instruction)
{
    size_t semi = instruction.find(';');

    if (semi != string::npos)
    {
        return instruction.substr(semi + 1);
    }

    else
    {
        return "null";
    }
}

map<string, string> Parser::symbolTable(vector<string> instructions)
{
    map<string, string> symbols;
    symbols.insert(pair<string, string> ("R0", "0"));
    symbols.insert(pair<string, string> ("R1", "1"));
    symbols.insert(pair<string, string> ("R2", "2"));
    symbols.insert(pair<string, string> ("R3", "3"));
    symbols.insert(pair<string, string> ("R4", "4"));
    symbols.insert(pair<string, string> ("R5", "5"));
    symbols.insert(pair<string, string> ("R6", "6"));
    symbols.insert(pair<string, string> ("R7", "7"));
    symbols.insert(pair<string, string> ("R8", "8"));
    symbols.insert(pair<string, string> ("R9", "9"));
    symbols.insert(pair<string, string> ("R10", "10"));
    symbols.insert(pair<string, string> ("R11", "11"));
    symbols.insert(pair<string, string> ("R12", "12"));
    symbols.insert(pair<string, string> ("R13", "13"));
    symbols.insert(pair<string, string> ("R14", "14"));
    symbols.insert(pair<string, string> ("R15", "15"));
    symbols.insert(pair<string, string> ("SP", "0"));
    symbols.insert(pair<string, string> ("LCL", "1"));
    symbols.insert(pair<string, string> ("ARG", "2"));
    symbols.insert(pair<string, string> ("THIS", "3"));
    symbols.insert(pair<string, string> ("THAT", "4"));
    symbols.insert(pair<string, string> ("SCREEN", "16384"));
    symbols.insert(pair<string, string> ("KBD", "24576"));

    int linecount = 0;
    int varcount = 16;

    size_t size = instructions.size();

    for (size_t i = 0; i < size; i++)
    {
        if (instructionType(instructions.at(i)) == A_INSTRUCTION)
        {
            linecount ++;
        }

        else if (instructionType(instructions.at(i)) == C_INSTRUCTION)
        {
            linecount ++;
        }

        else if (instructionType(instructions.at(i)) == L_INSTRUCTION)
        {
            string symb = symbol(instructions.at(i));
            
            if (symbols.count(symb) == 0)
            {
                string temp = to_string(linecount);
                symbols.insert(pair<string, string> (symb, temp));
            }
        }
    }

    for (size_t i = 0; i < size; i++)
    {
        if (instructionType(instructions.at(i)) == A_INSTRUCTION)
        {
            if (!((instructions.at(i)[1] == '0') or (instructions.at(i)[1] == '1') or (instructions.at(i)[1] == '2') or (instructions.at(i)[1] == '3') or (instructions.at(i)[1] == '4') or (instructions.at(i)[1] == '5') or (instructions.at(i)[1] == '6') or (instructions.at(i)[1] == '7') or (instructions.at(i)[1] == '8') or (instructions.at(i)[1] == '9')))
            {
                string symb = symbol(instructions.at(i));

                if (symbols.count(symb) == 0)
                {
                    string temp = to_string(varcount);
                    symbols.insert(pair<string, string> (symb, temp));
                    varcount ++;
                }
            }
        }
    }

    return symbols;
}
#include "Assembler.h"
#include "Parser.h"
#include "Coder.h"
#include "InstructionTypes.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

string Assembler::binconverter(string decimal)
{
    int dec = stoi(decimal);

    string output = "";

    while (dec > 0)
    {
        if (dec % 2 == 0)
        {
            output = "0" + output;
            dec = dec / 2;
        }

        else
        {
            output = "1" + output;
            dec = (dec - 1) / 2;
        }
    }

    while (output.length() < 15)
    {
        output = "0" + output;
    }

    return output;
}

void Assembler::assemble(string filename)
{
    Parser myParser;
    Coder myCoder;

    vector<string> instructions = myParser.parse(filename);

    map<string, string> symbols = myParser.symbolTable(instructions);

    size_t length = filename.size();
    string newfile = filename.substr(0, length - 4);
    newfile += ".hack";

    ofstream myFile(newfile);

    length = instructions.size();

    /*for (size_t i = 0; i < length; i++)
    {
        cout << instructions.at(i) << endl;
    }*/

    for (size_t i = 0; i < length; i++)
    {
        if (myParser.instructionType(instructions.at(i)) == A_INSTRUCTION)
        {
            string out = "0";

            if ((instructions.at(i)[1] == '0') or (instructions.at(i)[1] == '1') or (instructions.at(i)[1] == '2') or (instructions.at(i)[1] == '3') or (instructions.at(i)[1] == '4') or (instructions.at(i)[1] == '5') or (instructions.at(i)[1] == '6') or (instructions.at(i)[1] == '7') or (instructions.at(i)[1] == '8') or (instructions.at(i)[1] == '9'))
            {
                size_t templength = instructions.at(i).size();
                string temp = instructions.at(i).substr(1, templength - 1);
                out += binconverter(temp);
            }

            else
            {
                string symb = myParser.symbol(instructions.at(i));
                string temp = symbols.at(symb);

                out += binconverter(temp);
            }

            myFile << out;
            myFile << endl;

            //cout << "writing a inst" << endl;
        }

        else if (myParser.instructionType(instructions.at(i)) == C_INSTRUCTION)
        {
            string out = "111";
            out += myCoder.writeComp(myParser.comp(instructions.at(i)));

            /*cout << "starting output" << endl;
            cout << "instructions.at(i): " << instructions.at(i) << "test" << endl;
            cout << "myParser.comp(instructions.at(i)): " << myParser.comp(instructions.at(i)) << "test" << endl;
            cout << "myCoder.writeComp(myParser.comp(instructions.at(i))): " << myCoder.writeComp(myParser.comp(instructions.at(i))) << endl; */

            out += myCoder.writeDest(myParser.dest(instructions.at(i)));
            out += myCoder.writeJump(myParser.jump(instructions.at(i)));

            myFile << out;
            myFile << endl;

            //cout << "writing c inst" << endl;
        }

        
    }

    myFile.close();
}
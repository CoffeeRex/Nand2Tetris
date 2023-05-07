#include "Parser.h"
#include "Coder.h"
#include "Assembler.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
    Parser myParser;
    Coder myCoder;
    Assembler myAssembler;

    /*vector<string> instructions = myParser.parse("text.txt");

    cout << instructions.at(0) << endl;
    cout << instructions.at(1) << endl;
    cout << instructions.at(2) << endl;
    cout << instructions.at(3) << endl;*/

    /*cout << myParser.instructionType(instructions.at(2)) << myParser.instructionType(instructions.at(3)) << endl;
    cout << myParser.symbol(instructions.at(2)) << myParser.symbol(instructions.at(3)) << endl;
    cout << myParser.dest(instructions.at(2)) << myParser.dest(instructions.at(3)) << endl;
    cout << myParser.comp(instructions.at(0)) << myParser.comp(instructions.at(1)) << endl;
    cout << myParser.comp(instructions.at(2)) << myParser.comp(instructions.at(3)) << endl;
    cout << myParser.jump(instructions.at(0)) << myParser.jump(instructions.at(1)) << endl;
    cout << myParser.jump(instructions.at(2)) << myParser.jump(instructions.at(3)) << endl;*/

    /*cout << myParser.dest(instructions.at(0)) << " " << myCoder.writeDest(myParser.dest(instructions.at(0))) << endl;
    cout << myParser.dest(instructions.at(1)) << " " << myCoder.writeDest(myParser.dest(instructions.at(1))) << endl;
    cout << myParser.dest(instructions.at(2)) << " " << myCoder.writeDest(myParser.dest(instructions.at(2))) << endl;
    cout << myParser.dest(instructions.at(3)) << " " << myCoder.writeDest(myParser.dest(instructions.at(3))) << endl;

    cout << myParser.comp(instructions.at(0)) << " " << myCoder.writeComp(myParser.comp(instructions.at(0))) << endl;
    cout << myParser.comp(instructions.at(1)) << " " << myCoder.writeComp(myParser.comp(instructions.at(1))) << endl;
    cout << myParser.comp(instructions.at(2)) << " " << myCoder.writeComp(myParser.comp(instructions.at(2))) << endl;
    cout << myParser.comp(instructions.at(3)) << " " << myCoder.writeComp(myParser.comp(instructions.at(3))) << endl;
    
    cout << myParser.jump(instructions.at(0)) << " " << myCoder.writeJump(myParser.jump(instructions.at(0))) << endl;
    cout << myParser.jump(instructions.at(1)) << " " << myCoder.writeJump(myParser.jump(instructions.at(1))) << endl;
    cout << myParser.jump(instructions.at(2)) << " " << myCoder.writeJump(myParser.jump(instructions.at(2))) << endl;
    cout << myParser.jump(instructions.at(3)) << " " << myCoder.writeJump(myParser.jump(instructions.at(3))) << endl;*/

    string filename = argv[1];

    /*vector<string> instructions = myParser.parse(filename);

    cout << instructions.at(5) << instructions.at(5).size() << myParser.comp(instructions.at(5))<< endl;*/
    /*string myString = "1234";
    cout << myString.substr(0,1) << " " << myString.find('2') << endl;

    cout << myString.substr(1) << endl;*/

    myAssembler.assemble(filename);



    /*vector<string> instructions = myParser.parse(filename);

    for (size_t i = 0; i < instructions.size(); i++)
    {
        cout << instructions.at(i) << endl;
    }*/
    
    //cout << myParser.comp("D=A") << " " << myCoder.writeComp(myParser.comp("D=A")) << endl;

    /*map<string, string> myMap;
    myMap.insert(pair<string, string> ("a", "b"));

    cout << myMap.at("a") << myMap.at("b");*/

    /*vector<string> instructions = myParser.parse(filename);

    size_t length = instructions.size();

    cout << int(instructions.at(0)[0]) << endl;

    for (size_t i = 0; i < length; i++)
    {
        cout << instructions.at(i) << endl;
    }*/

    



    
}
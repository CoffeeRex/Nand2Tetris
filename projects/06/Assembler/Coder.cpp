#include "Coder.h"

#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

string Coder::writeDest(string instruction)
{
    set<string> dests = {"A",
        "D",
        "M",
        "AM",
        "AD",
        "MD",
        "AMD", 
        ""};

    map<string, string> strToBin;

    strToBin.insert(pair<string, string> ("A", "100"));
    strToBin.insert(pair<string, string> ("D", "010"));
    strToBin.insert(pair<string, string> ("M", "001"));
    strToBin.insert(pair<string, string> ("AM", "101"));
    strToBin.insert(pair<string, string> ("AD", "110"));
    strToBin.insert(pair<string, string> ("MD", "011"));
    strToBin.insert(pair<string, string> ("AMD", "111"));
    strToBin.insert(pair<string, string> ("", "000"));

    if (dests.count(instruction) > 0)
    {
        return strToBin.at(instruction);
    }

    else
    {
        return "error";
    }
}

string Coder::writeComp(string instruction)
{
    set<string> comps = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A", "D+1", "A+1", "D-1", "A-1", "D+A", "D-A", "A-D", "D&A", "D|A", "M", "!M", "-M", "M+1", "M-1", "D+M", "D-M", "M-D", "D&M", "D|M"};

    map<string, string> strToBin;

    strToBin.insert(pair<string, string> ("0", "0101010"));
    strToBin.insert(pair<string, string> ("1", "0111111"));
    strToBin.insert(pair<string, string> ("-1", "0111010"));
    strToBin.insert(pair<string, string> ("D", "0001100"));
    strToBin.insert(pair<string, string> ("A", "0110000"));
    strToBin.insert(pair<string, string> ("!D", "0001101"));
    strToBin.insert(pair<string, string> ("!A", "0110001"));
    strToBin.insert(pair<string, string> ("-D", "0001111"));
    strToBin.insert(pair<string, string> ("-A", "0110011"));
    strToBin.insert(pair<string, string> ("D+1", "0011111"));
    strToBin.insert(pair<string, string> ("A+1", "0110111"));
    strToBin.insert(pair<string, string> ("D-1", "0001110"));
    strToBin.insert(pair<string, string> ("A-1", "0110010"));
    strToBin.insert(pair<string, string> ("D+A", "0000010"));
    strToBin.insert(pair<string, string> ("D-A", "0010011"));
    strToBin.insert(pair<string, string> ("A-D", "0000111"));
    strToBin.insert(pair<string, string> ("D&A", "0000000"));
    strToBin.insert(pair<string, string> ("D|A", "0010101"));
    strToBin.insert(pair<string, string> ("M", "1110000"));
    strToBin.insert(pair<string, string> ("!M", "1110001"));
    strToBin.insert(pair<string, string> ("-M", "1110011"));
    strToBin.insert(pair<string, string> ("M+1", "1110111"));
    strToBin.insert(pair<string, string> ("M-1", "1110010"));
    strToBin.insert(pair<string, string> ("D+M", "1000010"));
    strToBin.insert(pair<string, string> ("D-M", "1010011"));
    strToBin.insert(pair<string, string> ("M-D", "1000111"));
    strToBin.insert(pair<string, string> ("D&M", "1000000"));
    strToBin.insert(pair<string, string> ("D|M", "1010101"));

    if (comps.count(instruction) > 0)
    {
        return strToBin.at(instruction);
    }
    
    else
    {
        return "error";
    }
}

string Coder::writeJump(string instruction)
{
    set<string> jumps = {"null", "JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};

    map<string, string> stringToBin;

    stringToBin.insert(pair<string, string> ("null", "000"));
    stringToBin.insert(pair<string, string> ("JGT", "001"));
    stringToBin.insert(pair<string, string> ("JEQ", "010"));
    stringToBin.insert(pair<string, string> ("JGE", "011"));
    stringToBin.insert(pair<string, string> ("JLT", "100"));
    stringToBin.insert(pair<string, string> ("JNE", "101"));
    stringToBin.insert(pair<string, string> ("JLE", "110"));
    stringToBin.insert(pair<string, string> ("JMP", "111"));

    if (jumps.count(instruction) > 0)
    {
        return stringToBin.at(instruction);
    }

    else
    {
        return "error";
    }
}
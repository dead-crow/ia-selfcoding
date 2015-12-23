#include <iostream>

using namespace std;

#include "instructionClass.h"

instructionClass::instructionClass(const int& s,const std::string& ns, const std::string& ctxt ){
    start(s);
    end(s);
    Namespace(ns);
    context(ctxt);
    _instructions.clear();
}

instructionClass::instructionClass(const std::string& ns, const std::string& ctxt ){
    start(0);
    end(0);
    Namespace(ns);
    context(ctxt);
    _instructions.clear();
}

instructionClass::~instructionClass(){
    _instructions.clear();
}

std::string instructionClass::instruction(const int& s){
    if(s<0 || s>=(int)_instructions.size())
        throw "[instructionClass::instruction]Out of range.";
    return _instructions.at(s);
}

vector<std::string> instructionClass::instruction(const int& s,const std::string& str){
    if(s<0 || s>=(int)_instructions.size())
        throw "[instructionClass::instruction]Out of range.";
    _instructions.at(s) = str;
    return _instructions;
}

instructionClass* instructionClass::add(const std::string& instruction){
    _instructions.push_back(instruction);
    _end++;
    return this;
}

instructionClass* instructionClass::del(const int& s){
    if(s<0 || s>=(int)_instructions.size())
        throw "[instructionClass::del]Out of range.";
    _instructions.erase(_instructions.begin()+s);
    _end--;
    return this;
}

instructionClass* instructionClass::DEBUG(){
    cout << "L" << _start << " - L" << _end-1 << " " << _namespace << "::" << _context << endl;
    for(std::string s : _instructions)
        cout << s << endl;
    cout << endl;
    return this;
}

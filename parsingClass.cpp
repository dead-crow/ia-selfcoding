#include <iostream>
#include "parsingClass.h"

parsingClass::parsingClass(){
    //ctor
}

parsingClass::parsingClass( parsingClass& p){
    _namespace = p._namespace;
    _context = p._context;
    if(p._contexted_file.good())
        p._contexted_file.close();
    _contexted_file.open(_context, std::fstream::in |  std::fstream::app);
    if(! _contexted_file.good())
        throw "[parsingClass::parsingClass] Le fichier est introuvable";
}

parsingClass::~parsingClass(){
    if(_contexted_file.good())
        _contexted_file.close();
}

parsingClass parsingClass::getContext(const std::string& ctxt){
    if(! _contexted_file.good())
        _contexted_file.open(ctxt, std::fstream::in |  std::fstream::app);
    if(! _contexted_file.good())
        throw "[parsingClass::getContext] Le fichier est introuvable";
    _context = ctxt;
    return (*this);
}

parsingClass parsingClass::inNamespace(const std::string& ns){
    _namespace = ns;
    return *(this);
}

t_instruction parsingClass::searchFunction(const std::string& fonction){
    t_instruction ins(_namespace,_context);
    bool found = false;
    int i = -1, openningbracket=0;

    if(_contexted_file.good())
        _contexted_file.close();
    _contexted_file.open(_context, std::fstream::in |  std::fstream::app);

    string line;
    //considering cpp file
    while(_contexted_file.good() && !found){
        i++;
        getline(_contexted_file,line);
        std::size_t pos = line.find(_namespace+"::"+fonction);
        if(pos==string::npos)
            continue;
        found = true;
        ins.start(i);
        break;
    }
    if(found){
        do{
            ins.add(line);

            std::size_t pos = line.find("{");
            if(pos!=string::npos){
                openningbracket++;
            }
            pos = line.find("}");
            if(pos!=string::npos){
                openningbracket--;
            }
            i++;
            getline(_contexted_file,line);

        }while(_contexted_file.good() && openningbracket!=0);
        ins.end(i);
    }
    _contexted_file.close();

    return ins;
}

t_instruction parsingClass::searchPrototype(const std::string& fonction){
    t_instruction ins(_namespace,_context);
    bool found = false;
    int i = -1;

    if(_contexted_file.good())
        _contexted_file.close();
    _contexted_file.open(_context, std::fstream::in |  std::fstream::app);

    string line;
    //considering h file
    while(_contexted_file.good() && !found){
        i++;
        getline(_contexted_file,line);
        std::size_t pos = line.find(fonction);
        if(pos==string::npos)
            continue;
        found = true;
        ins.start(i);
        break;
    }
    if(found){
        ins.add(line);
        ins.end(++i);
    }
    _contexted_file.close();

    return ins;
}

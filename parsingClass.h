#ifndef PARSINGCLASS_H
#define PARSINGCLASS_H

#include <fstream>
#include <string>

using namespace std;

#include "instructionClass.h"

class parsingClass
{
    public:
        /** Default constructor */
        parsingClass();
        /** Default destructor */
        virtual ~parsingClass();

        parsingClass getContext(const std::string& ctxt);
        parsingClass inNamespace(const std::string& ns);
        t_instruction searchFunction(const std::string& ns);
        t_instruction searchPrototype(const std::string& ns);

    protected:
    private:
        parsingClass( parsingClass& p);
        //friend parsingClass;
        std::string _namespace = "";
        std::string _context = "";
        ifstream _contexted_file;
};

typedef parsingClass t_parsing;

#endif // PARSINGCLASS_H

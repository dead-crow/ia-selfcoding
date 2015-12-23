#ifndef INSTRUCTIONCLASS_H
#define INSTRUCTIONCLASS_H

#include <vector>
#include <string>

using namespace std;

class instructionClass{
    public:
        /** Default constructor */
        instructionClass(const int& s,const std::string& ns, const std::string& ctxt );
        instructionClass(const std::string& ns, const std::string& ctxt );
        /** Default destructor */
        virtual ~instructionClass();

        int start() const{return _start;};
        void start(const int& s) { _start=s;};
        int end() const{return _end;};
        void end(const int& s) { _end=s;};
        std::string Namespace() const{return _namespace;};
        void Namespace(const std::string& s) { _namespace=s;};
        std::string context() const{return _context;};
        void context(const std::string& s) { _context=s;};
        std::string instruction(const int& s);
        vector<std::string> instruction(const int& s,const std::string& str);

        instructionClass* add(const std::string& instruction);
        instructionClass* del(const int& i);

        instructionClass* DEBUG();
    protected:
    private:
        int _start; /**\brief ligne commençant les instructions*/
        int _end; /**\brief ligne terminant les instructions*/
        std::string _namespace; /**\brief nom du fichier*/
        std::string _context; /**\brief nom du fichier*/
        vector<std::string> _instructions;
};

typedef instructionClass t_instruction;

#endif // INSTRUCTIONCLASS_H

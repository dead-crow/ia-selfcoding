#include <iostream>

using namespace std;

#include "instructionClass.h"
#include "parsingClass.h"

int main(){
    t_instruction* code = new t_instruction("instructionClass","instructionClass.cpp");
    code
    ->add("int \"i = 3;")
    ->add("while(i<50){")
    ->add("cout << i++ << endl;")
    ->add("}")
    ->DEBUG();
    code->instruction(2,"afficher(i++);");
    code->DEBUG();
    code
    ->del(3)
    ->add("afficher();")
    ->add("parler();")
    ->add("converser();")
    ->add("}")
    ->DEBUG();

    t_parsing parseur;
    string pattern;
    cout << "pattern : ";
    cin >> pattern;
    *code = parseur.getContext("parsingClass.cpp").inNamespace("parsingClass").searchFunction(pattern);
    t_instruction code2 = parseur.getContext("parsingClass.h").inNamespace("parsingClass").searchPrototype(pattern);

    code->DEBUG();
    code2.DEBUG();


    return 0;
}

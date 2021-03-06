#ifndef _CONST_MACRO_H_
#define _CONST_MACRO_H_

#include "app_conf.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
WF_MSW_DISABLE();

/* Constants definition.
If the variable type is missing, int is assumed */
const int varInt = 3;

/*Macro is a generalization of the constant concept
that gets replaces in the executable at the runtime*/
#define macInt 100

/*Using macros is not a best practice because each macro call
is replaced into the memory with the body of the function
which leads to an increased exe size.*/
/*One advantage of macros is that do not work with specifica
data type. They are like a preistoric generic programming form*/
#define sumMac(a,b) a+b

/* A namespace is designed to overcome this difficulty and is used 
as additional information to differentiate similar functions, classes, 
variables etc. with the same name available in different libraries. 
Using namespace, you can define the context in which names are defined. 
In essence, a namespace defines a scope.  */
namespace const_macro
{
  inline void constPrinting()
  {
    std::cout << "Constant Printigs" << std::endl;
    std::cout << "Constant Int: " << varInt << std::endl;
    std::cout << "Macro Int: " << macInt << std::endl;
    
    std::cout << "\nConstant + 2: " << varInt + 2 << std::endl;
    std::cout << "Constant: " << varInt << std::endl;
    //varInt = varInt + 3; Error, cannot be modified

    std::cout << "\nMacro + 2: " << macInt + 2 << std::endl;
    std::cout << "Macro: " << macInt << std::endl;
    //macInt = macInt + 4; Error, cannot be modified

    std::cout << "\nMacro sum: 2 + 3 = " << sumMac(2, 3) << std::endl;
  }
}

#endif // !CONST_MACRO_H_
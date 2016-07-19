#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <iostream>

/*The typedef-names are aliases for existing types, and are not declarations of new types. 
Typedef cannot be used to change the meaning of an existing type name (including a typedef-name). 
Once declared, a typedef-name may only be redeclared to refer to the same type again. 
Typedef names are only in effect in the scope where they are visible: different functions 
or class declarations may define identically-named types with different meaning.*/

namespace typedefs
{

  typedef int intreg;
  
  typedef struct { int a; int b; } s;

  typedef int int_t, *intp_t, arr_t[10];

  inline void typedefPrinting()
  {
    intreg numI = 3;
    std::cout << "Printing alias for int: " << numI << std::endl;
    numI += 4;
    std::cout << "Printing alias for int + 4: " << numI << std::endl;
    s testS;
    testS.a = 3;
    testS.b = 4;
    std::cout << "Struct with alias: " << testS.a << ", " << testS.b << std::endl;
    std::cout << "Sum with struct elements: " << testS.a + testS.b << std::endl;
  }
}

#endif // !TYPEDEFS_H_
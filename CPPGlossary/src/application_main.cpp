#ifndef _TYPEDEFS_H_
#include "typedefs.hpp"
#endif // !CONST_MACRO_H_

#include "app_conf.hpp"

#include <iostream>

int main(int argc, char** args)
{
  APP_UNSED(argc);
  APP_UNSED(args);

  typedefs::typedefPrinting();
  return 0;
}
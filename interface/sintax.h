#ifndef SINTAX_H
#define SINTAX_H
//#include <string.h> //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
#include <iostream>

class Sintax
{
public:
    bool operator_error(std::string expression);
    bool sintax_error(std::string expression);
    bool bracket_error(std::string expression);
    bool dots_error(std::string expression);
    bool general_sintax_error(std::string expression);
};

#endif // SINTAX_H

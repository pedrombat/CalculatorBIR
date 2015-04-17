#include "isop.h"

bool isop(std::string mystring)
{
    if(mystring == "-" || mystring == "+" || mystring == "/" || mystring == "*")
        return(true);
    else
        return(false);
}

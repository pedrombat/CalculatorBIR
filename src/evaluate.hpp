#ifndef EVALUATE_INCLUDED
#define EVALUATE_INCLUDED
#include "binary_tree.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <regex>

using namespace std;

class Evaluate
{

public:
    
    void evaluatetree(Nodetype* prt);
    bool isop(string mystring);
    
};

#endif // EVALUATE_INCLUDED

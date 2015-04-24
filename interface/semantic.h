#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

#include <iostream>
//#include <deque>
#include <stack>

class Semantic {

public:

bool isop(char mychar);
int priority(char a);

std::deque<std::string> conversion (std::string infix);

};
#endif

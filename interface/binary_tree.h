/*
 * binary_tree.hpp

 *
 *  Created on: 08/04/2015
 *      Author: vitorvarandas
 */

#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_

#include <iostream>

//#include <string>   //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <stdlib.h> //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <math.h>   //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <sstream>  //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.

class Nodetype
{
public:
    std::string data;
    Nodetype *left_child;
    Nodetype *right_child;
    Nodetype(std::string k);

};


class Binarytree
{

public:
    Nodetype *root;
    void print(Nodetype *r); // Postfix traversal
    Binarytree(void) { root = NULL;}
    struct Nodetype* insert(Nodetype *node, std::string data);
    void clear_help(Nodetype* rt); // destructor
    void clear(){ clear_help(root);};
    bool isinright = false;         //PEDRO acrescentou.

};


#endif /* BINARY_TREE_HPP_ */

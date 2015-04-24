/*
 * binary_tree.cpp
 *
 *  Created on: 13/04/2015
 *      Author: vitorvarandas
 */

#include "binary_tree.h"
//#include "evaluate.h"
#include "isop.h"

#include <iostream>  //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
#include <string>    //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
#include <sstream>   //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
#include <stdlib.h>  //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
#include <math.h>    //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.

Nodetype::Nodetype(std::string k)
{
    data=k;
    left_child = NULL;
    right_child = NULL;
}

Nodetype *build_node(std::string x) //build a new node for the tree
{
    Nodetype *new_node;
    new_node = new Nodetype(x);
    return(new_node);
}

struct Nodetype* Binarytree::insert(Nodetype *node, std::string data)
{
isinright=false;
    //bool checkInsert = false; //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
    if(node==NULL) {
        // checkInsert = true; //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
        isinright = true;
        return (build_node(data));}
    else
    {
        if(isop(node->data)){

            node->right_child=insert(node->right_child,data);
            //std::cout<<"2"<<node->right_child->data<<std::endl;

            if(isinright==false){
                node->left_child=insert(node->left_child,data);
                // std::cout<<"3"<<node->left_child->data<<std::endl;

            }
        }
    }
    return node;
}



void Binarytree::clear_help(Nodetype* rt) // destructor
{
    if( rt != NULL )
    {
        clear_help( rt->left_child);
        clear_help( rt->right_child);
        delete rt;
    }

}

void Binarytree::print (Nodetype *p) //postfix traversal
{
    if(p != NULL)
    {
        print(p->left_child);
        print(p->right_child);
        std::cout << p->data << " ";
    }
}

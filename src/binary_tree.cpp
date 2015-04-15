/*
 * binary_tree.cpp
 *
 *  Created on: 13/04/2015
 *      Author: vitorvarandas
 */
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include "binary_tree.hpp"
#include "evaluate.hpp"


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
bool checkInsert;
Evaluate check;
struct Nodetype* Binarytree::insert(Nodetype *node, std::string data)
{

		if(node==NULL) {
			checkInsert = true;
			//std::cout<<"1"<<std::endl;
			return (build_node(data));}
		 else
		    {
                if(check.isop(node->data)){
						 node->right_child=insert(node->right_child,data);
						 //std::cout<<"2"<<node->right_child->data<<std::endl;
						 if(!checkInsert){
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




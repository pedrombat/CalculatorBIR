/*
 * evaluate.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: gustavo
 */
#include "evaluate.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <regex>
#include "binary_tree.hpp"
using namespace std;

bool Evaluate::isop(std::string mystring)
{
    if(mystring == "-" || mystring == "+" || mystring == "/" || mystring == "*" || mystring == "^")
        return(true);
    else
        return(false);
}

void Evaluate::evaluatetree(Nodetype* prt)
{

    if(isop(prt->data) && !isop(prt->right_child->data) && !isop(prt->left_child->data))
    {
        double num;
        double num2 = atof(prt->right_child->data.c_str());
        double num1 = atof(prt->left_child->data.c_str());
        if(prt->data == "+")
        {
            num = num1 + num2;
        }
        else if (prt->data == "-")
        {
            num = num1 - num2;
        }
        else if(prt->data == "/")
        {
            num = num1 / num2;
        }
        else if (prt->data == "*")
        {
            num = num1 * num2;
        }

        stringstream ss;
        string result;
        ss << num;
        ss >> result;
        prt->data = result;
        prt->left_child = NULL;
        prt->right_child = NULL;

       // cout<<"Resultado = "<< result <<endl;

    }
    else if(prt->left_child == NULL && prt->right_child == NULL);
    else
    {
        evaluatetree(prt->left_child);
        evaluatetree(prt->right_child);
        evaluatetree(prt);
    }
}


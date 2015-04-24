/*
 * evaluate.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: gustavo
 */


//#include <string>     //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <math.h>     //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <algorithm>  //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <regex>      //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.
//#include <iostream>   //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.

#include "isop.h"
#include <stdlib.h>
#include <sstream>
#include "binary_tree.h"
#include "evaluate.h"

//using namespace std;  //PEDRO TIROU POIS NÃO TEM PQ ESTA AQUI.



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
            if(num2==0){                                //PEDRO COLOCOU.
                divisionforzero = true;
            }
            num = num1 / num2;
        }
        else if (prt->data == "*")
        {
            num = num1 * num2;
        }

        std::stringstream ss;
        std::string result;
        ss << num;
        ss >> result;
        prt->data = result;
        prt->left_child = NULL;
        prt->right_child = NULL;

if(divisionforzero){                             //PEDRO COLOCOU.
    prt->data ="Error: Division By Zero";
    return;
}
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

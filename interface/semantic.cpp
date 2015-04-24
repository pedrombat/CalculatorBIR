#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include "semantic.h"

using namespace std;

bool Semantic::isop(char mychar)
{
    if(mychar == '-' || mychar == '+' || mychar == '*' || mychar == '/' || mychar == '^' || mychar == '\0')
        return(true);
    else
        return(false);
}
int Semantic::priority(char a){
    int b;
    if (a == '^')
        b = 1;
    else if (a == '/' || a == '*')
        b = 2;
    else if (a == '+' || a == '-')
        b = 3;
    return b;
}


std::deque<std::string> Semantic::conversion (std::string infix){

    stack<char> pilha;
    deque<string> node;
    std::string temp1, temp2;
    stringstream resultado,temp;
    int aux, aux3=0;

    for(unsigned int i = 0;i<infix.length();i++){
        if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') && (i!=0 && aux3 ==0)){
            while(!pilha.empty() && priority(pilha.top()) <= priority(infix[i])){
                temp << pilha.top();
                temp >> temp2;
                node.push_back(temp2);
                pilha.pop();
                temp.clear();
                temp2.clear();
            }
            pilha.push(infix[i]);
        }
        else if (infix[i] == '(') {
            pilha.push(infix[i]);
            if(isop(infix[i+1])){
                aux3=1;
            }
        } else if (infix[i] == ')') {
            while (pilha.top() != '(') {
                temp << pilha.top();
                temp >> temp2;
                node.push_back(temp2);
                pilha.pop();
                temp.clear();
                temp2.clear();
            }
            pilha.pop();
        } else {
            for(unsigned int j=i; j<infix.size(); ++j){
                temp1 = temp1 + infix[j];
                if(isop(infix[j+1]) || infix[j+1] == '(' || infix[j+1] == ')'){
                    aux = j-i;
                    j = infix.size();
                    i=i+aux;
                    node.push_back(temp1);
                    temp1.clear();
                    aux3 = 0;
                }
            }
        }
    }
    while (!pilha.empty()) {
        if(isop(pilha.top())){
        temp << pilha.top();
        temp >> temp2;
        node.push_back(temp2);
        temp.clear();
        temp2.clear();
        }
        pilha.pop();
    }
return node;
}

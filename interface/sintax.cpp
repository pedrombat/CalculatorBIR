#include "sintax.h"


using namespace std;

bool Sintax::operator_error(std::string expression)
{
    if(expression[expression.size()-1]=='-'|| expression[expression.size()-1]=='+'||                  //1st check, operator at the end of the sentence
            expression[expression.size()-1]=='/'|| expression[expression.size()-1]=='*')
    {

   //     std::cout<< "ERROR, operator in the end of the sentence: "<<expression[expression.size()-1]<<std::endl;
        return false;
    }

    if(expression[0]=='+'||expression[0]=='/'||expression[0]=='*')                                      //2nd check, operator at the beggining of the sentence
    {
   //     std::cout<<"ERROR, operator at the beginning of the sentence: "<< expression[0] <<std::endl;
        return false;
    }

    for(unsigned int i=0; i<expression.size(); ++i)
    {
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/')                            //3rd check, two operators together
        {
            if(expression[i+1]=='+'||expression[i+1]=='-'||expression[i+1]=='*'||expression[i+1]=='/')
            {
    //            std::cout<<"ERROR, two operator together:  "<<expression[i]<<expression[i+1]<<std::endl;
                return false;
            }
        }

    }
    return true;
}

bool Sintax::sintax_error(string expression)
{
    for(unsigned int i=0; i<expression.size(); ++i)
    {
        if(     expression[i]!='9' && expression[i]!='8' && expression[i]!='7' && expression[i]!='6' &&            //3rd check, diferent kind of charactere
                expression[i]!='5' && expression[i]!='4' && expression[i]!='3' && expression[i]!='2' &&
                expression[i]!='1' && expression[i]!='0' && expression[i]!='+' && expression[i]!='-' &&
                expression[i]!='*' && expression[i]!='/' && expression[i]!='(' && expression[i]!=')' &&
                expression[i]!=',' && expression[i]!='.')
        {
       //     std::cout<<"ERROR, please type a number among these:  9 8 7 6 5 4 3 2 1 0 + - * / ) ( . "<<std::endl;
            return false;
        }
    }
    return true;
}

bool Sintax::bracket_error(string expression)
{
    int countbracket=0;

    for(unsigned int i=0; i<expression.size(); ++i)
    {
        if(expression[i]=='(')
        {
            countbracket++;
        }
        if(expression[i]==')')
        {
            countbracket--;
        }

        if(expression[i]=='(')                                                                                      //4th check, just operator in the bracket(openning)
        {
            if(expression[i+1]=='+'||expression[i+1]=='*'||expression[i+1]=='/')
            {
           //     std::cout<< "ERROR, operator after the opening bracket! "<<expression[i+1]<<std::endl;
                return false;
            }
        }
        if(expression[i]==')')
        {
            if(expression[i-1]=='+'||expression[i-1]=='-'||expression[i-1]=='*'||expression[i-1]=='/')              //5th check,just operator in the bracket(closing)
            {
          //      std::cout<<"ERROR, operator before the close bracket! "<<expression[i-1]<<std::endl;
                return false;
            }
        }

        if(expression[i]=='(')                                                                                      //6th check, number before bracket
        {
            if(i>0 && expression[i-1]!='+'&& expression[i-1]!='-'&& expression[i-1]!='*'
                    && expression[i-1]!='/' && expression[i-1]!='(' )
            {

          //      std::cout<< "ERROR, number before bracket!"<<std::endl;
                return false;
            }
        }

        if(expression[i]==')')                                                                                      //7th check, number after bracket
        {
            if(i>0 && expression[i+1]!='+'&& expression[i+1]!='-'&& expression[i+1]!='*'
                    && expression[i+1]!='/' && expression[i+1]!=')' && expression[i+1]!='\0')
            {
          //      std::cout<< "ERROR, number after bracket!"<<std::endl;
                return false;
            }
        }

    }

    if(countbracket<0)                                                                                              //8th check, just the closing bracket
    {
    //    std::cout<< "ERROR,  need to open a bracket"<<std::endl;
        return false;
    }

    if(countbracket!=0)                                                                                             //9th check, just the closing bracket
    {
   //     std::cout<<"ERROR, need to close a bracket"<<std::endl;
        return false;
    }
    return true;
}

bool Sintax::dots_error(string expression)
{

    for(unsigned int i=0; i<expression.size(); ++i)
    {
        if(expression[i]==',' || expression[i]=='.')                                      //10th check, 2 or more dots in one number
        {
            for(unsigned int j = i+1; j<expression.size(); ++j)
            {
                if(expression[j]=='+'||expression[j]=='-'||expression[j]=='*'
                        ||expression[j]=='/'||expression[j]=='('||expression[j]==')')
                {

                    break;
                }
                else if(expression[j]==','|| expression[j]=='.' )
                {
         //           std::cout<< "ERROR, two or more dots in the same number!"<<std::endl;
                    return false;

                }
            }

            for(int j = i-1; j>0; --j)
            {
                if(expression[j]=='+'||expression[j]=='-'||expression[j]=='*'
                        ||expression[j]=='/'||expression[j]=='('||expression[j]==')')
                {

                    break;
                }
                else if(expression[j]==','|| expression[j]=='.' )
                {
         //           std::cout<< "ERROR, two or more dots in the same number!"<<std::endl;
                    return false;

                }
            }

        }
    }
    return true;
}

bool Sintax::general_sintax_error(string expression)
{
    if(Sintax::operator_error(expression) == true)
    {
        if(Sintax::sintax_error(expression) == true)
        {
            if(Sintax::bracket_error(expression) == true)
            {
                if(Sintax::dots_error(expression) == true)
                {
                    return true;
                }

            }

        }
    }

    return false;
}

#include <iostream>
#include <stack>
//#include <string>
#include <sstream>
using namespace std;

//std::string saveextenso (std::string infix, int i){
//
//	std::string xnumber;
//
//	for (int j = 0; j < infix.length(); ++j) {
//
//		xnumber = xnumber + infix[j];
//
//		if(infix[j+1] == '+' || infix[j+1] == '-' || infix[j+1] == '*' || infix[j+1] == '/' || infix[j+1] == '\0'){
//			j = infix.length;
//		}
//	}
//	return xnumber;
//}

int priority(char a){
	int b;
	if (a == '^')
		b = 1;
	else if (a == '/' || a == '*')
		b = 2;
	else if (a == '+' || a == '-')
		b = 3;
	return b;
}

int main(){

	string infix,temp2;
	cout<<"Digite a expressao :"<<endl;
	cin>>infix;

//	#################################                                 ########################
//                                  ##########################################################
//	##################################################################

//
//	std::deque<std::string> symboldeque;
//	std::deque<std::string> numberdeque;
//
//	std::string number;
//	std::string symbol;
//
//	for (unsigned int i = 0; i <= infix.length(); ++i) {
//		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '\0'){
//
//			std::cout << "symbol" << std::endl;
//
//			symbol = symbol + infix[i];
//
//			std::cout<< "the number is " << number << std::endl;
//			numberdeque.push_back(number);
//			number.clear();
//		}
//		else{
//			std::cout << "not a symbol " << std::endl;
//
//			number = number + infix[i];
//
//			if(symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" ){
//				std::cout << "the symbol is " << symbol << std::endl;
//				symboldeque.push_back(symbol);
//				symbol.clear();
//			}
//		}
//	}



//	#################################                                 ########################
//                                  ##########################################################
//	##################################################################

	stack<char> pilha;
	deque<string> node;

	stringstream resultado,temp;

	for(unsigned int i = 0;i<infix.length();i++){
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^' ){
			while(!pilha.empty() && priority(pilha.top()) <= priority(infix[i])){
				temp << pilha.top();
				temp >> temp2;
				node.push_back(temp2);       //aqui ele salva numero
				pilha.pop();
				temp.clear();
				temp2.clear();
			}
			pilha.push(infix[i]);
		}
		else if (infix[i] == '(') {
			pilha.push(infix[i]);
		} else if (infix[i] == ')') {
			while (pilha.top() != '(') {
				temp << pilha.top();
				temp >> temp2;
				node.push_back(temp2);         //aqui ele tambem salva numero
				pilha.pop();
				temp.clear();
				temp2.clear();

			}
			pilha.pop();
		} else {
			temp << infix[i];
			temp >> temp2;
			node.push_back(temp2);             //aqui ele tambem salva numero
			temp.clear();
			temp2.clear();
		}
	}
	while (!pilha.empty()) {
		temp << pilha.top();
		temp >> temp2;
		node.push_back(temp2);                // aqui ele tambem salva
		pilha.pop();
		temp.clear();
		temp2.clear();
	}

	std::deque<std::string> pOsTfIx;

	for(unsigned int j=0; j<infix.size();++j){
		std::cout<<"A expressao pos fixa e igual a = "<<node.back()<<std::endl;
		pOsTfIx.push_front(node.back());
		node.pop_back();
	}


	std::cout << "a expressao pPoStFiX eh: " << std::endl;
	for (unsigned int fnl = 0; fnl < infix.length(); ++fnl){
	std::cout << pOsTfIx.at(fnl);

	}


return 0;

}

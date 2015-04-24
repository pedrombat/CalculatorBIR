#include "interface.h"
#include "sintax.h"
#include "binary_tree.h"
#include "evaluate.h"
#include "semantic.h"

int main(int argc, char *argv[])
{

    if(argc==1){
        open_interface(argc, argv);

    }else{

    for(int i=1;i<argc;++i){
//std::string str("5+6*8/7.5");//5 6 8 * 7.5 / +

Sintax sinta;
Semantic semanti;
Evaluate eval;
Binarytree etree;
Nodetype *root=NULL;
std::deque<std::string> vetor;
std::string result;
bool isnoterror=sinta.general_sintax_error(argv[i]);
if(isnoterror){
   vetor = semanti.conversion(argv[i]);

    for(int i=vetor.size()-1;i>=0;--i){
        root=etree.insert(root,vetor[i]);
       // std::cout<<vetor[i]<<std::endl;

    }
  //  std::cout << "Postfix traversal: "<<std::endl;
  //  etree.print(root);
    eval.evaluatetree(root);
    result = root->data;
    std::cout << " \n Result "<< i << " :"<< result << std::endl;
}else{
    std::cout << " \n Result "<< i << " : Error!"  << std::endl;
}

    }
}
}

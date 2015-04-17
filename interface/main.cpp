#include "interface.h"
#include "sintax.h"
#include "binary_tree.h"
#include "evaluate.h"

int main(int argc, char *argv[])
{

    if(argc==1){
        open_interface(argc, argv);

    }else{

        Evaluate eval;
        Binarytree etree;
        Nodetype *root=NULL;


        root = etree.insert(root,"*");
        root = etree.insert(root,"5");
        root = etree.insert(root,"5,5");
        //    root = etree.insert(root,"5");
        //    root = etree.insert(root,"*");
        //    root = etree.insert(root,"4");
        //    root = etree.insert(root,"2");

        std::cout << "Postfix traversal: "<<std::endl;

        etree.print(root);

        eval.evaluatetree(root);
        std::cout << " \n Result: " << root->data << std::endl;

    }




}

#include <iostream>
#include <fstream>
#include "node.h"
#include "traversals.h"
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]) {

        /* Variable Declarations */
        FILE *f;
        char keyboard[1000];
        ofstream kb;
        //Switch statement to handle command line arguments
        buildTree(f);
        /*
        switch(argc) {
                case 1:
                        //open the kb file "out.txt"
                        kb.open("out.txt");
                        cout << "Text to enter into the file: ";
                        //Read from command line until simulated EOF
                        while (fgets(keyboard, 1000, stdin) != NULL) {
                                //Write to the out.txt file
                                kb << keyboard;
                        }
                        kb.close();
                        break;
                case 2:
                        //Read from a file given in the Command Line
                        if ((f = fopen(argv[1], "r")) == NULL) {
                                cout << "Cannot open input file." << endl;
                                exit(1);
                        }
                        else {
                                //do stuff
                                //node_t *root = buildTree(f);

                                //levelOrder(root);
                                //preOrder(root);
                                //postOrder(root);

                        }
                default:
                        cout << "Fatal: Improper usage. Usage: P0 [filename]" << endl;
                        exit(0);
        }
        */

        return 0;
}
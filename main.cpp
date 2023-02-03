#include <iostream>
#include <fstream>
#include "node.h"
#include "traversals.h"
#include "buildTree.h"

using namespace std;

int main(int argc, char* argv[]) {

        /* Variable Declarations */
        FILE *mainIn; 
        ofstream kb;
        char whileChar;
        string whileString = "";
        //Switch statement to handle command line arguments
        string filename = "out";
        switch(argc) {
                case 1:
                        kb.open("out");
                        cout << "Text to enter into the file: ";
                        //Read from command line until simulated EOF

                        while ((whileChar = getchar()) != EOF) {
                                if ((static_cast<int>(whileChar) > 122 || static_cast<int>(whileChar) < 97) && !isspace(whileChar)) {
                                        cout << "Error. Invalid character detected.";
                                        exit(1);
                                }
                                whileString += whileChar;
                        }
                        kb << whileString;
                        kb.close();
                        break;
                case 2:
                        //Read from a file given in the Command Line
                        if ((mainIn = fopen(argv[1], "r")) == NULL) {
                                cout << "Cannot open input file." << endl;
                                exit(1);
                        }
                        else {
				filename = argv[1];
                        }
			break;
                default:
                        cout << "Fatal: Improper usage. Usage: P0 [filename]" << endl;
                        exit(0);
        }
        struct node* build = buildTree(filename);
	traverseInOrder(build, 0, filename);
	traversePreOrder(build, 0, filename);
	traverseLevelOrder(build, 0, filename);
        return 0;
}

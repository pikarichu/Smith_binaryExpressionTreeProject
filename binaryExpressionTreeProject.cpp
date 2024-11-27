#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include "binaryExpressionTree.h"
//#include "binaryTree.h"

using namespace std;
string postfix_1 = "35 27 + 3 *";
string postfix_2 = "23 30 15 * /";
string postfix_3 = "34 24 12 7 / * + 23 -";
string postfix_4 = "3 7 + 14 *";
string postfix_5 = "3 7 + 14 *";

string expressions[4] = {"35 27 + 3 *", "23 30 15 * /", "34 24 12 7 / * + 23 -", "3 7 + 14 *"};



int main()
{
    binaryExpressionTree *Tree = new binaryExpressionTree();
    ifstream pfFile("RpnData.txt");
    ofstream outFile("results.txt");
    string line;

    if (pfFile.is_open())
    {
        while (getline(pfFile, line))
        {
            Tree->buildExpressionTree(line);
            double output = Tree->evaluateExpressionTree();
            cout << "output = " << output << endl;
          
            string outLine = line + " = " + to_string(output);
            outFile << outLine << endl;
            Tree->destroyTree();
        }
        pfFile.close();
        outFile.close();

    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
 

}



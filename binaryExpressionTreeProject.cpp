#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "binaryExpressionTree.h"
#include "binaryTree.h"

using namespace std;
binaryExpressionTree *Tree;
string postfix_1 = "35 27 + 3 *";
string postfix_2 = "23 30 15 * /";
string postfix_3 = "34 24 12 7 / * + 23 -";
string postfix_4 = "3 7 + 14 *";
string postfix_5 = "3 7 + 14 *";

string expressions[4] = {"35 27 + 3 *", "23 30 15 * /", "34 24 12 7 / * + 23 -", "3 7 + 14 *"};


/*vector<string> tokenizePostfix(const string& expression) {
    vector<string> tokens;
    string currentToken;

    for (char c : expression) {
        if (isspace(c)) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        }
        else if (isdigit(c)) {
            currentToken += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
            tokens.push_back(string(1, c));
        }
        else {
            // Handle invalid characters or unexpected tokens
            cerr << "Invalid character: " << c << endl;
            return vector<string>();
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    cout << tokens[0] << endl;
    return tokens;
}*/

int main()
{
    //binaryExpressionTree Tree;

    Tree->buildExpressionTree(postfix_3);
    /*vector<string> tokens;
    for (int i = 0; i < 4; i++)
    {
        
        tokens = tokenizePostfix(expressions[i]);

        for (const string& token : tokens) {
            cout << token << " : ";
        }
        cout << endl;
    }*/
    //char* expression = new char[postfixExpression.length() + 1];
    //strcpy(expression, postfixExpression.c_str());
}
/*int main() {
    string expression = "2 3 + 4 *";

    vector<string> tokens = tokenizePostfix(expression);

    for (const string& token : tokens) {
        cout << token << endl;
    }

    return 0;
}*/


#pragma once
#ifndef H_binaryExpressionTree 
#define H_binaryExpressionTree

#include "binaryTree.h"
#include <stack>
#include <vector>
#include <cstring>
//#include <cctype>


using namespace std;



class binaryExpressionTree : public binaryTreeType<string>
{
public:

	void buildExpressionTree(string postFixExpression)
	{
        cout << "Size of postFixExpression: " << sizeof(postFixExpression) << endl;
        cout << "postFixExpression Length : " << postFixExpression.length() << endl;

        stack<nodeType<string>*> eStack;

        char* expression = new char[postFixExpression.length() + 1];

        cout << "Size of expression: " << sizeof(expression) << endl;
        strcpy(expression, postFixExpression.c_str());
        string currentToken;
        cout << expression << endl;
        char c;
        //for (char c : expression) {
        cout << "sizeof(expression): " << sizeof(expression) << endl;
        for (int i = 0; i < postFixExpression.length(); i++) {
            c = expression[i];
            if (isspace(c)) {
                if (!currentToken.empty()) {
                    nodeType<string>* newNode;

                    newNode = new nodeType<string>;

                    cout << currentToken << endl;
                    newNode->info = string(currentToken);
                    newNode->lLink = nullptr;
                    newNode->rLink = nullptr;
                    cout << "Number newNode->info " << newNode->info << endl;

                    eStack.push(newNode);
                    currentToken.clear();
                    cout << endl << endl;

                }
            }
            else if (isdigit(c)) {
                currentToken += c;
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                nodeType<string>* newNode;
                newNode = new nodeType<string>;
                newNode->info = c;
                newNode->lLink = nullptr;
                newNode->rLink = nullptr;
                cout << c << endl;
                if (!eStack.empty()) {
                    //nodeType<string> temp;

                    //cout << "eStack.top().info " << eStack.top()->info << endl;
                    if (!eStack.empty()) {

                        newNode->rLink = eStack.top();
                        //cout << "eStack.top().info " << eStack.top()->info << endl;
                        eStack.pop();

                        if (!eStack.empty()) {

                            //eStack.pop();
                            newNode->lLink = eStack.top();
                            eStack.pop();

                            eStack.push(newNode);

                            currentToken.clear();
                            //root->insert(temp.info);
                            cout << "operator newNode->info " << newNode->info << endl;

                            cout << "operator newNode->rLink " << newNode->rLink->info << endl;
                            cout << "operator newNode->lLink " << newNode->lLink->info << endl;
                            cout << endl << endl;


                        }
                        else
                            cerr << "Error: Stack is empty" << endl;
                    }
                    else
                    {
                        cerr << "Error: Stack is empty" << endl;
                        //currentToken.clear();
                    }
                }
                else
                    cerr << "Unsupported token" << endl;
                    //cout << "Unsupported token" << endl;
            }
            else {
                // Handle invalid characters or unexpected tokens
                cout << "Invalid character: " << c << endl;
            }
        }
        //cout << eStack.top().lLink->info << endl;
        //nodeType<string>* tempNode = &eStack.top();
        //cout << "Left Value:" << tempNode->lLink->info << endl;
        //cout << "Right Value:" << tempNode->rLink->info << endl;
        if (!eStack.empty()) {
            cout << eStack.top()->info << endl;
            cout << eStack.top()->lLink->info << endl;
            cout << eStack.top()->rLink->info << endl;

            root = eStack.top();
            //tree = eStack.top();
            //tree->insert(*eStack.top());
            //this->copyTree(root, eStack.top());
            cout << "It worked!!" << endl;
            eStack.pop();
            if (!eStack.empty()) {
                cerr << "There was an error" << endl;
                root = NULL;
            }

        }

	}

	double evaluateExpressionTree()
	{
		//evaluateExpressionTree(root);
	}

	bool search(const string&)
	{

	}

	void insert(const string&)
	{

	}

	void deleteNode(const string&)
	{

	}

    binaryExpressionTree(string&)
    {

    }

  

    binaryExpressionTree(const binaryExpressionTree& otherTree);
    //Copy constructor

    binaryExpressionTree(string);

    ~binaryExpressionTree()
    {

    }
    //Destructor

private:
	
    string thisExpression;
    //binaryTreeType<string> *tree;
    //tree = new binaryTreeType<string>;
    //binaryTreeType<string>* temp;

	double evaluateExpressionTree(nodeType<string>* postFixExpression)
	{
        //nodeType<string>* p;

	}

};

binaryExpressionTree::binaryExpressionTree(const binaryExpressionTree& otherTree)
{

}

binaryExpressionTree::binaryExpressionTree(string expression)
{
    buildExpressionTree(expression);
    //tree = new binaryTreeType<string>();
    //thisExpression = expression;
    //nodeType<string> root = expression;
    //stack<string> thisStack;
}



#endif
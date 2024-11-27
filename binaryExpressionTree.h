#pragma once
#ifndef H_binaryExpressionTree 
#define H_binaryExpressionTree

#include "binaryTree.h"
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

class binaryExpressionTree : public binaryTreeType<string>
{
public:

    virtual void binaryTreeType() {};

    virtual void binaryTreeType(string exp)
    {
        binaryTreeType(exp);
    }

	void buildExpressionTree(string postFixExpression)
	{

        //cout << "Size of postFixExpression: " << sizeof(postFixExpression) << endl;
        //cout << "postFixExpression Length : " << postFixExpression.length() << endl;

        stack<nodeType<string>*> eStack;

        char* expression = new char[postFixExpression.length() + 1];

        //cout << "Size of expression: " << sizeof(expression) << endl;
        strcpy(expression, postFixExpression.c_str());
        string currentToken;
        cout << expression << endl;
        char c;
        //cout << "sizeof(expression): " << sizeof(expression) << endl;
        for (int i = 0; i < postFixExpression.length(); i++) {
            c = expression[i];
            if (isspace(c)) {
                if (!currentToken.empty()) {
                    nodeType<string>* newNode;

                    newNode = new nodeType<string>;

                    //cout << currentToken << endl;
                    newNode->info = string(currentToken);
                    newNode->lLink = nullptr;
                    newNode->rLink = nullptr;
                    //cout << "Number newNode->info " << newNode->info << endl;

                    eStack.push(newNode);
                    currentToken.clear();
                    //cout << endl << endl;

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
                //cout << c << endl;
                if (!eStack.empty()) {

                    if (!eStack.empty()) {

                        newNode->rLink = eStack.top();
                        eStack.pop();

                        if (!eStack.empty()) {
                            newNode->lLink = eStack.top();
                            eStack.pop();
                            eStack.push(newNode);
                            currentToken.clear();
                            //root->insert(temp.info);

                            //cout << "operator newNode->info " << newNode->info << endl;
                            //cout << "operator newNode->rLink " << newNode->rLink->info << endl;
                            //cout << "operator newNode->lLink " << newNode->lLink->info << endl;
                            //cout << endl << endl;
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

        if (!eStack.empty()) {
            //cout << eStack.top()->info << endl;
            //cout << eStack.top()->lLink->info << endl;
            //cout << eStack.top()->rLink->info << endl;

            root = eStack.top();

            //cout << "It worked!!" << endl;
            eStack.pop();
            if (!eStack.empty()) {
                cerr << "There was an error" << endl;
                root = nullptr;
            }

        }

	}

    double evaluate(nodeType<string>*);

	double evaluateExpressionTree()
	{
        double result = evaluate(root);
        //cout << "result = " << result << endl;
		return evaluate(root);
	}

    bool search(const string& searchItem) const override
    {
        return true;
    }

	void insert(const string&) override
	{

	}

	void deleteNode(const string&) override
	{

	}

    binaryExpressionTree()
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
    double evaluateExpressionTree(nodeType<string>* root)
    {

        return(evaluate(root));

    }
};

binaryExpressionTree::binaryExpressionTree(const binaryExpressionTree& otherTree)
{

}

binaryExpressionTree::binaryExpressionTree(string expression)
{
    buildExpressionTree(expression);
}

double binaryExpressionTree::evaluate(nodeType<string>* p)
{
    double x, y;
    string op;

    if (p->lLink == NULL &&  p->rLink == NULL)
    {
        return stod(p->info);
    }
    else
    {
        op = p->info;
        x = evaluate(p->lLink);
        y = evaluate(p->rLink);
        if (op == "+")
        {
            //cout << "+" << endl;
            return (x + y);
        }
        else if (op == "-")
        {
            //cout << "-" << endl;
            return (x - y);
        }
        else if (op == "*")
        {
            //cout << "*" << endl;
            return (x * y);
        }
        else if (op == "/")
        {
            //cout << "/" << endl;
            return (x / y);
        }
        else
        {
            cout << "Error";
            return 0;
        }

    }

}


#endif
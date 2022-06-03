#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOperand(char x) {
	return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

bool IsOperator(char C) {
	if (C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}

int GetOperatorWeight(char op) {

	int weight = -1;
	switch (op) {
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2) {

	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);
	if (op1Weight == op2Weight) {
		if (op1 == '*' || op1 == '/')
			return true;
		else
			return false;
	}
	return op1Weight > op2Weight ? true : false;
}

string infixToPostfix(string expression) {

	stack<char> S;
	string postfix = "";

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ' || expression[i] == ',') continue;
		else if (isOperand(expression[i]))
			postfix += expression[i];
		else if (expression[i] == '(')
			S.push(expression[i]);
		else if (expression[i] == ')') {
			while (!S.empty() && S.top() != '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
		else {
			while (!S.empty() && S.top() != '(' &&
				HasHigherPrecedence(S.top(), expression[i])) {
				postfix += S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
	}

	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	return postfix;

}

int main() {

	string s;

	cout << "Enter Expression: ";
	//getline(cin, s);
	cin >> s;

	string postfix = infixToPostfix(s);

	cout << "the input before the fixing: " + s << endl;
	cout << "the input after the fixing: " + postfix << endl;

	if (postfix == s)
		cout << "\n\n So we can say that the input is valid";
	else
		cout << "\n\nSo we can say that the input is not valid";

	return 0;
}


//Pseudo Code :
//
//Input: an infix expression
//Output : a postfix expression
//Begin
//if the given infix expression is empty
//then, output "No expression" and stop
//else
//instantiate a stack
//for each character ch in the given infix expression do
//if ch is an operand
//then add it to the postfix expression
//else if ch is '('
//then push it into the stack
//else if ch is ')'
//then
//while the stack is not empty and top of the stack is not '(' do
//pop the element from the stack and add it to the postfix expression
//end while
//if the stack is empty
//then output "Invalid Expression" and stop
//else
//pop the element from the stack
//else
//while the stack is not empty and top of the stack is not '(' and top of the stack has same or higher precedence than ch do
//pop the element from the stackand add it to the postfix expression
//end while
//push ch into the stack
//end for
//while the stack is not empty do
//pop the element from the stackand add it to the postfix expression
//end while
//output the postfix expression
// 
// check if the old expression equals to the new expression then its valid any thing else it will not be valid
//
//End
//
//Explanation:The given infix expression is first converted to a postfix expression.Then, the postfix expression is evaluated to get the final result.

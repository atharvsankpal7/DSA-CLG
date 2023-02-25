/*Prefix Evaluation
One way to evaluate a prefix expression is to use a queue. To evaluate the expression, scan it repeatedly until you know the final
expression value. In each scan read the tokens and store them in a queue. In each scan replace an operator that is followed by
two operands with their calculated values.
For example, the following expression is a prefix expression that is evaluated
to 159:
 - + * 9 + 2 8 * + 4 8 6 3
We scan the expression and store it in a queue. During the scan when an operator is followed by two operands, such as + 2 8, we
put the result, 10, in the queue.
After the first scan, we have
 - + * 9 10 * 12 6 3
After the second scan, we have
 - + 90 72 3
After the third scan, we have
 - 162 3
After the fourth scan, we have
 159*/
// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
	// If the character is a digit then it must
	// be an operand
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		// Push operand to Stack
		// To convert exprsn[j] to digit subtract
		// '0' from exprsn[j].
		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			// Operator encountered
			// Pop two elements from Stack
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 Or o2.
			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}

// Driver code
int main()
{
	string exprsn = "+9*26";
	printf("%d",evaluatePrefix(exprsn));
	return 0;
}

#ifndef EVALUATOR__
#define EVALUATOR__

#include <string>

namespace Evaluator
{
	int applyOperatorToTwoNums(const char& op, const int& left, const int& right);
	bool isOperatorHighPriority(const char& op);
	bool isParenthesis(const char& elem);

	int evaluateExpression(std::istream& in);
	int evaluateRPNExpression(std::istream& in);
	std::string infixToRPN(std::istream& in);
};

#endif 
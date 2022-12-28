#include <iostream>
#include <cassert>
#include <stack>
#include <sstream>
#include "Token.h"
#include "Evaluator.h"

int Evaluator::applyOperatorToTwoNums(const char& op, const int& left, const int& right)
{
	switch (op)
	{
	case '+': return left + right;
	case '-': return left - right;
	case '*': return left * right;
	case '/': return left / right;
	}

	throw std::exception("Unknown operator.\n");
}

bool Evaluator::isOperatorHighPriority(const char& op)
{
	return op == '*' || op == '/';
}

bool Evaluator::isParenthesis(const char& elem)
{
	return elem == '(' || elem == ')';
}

int Evaluator::evaluateExpression(std::istream& in)
{
	Token next;
	in >> next;

	if (next.type == Token::TokenType::NUMBER)
		return next.value;

	if (next.type == Token::TokenType::OPEN_PARENTHESES)
	{
		int left = evaluateExpression(in);

		Token op;
		in >> op;
		assert(op.type == Token::TokenType::OPERATOR);

		int right = evaluateExpression(in);

		in >> next;
		assert(next.type == Token::TokenType::CLOSED_PARENTHESES);

		return applyOperatorToTwoNums(op.symbol, left, right);
	}

	throw std::exception("Could not evaluate expression.\n");
}

int Evaluator::evaluateRPNExpression(std::istream& in)
{
	std::stack<int> stack;

	Token next;
	in >> next;

	while (in)
	{
		if (next.type == Token::TokenType::NUMBER)
		{
			stack.push(next.value);
		}
		else
		{
			assert(next.type == Token::TokenType::OPERATOR);
			assert(stack.size() >= 2);

			int right = stack.top();
			stack.pop();

			int left = stack.top();
			stack.pop();

			stack.push(applyOperatorToTwoNums(next.symbol, left, right));
		}

		in >> next;
	}

	assert(stack.size() == 1);
	return stack.top();
}

std::string Evaluator::infixToRPN(std::istream& in)
{
	std::stringstream output;
	std::stack<char> operatorStack;

	Token next;
	in >> next;
	while (in)
	{
		switch (next.type)
		{
		case Token::TokenType::NUMBER:
			output << next.value << " ";
			break;

		case Token::TokenType::OPERATOR:
			if (!isOperatorHighPriority(next.symbol))
			{
				while (operatorStack.size() > 0 && !isParenthesis(operatorStack.top()))
				{
					output << operatorStack.top() << " ";
					operatorStack.pop();
				}
				operatorStack.push(next.symbol);
			}
			else
			{
				operatorStack.push(next.symbol);
			}
			break;

		case Token::TokenType::OPEN_PARENTHESES:
			operatorStack.push(next.symbol);
			break;

		case Token::TokenType::CLOSED_PARENTHESES:
			while (operatorStack.size() > 0 && !isParenthesis(operatorStack.top()))
			{
				output << operatorStack.top() << " ";
				operatorStack.pop();
			}
			assert(operatorStack.size() > 0);
			operatorStack.pop(); //pop open parentheses
			break;

		default:
			throw std::exception("Unable to convert infix to RPN expression.\n");
		}
		in >> next;
	}

	while (operatorStack.size() > 0)
	{
		output << operatorStack.top() << " ";
		operatorStack.pop();
	}

	return output.str();
}

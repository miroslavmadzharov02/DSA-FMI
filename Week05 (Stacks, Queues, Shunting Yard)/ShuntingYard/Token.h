#ifndef TOKEN__
#define TOKEN__

#include <iostream>

namespace Tokenizer
{
	bool isDigit(const char& elem);
	bool isWhiteSpace(const char& elem);
	void clearWhiteSpace(std::istream& in);
};

class Token
{
public:

	enum class TokenType
	{
		OPEN_PARENTHESES,
		CLOSED_PARENTHESES,
		NUMBER,
		OPERATOR
	};

	TokenType type;
	char symbol;
	int value;
};

std::istream& operator>>(std::istream& in, Token& token);

#endif 
#include "Token.h"

bool Tokenizer::isDigit(const char& elem)
{
	return elem >= '0' && elem <= '9';
}

bool Tokenizer::isWhiteSpace(const char& elem)
{
    return elem == ' ' ||
        elem == '\r' ||
        elem == '\n' ||
        elem == '\t';
}

void Tokenizer::clearWhiteSpace(std::istream& in)
{
    while (isWhiteSpace(in.peek()))
    {
        in.get();
    }
}

std::istream& operator>>(std::istream& in, Token& token)
{
    using namespace Tokenizer;

    clearWhiteSpace(in);
    char next = in.peek();

    if (!in || in.eof())
        return in;

    if (isDigit(next))
    {
        token.type = Token::TokenType::NUMBER;
        in >> token.value;
        token.symbol = 0;
    }
    else
    {
        switch (next)
        {
        case '+': case '-': case '/': case '*':
            token.type = Token::TokenType::OPERATOR;
            break;
        case '(':
            token.type = Token::TokenType::OPEN_PARENTHESES;
            break;
        case ')':
            token.type = Token::TokenType::CLOSED_PARENTHESES;
            break;
        default:
            throw std::exception("Unrecognized token.\n");
        }

        token.symbol = next;
        token.value = 0;
        in.get();
    }

    return in;
}

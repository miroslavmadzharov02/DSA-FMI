#include "Evaluator.h"
#include "Token.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
#include <map>

void should_convert_basic_expression_to_token()
{
    std::stringstream expression("123*(11+20)");

    std::vector<Token> expected = { {Token::TokenType::NUMBER,0,123},
                                   {Token::TokenType::OPERATOR,'*',0},
                                   {Token::TokenType::OPEN_PARENTHESES,'(',0},
                                   {Token::TokenType::NUMBER,0,11},
                                   {Token::TokenType::OPERATOR,'+',0},
                                   {Token::TokenType::NUMBER,0,20},
                                   {Token::TokenType::CLOSED_PARENTHESES,')',0} };

    Token in;
    for (const Token& expectedToken : expected)
    {
        expression >> in;
        assert(in.type == expectedToken.type);
        assert(in.value == expectedToken.value);
        assert(in.symbol == expectedToken.symbol);
    }
}

void should_convert_advanced_expression_to_token()
{
    std::stringstream expression("123  \n\n\n\r\r\t"
        "  *      (\n"
        "11\n"
        "+20)\n\n\n");

    std::vector<Token> expected = { {Token::TokenType::NUMBER,0,123},
                                {Token::TokenType::OPERATOR,'*',0},
                                {Token::TokenType::OPEN_PARENTHESES,'(',0},
                                {Token::TokenType::NUMBER,0,11},
                                {Token::TokenType::OPERATOR,'+',0},
                                {Token::TokenType::NUMBER,0,20},
                                {Token::TokenType::CLOSED_PARENTHESES,')',0} };


    Token in;
    for (const Token& expectedToken : expected)
    {
        expression >> in;
        assert(in.type == expectedToken.type);
        assert(in.value == expectedToken.value);
        assert(in.symbol == expectedToken.symbol);
    }
}

void should_evaluate_infix_expression_correctly()
{
    std::map<std::string, int> expressionToResult = 
    {
        {"1",1},
        {"(1+2)",3},
        {"((1+10)*(3+4))",77},
        {"(1+(9+1))",11}
    };

    for (const auto& test : expressionToResult)
    {
        std::stringstream str(test.first);
        assert(Evaluator::evaluateExpression(str) == test.second);
    }
}

void should_evaluate_RPN_expression_correctly()
{
    std::map<std::string, int> expressionToResult =
    {
        {"2 1 +", 3},
        {"1 2 3 * +", 7},
        {"7 3 1 2 + * *", 63},
        {"1", 1} 
    };

    for (const auto& test : expressionToResult)
    {
        std::stringstream str(test.first);
        assert(Evaluator::evaluateRPNExpression(str) == test.second);
    }
}

void should_evaluate_full_shunting_yard_expression()
{
    std::map<std::string, int> expressionToResult =
    {
        {"7*(3*(2+1))", 63},
        {"1+2*3", 7},
        {"1", 1},
        {"((1+2)*(3+4))", 21}
    };

    for (const auto& test : expressionToResult)
    {
        std::stringstream expression(test.first);
        std::stringstream rpnExpression(Evaluator::infixToRPN(expression));
        assert(Evaluator::evaluateRPNExpression(rpnExpression) == test.second);
    }
}

int main()
{
    should_convert_basic_expression_to_token();
    should_convert_advanced_expression_to_token();
    should_evaluate_infix_expression_correctly();
    should_evaluate_RPN_expression_correctly();
    should_evaluate_full_shunting_yard_expression();

    return 0;
}

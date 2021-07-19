#include "parser.h"
#include "operations.h"


Operations operators;

float Parser::parse(std::vector<Token> TokenisedInput)
{
	TokenisedString = TokenisedInput;

	return expression();
}

float Parser::expression()
{
	float result = term();
	while (TempToken.mTokenType == ADDITION || TempToken.mTokenType == SUBSTRACTION)
	{
		if (TempToken.mTokenType == ADDITION)
		{
			next_token();
			result = operators.add(result , term());
		}
		else if (TempToken.mTokenType == SUBSTRACTION)
		{
			next_token();
			result = operators.substract(result, term());
		}
	}
	return result;
}

float Parser::term()
{
	float result = factor();
	while (TempToken.mTokenType == MULTIPLICATION || TempToken.mTokenType == DIVISION)
	{
		if (TempToken.mTokenType == MULTIPLICATION)
		{
			next_token();
			result = operators.multiply(result , factor());
		}
		else if (TempToken.mTokenType == DIVISION)
		{
			next_token();
			result = operators.divide(result , factor());
		}
	}
	return result;
}

float Parser::factor()
{
	float result = NULL;
	TempToken = TokenisedString[Counter];
	if (TempToken.mTokenType == DOUBLE)
	{
		result = TempToken.mNumTokenValue;
		next_token();
	}
	else if (TempToken.mTokenType == SUBSTRACTION)
	{
		next_token();
		result = operators.neg_unary(factor());
	}
	else if (TempToken.mTokenType == ADDITION)
	{
		next_token();
		result = operators.pos_unary(factor());
	}
	else if (TempToken.mTokenType == BRACKET_OPEN)
	{
		next_token();
		result = expression();

		if (TempToken.mTokenType != BRACKET_CLOSE)
		{
			//error
		}
		next_token();
	}
	return result;
}

void Parser::next_token()
{
	if (Counter != TokenisedString.size() - 1)
	{
		Counter++;
		TempToken = TokenisedString[Counter];
	}
}

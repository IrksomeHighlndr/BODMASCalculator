#include "token.h"
#include "iostream"

std::vector<Token> Tokeniser::tokenise(const std::string& Equation)
{
	std::vector<Token>tokens;
	Token tempToken{ NONE, };
	int j = 0;
	for (char StringChar : Equation)
	{
		j++;
		switch (StringChar)
		{
			// impliment ignore whitespace
		case ' ':
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			tempToken.mTokenType = DOUBLE;
			tempToken.mTokenValue.append(1, StringChar);
			break;
		case '.':
			if (tempToken.mTokenType == OPERATOR || tempToken.mTokenType == NONE)
			{
				tempToken.mTokenType = DOUBLE;
				tempToken.mTokenValue.append(1, '0');
				tempToken.mTokenValue.append(1, StringChar);
				break;
			}
			if (tempToken.mTokenType == DOUBLE)
			{
				tempToken.mTokenValue.append(1, StringChar);
				break;
			}
		case '-':
			if (j == 1)
			{
				tempToken.mTokenType = SUBSTRACTION;
				tempToken.mTokenValue.append(1, StringChar);
				endToken(tempToken, tokens);
				break;
			}
// it first seperate the symbols from digits then identifies them in a different switch case
		case '+':
		case '/':
		case '*':
		case '%':
			if (tempToken.mTokenType != BRACKET_CLOSE)
			{
				if (tempToken.mTokenType == DOUBLE)
				{
					endToken(tempToken, tokens);
				}
				else
				{
					endToken(tempToken, tokens);
				}
			}
			switch (StringChar)
			{
			case '+':
				tempToken.mTokenType = ADDITION;
				break;
			case '-':
				tempToken.mTokenType = SUBSTRACTION;
				break;
			case '/':
				tempToken.mTokenType = DIVISION;
				break;
			case '*':
				tempToken.mTokenType = MULTIPLICATION;
				break;
			case '%':
				tempToken.mTokenType = OPERATOR;
				break;
			}
			tempToken.mTokenValue.append(1, StringChar);
			endToken(tempToken, tokens);
			break;
		case '(':
			if (tempToken.mTokenType == DOUBLE)
			{
				endToken(tempToken, tokens);
				tempToken.mTokenType = MULTIPLICATION;
				tempToken.mTokenValue.append(1, '*');
				endToken(tempToken, tokens);
			}
			tempToken.mTokenType = BRACKET_OPEN;
			tempToken.mTokenValue.append(1, StringChar);
			endToken(tempToken, tokens);
			break;
		case ')':
			if (tempToken.mTokenType != BRACKET_CLOSE)
			{
				endToken(tempToken, tokens);
			}
			tempToken.mTokenType = BRACKET_CLOSE;
			tempToken.mTokenValue.append(1, StringChar);
			if (j == Equation.size())
			{
				break;
			}
			endToken(tempToken, tokens);
		}
	}
	endToken(tempToken, tokens);
	return tokens;
}


void Token::DebugLog()
{
	std::cout << "Token(" << stringTokenType[mTokenType] << ")" << "\n  =>  " << mTokenValue << std::endl;
}

void Tokeniser::endToken(Token& token, std::vector<Token>& tokens)
{
	if (token.mTokenType == DOUBLE)
	{
		token.mNumTokenValue = stof(token.mTokenValue);
	}
	tokens.push_back(token);
	token.mTokenValue.erase();
	token.mNumTokenValue = 0;
}

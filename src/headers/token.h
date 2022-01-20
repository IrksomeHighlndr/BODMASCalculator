#pragma once
#include "string"
#include "vector"

enum TokenType
{
	NONE,
	DOUBLE,
	BRACKET_OPEN,
	BRACKET_CLOSE,
	ADDITION,
	SUBSTRACTION,
	DIVISION,
	MULTIPLICATION,
	OPERATOR
};

static const char* stringTokenType[] =
{
	"NONE",
	"DOUBLE",
	"BRACKET_OPEN",
	"BRACKET_CLOSE",
	"ADDITION",
	"SUBSTRACTION",
	"DIVISION",
	"MULTIPLICATION",
	"OPERATOR"
};
																					
class Token
{
public:
	enum TokenType mTokenType;
	std::string mTokenValue;
	float mNumTokenValue;
	void DebugLog();
private:
};

class Tokeniser
{
public:
	std::vector<Token> tokenise(const std::string& Equation);

private:
	void endToken(Token& token, std::vector<Token>& tokens);
};

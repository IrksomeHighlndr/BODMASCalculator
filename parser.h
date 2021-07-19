#pragma once
#include "token.h"

class Parser
{
private:
	int Counter = 0;
	Token TempToken;
public:
	std::vector<Token>TokenisedString;
	float parse(std::vector<Token>TokenisedInput);
	float expression();
	float term();
	float factor();
	void next_token();
};
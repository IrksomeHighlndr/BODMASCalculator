#include"iostream"
#include"token.h"
#include"parser.h"


int main(void)
{
	std::cout << "Simple Calculator v3.5" << std::endl;
	while (true)
	{
		std::string Equation;
		std::cout << "\nEquation: ";
		std::cin >> Equation;

		if (Equation == "Exit" || Equation == "exit") 
		{
			break;
		}
		Tokeniser tokenizer;
		std::vector<Token>TokenisedInput = tokenizer.tokenise(Equation);
		Parser parser;
		float result = parser.parse(TokenisedInput);
		// Impliment inte

		std::cout << '\n' << result << std::endl;
		for (Token tempToken : TokenisedInput)
		{
			tempToken.DebugLog();
		}

		Equation.erase();
	};
	return 0;
}
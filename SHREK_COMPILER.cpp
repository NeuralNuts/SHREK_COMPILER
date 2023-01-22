#include <iostream>
#include <string>
#include <string_view>

#include "linenoise.hpp"
#include "reader.h"
#include "printer.h"

Value* READ(std::string input)
{
	return read_str(input);
}

Value* EVAL(Value *input)
{  
	return input;
}

std::string PRINT(Value *input)
{
	return pr_str(input);
}




std::string REP(std::string input)
{
	auto ast = READ(input);
	auto result = EVAL(ast);

	return PRINT(result);
}

int main()
{
	const auto history_path = "history.txt";
	linenoise::LoadHistory(history_path);

	std::string input;
	for (;;)
	{
		auto quit = linenoise::Readline("user> ", input);

		if (quit)
			break;

		std::cout << REP(input) << std::endl;
		linenoise::AddHistory(input.c_str());
	}

	linenoise::SaveHistory(history_path);

	return 0;
};
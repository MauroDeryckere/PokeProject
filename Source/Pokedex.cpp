#include "ServiceLocator.h"
#include <iostream>
#include <memory>

#ifdef USE_NLOHMANN_JSON
	#include "NlohmannParser.h"
#elif defined USE_RAPIDJSON
	#include "RapidJsonParser.h"
#endif

#ifdef _WIN32
	#include <windows.h>
#endif

void SetConsoleEncodingUTF8()
{
	#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
	#endif
}

int main()
{
	SetConsoleEncodingUTF8();

	#ifdef USE_NLOHMANN_JSON
		PokeProject::ServiceLocator::RegisterJsonParser(std::make_unique<PokeProject::NlohmannParser>());
		std::cout << "Using NLOHMANN Parser \n";
	#elif defined USE_RAPIDJSON
		PokeProject::ServiceLocator::RegisterJsonParser(std::make_unique<PokeProject::RapidJsonParser>());
		std::cout << "Using RapidJson Parser \n";
	#endif

	using namespace PokeProject;
	auto const& parser{ ServiceLocator::GetJsonParser() };

	std::filesystem::path const path{ "Content/pokedex.json" };
	auto const& pokemons{ parser.ParsePokedex(path) };

	for (auto const& p : pokemons)	
	{
		p.Print();
		std::cout << "\n";
	}

	return 0;
}

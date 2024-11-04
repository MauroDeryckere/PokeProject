#include "NlohmannParser.h"

#include <nlohmann/json.hpp>
#include <fstream>

namespace PokeProject
{
    std::vector<Pokemon> NlohmannParser::ParsePokedex(std::filesystem::path const& path) const noexcept
    {
        assert(std::filesystem::exists(path));

        std::vector<Pokemon> pokedex;

        std::ifstream file{ path };
        if (!file.is_open())
        {
            return pokedex;
        }

        try
        {
            nlohmann::json jsonFile;
            file >> jsonFile;

            pokedex.reserve(jsonFile["pokemon"].size());

            for (const auto& entry : jsonFile["pokemon"])
            {
                Pokemon pokemon{};

                if(entry.contains("id"))
                {
                    pokemon.id = entry["id"];
                }
                if (entry.contains("name"))
                {
                    pokemon.name = entry["name"];
                }
                if (entry.contains("type"))
                {
                    for(auto const& t : entry["type"])
					  pokemon.type.emplace_back(t);

                    pokemon.type.shrink_to_fit();
                }

                pokedex.emplace_back(pokemon);
            }
        }
	    catch (const nlohmann::json::exception& e)
	    {
	        std::cerr << "JSON parsing error: " << e.what() << std::endl;
	        return {};
	    }

    	return pokedex;
	}
}



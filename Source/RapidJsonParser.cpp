#include "RapidJsonParser.h"

#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h> 

namespace PokeProject
{
	std::vector<Pokemon> RapidJsonParser::ParsePokedex(std::filesystem::path const& path) const noexcept
	{
        assert(std::filesystem::exists(path));

        std::vector<Pokemon> pokedex{};

        std::ifstream file{path};
        if (!file.is_open())
        {
            return pokedex;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        rapidjson::Document document;
        document.Parse(buffer.str().c_str());

        if (document.HasParseError() || !document.IsObject() || !document.HasMember("pokemon"))
        {
            return pokedex;
        }

        const rapidjson::Value& pokemonArray{ document["pokemon"] };
        pokedex.reserve(pokemonArray.GetArray().Size());

        for (const auto& entry : pokemonArray.GetArray())
        {
            Pokemon pokemon{};

            if (entry.HasMember("id") && entry["id"].IsInt())
                pokemon.id = entry["id"].GetInt();

            if (entry.HasMember("name") && entry["name"].IsString())
                pokemon.name = entry["name"].GetString();

            if (entry.HasMember("type") && entry["type"].IsArray())
            {
                for (const auto& type : entry["type"].GetArray())
                {
                    if (type.IsString())
                    {
                        pokemon.type.emplace_back(type.GetString());
                    }
                }

                pokemon.type.shrink_to_fit();
            }

            pokedex.emplace_back(pokemon);
        }

        return pokedex;
	}
}

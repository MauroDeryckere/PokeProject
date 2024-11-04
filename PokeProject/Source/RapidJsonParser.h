#ifndef RAPIDJSONPARSER_H
#define RAPIDJSONPARSER_H

#include "JsonParser.h"

namespace PokeProject
{
	class RapidJsonParser final : public JsonParser
	{
	public:
		 std::vector<Pokemon> ParsePokedex(std::filesystem::path const& path) const noexcept override;
	private:
	};
}

#endif

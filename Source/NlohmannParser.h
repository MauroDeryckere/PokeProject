#ifndef NLOHMANNPARSER_H
#define NLOHMANNPARSER_H

#include "JsonParser.h"

namespace PokeProject
{
	class NlohmannParser final : public JsonParser
	{
	public:
		std::vector<Pokemon> ParsePokedex(std::filesystem::path const& path) const noexcept override;
	private:
	};
}

#endif
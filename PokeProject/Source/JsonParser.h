#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <string>
#include <vector>
#include <filesystem>
#include "Pokemon.h"

namespace PokeProject
{
	class JsonParser
	{
	public:
		JsonParser() = default;
		virtual ~JsonParser() = default;

		virtual std::vector<Pokemon> ParsePokedex(std::filesystem::path const& path) const noexcept = 0;

	private:
	};

	class NullJsonParser final : public JsonParser
	{
	public:
		NullJsonParser() = default;
		~NullJsonParser() override = default;

		std::vector<Pokemon> ParsePokedex(std::filesystem::path const&) const noexcept override
		{
			return{};
		}

	};
}

#endif

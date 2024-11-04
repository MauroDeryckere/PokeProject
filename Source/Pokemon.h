#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

namespace PokeProject
{
	struct Pokemon final
	{
		std::string name;
		std::vector<std::string> type;

		int32_t id;

		void Print() const noexcept
		{
			std::cout << id << ". " << name << " ["; 

			for(uint32_t i{0}; i < type.size(); ++i)
			{
				std::cout << type[i];

				if (i < type.size() - 1)
				{
					std::cout << ", ";
				}
			}

			std::cout << "]";
		}
	};
}

#endif

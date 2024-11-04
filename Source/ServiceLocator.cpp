#include "ServiceLocator.h"

//Default intitialize systems in the service locator

namespace PokeProject
{
	std::unique_ptr<PokeProject::JsonParser> ServiceLocator::m_pJsonParser{ std::make_unique<NullJsonParser>() };
}
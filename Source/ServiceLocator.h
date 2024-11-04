#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include <memory>
#include "JsonParser.h"

namespace PokeProject
{
	class ServiceLocator final
	{
	public:
		[[nodiscard]] static JsonParser& GetJsonParser() { return (*m_pJsonParser); }
		static void RegisterJsonParser(std::unique_ptr<JsonParser>&& pParser)
		{
			m_pJsonParser = ((!m_pJsonParser) ? std::make_unique<NullJsonParser>() : std::move(pParser));
		}

	private:
		static std::unique_ptr<JsonParser> m_pJsonParser;
	};
}

#endif

# Pokedex Project

This project is a simple application named **PokeProject**, which utilizes a JSON parser to manage and handle pokedex data. The project offers flexibility by allowing you to select between two popular JSON parsing libraries: **nlohmann/json** and **RapidJSON**.

## Libraries Used
The project uses CMake FetchContent to automatically retrieve external libraries during the build process. This allows for easy management of dependencies without manual downloads or setups.

### JSON Parsers
The project supports two JSON parsing libraries, which can be selected at build time:
- **[nlohmann/json](https://github.com/nlohmann/json)**: A widely used, user-friendly JSON library for C++ that provides a modern, STL-like API for working with JSON.
- **[RapidJSON](https://github.com/Tencent/rapidjson)**: A fast JSON parser and generator that is especially suitable for performance-critical applications.

## Configuring the Project

You can specify which JSON parser to use by setting CMake options:
- **USE_NLOHMANN_JSON**: Enables the nlohmann/json parser.
- **USE_RAPIDJSON**: Enables the RapidJSON parser (default option).

> **Note**: Only one of these options should be enabled at a time. If both options are set to `ON`, **USE_RAPIDJSON** will be prioritized.

### Example Configuration

To select a JSON parser, set the desired option when configuring with CMake. By default, RapidJSON is enabled.

#### Example: Use nlohmann/json
```bash
cmake -DUSE_NLOHMANN_JSON=ON -DUSE_RAPIDJSON=OFF ..
```

cmake_minimum_required(VERSION 3.10)
project(PokeProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Make the standard version required
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Choose between JSON parsers
option(USE_NLOHMANN_JSON "Use nlohmann/json parser" ON)
option(USE_RAPIDJSON "Use RapidJSON parser" OFF)

if(USE_NLOHMANN_JSON)
    # Fetch nlohmann/json
    FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5  
    )
    FetchContent_MakeAvailable(nlohmann_json)

    add_compile_definitions(USE_NLOHMANN_JSON)  # Define a preprocessor directive
elseif(USE_RAPIDJSON)
    # Fetch RapidJSON
    FetchContent_Declare(
        rapidjson
        GIT_REPOSITORY https://github.com/Tencent/rapidjson.git
        GIT_TAG v1.1.0 
    )
    FetchContent_MakeAvailable(rapidjson)

    add_compile_definitions(USE_RAPIDJSON)  # Define a preprocessor directive
    include_directories(${rapidjson_SOURCE_DIR}/include)  # Include RapidJSON headers only
endif()

if(USE_NLOHMANN_JSON)
    include_directories(${nlohmann_json_SOURCE_DIR}/single_include)
elseif(USE_RAPIDJSON)
    include_directories(${rapidjson_SOURCE_DIR}/include)
endif()

# Define source files
set(SOURCE_FILES
    Source/Pokedex.cpp
    Source/ServiceLocator.cpp
)

if(USE_NLOHMANN_JSON)
    list(APPEND SOURCE_FILES Source/NlohmannParser.cpp)  # Add Nlohmann-specific implementation
elseif(USE_RAPIDJSON)
    list(APPEND SOURCE_FILES Source/RapidJsonParser.cpp)  # Add RapidJSON-specific implementation
endif()

include_directories(${CMAKE_SOURCE_DIR}/Source)

add_executable(PokeProject ${SOURCE_FILES})

# Link the JSON library based on selection
if(USE_NLOHMANN_JSON)
    target_link_libraries(PokeProject PRIVATE nlohmann_json::nlohmann_json)
endif()


# Copy the resources folder to the build directory
add_custom_command(
    TARGET PokeProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/Content $<TARGET_FILE_DIR:PokeProject>/Content
    COMMENT "Copying resources folder to the output directory"
)

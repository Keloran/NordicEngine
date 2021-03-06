#ifndef NordicArts_NordicEngine_String_INL
#define NordicArts_NordicEngine_String_INL

#include <NordicEngine/Exception/Exception.hpp>

template<typename T>
T convertToType(const std::string &cString, std::ios_base &(*pFormat)(std::ios_base&)) {
    T output;

    std::istringstream input(cString);
    input >> pFormat >> output;

    if (!input) {
        std::ostringstream cStream;
        cStream << __FUNCTION__ << ": Bad conversion of [" << cString << "] to " << typeid(output).name();
        throw NordicArts::NordicEngine::Exception(cStream);
    }    

    char cChar;
    if (input.get(cChar)) {
        std::ostringstream cStream;
        cStream << __FUNCTION__ << ": Conversion of [" << cString << "] to " << typeid(output).name() << " - [" << output << "] Failed";
        
        throw NordicArts::NordicEngine::Exception(cStream);
    }

    return output;
}

#endif

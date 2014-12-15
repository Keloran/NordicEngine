#include <NordicEngine/Files/Handler/TextFile/Reader.hpp>

namespace NordicArts {
    namespace NordicEngine {
        namespace TextFile {
            Reader::Reader() : FileHandler(true) {
            }
            Reader::Reader(const std::string &cFileName, bool bFilePath) : FileHandler(cFileName, true) {
                m_cFileStream.open(m_cFilePath.c_str(), std::ios_base::in);
                if (!m_cFileStream.is_open()) {
                    throwError(__FUNCTION__ + std::string(" cannot open file for reading!"));
                }
                m_cFileStream.close();
            }
            Reader::Reader(const std::string &cFileName) : FileHandler(cFileName, true) {
                m_cFileStream.open(m_cFilePath.c_str(), std::ios_base::in);
                if (!m_cFileStream.is_open()) {
                    throwError(__FUNCTION__ + std::string(" cannot open file for reading!"));
                }
            }

            std::string Reader::readAll() const {
                std::ostringstream cStream;
                cStream << m_cFileStream.rdbuf();
                if (cStream.str().length() < 1) {
                    throwError(__FUNCTION__ + std::string(" failed because file is empty"));
                }
        
                return cStream.str();
            }
        };
    };
};

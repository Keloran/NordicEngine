#include <NordicEngine/Files/Files.hpp>
#include <NordicEngine/Files/Handler/TextFile/Writer.hpp>
#include <NordicEngine/Files/Handler/TextFile/Reader.hpp>

namespace NordicArts {
    namespace NordicEngine {
        Files::Files() {
        }
        Files::Files(std::string cFile) : m_cFile(cFile), m_bFilePath(false), m_bAppend(false) {
        }
        Files::Files(std::string cFile, bool bFilePath) : m_cFile(cFile), m_bFilePath(bFilePath), m_bAppend(false) {
        }
        Files::Files(std::string cFile, bool bFilePath, bool bAppend) : m_cFile(cFile), m_bFilePath(bFilePath), m_bAppend(bAppend) {
        }
        Files::Files(std::string cFile, bool bFilePath, bool bAppend, bool bSaveException) : m_cFile(cFile), m_bFilePath(bFilePath), m_bAppend(bAppend), m_bSaveException(bSaveException) {
        }

        Files::~Files() {
        }

        void Files::setFile(std::string cFile) {
            m_cFile = cFile;
        }
        void Files::setFile(std::string cFile, Format eFormat) {
            m_cFile     = cFile;
            m_eFormat   = eFormat;
        }

        std::string Files::read() {
            if (m_bAppend) {
                TextFile::Reader  oReader(m_cFile, m_bAppend);
                TextFile::Reader *pReader = &oReader;
        
                return pReader->readAll();
            } else {
                TextFile::Reader  oReader(m_cFile);
                TextFile::Reader *pReader = &oReader;
                
                return pReader->readAll();
            }
        }

        void Files::write(std::string cString) {
            if (m_bSaveException) {
                TextFile::Writer  oWriter(m_cFile, m_bFilePath, m_bAppend, m_bSaveException);
                TextFile::Writer *pWriter = &oWriter;

                return pWriter->write(cString);
            } else {
                TextFile::Writer  oWriter(m_cFile, m_bFilePath, m_bAppend);
                TextFile::Writer *pWriter = &oWriter;

                return pWriter->write(cString);
            }
        }
    };
};

#include <NordicEngine/Files/Format/TextFile/Writer.hpp>

namespace NordicArts {
    namespace NordicEngine {
        namespace Files {
            namespace TextFile {
                Writer::Writer() : Handler(true) {
                }
                Writer::Writer(const std::string &cFileName, bool bFilePath, bool bAppend) : Handler(cFileName, false) {
                    openStream(bAppend);
                }
                Writer::Writer(const std::string &cFileName, bool bFilePath, bool bAppend, bool bSaveException) : Handler(cFileName, bSaveException) {
                    openStream(bAppend);
                }

                void Writer::openStream(bool bAppend) {
                    m_cFileStream.open(getFilePath().c_str(), (std::ios_base::out | (bAppend ? std::ios_base::app : std::ios_base::trunc)));

                    if (!m_cFileStream.is_open()) {
                        throwError(__FUNCTION__, " can't open file for writing");
                    }
                }

                void Writer::write(const std::string &cMessage) {
                    m_cFileStream << cMessage;
                    m_cFileStream.close();
                }

                bool Writer::deleteFile() {
                    openStream(false);
                    
                    return handlerDeleteFile();
                }
            };
        };
    };
};

#ifndef NordicArts_NordicEngine_FileHandler_H
#define NordicArts_NordicEngine_FileHandler_H

#include <NordicEngine/Engine.hpp>
#include <NordicEngine/FileHandler/FileUtils.hpp>
#include <NordicEngine/ExceptionHandler/ExceptionHandler.hpp>

namespace NordicArts {
    namespace NordicEngine {
        class FileHandler {
        // Variables
        public:
            std::string     m_cFilePath;
        protected:
            std::fstream    m_cFileStream;

            std::string     m_cFileName;

        private:
            bool            m_bSaveException;

        // Methods
        public:
            virtual ~FileHandler();
            
            std::string getFilePath() const;
            
        protected:
            FileHandler(std::string cFileName, bool bSaveException);

            void throwError(const std::string &cMessage) const;
            void throwError(const std::ostringstream &cMessage) const;

        private:
        };
    };
};

#endif
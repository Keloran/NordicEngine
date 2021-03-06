#ifndef NordicArts_NordicEngine_OS_Windows_H
#define NordicArts_NordicEngine_OS_Windows_H

#include <NordicEngine/Engine.hpp>

// Strip lots of rubbish from windows builds
#define VC_EXTRALEAN

// System
#include <windows.h>
#include <conio.h>
#include <tchar.h>
#include <process.h>
#include <winbase.h>

// MUTEX_THREAD is really a HANDLE on Windows
typedef HANDLE MUTEX_THREAD;

// Time
#ifndef NA_TIME
#define NA_TIME SYSTEMTIME
#endif

#ifndef NA_TIMEINFO
#define NA_TIMEINFO NULL
#endif

// Critical Section
typedef CRITICAL_SECTION NA_CRITICAL;

namespace NordicArts {
    namespace NordicEngine {
        class OSSpecific {
        // Variables
        public:
        protected:
        private:

        // Methods
        public:
            std::string getPath(std::string cFileName);
            std::string getResourcePath(std::string cFileName);

            bool deleteFile(std::string cFileName);

        protected:
        private:

        };
    };
};

#endif

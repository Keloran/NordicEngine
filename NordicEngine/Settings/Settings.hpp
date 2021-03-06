#ifndef NordicArts_NordicEngine_Settings_H
#define NordicArts_NordicEngine_Settings_H

#include <NordicEngine/Engine.hpp>

#include <NordicEngine/ThirdParty/glm/glm/glm.hpp>

namespace NordicArts {
    namespace NordicEngine {
        namespace Files {
            class Lua;
        };

        class Logger;

        class Settings {
        // Variables
        public:
        protected:
        private:
            unsigned int    m_iPhysicsRefreshRate;
            
            int             m_iFSAA;

            int             m_iRandomNumberSeed;

            bool            m_bWindowMode;
            bool            m_bStatsLogging;
            bool            m_bVSync;
            bool            m_bSettingsDone;
        
            glm::uvec2      m_vResolution;
            glm::uvec2      m_vOpenGL;

            float           m_fFOV;

            std::string     m_cGameName;

            Logger         *m_pLogger;

        // Methods
        public:
            Settings();
            Settings(std::string cGameName);
            Settings(Logger *pLogger, std::string cGameName);

            virtual ~Settings();

            void setup();

            void setRandomSeed(int iSeed);
            int getRandomSeed() const;

            void setGameName(std::string cName);
            std::string getGameName() const;
            
            void setStats(bool bStats);

            void setFOV(float fFOV);
            float getFOV() const;
            float getFOVCalc() const;

            void setVSync(bool bVSync);
            bool getVSync() const;

            void setOpenGL(const glm::uvec2 &vOpenGL);
            const glm::uvec2 getOpenGL() const;            

            void setOpenGLVerbose(int iMajor, int iMinor);
            int getOpenGLMajor() const;
            int getOpenGLMinor() const;

            void setFSAA(int iFSAA);
            int getFSAA() const;

            void setPhysicsRefresh(int iRefresh);
            int getPhysicsRefresh() const;

            void setResolution(const glm::uvec2 &vResolution);
            const glm::uvec2 getResolution() const;

            void setResolutionVerbose(int iWidth, int iHeight);
            int getResolutionWidth() const;
            int getResolutionHeight() const;

            void setWindowMode(bool bWindow);
            bool isWindowed() const;

            static void registerLua(Files::Lua *pLua);

        protected:
        private:
            bool checkDefaults();
            bool checkTableExists();

            void setDefaults();
            bool createTable();
        };
    };
};

#endif

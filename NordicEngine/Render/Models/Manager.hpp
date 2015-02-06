#ifndef NordicArts_NordicEngine_Render_Model_Manager_H
#define NordicArts_NordicEngine_Render_Model_Manager_H

#include <NordicEngine/Engine.hpp>
#include <NordicEngine/Render/Models/Model.hpp>
#include <NordicEngine/Logger/Logger.hpp>

namespace NordicArts {
    namespace NordicEngine {
        namespace Render {
            namespace Models {
                class Manager {
                // Variables
                public:
                    Model *m_pModels[128];
        
                protected:
                private:
                    Logger *m_pLogger;

                    int m_iModels;

                // Methods
                public:
                    Manager();
                    Manager(Logger *pLogger);

                    void destroy();

                    Model *addModel(std::string cName, std::vector<glm::vec3> vVerticies, std::string cVertex, std::string cFragment);
                    Model *addModel(std::string cName, std::string cFile, std::string cVertex, std::string cFragment);
                    Model *getModel(std::string cName);

                protected:
                private:

                };
            };
        };
    };
};

#endif

#ifndef NordicArts_NordicEngine_Model_H
#define NordicArts_NordicEngine_Model_H

#include <NordicEngine/Engine.hpp>
#include <NordicEngine/Render/Shader/Shader.hpp>
#include <NordicEngine/ThirdParty/glm/glm/glm.hpp>

namespace NordicArts {
    namespace NordicEngine {
        class Model {
        // Variables
        public:
            static const GLuint m_iVertexIndex = 0;
            static const GLuint m_iColorIndex = 1;
            static const GLuint m_iTextureID = 2;
            static const GLuint m_iNormalIndex = 3;

        protected:
        private:
            std::vector<glm::vec3> m_vVertices;

            GLint m_iSize;
                
            GLuint m_iVertexID;
            GLuint m_iVertexArrayID;

            Render::Shader m_oShader;

        // Methods
        public:
            Model();
            
            ~Model();

            void initalize(std::vector<glm::vec3> vVerticies, int iLength, std::string cVertex, std::string cFragment);
            void render();
            void destroy();

        protected:
        private:

        };
    };
};

#endif

#pragma once 

#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum direction {

    FORWARD = 0,
    BACKWARD,
    LEFT,
    RIGHT

};


class Camera {

    public:
        Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp);

        const glm::mat4 getViewMatrix();
        const glm::vec3 getPosition();
        void updateMouseInput(const float& dt, const double& offsetX, const double& offsetY);
        void updateKeyboardInput(const float& dt, const int& direction);
        void updateInput(const float& dt, const int& direction, const double& offsetX, const double& offsetY);
        void changeBendDown();

    private:
        void updateCameraVectors();
        

    private:
        glm::mat4 ViewMatrix;
        
        GLfloat movementSpeed;
        GLfloat sensitivity;

        glm::vec3 worldUp;
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 right;
        glm::vec3 up;

        glm::vec3 front_projection;
        glm::vec3 right_projection;
        
        GLfloat pitch;
        GLfloat yaw;
        GLfloat roll;
        
        bool bend_down;
};

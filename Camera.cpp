#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 direction, glm::vec3 worldUp) {

    ViewMatrix = glm::mat4(1.0f);
    sensitivity = 8.0f;
    movementSpeed = 3.0f;    

    this->worldUp = worldUp;
    this->position = position;
    right = glm::vec3(0.0f);
    up = worldUp;

    pitch = 0.0f;
    yaw = -90.0f;
    roll = 0.0f;
    
    bend_down = false;

    updateCameraVectors();

}


void Camera::changeBendDown() {

    if (bend_down) {
            
        position.y = -2.0f;
        bend_down = false;

    } else {

        position.y = -2.6f;
        bend_down = true;

    }

}

void Camera::updateKeyboardInput(const float& dt, const int& direction) {

    switch (direction) {
        
        case direction::FORWARD:
            position += front_projection * movementSpeed * dt;
            break;

        case direction::BACKWARD:
            position -= front_projection * movementSpeed * dt;
            break;

        case direction::LEFT:
            position -= right_projection * movementSpeed * dt;
            break;

        case direction::RIGHT:
            position += right_projection * movementSpeed * dt;
            break;

    }

}

void Camera::updateMouseInput(const float& dt, const double& offsetX, const double& offsetY) {

    pitch += (GLfloat)offsetY * sensitivity * dt;
    yaw += (GLfloat)offsetX * sensitivity * dt;

    
    if (pitch > 95.0f) {
        
        pitch = 95.0f;

    } else if (pitch < -95.0f) {

        pitch = -95.0f;

    }

    if (yaw > 360.0f || yaw < -360.0f) {

        yaw = 0.0f;

    }
    

}

void Camera::updateInput(const float& dt, const int& direction, const double& offsetX, const double& offsetY) {

    updateKeyboardInput(dt, direction);
    updateMouseInput(dt, offsetX, offsetY);

}

void Camera::updateCameraVectors() {

    front.x = cos(glm::radians(yaw) * cos(glm::radians(pitch)));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw) * cos(glm::radians(pitch)));

    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
    
    front_projection = front;
    front_projection.y = 0.0f;

    right_projection = right;
    right_projection.y = 0.0f;

}

        

const glm::mat4 Camera::getViewMatrix() {
    
    updateCameraVectors();

    ViewMatrix = glm::lookAt(position, position + front, up);

    return ViewMatrix;

}

const glm::vec3 Camera::getPosition() {

    return position;

}

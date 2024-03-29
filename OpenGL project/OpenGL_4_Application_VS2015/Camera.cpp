//
//  Camera.cpp
//  Lab5
//
//  Created by CGIS on 28/10/2016.
//  Copyright © 2016 CGIS. All rights reserved.
//

#include "Camera.hpp"

namespace gps {
    
	Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget)
	{
		this->cameraPosition = cameraPosition;
		this->cameraTarget = cameraTarget;
		this->cameraDirection = glm::normalize(cameraTarget - cameraPosition);
		this->cameraRightDirection = glm::normalize(glm::cross(this->cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::lookAt(cameraPosition, cameraPosition + cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::vec3 Camera::getCameraTarget()
	{
		return cameraTarget;
	}

	glm::vec3 Camera::getCameraPosition()
	{
		return cameraPosition;
	}

	void Camera::setCameraTarget(glm::vec3 newTarget)
	{
		cameraTarget = newTarget;
	}

	void Camera::moveAlone(int start, float speed) {
		if (start == 1) {
			cameraPosition += cameraDirection * speed;
		}
		if (start == 0) {
			cameraPosition -= cameraDirection * speed;
		}

	}

	void Camera::move(MOVE_DIRECTION direction, float speed)
	{
		switch (direction) {
		case MOVE_FORWARD:
			cameraPosition += cameraDirection * speed;
			break;

		case MOVE_BACKWARD:
			cameraPosition -= cameraDirection * speed;
			break;

		case MOVE_RIGHT:
			cameraPosition += cameraRightDirection * speed;
			break;

		case MOVE_LEFT:
			cameraPosition -= cameraRightDirection * speed;
			break;
		}
	}

	void Camera::rotate(float pitch, float yaw)
	{
		cameraDirection.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		cameraDirection.y = sin(glm::radians(pitch));
		cameraDirection.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		cameraRightDirection = glm::normalize(glm::cross(cameraDirection, glm::vec3(0, 1, 0)));

		cameraDirection = glm::normalize(cameraDirection);
	}
    
}

#include <windows.h>	// Header File For Windows
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/GLAUX.H>
#include <cmath>
#include"camera.h"
#include<iostream>
#define PI 3.14159265359
#define DEG2RAD(angle) (angle * PI / 180.0)

Camera::Camera() {

    position[0] = 544.0f; position[1] = -259.0f; position[2] = 185.0f;


    forward[0] = 1.0f; forward[1] = 1.0f; forward[2] = 0.0f;
    right[0] = 0.0f; right[1] = 1.0f; right[2] = 0.0f;
    up[0] = 0.0f; up[1] = 0.0f; up[2] = 1.0f;


    RotateX(0);
    RotateY(-90);
}

void Camera::Normalize(GLfloat* vector) {
    GLfloat length = sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
    if (length > 0.0f) {
        vector[0] /= length;
        vector[1] /= length;
        vector[2] /= length;
    }
}

void Camera::CrossProduct(const GLfloat* a, const GLfloat* b, GLfloat* result) {
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

void Camera::RotateVector(GLfloat* vector, const GLfloat* axis, GLfloat angle) {
    GLfloat rad = DEG2RAD(angle);
    GLfloat cosAngle = cosf(rad);
    GLfloat sinAngle = sinf(rad);

    GLfloat temp[3];
    temp[0] = (cosAngle + (1 - cosAngle) * axis[0] * axis[0]) * vector[0] +
        ((1 - cosAngle) * axis[0] * axis[1] - axis[2] * sinAngle) * vector[1] +
        ((1 - cosAngle) * axis[0] * axis[2] + axis[1] * sinAngle) * vector[2];

    temp[1] = ((1 - cosAngle) * axis[1] * axis[0] + axis[2] * sinAngle) * vector[0] +
        (cosAngle + (1 - cosAngle) * axis[1] * axis[1]) * vector[1] +
        ((1 - cosAngle) * axis[1] * axis[2] - axis[0] * sinAngle) * vector[2];

    temp[2] = ((1 - cosAngle) * axis[2] * axis[0] - axis[1] * sinAngle) * vector[0] +
        ((1 - cosAngle) * axis[2] * axis[1] + axis[0] * sinAngle) * vector[1] +
        (cosAngle + (1 - cosAngle) * axis[2] * axis[2]) * vector[2];

    memcpy(vector, temp, 3 * sizeof(GLfloat));
}

void Camera::MoveForward(GLfloat distance) {
    position[0] += forward[0] * distance;
    position[1] += forward[1] * distance;
    position[2] += forward[2] * distance;
}

void Camera::MoveBackward(GLfloat distance) {
    MoveForward(-distance);
}

void Camera::MoveRight(GLfloat distance) {
    position[0] += right[0] * distance;
    position[1] += right[1] * distance;
    position[2] += right[2] * distance;
}

void Camera::MoveUpward(GLfloat distance) {
    position[0] += up[0] * distance;
    position[1] += up[1] * distance;
    position[2] += up[2] * distance;
}

void Camera::RotateX(GLfloat angle) {
    RotateVector(forward, right, angle);
    RotateVector(up, right, angle);
    Normalize(forward);
    Normalize(up);
    CrossProduct(up, forward, right); // Ensure right is recalculated to maintain orthonormality
}

void Camera::RotateY(GLfloat angle) {
    RotateVector(forward, up, angle);
    RotateVector(right, up, angle);
    Normalize(forward);
    Normalize(right);
    CrossProduct(forward, right, up); // Ensure up is recalculated to maintain orthonormality
}

void Camera::RotateZ(GLfloat angle) {
    RotateVector(up, forward, angle);
    RotateVector(right, forward, angle);
    Normalize(up);
    Normalize(right);
    CrossProduct(forward, right, up); // Recalculate up for consistency
}

void Camera::Render() {
    GLfloat lookAt[3] = {
        position[0] + forward[0],
        position[1] + forward[1],
        position[2] + forward[2]
    };

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        position[0], position[1], position[2],
        lookAt[0], lookAt[1], lookAt[2],
        up[0], up[1], up[2]
    );
}


void Camera::SetRotateX(GLfloat angle) {

    forward[0] = 0.0f; forward[1] = 0.0f; forward[2] = -1.0f;
    right[0] = 1.0f; right[1] = 0.0f; right[2] = 0.0f;
    up[0] = 0.0f; up[1] = 1.0f; up[2] = 0.0f;                

    RotateX(angle);
}

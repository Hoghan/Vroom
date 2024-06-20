#include "Vroom/Render/Camera/FirstPersonCamera.h"

#include <glm/ext/matrix_transform.hpp>

namespace vrm
{

FirstPersonCamera::FirstPersonCamera(const glm::vec3& position, const glm::vec3& rotation)
    : m_WorldPosition(position), m_Rotation(rotation)
{
}

FirstPersonCamera::FirstPersonCamera(float near, float far, float fov, float aspectRatio, const glm::vec3& position, const glm::vec3& rotation)
    : PerspectiveCameraBasic(near, far, fov, aspectRatio), m_WorldPosition(position), m_Rotation(rotation)
{
}

void FirstPersonCamera::setWorldPosition(const glm::vec3& pos)
{
    m_WorldPosition = pos;
    markViewDirty();
}

void FirstPersonCamera::setRotation(const glm::vec3& rot)
{
    m_Rotation = rot;
    markViewDirty();
}

void FirstPersonCamera::addYaw(float yaw)
{
    m_Rotation.y += yaw;
    markViewDirty();
}

void FirstPersonCamera::addPitch(float pitch)
{
    m_Rotation.z += pitch;
    markViewDirty();
}

void FirstPersonCamera::addRoll(float roll)
{
    m_Rotation.x += roll;
    markViewDirty();
}

void FirstPersonCamera::move(const glm::vec3& delta)
{
    m_WorldPosition = m_WorldPosition + delta;
    markViewDirty();
}

glm::mat4 FirstPersonCamera::onViewComputed() const
{
    glm::mat4 view = glm::mat4(1.f);
    view = glm::rotate(view, glm::radians(m_Rotation.x), glm::vec3(1.f, 0.f, 0.f));
    view = glm::rotate(view, glm::radians(m_Rotation.y), glm::vec3(0.f, 1.f, 0.f));
    view = glm::rotate(view, glm::radians(m_Rotation.z), glm::vec3(0.f, 0.f, 1.f));
    view = glm::translate(view, -m_WorldPosition);
    return view;
}

} // namespace vrm
#include "Vroom/Render/Camera/CameraBasic.h"

namespace vrm
{

CameraBasic::CameraBasic(float near, float far)
    : m_Near(near), m_Far(far)
{
    markProjectionDirty();
}

void CameraBasic::setNear(float near)
{
    m_Near = near;
    markProjectionDirty();
}

void CameraBasic::setFar(float far)
{
    m_Far = far;
    markProjectionDirty();
}

const glm::mat4 &CameraBasic::getView() const
{
    computeView();
    return m_View;
}

const glm::mat4 &CameraBasic::getProjection() const
{
    computeProjection();
    return m_Projection;
}

const glm::mat4 &CameraBasic::getViewProjection() const
{
    computeViewProjection();
    return m_ViewProjection;
}

glm::vec3 CameraBasic::getForwardVector() const
{
    return glm::inverse(getView()) * glm::vec4{0.f, 0.f, -1.f, 1.f};
}

glm::vec3 CameraBasic::getUpVector() const
{
    return glm::inverse(getView()) * glm::vec4{0.f, 1.f, 0.f, 1.f};
}

glm::vec3 CameraBasic::getRightVector() const
{
    return glm::inverse(getView()) * glm::vec4{1.f, 0.f, 0.f, 1.f};
}

void CameraBasic::computeView() const
{
    if (!m_ViewDirty) return;

    m_View = onViewComputed();

    m_ViewDirty = false;
}

void CameraBasic::computeProjection() const
{
    if (!m_ProjectionDirty) return;

    m_Projection = onProjectionComputed();

    m_ProjectionDirty = false;
}

void CameraBasic::computeViewProjection() const
{
    if (!m_ViewProjectionDirty) return;

    m_ViewProjection = getProjection() * getView();

    m_ViewProjectionDirty = false;
}

} // namespace vrm
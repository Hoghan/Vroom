#include "Scripts/SuzanneScript.h"

#include <Vroom/Core/Log.h>
#include <Vroom/Scene/Entity.h>
#include <Vroom/Scene/Components/TransformComponent.h>

SuzanneScript::SuzanneScript(float circleRadius, float startAngle, float speed)
    : vrm::ScriptComponent(), m_CircleRadius(circleRadius), m_Angle(startAngle), m_Speed(speed)
{
}

SuzanneScript::~SuzanneScript()
{
}

void SuzanneScript::onSpawn()
{
    LOG_INFO("Suzanne spawned!");
}

void SuzanneScript::onUpdate(float dt)
{
    m_Angle += m_Speed * dt;

    auto& transform = getEntity().getComponent<vrm::TransformComponent>();
    transform.setPosition({ m_CircleRadius * cos(m_Angle), 0.f, m_CircleRadius * sin(m_Angle) });
    transform.setRotation({ 0.f, -glm::degrees(m_Angle), 0.f });
}

void SuzanneScript::onDestroy()
{
    LOG_INFO("Suzanne destroyed!");
}
#include "Vroom/Core/Application.h"

#include "Vroom/Core/Assert.h"
#include "Vroom/Event/GLFWEventsConverter.h"

namespace vrm
{

Application::Application(int argc, char** argv)
{
    Log::Init();
    GLFWEventsConverter::Init();

    VRM_ASSERT(initGLFW());
    m_Window = std::make_unique<Window>();
    VRM_ASSERT(m_Window->create("Vroom engine", 600, 400));

    glewExperimental = TRUE;
    VRM_ASSERT(glewInit() == GLEW_OK);

    m_Renderer = std::make_unique<Renderer>();
    m_Renderer->setViewport({ 0, 0 }, { 800, 800 });

    LOG_TRACE("Vroom application created.");
}

Application::~Application()
{
    m_Window.release();
    glfwTerminate();
    m_Renderer.release();
}

bool Application::initGLFW()
{
    if (!glfwInit()) return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    return true;
}

void Application::run()
{
    while (!m_Window->requestedClose())
    {
        update();
        draw();
    }
}

void Application::update()
{
    m_Window->updateEvents();
    while (m_Window->hasPendingEvents())
    {
        Event e = m_Window->pollEvent();

        std::string type;

        if (e.keyEvent) type = "Key event";
        else if (e.mouseEvent) type = "Mouse event";
        else if (e.scrollEvent) type = "Scroll event";

        LOG_TRACE("{} triggered.", type);
    }
}

void Application::draw()
{
    m_Renderer->beginScene();


    m_Renderer->endScene();
    m_Window->swapBuffers();
}

} // namespace vrm

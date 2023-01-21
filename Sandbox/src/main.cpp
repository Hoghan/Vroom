#include <Vroom/Core/Application.h>

#include <Vroom/Scene/Scene.h>
#include <Vroom/Scene/Entity.h>

class MyScript : public Vroom::ScriptComponent
{
public:
	MyScript()
	{
		Vroom::Application::Get().registerEventCallback("Exit", VR_BIND_FN(onExit));
	}

	virtual void onUpdate() override
	{
		if(getEventState("MoveLeft"))
			moveVector += { -1.f, 0.f};
		if(getEventState("MoveRight"))
			moveVector += { 1.f, 0.f};
		if(getEventState("MoveUp"))
			moveVector += { 0.f, -1.f };
		if(getEventState("MoveDown"))
			moveVector += { 0.f, 1.f };

		float moveLength = std::sqrt(moveVector.x * moveVector.x + moveVector.y * moveVector.y);

		if (moveLength > 0.0001f)
		{
			moveVector = moveVector * getDeltaTime() * moveSpeed / moveLength;
		}

		auto& transform = getEntity().getComponent<Vroom::TransformComponent>();
		transform.setTranslation(transform.getTranslation() + moveVector);

		moveVector = { 0.f, 0.f };
	}

	void onExit(bool pressed)
	{
		quitGame();
	}

private:
	float moveSpeed = 100.f;
	sf::Vector2f moveVector;
};

class MyScene : public Vroom::Scene
{
public:
	MyScene()
	{
		auto entity = createEntity();
		auto& spriteComponent = entity.addComponent<Vroom::SpriteComponent>
			(getAssetManager().getAsset<Vroom::Sprite>("Data/Sprites/SpriteTest.sprite"));

		entity.addScriptComponent<MyScript>(); 

		auto& transformComponent = entity.getComponent<Vroom::TransformComponent>();
		transformComponent.setScale(.2f);

		// Tiles
		for (size_t i = 0; i < 10; i++)
		{
			auto topBrick = createEntity();
			topBrick.addComponent<Vroom::SpriteComponent>(getAssetManager().getAsset<Vroom::Sprite>("Data/Sprites/brick.sprite"));
			topBrick.getComponent<Vroom::TransformComponent>().setTranslation(64.f * i, 0.f);

			auto botBrick = createEntity();
			botBrick.addComponent<Vroom::SpriteComponent>(getAssetManager().getAsset<Vroom::Sprite>("Data/Sprites/brick.sprite"));
			botBrick.getComponent<Vroom::TransformComponent>().setTranslation(64.f * i, 9.f * 64.f);
		}
		for (size_t i = 1; i < 9; i++)
		{
			auto leftBrick = createEntity();
			leftBrick.addComponent<Vroom::SpriteComponent>(getAssetManager().getAsset<Vroom::Sprite>("Data/Sprites/brick.sprite"));
			leftBrick.getComponent<Vroom::TransformComponent>().setTranslation(0.f, 64.f * i);

			auto rightBrick = createEntity();
			rightBrick.addComponent<Vroom::SpriteComponent>(getAssetManager().getAsset<Vroom::Sprite>("Data/Sprites/brick.sprite"));
			rightBrick.getComponent<Vroom::TransformComponent>().setTranslation(64.f * 9.f, i * 64.f);
		}
	}
};

int main()
{
	std::unique_ptr<Vroom::Application> app = std::make_unique<Vroom::Application>(64 * 10, 64 * 10, "A Vroom game");

	app->registerEvent("MoveLeft");
	app->registerEvent("MoveRight");
	app->registerEvent("MoveUp");
	app->registerEvent("MoveDown");
	app->registerEvent("Exit");

	app->bindEventInput("MoveLeft", sf::Keyboard::Q);
	app->bindEventInput("MoveLeft", sf::Keyboard::Left);
	app->bindEventInput("MoveRight", sf::Keyboard::D);
	app->bindEventInput("MoveUp", sf::Keyboard::Z);
	app->bindEventInput("MoveDown", sf::Keyboard::S);
	app->bindEventInput("Exit", sf::Keyboard::Escape);

	app->setScene(new MyScene());

	app->run();

	return 0;
}
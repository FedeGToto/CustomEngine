#include <TestScene.h>

void TestScene::OnCreate(SDL_Renderer* gameRenderer)
{
	Scene::OnCreate(gameRenderer);

	testActor = new Actor();
	Texture* testTexture = new Texture(currentRenderer, "./Resources/Sprites/TestSprite.bmp");
	Vector2 newVector2 = Vector2(15, 115);
	testActor->Start(newVector2, testTexture);
}

void TestScene::Update()
{
	Scene::Update();

	Vector2 newPos;
	if (keyDown)
	{
		newPos.y = 100 * Game::deltaTime;
	}
	else if (keyUp)
	{
		newPos.y = -100 * Game::deltaTime;
	}

	if (keyLeft)
	{
		newPos.x = -100 * Game::deltaTime;
	}
	else if (keyRight)
	{
		newPos.x =  100 * Game::deltaTime;
	}

	testActor->setPos(testActor->getPos() + newPos);
}
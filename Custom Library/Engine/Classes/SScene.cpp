#include "SScene.h"

SScene::SScene(char* Name) : ZObject(Name)
{
}

SScene::~SScene()
{
	for (int i = 0; i < dpxSceneObjects.Size(); i++)
	{
		delete dpxSceneObjects.Pop();
	}
}

void SScene::Update(float deltaTime)
{
	for (int i = 0; i < dpxSceneObjects.Size(); i++)
	{
		dpxSceneObjects[i]->Update(deltaTime);
	}
}

void SScene::Draw(aie::Renderer2D* Renderer)
{
	for (int i = 0; i < dpxSceneObjects.Size(); i++)
	{
		dpxSceneObjects[i]->Draw(Renderer);
	}
}

void SScene::AddObject(ZObject * Object)
{
	dpxSceneObjects.Push(Object);
}

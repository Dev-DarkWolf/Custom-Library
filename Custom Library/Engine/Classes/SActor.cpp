#include "SActor.h"

SActor::SActor(char * Name) : ZObject(Name)
{

}

SActor::SActor(char* Name, ZObject* Parent) : ZObject(Name, Parent)
{
	pParent = Parent;
}

SActor::~SActor()
{
}

void SActor::Update(float deltaTime)
{
	for (int i = 0; i < dpxSceneObjects.Size(); i++)
	{
		dpxSceneObjects[i]->Update(deltaTime);
	}
}

void SActor::Draw(aie::Renderer2D* Renderer)
{
	for (int i = 0; i < dpxSceneObjects.Size(); i++)
	{
		dpxSceneObjects[i]->Draw(Renderer);
	}
}

Matrix3 SActor::ActorToWorld()
{
	return Matrix3();
}

void SActor::AddWorldOffset(Vector2 vOffset)
{
}

bool SActor::IsRoot()
{
	if (pParent->GetParent())
	{
		return true;
	}
	return false;
}

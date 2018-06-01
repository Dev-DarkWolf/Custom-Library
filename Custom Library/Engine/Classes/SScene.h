#pragma once
#include "ZObject.h"

#include "DynamicArray.h"
#include "Matrix3.h"

class SScene : public ZObject
{
public:
	SScene(char* Name);
	virtual ~SScene();


	// --- Defineable Class Functions ---
	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* Renderer);

	// --- Pre-Defined Class Functions ---
	virtual void AddObject(ZObject* Object);

private:
	Matrix3 mGlobalTransform;
	wolf::DynamicArray<ZObject*> dpxSceneObjects;
};


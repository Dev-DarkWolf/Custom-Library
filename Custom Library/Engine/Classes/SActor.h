#pragma once
#include "SScene.h"
#include "ZObject.h"

#include "Matrix3.h"
#include "Vector2.h"

class SActor : public ZObject
{
public:
	SActor(char* Name);
	SActor(char* Name, ZObject* Parent);
	virtual ~SActor();

	// --- Defineable Class Functions ---
	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* Renderer);

	// --- Pre-Defined Class Functions ---
	Matrix3 ActorToWorld(); //Global Transform Of Root
	void AddWorldOffset(Vector2 vOffset);
	bool IsRoot();

protected: 
	Matrix3 mGlobalTransform;
	Matrix3 mLocalTransform;
	wolf::DynamicArray<ZObject*> dpxSceneObjects;
};


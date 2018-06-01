#pragma once
#include "DynamicArray.h"
#include "Matrix3.h"

#include "Texture.h"
#include "Renderer2D.h"

class ZObject
{
public:
	ZObject(char* Name);
	ZObject(char * Name, ZObject * Parent);
	virtual ~ZObject();

	// --- Defineable Class Functions ---
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(aie::Renderer2D* Renderer) = 0;

	// --- Pre-Defined Class Functions ---
	void Rename(char* newName);
	ZObject* GetParent();
	bool operator != (ZObject* Compare);
	bool operator == (ZObject* Compare);

protected:
	char stName[140];
	ZObject* pParent = nullptr;
};



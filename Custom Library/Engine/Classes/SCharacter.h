#pragma once
#include "SActor.h"
#include "Input.h"

class SCharacter : public SActor
{
public:
	SCharacter(char* Name);
	SCharacter(char* Name, ZObject* Parent);
	virtual ~SCharacter();

	// --- Defineable Class Functions ---
	virtual void Update(float deltaTime);
	virtual void Draw(aie::Renderer2D* Renderer);

	void GetInputHandle();

	Vector2 vPlayerPos;
private:
	aie::Input* input;
	aie::Texture* m_playerTexture;

	float fSpeed = 250.0f;
};


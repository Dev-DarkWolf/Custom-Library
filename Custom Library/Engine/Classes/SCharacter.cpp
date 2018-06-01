#include "SCharacter.h"
#include "Input.h"

#include "Vector2.h"
#include "Matrix3.h"

SCharacter::SCharacter(char* Name) : SActor(Name)
{
	GetInputHandle();
	m_playerTexture = new aie::Texture("./textures/ship.png"); //Texture Refrence
}

SCharacter::SCharacter(char * Name, ZObject * Parent) : SActor(Name, Parent)
{
	GetInputHandle();
	m_playerTexture = new aie::Texture("./textures/ship.png"); //Texture Refrence
}

SCharacter::~SCharacter()
{
	delete m_playerTexture;
	m_playerTexture = nullptr;
}

void SCharacter::Update(float deltaTime)
{
	//User Input
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		vPlayerPos.y += fSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		vPlayerPos.y -= fSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		vPlayerPos.x += fSpeed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		vPlayerPos.x -= fSpeed * deltaTime;
	}

	//Update Position
	Matrix3 mPosition;
	mPosition.setPosition(mGlobalTransform.getPosition());
	mPosition[2] += (Vector3)vPlayerPos;

	//Physics

	//Colition

}

void SCharacter::Draw(aie::Renderer2D* Renderer)
{
	Renderer->begin();
///-------------------------------------------------	

	Renderer->drawSpriteTransformed3x3(m_playerTexture, (float*)mGlobalTransform);

///-------------------------------------------------	
	Renderer->end();
}

void SCharacter::GetInputHandle()
{
	input = aie::Input::getInstance();
}

#pragma once
#include "ColorTypes.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Font.h"

#include <string.h>

struct ButtonVarablesStruct
{
	//All Changes That Can Be Made To Button
};

class BasicBtn
{
public:
	BasicBtn(aie::Renderer2D* renderer, aie::Font* font, char text[32] = "...", float posX = (1920 / 2), float posY = (1080 / 2))
	{
		m_2dRenderer = renderer;
		m_font = font;
		m_posX = posX;
		m_posY = posY;
		strcpy_s(m_text, text);
	
	}
	~BasicBtn()
	{
	}

	void DrawButton()
	{
		m_2dRenderer->begin();
		if (bHasShadow)
		{
			m_2dRenderer->setRenderColour(shadowdColor.r, shadowdColor.g, shadowdColor.b, shadowdColor.A);
			m_2dRenderer->drawBox(m_posX + 2, m_posY - 2, sizeX + 2, sizeY + 2, 0.0f, zOrder+2);
		}
		if (bHasText)
		{
			m_2dRenderer->setRenderColour(textColor.r, textColor.g, textColor.b, textColor.A);
			m_2dRenderer->drawText(m_font, m_text, m_posX - (sizeX / 2) + 35, m_posY - (sizeY / 2) + 15, zOrder);

		}
		m_2dRenderer->setRenderColour(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.A);
		m_2dRenderer->drawBox(m_posX, m_posY, sizeX, sizeY, 0.0f, zOrder+1);
		m_2dRenderer->end();
	}

private:

	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	float m_posX, m_posY;
	float paddingX = 1.5f, paddingY = 1.5f;
	float sizeX = 200.0f, sizeY = sizeX /3;
	float zOrder = 0;

	Color_rgbA textColor{ 0.75f,0.75f,0.75f,1.0f };
	Color_rgbA backgroundColor{ 0.9f,0.9f,0.9f,1.0f };
	Color_rgbA shadowdColor{ 0.5f,0.5f,0.5,1.0f };

	bool bHasText = true;
	int m_fontSize = 32;
	bool bHasShadow = true;
	char m_text[32];
};

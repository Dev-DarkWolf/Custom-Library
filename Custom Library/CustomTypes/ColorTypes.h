#pragma once

struct Color_rgbA
{
	float r = 0;
	float g = 0;
	float b = 0;
	float A = 1.0f;

	Color_rgbA(float red,float green, float blue,float Alpha)
	{
		r = red;
		g = green;
		b = blue;
		A = Alpha;

		//--Red--
		if (r > 1.0f)
		{
			r = 1.0f;
		}
		else if (r < 0.0f)
		{
			r = 0.0f;
		}
		//--Green--
		if (g > 1.0f)
		{
			g = 1.0f;
		}
		else if (g < 0.0f)
		{
			g = 0.0f;
		}
		//--Blue--
		if (b > 1.0f)
		{
			b = 1.0f;
		}
		else if (b < 0.0f)
		{
			b = 0.0f;
		}
		//--Alpha--
		if (r > 1.0f)
		{
			r = 1.0f;
		}
		else if (r < 0.0f)
		{
			r = 0.0f;
		}
	}
};
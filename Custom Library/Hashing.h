//----------------------------------------
//File Name: Deque.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#pragma once
#include "MathLibrary.h"

#define PRIME 86969

namespace wolf {
	class Hashing
	{
	public:
		unsigned StringHash(char* value)
		{
			int nSize = mathHandle.SizeOfString(value);

			unsigned hHash = 0;
			for (int i = 0; i < nSize; i++)
			{
				hHash = (hHash + nSeed) + value[i];
			}
			return hHash;
		};

	private:
		int nSeed = PRIME;
		MathLibrary mathHandle;
	};

} //End namespace
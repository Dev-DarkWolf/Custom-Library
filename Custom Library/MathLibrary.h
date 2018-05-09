//----------------------------------------
//File Name: MathLibrary.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

#pragma once
#include <string>
#include "DynamicArray.h"

namespace wolf {
	class MathLibrary
	{
	public:
		int SizeOfString(char* word) //Returns Size Of String In Bytes
		{
			int nBytes = 0;
			char tempChar = '1';

			while (tempChar != '\0')
			{
				tempChar = word[nBytes];
				nBytes++;
			}
			return nBytes;
		}

	private:

	};

}; //End namespace
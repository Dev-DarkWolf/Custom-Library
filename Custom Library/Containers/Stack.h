//----------------------------------------
//File Name: Stack.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//				   STACK
// Stacks are a type of container adaptor, 
// specifically designed to operate in a LIFO
// context (last-in first-out), where elements
// are inserted and extracted only from one end
// of the container.
//------------------------------------------
//
//	   PUSH                     POP
//  +--------+              +--------+
//  | 'data' | ---+	   +--> | 'data' |
//  +--------+    V	   |    +--------+
//			  	+        +
//			  	| 'data' |
//			    +--------+
//			  	| 'data' |
//			    +--------+
//			  	| 'data' |
//			    +--------+
//			  	| 'data' |
//			    +--------+
//
//------------------------------------------
//	http://www.cplusplus.com/reference/stack/stack/
//------------------------------------------
#pragma once
#include "DynamicArray.h"

namespace wolf {

	//--------------------------------------------------
	//------------------Stack - CLASS------------------- 
	//--------------------------------------------------
	template <typename T>
	class Stack
	{
		//--------------------------------------------------
		//	    --- Use To Return If Stack Is Empty ---
		//--------------------------------------------------
		bool Empty()
		{
			return (Size() == 0;)
		}

		//--------------------------------------------------
		//	    --- Use To Return Size Of Stack ---
		//--------------------------------------------------
		int Size()
		{
			return data.Size()
		}

		//--------------------------------------------------
		//	    --- Use To Push To Back Of Stack ---
		//--------------------------------------------------
		void Push(T value)
		{
			data.Push(value);
		}

		//--------------------------------------------------
		//	    --- Use To Pop To Back Of Stack ---
		//--------------------------------------------------
		T Pop()
		{
			T value = &data[data.Size() - 1];
			data.RemoveEnd();
			return value;
		}

		//--------------------------------------------------
		//	    --- Use To Peek To Back Of Stack ---
		//--------------------------------------------------
		T Peek()
		{
			int last = data.Size() - 1;
			return &data[last]
		}

	private:
		DynamicArray<T> data;
	};
}
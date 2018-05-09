//----------------------------------------
//File Name: Deque.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//	               DEQUE
// Deque (usually pronounced like "deck") is 
// an irregular acronym of double-ended queue. 
// Double-ended queues are sequence containers 
// with dynamic sizes that can be expanded or 
// contracted on both ends (either its front or its back).
//------------------------------------------
//			START				INSERTED NODE				 END
//	+-------------------+	+-------------------+	+-------------------+
//	|       'null'      |	|      'data'       |	|      'null'       |
//	|-------------------|<->|-------------------|<->|-------------------|
//	| 'null'  | 'pNext' |	| 'pPrev' | 'pNext' |	| 'pPrev' |  'null' |
//	+-------------------+	+-------------------+	+-------------------+
//						  ^                       ^
//	EnqueueFront ---------+						  +---------- EnqueueBack
//	DequeueFront											  DequeueBack
//
//------------------------------------------
//	http://www.cplusplus.com/reference/deque/deque/
//------------------------------------------
#pragma once
#include "LinkedList.h"

namespace wolf {

	//--------------------------------------------------
	//------------------Deque - CLASS-------------------
	//	Functions:
	//		- Clear
	//		- EnqueueBack
	//		- EnqueueFront
	//		- DequeueFront
	//		- DequeueBack
	//		- PeekFront
	//		- PeekEnd
	//		- Size
	//--------------------------------------------------
	template<typename T>
	class Deque
	{
	public:
		//--------------------------------------------------
		//           --- Use To Clear Deque ---
		//--------------------------------------------------
		void Clear()
		{
			m_pDeque->Clear();
		}

		//--------------------------------------------------
		//  --- Use To Push Data To Back Of Deque ---
		//--------------------------------------------------
		void EnqueueBack(T value)
		{
			m_pDeque.InsertEnd(value);
		}

		//--------------------------------------------------
		//  --- Use To Push Data To Front Of Deque ---
		//--------------------------------------------------
		void EnqueueFront(T value)
		{
			m_pDeque.InsertFront(value);
		}

		//--------------------------------------------------
		// --- Use To Remove & Return Data From Back Of Deque ---
		//--------------------------------------------------
		T DequeueBack()
		{
			Node<T>* end = m_pDeque.PeekEnd();
			T value = end->m_pPrev->m_pData;

			m_pDeque.Remove(end->m_pPrev);

			return value;
		}

		//--------------------------------------------------
		//--- Use To Remove & Return Data From Front Of Deque ---
		//--------------------------------------------------
		T DequeueFront()
		{
			Node<T>* start = m_pDeque.GetStart();
			T value = start->m_pNext->m_pData;

			m_pDeque.Remove(start->m_pNext);

			return value;
		}

		//--------------------------------------------------
		// --- Use To Return Data At Start Of Deque ---
		//--------------------------------------------------
		T PeekFront()
		{
			return m_pDeque.PeekFront();
		}

		//--------------------------------------------------
		// --- Use To Return Data At Start Of Deque ---
		//--------------------------------------------------
		T PeekEnd()
		{
			return m_pDeque.PeekEnd();
		}

		//--------------------------------------------------
		//	 --- Use To Return Size Of LinkedList ---
		//--------------------------------------------------
		int Size()
		{
			return m_pDeque.Size();
		}
		
		//--------------------------------------------------
		//	 --- Use To Return Pointer In LinkedList ---
		//--------------------------------------------------
		T DebugPeekAt(int nPosition)
		{
			return m_pDeque.PeekPosition(nPosition)->m_pData;
		}

		//--------------------------------------------------
		//	 --- Use To Return Pointer In LinkedList ---
		//--------------------------------------------------
		void DebugPopPointer(T pPointer)
		{
			m_pDeque.PopPosition(m_pDeque.FindIndex(pPointer));
		}

	private:
		LinkedList<T> m_pDeque;
	};

}//END NAMESPACE
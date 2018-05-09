//----------------------------------------
//File Name: ObjectPool.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//             OBJECT POOLING
// Holds Objects To Be Reused When Drawing
// And Using In-Game. Prevents The 'new' & 
// 'delete' Function Being Called While 
// Player Is In Game.  
//------------------------------------------
//        OffScreen
//        --- *	 
//     	  |	  *
//		  |	  *
//		  |	  *
//  Reuse |   *     <--- Objects/BUllets
//		  |   *
//		  |   *
//        --- *
//           <T>    <--- Ship/Gun
//
//------------------------------------------
// http://best-practice-software-engineering.ifs.tuwien.ac.at/patterns/objectpool.html
//------------------------------------------

#pragma once
#include "DynamicArray.h"

namespace wolf {

	//--------------------------------------------------
	//----------Remove Template Pointer - STRUCT--------
	//--------------------------------------------------
	template <typename T>
	struct remove_pointer
	{
		typedef T type;
	};
	template <typename T>
	struct remove_pointer<T*>
	{
		typedef T type;
	};

	//--------------------------------------------------
	//---------------ObjectPool - CLASS-----------------
	//--------------------------------------------------
	template <typename T>
	class ObjectPool
	{
	public:
		//--------------------------------------------------
		//	             --- Constructor ---
		//--------------------------------------------------
		//	Set 'm_nPoolSize' As 'nPoolSize'
		//	Create Two Dynamic Arrays For Storing Objetcs
		//		'm_availablePool' = Objects That Aren't Being Used
		//		'm_used' = Objects That Are Being Used
		//
		//	Loop Though For The Size Of 'nPoolSize'
		//		Create 'new' Templated Object
		//		'Push' That Object Into 'm_avaliable' Array
		//--------------------------------------------------
		ObjectPool(int nPoolSize)
		{
			m_nPoolSize = nPoolSize;

			m_availablePool = new wolf::DynamicArray(nPoolSize);
			m_usedPool = new wolf::DynamicArray(nPoolSize);

			for (int i = 0; i < nPoolSize; i++)
			{
				typedef typename remove_pointer<T>::type type;
				T object = new type;
				m_availablePool->Push(object);
			}
		}

		//--------------------------------------------------
		//	            --- Deconstructor ---
		//--------------------------------------------------
		//	For Each Object In 'm_avaliable'
		//		'delete' Object
		//	For Each Object In 'm_used'
		//		'delete' Object
		//--------------------------------------------------
		~ObjectPool()
		{
			for (int i = 0; i < m_availablePool->Size(); i++)
			{
				delete m_availablePool[i];
			}
			for (int i = 0; i < m_usedPool->Size(); i++)
			{
				delete m_usedPool[i];
			}
		}

		//--------------------------------------------------
		//	 --- Use To Return Object In Pool To Use  ---
		//--------------------------------------------------
		//	Define 'Allocate' 
		//		Set 'object' As Popped Object In 'm_availablePool'
		//		Push 'object' Into 'm_usedPool'
		//		Return 'object'
		//--------------------------------------------------
		T Allocate()
		{
			T object = m_availablePool->Pop();
			m_usedPool->Push(object);
			return object;
		}

		//--------------------------------------------------
		//	 --- Use To Return Object In Pool To Use  ---
		//--------------------------------------------------
		//	Define 'DeAllocate(T objectToFind)'
		//		FindAndDestroy 'objectToFind' In 'm_usedPool'
		//		Push 'objectToFind' Into 'm_availiablePool'
		//--------------------------------------------------
		void DeAllocate(T objectToFind)
		{
			m_usedPool->FindAndDestroy(objectToFind);
			m_availablePool->Push(objectToFind)
		}

		int Size()
		{
			return m_nPoolSize;
		}

	private:
		wolf::DynamicArray<T>* m_availablePool;
		wolf::DynamicArray<T>* m_usedPool;
		int m_nPoolSize;
	};
}//END NAMESPACE

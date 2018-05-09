//----------------------------------------
//File Name: DynamicArray.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//				DYNAMIC ARRAY
// A dynamic array is not the same thing as a 
// dynamically allocated array, which is an array
// whose size is fixed when the array is allocated,
// although a dynamic array may use such a fixed-size
// array as a back end.
//------------------------------------------
//
//   +--------+--------+
//   | 'data' | UNUSED |  <-- Container Has Spot Left
//   +--------+--------+
//   +--------+--------+
//   | 'data' | 'data' |  <-- Container Full - Resize Array
//   +--------+--------+
//   +--------+--------+--------+--------+
//   | 'data' | 'data' | 'data' | UNUSED |    <-- Container Resized And Data Added
//   +--------+--------+--------+--------+
//
//------------------------------------------
//	https://brilliant.org/wiki/dynamic-arrays/
//------------------------------------------

#pragma once
#include <memory.h> //Used For 'memcpy'

namespace wolf {
	//--------------------------------------------------
	//--------------DynamicArray - CLASS---------------- 
	//--------------------------------------------------
	template <typename T>
	class DynamicArray
	{
	public:
		//--------------------------------------------------
		//	  --- Used For Sorting Dynamic Array ---
		//	- !!! USER TO CREATE CUSTOM COMPARE FUNTION !!! -
		//--------------------------------------------------
		//	Typedef 'bool' As 'CompareFunction'
		//--------------------------------------------------
		typedef bool(*CompareSort)(T lhs, T rhs);

		//--------------------------------------------------
		//	  --- Used For Searching Dynamic Array ---
		//	- !!! USER TO CREATE CUSTOM COMPARE FUNTION !!! -
		//--------------------------------------------------
		//	Typedef 'bool' As 'CompareFunction'
		//--------------------------------------------------
		typedef int(*CompareSearch)(T lhs, T rhs);

		//--------------------------------------------------
		//	             --- Constructor ---
		//--------------------------------------------------
		//	Define DynamicArray(int initSize)
		//		'int initSize' = Capacity Of Array
		//
		//	Set 'm_pData' As A New Array Item * 'initSize'
		//	Set 'm_nCapacity' As 'initSize'
		//	Set 'm_nUsed' As 0
		//--------------------------------------------------
		DynamicArray(int initSize = 1)
		{
			m_pData = new T[initSize];
			m_nCapacity = initSize;
			m_nUsed = 0;
		}

		//--------------------------------------------------
		//	           --- Deconstructor ---
		//--------------------------------------------------
		//	Delete Array
		//--------------------------------------------------
		~DynamicArray()
		{
			delete[] m_pData;
		}

		//--------------------------------------------------
		//		  --- Use To Push To End Of Array ---
		//--------------------------------------------------
		//	Define Push(T data) 
		//		'T data' = Data To Add Into The Array
		//
		//	If 'm_nUsed' Is Greater OR Equil To Capacity Of Array
		//		- Resize Array
		//	else 
		//		- Add 'data' To Array
		//		- Add One To 'm_nUsed'
		//--------------------------------------------------
		void Push(T data)
		{
			if (m_nUsed >= m_nCapacity)
			{
				Resize();
			}
			m_pData[m_nUsed] = data;
			m_nUsed++;
		}

		//--------------------------------------------------
		//	   --- Use To Push To A Point In Array ---
		//--------------------------------------------------
		//	Define PushAt(int position, T data, bool replace = false)
		//		'int position' = Position In Array To Change/Add
		//		'T data' = Data To Add Into The Array
		//		'bool replace' = Will The Array Replace Data Or Add
		//						('false' = Add | 'true' = Replace)
		//
		//	If 'replace' Is Equil To True
		//		Set 'm_pData' As 'data'
		//	else
		//		If 'm_nUsed' Is Greater OR Equil To Capacity Of Array
		//			- Resize Array
		//		else 
		//			- Add 'data' To Array
		//			- Add One To 'm_nUsed'
		//--------------------------------------------------
		void PushAt(int position, T data, bool replace = false)
		{

			if (replace)
			{
				m_pData[position] = data;
			}
			else
			{
				if (m_nUsed + 1 >= m_nCapacity)
				{
					Resize();
				}
				m_nUsed++;
				memcpy(&m_pData[position + 1], &m_pData[position], sizeof(T) * (m_nUsed - (position + 1)));
				m_pData[position] = data;

			}
		}

		//--------------------------------------------------
		//  --- Use To Return & Pop Last Item In Array ---
		//--------------------------------------------------
		//	Define T Pop
		//
		//		Minus One From 'm_nUsed'
		//	Return 'm_pData[last index]' - Will Return Data At Last Index
		//--------------------------------------------------
		T Pop()
		{
			T data = m_pData[m_nUsed];
			m_nUsed--;
			return data;
		}

		//--------------------------------------------------
		//	   --- Use To Return & Pop Point In Array ---
		//--------------------------------------------------
		//	Define T Pop (int position)
		//		'int position' = Position To Return & Pop
		//
		//		Copy Memory Block From 'position' To End Of Array Into Previouse Point
		//		Minus One From 'm_nUsed'
		//	Return 'm_pData[last index]' - Will Return Data At Last Index
		//--------------------------------------------------
		T PopAt(int position)
		{
			T data = m_pData[position];
			memcpy(&m_pData[position], &m_pData[position + 1], sizeof(T) * (m_nUsed - (position + 1)));
			m_nUsed--;
			return data;
		}
		//--------------------------------------------------
		//	 --- Use To Return Data At Point In Array ---
		//--------------------------------------------------
		T GetAt(int position)
		{
			return m_pData[position];
		}

		//--------------------------------------------------
		//	   --- Use To Remove End Of Array ---
		//--------------------------------------------------
		//	Define RemoveEnd
		//		
		//	Minus One From 'm_nUsed'
		//--------------------------------------------------
		void RemoveEnd()
		{
			m_nUsed--;
		}

		//--------------------------------------------------
		//	   --- Use To Remove Index At Point In Array ---
		//--------------------------------------------------
		void RemoveAt(int position)
		{
			memcpy(&m_pData[position], &m_pData[position + 1], sizeof(T) * (m_nUsed - (position + 1)));
			m_nUsed--;
		}

		//--------------------------------------------------
		//   --- Use To Find And Remove Data In Array ---
		//--------------------------------------------------
		void FindAndDestroy(T value)
		{
			for (int i = 0; i < m_nUsed; i++)
			{
				if (m_pData[i] == value)
				{
					RemoveAt(i);
				}
			}
		}

		//--------------------------------------------------
		//	   --- Use To Return Size Of Array ---
		//--------------------------------------------------
		//	Define T Size
		//		
		//	Return 'm_nUsed' - Size Of Array (Not Capacity)
		//--------------------------------------------------
		int Size()
		{
			return m_nUsed;
		}

		//--------------------------------------------------
		//	   --- Use For Bubble Sorting Dynamic Array ---
		//--------------------------------------------------
		//	Create Temp 'T' Variable
		//	For Loop Though Array Using 'm_nUsed' - 1
		//		For Loop Though Each Object Again
		//			If Users Custom Compare Is True
		//				Set 'pivot' As 'm_pData' At 'j'
		//				Set 'm_pData' As 'm_pData' + 1
		//				Set 'm_pData' + 1 As 'pivot'
		//--------------------------------------------------
		void BubbleSort(CompareSort compare)
		{
			T temp;
			for (int i = 0; i < m_nUsed - 1; i++)
			{
				for (int j = 0; j < m_nUsed - 1; j++)
				{
					if (compare(m_pData[j], m_pData[j + 1]))
					{
						temp = m_pData[j];
						m_pData[j] = m_pData[j + 1];
						m_pData[j + 1] = temp;
					}
				}
			}
		}

		//--------------------------------------------------
		//	--- Use For Insertion Sorting Dynamic Array ---
		//--------------------------------------------------
		//	
		//--------------------------------------------------
		void InsertionSort(CompareSort compare)
		{
			T temp;
			int j = 0;
			for (int i = 0; i < m_nUsed - 1; i++)
			{
				temp = m_pData[i];
				 j = i - 1;
				while ((j >= 0) && (compare(m_pData[j], temp))) // < 
				{
					m_pData[j + 1] = m_pData[j];
					j -= 1;
					m_pData[j + 1] = temp;
				}
			}
		}
		//--------------------------------------------------
		//	--- Use For Insertion Sorting Dynamic Array ---
		//--------------------------------------------------
		//	
		//--------------------------------------------------
		void QuickSort(CompareSort compare, int nLow, int nHigh)
		{
			int nPartitionIndex = 0;
			int nP = nLow;
			int nR = nHigh;

			if (nLow < nHigh)
			{
				nPartitionIndex = Partition(compare, nP, nR);
				QuickSort(compare, nP, nPartitionIndex - 1);
				QuickSort(compare, nPartitionIndex + 1, nR);
			}
		}

		//--------------------------------------------------
		//	   --- Use For Searching For Data Dynamic Array ---
		//--------------------------------------------------
		//	
		//--------------------------------------------------
		T BinarySearch(CompareSearch searchFunction)
		{
			int nMin = 0;
			int nMax = m_nUsed - 1;
			int nPoint = (nMin + nMax) / 2;

			while (nMax >= nMin)
			{
				nPoint = (nMin + nMax) / 2;
				switch (searchFunction(m_pData[nPoint], m_pData[nPoint + 1]))
				{
				case 0: //EQUILS
					return m_pData[nPoint];
					break;
				case 1://LESS THAN
					nMin = nPoint + 1;
					break;
				case 2://GREATER THAN
					nMax = nPoint - 1;
					break;
				}
			}
		}

		//--------------------------------------------------
		//	--- Use For Returning Value At Index In Array ---
		//--------------------------------------------------
		T& operator[] (int nIndex)
		{
			return m_pData[nIndex];
		}

	private:
		//--------------------------------------------------
		//        --- Used To Resize Array ---
		//--------------------------------------------------
		//	Define Resize
		//		Set Capacity As 'Capacity * 1.5'
		//		Create Temp Array
		//		memcpy From One Array To Temp
		//		Delete Old Array Data
		//		Set Old Array As Tmp
		//		Delete Temp Array
		//		Nullptr Temp Array
		//--------------------------------------------------
		void Resize()
		{
			m_nCapacity = (int)(m_nCapacity * 1.5) + 1;
			T *pTemp = new T[m_nCapacity];
			memcpy(pTemp, m_pData, sizeof(T) * m_nUsed);
			delete[] m_pData;
			m_pData = pTemp;
		}

		int Partition(CompareSort compare, int nLow, int nHigh)
		{
			T pivot = m_pData[nHigh];
			int nI = nLow - 1;
			for (int j = nLow; j <= nHigh - 1; j++)
			{
				if (compare(m_pData[j], pivot)) //<=
				{
					nI += 1;

					T temp = m_pData[nI];
					m_pData[nI] = m_pData[j];
					m_pData[j] = temp;

				}
			}

			m_pData[nHigh] = m_pData[nI + 1];
			m_pData[nI + 1] = pivot;
			return nI + 1;
		}

		int m_nUsed; //Current Index Used
		int m_nCapacity; //Capacity Of Array
		T* m_pData; //Array Data
	};

}//END NAMESPACE
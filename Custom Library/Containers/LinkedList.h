//----------------------------------------
//File Name: LinkedList.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//	            LINKED LIST
// A linked list is a linear data structure
// where each element is a separate object. 
// Each element (Node) of a list is comprising 
// of three items - the data, a reference to the 
// next node and the previous node. 
//------------------------------------------
//			START				INSERTED NODE				 END
//	+-------------------+	+-------------------+	+-------------------+
//	|       'null'      |	|      'data'       |	|      'null'       |
//	|-------------------|<->|-------------------|<->|-------------------|
//	| 'null'  | 'pNext' |	| 'pPrev' | 'pNext' |	| 'pPrev' |  'null' |
//	+-------------------+   +-------------------+   +-------------------+
//						  ^                       ^
//	InsertFront ----------+						  +---------- InsertEnd
//
//------------------------------------------
//	https://www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html
//------------------------------------------

#pragma once

namespace wolf {

		//--------------------------------------------------
		//--------------LinkListNode - Struct---------------
		//--------------------------------------------------
		template <typename T>
		struct Node
		{
			T m_pData;
		
			Node<T>* m_pPrev;
			Node<T>* m_pNext;

		};

	//--------------------------------------------------
	//---------------LinkedList - CLASS-----------------
	//	Functions:
	//		- Constuctor
	//		- Deconstructor
	//		- InsertFront
	//		- InsertEnd
	//		- InsertAt
	//		- Remove
	//		- Clear
	//		- PeekStart
	//		- PeekEnd
	//		- FindPointer
	//		- FindIndex
	//		- PopFind
	//		- PopPosition
	//		- Size
	//		- BubbleSort
	//--------------------------------------------------
	template <typename T>
	class LinkedList
	{
	public:
		//--------------------------------------------------
		//	  --- Used For Bubble Sorting Linked List ---
		//	- !!! USER TO CREATE CUSTOM COMPARE FUNTION !!! -
		//--------------------------------------------------
		//	Typedef 'bool' As 'CompareFunction'
		//--------------------------------------------------
		typedef bool(*CompareSort)(T lhs, T rhs);


		//--------------------------------------------------
		//	             --- Constructor ---
		//--------------------------------------------------
		LinkedList()
		{
			m_pStart = new Node<T>();
			m_pEnd = new Node<T>();

			m_pStart->m_pNext = m_pEnd;
			m_pStart->m_pPrev = nullptr;

			m_pEnd->m_pNext = nullptr;
			m_pEnd->m_pPrev = m_pStart;
		}

		//--------------------------------------------------
		//	             --- Destructor ---
		//--------------------------------------------------
		~LinkedList()
		{
			Clear();

			delete m_pStart;
			m_pStart = nullptr;
			delete m_pEnd;
			m_pEnd = nullptr;
		}


		//--------------------------------------------------
		//      --- Use To Add Start To LinkedList ---
		//--------------------------------------------------
		void InsertFront(T data)
		{
			InsertAt(data, m_pStart, m_pStart->m_pNext);
		}

		//--------------------------------------------------
		//      --- Use To Add End To LinkedList ---
		//--------------------------------------------------
		void InsertEnd(T data)
		{
			InsertAt(data, m_pEnd->m_pPrev, m_pEnd);
		}

		//--------------------------------------------------
		//      --- Use To InsertAt Data To LinkedList ---
		//--------------------------------------------------
		void InsertAt(T data, Node<T>* pNodeBefore, Node<T>* pNodeAfter)
		{
			Node<T>* pNewNode = new Node<T>();
			pNewNode->m_pData = data;

			pNewNode->m_pPrev = pNodeBefore;
			pNewNode->m_pNext = pNodeAfter;

			pNodeBefore->m_pNext = pNewNode;
			pNodeAfter->m_pPrev = pNewNode;
			nUsed++;
		}

		//--------------------------------------------------
		// --- Use To Remove A Node At Pointer To LinkedList ---
		//--------------------------------------------------
		void Remove(Node<T>* pNodeToRemove)
		{
			Node<T>* pNodeBefore = pNodeToRemove->m_pPrev;
			Node<T>* pNodeAfter = pNodeToRemove->m_pNext;

			pNodeBefore->m_pNext = pNodeAfter;
			pNodeAfter->m_pPrev = pNodeBefore;

			delete pNodeToRemove;
			nUsed--;
		}

		//--------------------------------------------------
		//     --- Use To Remove All Nodes LinkedList ---
		//--------------------------------------------------
		void Clear()
		{
			while (m_pStart->m_pNext != m_pEnd)
			{
				Remove(m_pStart->m_pNext);
			}
			nUsed = 0;
		}

		//--------------------------------------------------
		//  --- Use To Return Start Data In LinkedList ---
		//--------------------------------------------------
		Node<T>* PeekStart()
		{
			return m_pStart;
		}

		//--------------------------------------------------
		// --- Use To Return Data At Position In LinkedList ---
		//--------------------------------------------------
		Node<T>* PeekPosition(int nPosition)
		{
			Node<T>* pCurrentNode = m_pStart->m_pNext;
			for (int i = 0; i < nPosition; i++)
			{
				pCurrentNode = pCurrentNode->m_pNext;
			}
			return pCurrentNode;
		}

		//--------------------------------------------------
		//  --- Use To Return End Data In LinkedList ---
		//--------------------------------------------------
		Node<T>* PeekEnd()
		{
			return m_pEnd;
		}

		//--------------------------------------------------
		// --- Use To Return Index At Found Data In LinkedList ---
		//--------------------------------------------------
		int FindIndex(T findData)
		{
			int i = 0;
			Node<T>* pCurrentNode = m_pStart->m_pNext;
			while (pCurrentNode->m_pData != findData && pCurrentNode->m_pData)
			{
				pCurrentNode = pCurrentNode->m_pNext;
				i++;
			}

			return i;
		}

		//--------------------------------------------------
		// --- Use To Return Pointer At Found Data In LinkedList ---
		//--------------------------------------------------
		Node<T>* FindPointer(T findData)
		{
			Node<T>* pCurrentNode = m_pStart->m_pNext;
			while (pCurrentNode->m_pData != findData)
			{
				pCurrentNode = pCurrentNode->m_pNext;
			}

			return pCurrentNode;
		}


		//--------------------------------------------------
		// --- Use To Return And Remove Searched Data In LinkedList ---
		//--------------------------------------------------
		Node<T> PopFind(T findData)
		{
			Node<T>* foundNode = FindPointer(findData);
			Node<T> temp = (*foundNode);
			Remove(foundNode);

			nUsed--;
			return temp;
		}

		//--------------------------------------------------
		// --- Use To Return And Remove Searched Data In LinkedList ---
		//--------------------------------------------------
		T PopPosition(int nPosition)
		{
			Node<T>* pCurrentNode = m_pStart->m_pNext;
			int nPoint = 0;

			while (nPoint != nPosition)
			{
				pCurrentNode = pCurrentNode->m_pNext;
				nPoint++;
			}

			T temp = pCurrentNode->m_pData;
			Remove(pCurrentNode);

			return temp;
		}

		//--------------------------------------------------
		//	 --- Use To Return Size Of LinkedList ---
		//--------------------------------------------------
		int Size()
		{
			return nUsed;
		}

		//--------------------------------------------------
		//	   --- Use For Bubble Sorting Dynamic Array ---
		//--------------------------------------------------
		//	Create Temp 'T' Variable
		//	For Loop Though Array Using 'm_nUsed' - 1
		//		For Loop Though Each Object Again
		//			If Users Custom Compare Is True
		//				Create 'swapNode' Pointer As 'pCurrentNode's Next
		//				Create 'prevNode' Pointer As 'pCurrentNode's Prev
		//				Create 'nextNode' Pointer As 'swapNode's Next
		//				Set 'pCurrentNode's Next As 'nextNode'
		//				Set 'nextNode's Prev As 'pCurrentNode'
		//				Set 'pCurrentNode's Prev As 'swapNode'
		//				Set 'prevNode's Next As 'swapNode'
		//				Set 'swapNode's Prev As 'prevNode'
		//				Set 'swapNode's Next As 'pCurrentNode'
		//		Set 'pCurrentNode' As 'pCurrentNode's Next
		//--------------------------------------------------
		void BubbleSort(CompareSort compare)
		{
			Node<T>* pCurrentNode = m_pStart->m_pNext;

			for (int i = 0; i < nUsed - 1; i++)
			{
				for (int j = 0; j < nUsed - 1; j++) //J = pCurrentNode
				{
					if (pCurrentNode->m_pNext->m_pData && compare(pCurrentNode->m_pData, pCurrentNode->m_pNext->m_pData))
					{
						Node<T>* swapNode = pCurrentNode->m_pNext;

						Node<T>* prevNode = pCurrentNode->m_pPrev;
						Node<T>* nextNode = swapNode->m_pNext;

						pCurrentNode->m_pNext = nextNode;
						nextNode->m_pPrev = pCurrentNode;
						
						pCurrentNode->m_pPrev = swapNode;
						prevNode->m_pNext = swapNode;

						swapNode->m_pPrev = prevNode;
						swapNode->m_pNext = pCurrentNode;

					}
				}
				pCurrentNode = m_pStart->m_pNext;
			}
		}

		int nUsed = 0;

	private:
		Node<T>* m_pStart;
		Node<T>* m_pEnd;
	};
}//END NAMESPACE
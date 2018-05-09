//----------------------------------------
//File Name: BinaryTree.h
//Author: Trent Manks
//------------------------------------------
//Copyright 2017 - DarkWolf Interactive
//------------------------------------------

//------------------------------------------
//	              BINARY TREE
// The binary tree is a fundamental data 
// structure used in computer science. The 
// binary tree is a useful data structure for
// rapidly storing sorted data and rapidly retrieving
// stored data. 
//------------------------------------------
//			
//			         10
//			       /    \
//			      6      14
//			     / \    /  \
//			    5   8  11  18
//
//------------------------------------------
//	https://www.cprogramming.com/tutorial/lesson18.html
//------------------------------------------

#pragma once
#include <iostream>

namespace wolf{

	//--------------------------------------------------
	//---------------EPrintOrder - ENUM-----------------
	//--------------------------------------------------
	enum EPrintOrder
	{
		PRE_ORDER,
		POST_ORDER,
		IN_ORDER
	};

	//--------------------------------------------------
	//---------------BinaryTree - CLASS-----------------
	//--------------------------------------------------
	template <typename T>
	class BinaryTree
	{
		//--------------------------------------------------
		//------------------Node - CLASS--------------------
		//--------------------------------------------------
		class Node
		{
		public:
			void RemoveAll()
			{
				if (m_pLeft)
				{
					m_pLeft->RemoveAll();
					delete m_pLeft;
					m_pLeft = nullptr;
				}
				if (m_pRight)
				{
					m_pRight->RemoveAll();
					delete m_pRight;
					m_pRight = nullptr;
				}
			}
			void PrintPreOrder()
			{
				std::cout << m_nValue << std::endl;
				if (m_pLeft)
				{
					m_pLeft->PrintPreOrder();
				}
				if (m_pRight)
				{
					m_pRight->PrintPreOrder();
				}
			}
			void PrintPostOrder()
			{
				if (m_pLeft)
				{
					m_pLeft->PrintPostOrder();
				}
				if (m_pRight)
				{
					m_pRight->PrintPostOrder();
				}
				std::cout << m_nValue << std::endl;
			}
			void PrintInOrder()
			{
				if (m_pLeft)
				{
					m_pLeft->PrintInOrder();
				}
				std::cout << m_nValue << std::endl;
				if (m_pRight)
				{
					m_pRight->PrintInOrder();
				}
			}

			T m_nValue;

			Node* m_pLeft;
			Node* m_pRight;

		};

	public:
		//--------------------------------------------------
		//	  --- Used For Sorting Binary Tree ---
		//	- !!! USER TO CREATE CUSTOM COMPARE FUNTION !!! -
		//--------------------------------------------------
		//	Typedef 'bool' As 'CompareFunction'
		//--------------------------------------------------
		typedef bool(*CompareSort)(T lhs, T rhs);

		//--------------------------------------------------
		//				 --- Constructor ---
		//--------------------------------------------------
		//	Set 'm_pRoot' As 'nullptr'
		//--------------------------------------------------
		BinaryTree::BinaryTree()
		{
			m_pRoot = nullptr;
		}

		//--------------------------------------------------
		//				--- Deconstructor ---
		//--------------------------------------------------
		//	If 'm_pRoot' Is Valid
		//		T = Run 'Clear()' | Delete 'm_pRoot' | Set 'm_pRoot' As 'nullptr'
		//--------------------------------------------------
		BinaryTree::~BinaryTree()
		{
			if (m_pRoot)
			{
				m_pRoot->RemoveAll();
				delete m_pRoot;
				m_pRoot = nullptr;
			}
		}

		//--------------------------------------------------
		//  --- Use To Add New Node To BinaryTree ---
		//--------------------------------------------------
		//	Create 'new' Node - 'pNewNode'
		//		- Make 'pNewNode's Value As 'data'
		//		- Make 'pNewNode's Left Pointer As 'nullptr'
		//		- Make 'pNewNode's Right Pointer As 'nullptr'
		//
		//	If 'm_pRoot' Is Not A 'nullptr'
		//		T = Set 'm_pRoot' As 'pNewNode' Then Return
		//
		//	Define 'pCurrent' as 'm_pRoot' (Start At Root)
		//	Define 'pParrent' as 'm_pRoot' (Start At Root)
		//
		//	While 'pCurrent' is not a 'nullptr'
		//		Check If 'pNewNode's Value Is Less Than 'pCurrent's Value
		//			T = Set 'pCurrent' As 'pCurrent's Left Pointer
		//			F = Set 'pCurrent' As 'pCurrent's Right Pointer
		//	
		//	Check If 'pNewNode's Value Is Smaller Than 'pParent's Value
		//		T = Set 'pParent's Left Value As 'pNewNode'
		//		F = Set 'pParent's Right Value As 'pNewNode'
		//--------------------------------------------------
		void BinaryTree::Add(T data, CompareSort compare)
		{
			Node* pNewNode = new Node;
			pNewNode->m_nValue = data;
			pNewNode->m_pLeft = nullptr;
			pNewNode->m_pRight = nullptr;

			if (!m_pRoot)
			{
				m_pRoot = pNewNode;
				return;
			}

			Node* pCurrent = m_pRoot;
			Node* pParent = m_pRoot;
			while (pCurrent)
			{
				pParent = pCurrent;

				if (compare(pNewNode->m_nValue, pCurrent->m_nValue)) // <
				{
					pCurrent = pCurrent->m_pLeft;
				}
				else
				{
					pCurrent = pCurrent->m_pRight;
				}
			}

			if (compare(pNewNode->m_nValue, pParent->m_nValue))// <
			{
				pParent->m_pLeft = pNewNode;
			}
			else
			{
				pParent->m_pRight = pNewNode;
			}
		}

		//--------------------------------------------------
		//   --- Use To Remove Node To BinaryTree ---
		//--------------------------------------------------
		//	Define 'pCurrent' As 'm_pRoot'
		//	Define 'pParent' As 'm_pRoot'
		//
		//	While 'pCurrent' Is Not 'nullptr'
		//		Set 'pParent' As 'pCurrent'
		//		If 'pCurrent's Value Is Equil To 'data'
		//			T = break
		//
		//		If 'data' Is Less Than 'pCurrent's Value
		//			T = Set 'pCurrent' As 'pCurrent's Left Pointer
		//		Else
		//			Set 'pCurrent' As 'pCurrent's Right Pointer
		//
		//	If 'pCurrent's Left && 'pCurrent's Right Is Valid
		//		T = Run 'RemoveTwoLeaf()'
		//	If 'pCurrent's Left && 'pCurrent's Right Is 'nullptr'
		//		T = Run 'RemoveNoLeaf()'
		//	Else
		//		Run 'RemoveOneLeaf()'
		//--------------------------------------------------
		void BinaryTree::Remove(int nValue)
		{
			Node* pCurrent = m_pRoot;
			Node* pParent = m_pRoot;
			while (pCurrent)
			{
				pParent = pCurrent;

				if (pCurrent->m_nValue == nValue)
				{
					break;
				}

				if (nValue < pCurrent->m_nValue)
				{
					pCurrent = pCurrent->m_pLeft;
				}
				else
				{
					pCurrent = pCurrent->m_pRight;
				}
			}

			if (pCurrent->m_pLeft && pCurrent->m_pRight)
			{
				RemoveTwoLeaf(pParent, pCurrent);
			}
			else if (pCurrent->m_pLeft == nullptr && pCurrent->m_pRight == nullptr)
			{
				RemoveNoLeaf(pParent, pCurrent);
			}
			else
			{
				RemoveOneLeaf(pParent, pCurrent);
			}
		}

		//--------------------------------------------------
		// --- Use To Print Nodes In Chosen Order In BinaryTree ---
		//--------------------------------------------------
		//	Switch Print Order Based On Users 'eOrder' (Default = 'IN_ORDER')
		//		case 'PRE_ORDER' = Run 'PrintPreOrder()'
		//		case 'POST_ORDER' = Run 'PrintPostOrder()'
		//		case 'IN_ORDER' = Run 'PrintInOrder()'
		//--------------------------------------------------
		void BinaryTree::Print(EPrintOrder eOrder)
		{
			switch (eOrder)
			{
			case PRE_ORDER:
			{
				PrintPreOrder();
			}
			break;
			case POST_ORDER:
			{
				PrintPostOrder();
			}
			break;
			case IN_ORDER:
			{
				PrintInOrder();
			}
			break;
			}
		}

	private:
		//--------------------------------------------------
		//   --- Used To Remove Node With No Leaf ---
		//--------------------------------------------------
		void BinaryTree::RemoveNoLeaf(Node * pParent, Node * pCurrent)
		{
			if (pParent->m_pLeft == pCurrent)
			{
				pParent->m_pLeft = nullptr;
			}
			else
			{
				pParent->m_pRight = nullptr;
			}

			delete pCurrent;
		}

		//--------------------------------------------------
		//   --- Used To Remove Node With One Leaf ---
		//--------------------------------------------------
		void BinaryTree::RemoveOneLeaf(Node * pParent, Node * pCurrent)
		{
			if (pParent->m_pLeft == pCurrent)
			{
				if (pParent->m_pLeft)
				{
					pParent->m_pLeft = pCurrent->m_pLeft;
				}
				else
				{
					pParent->m_pLeft = pCurrent->m_pRight;
				}
			}
			else
			{
				if (pParent->m_pLeft)
				{
					pParent->m_pRight = pCurrent->m_pLeft;
				}
				else
				{
					pParent->m_pRight = pCurrent->m_pRight;
				}
			}
		}

		//--------------------------------------------------
		//   --- Used To Remove Node With Two Leafs ---
		//--------------------------------------------------
		void BinaryTree::RemoveTwoLeaf(Node * pParent, Node * pCurrent)
		{
			pParent = pCurrent;
			Node* pSearch = pCurrent->m_pRight;
			while (pSearch->m_pLeft)
			{
				pParent = pSearch;
				pSearch = pSearch->m_pLeft;
			}

			pCurrent->m_nValue = pSearch->m_nValue;

			if (pSearch->m_pRight)
			{

			}
			else
			{
				if (pParent->m_pLeft == pSearch)
				{
					pParent->m_pLeft == pSearch->m_pRight;
				}
				else
				{
					pParent->m_pRight == pSearch->m_pRight;
				}
			}

		}

		//--------------------------------------------------
		//     --- Used To Print Nodes In PreOrder ---
		//--------------------------------------------------
		void BinaryTree::PrintPreOrder()
		{
			if (m_pRoot)
			{
				m_pRoot->PrintPreOrder();
			}
		}

		//--------------------------------------------------
		//     --- Used To Print Nodes In PostOrder ---
		//--------------------------------------------------
		void BinaryTree::PrintPostOrder()
		{
			if (m_pRoot)
			{
				m_pRoot->PrintPostOrder();
			}
		}

		//--------------------------------------------------
		//     --- Used To Print Nodes In InOrder ---
		//--------------------------------------------------
		void BinaryTree::PrintInOrder()
		{
			if (m_pRoot)
			{
				m_pRoot->PrintInOrder();
			}
		}

		Node* m_pRoot;
	};
}//END NAMESPACE


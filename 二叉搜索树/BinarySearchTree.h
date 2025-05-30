#pragma once
#include<iostream>
using namespace std;
template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& key)
		:_key(key), _left(nullptr), _right(nullptr)
	{
	}
	K _key;
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
};

template<class K>
class BinarySearchTree
{
	typedef BSTreeNode<K> Node;
public:
	BinarySearchTree()
		:_root(nullptr)
	{
	}
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (key == cur->_key)
			{
				return true;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		return false;
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;

		while (cur != nullptr)
		{
			if (cur->_key < key)//往右插入
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else //相等
			{
				return false;
			}
		}

		cur = new Node(key);
		if (key < parent->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	bool Erase(const K& key);
	~BinarySearchTree(){}

private:
	Node* _root;
};



template<class K>
bool BinarySearchTree<K>::Erase(const K& key)
{
	Node* cur = _root;
	Node* parent = cur;
	while (cur != nullptr)
	{
		if (key < cur->_key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if((key > cur->_key))
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			//找到了

			if (cur->_left == nullptr)
			{
				if (cur == _root)
				{
					_root = cur->_right;
				}
				else
				{
					if (parent->_right == cur)
					{
						parent->_right = cur->_right;
					}
					else
					{
						parent->_left = cur->_right;
					}
				}
				delete cur;
			}
			else if (cur->_right == nullptr)
			{
				if (cur == _root)
				{
					_root = cur->_left;
				}
				else
				{
					if (cur->_right == nullptr)
					{
						if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
				}
				delete cur;
			}
			else// 左右都不为空
			{
				Node* parent = cur;
				Node* leftMax = cur->_left;
				while (leftMax->_right !=nullptr)
				{
					parent = leftMax;
					leftMax = leftMax->_right;
				}
				cur->_key = leftMax->_key;

				if (parent->_right == leftMax)
				{
					parent->_right = leftMax->_left;
				}
				else
				{
					parent->_left = leftMax->_left;
				}
				delete leftMax;
			}

			
			return true;
		}
	}
}
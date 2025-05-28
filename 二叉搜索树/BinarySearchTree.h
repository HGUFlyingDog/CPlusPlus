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
			if (key = cur->_key)
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
			if (cur->_key < key)//���Ҳ���
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else //���
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
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;
		while (cur != nullptr)
		{
			if (key = cur->_key)
			{
				//�ҵ���

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
							parent->_left = cur->right;
						}
					}
				}
				else if(cur->_right == nullptr)
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
				}
				else// ���Ҷ���Ϊ��
				{

				}
				delete cur;
				return true;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
	}
	//~BinarySearchTree();

private:
	Node* _root;
};

void TestBSTree1()
{
	BinarySearchTree<int> t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto ch : a)
	{
		t.Insert(ch);
	}
	t.InOrder();
}
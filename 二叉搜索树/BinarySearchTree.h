#pragma once

template<class K>
class BSTreeNode
{
public:
	
	Key _key;
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

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_key < key)//Õ˘”“≤Â»Î
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else //œ‡µ»
			{
				return false;
			}
		}


	}
	~BinarySearchTree();

private:
	Node* _root;
};


#include"BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> t;
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	for (auto ch : a)
	{
		t.Insert(ch);
	}
	t.InOrder();

	t.Erase(8);
	t.InOrder();
	for (auto ch : a)
	{
		t.Erase(ch);
		t.InOrder();
	}
	return 0;
}
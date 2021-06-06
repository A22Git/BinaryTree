#include"BinaryTreeByTemplate.h"
using namespace std;
int main()
{
	BinaryTree<int>T1;

	T1.PushBack(6);
	T1.PushBack(12);
	T1.PushBack(7);
	T1.PushBack(30);
	T1.PushBack(10);
	T1.PushBack(32);
	T1.PushBack(50);


	T1.print_postorder(T1.GetHead());
	//T1.print_pre(T1.GetHead());
	cout << endl;
	/*T1.print_inorder(T1.GetHead());
	cout << endl;
	T1.print_postorder(T1.GetHead());
	cout << endl;

	Node* a = T1.Search(7, T1.GetHead());
	Node* b = T1.Search(50, T1.GetHead());

	T1.Delete(6);
	T1.print_pre(T1.GetHead());
	cout << endl;
	T1.Delete(32);
	T1.print_pre(T1.GetHead());
	cout << endl;
	T1.Delete(7);
	T1.print_pre(T1.GetHead());
	cout << endl;
	T1.Delete(10);*/
}
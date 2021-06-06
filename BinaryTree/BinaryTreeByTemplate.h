#include "node.h"
#include <iostream>
using namespace std;

template<class NType>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree& T1);

	Node<NType>* GetHead() { return head; };
	Node<NType>* Search(NType _data, Node<NType>* node);
	void PushBack(NType _data);
	void Delete(NType _data);
	void print_pre(Node<NType>* node);
	void print_inorder(Node<NType>* node);
	void print_postorder(Node<NType>* node);
	~BinaryTree();
private:
	Node<NType>* head;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
	head = NULL;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& t)
{
	if (t.head != NULL)
	{
		head = new Node(0);
		Node::CopyAllNode(t.head, head);
	}
	else
		head = NULL;
}
template<typename T>

BinaryTree<T>::~BinaryTree()
{
	Node<T>::DelAllNode(head);
}

template<typename T>
Node<T>* BinaryTree<T>::Search(T _data, Node<T> *node)
{
	if (node == NULL)
		return NULL;
	if (node->GetData() == _data)
		return node;
	else if (node->GetData() > _data)
		return Search(_data, node->touchLeft());
	else
		return Search(_data, node->touchRight());
}

template<typename T>
void BinaryTree<T>::PushBack(T _data)
{
	Node<T>* new_node = new Node<T>(_data);
	if (head == NULL)
	{
		head = new_node;
		return;
	}
	Node<T>* tmp = head;
	while (tmp != NULL)
	{
		if (_data < tmp->GetData())
		{
			if (tmp->touchLeft() == NULL)
			{
				tmp->putLeft(new_node);
				return;
			}
			tmp = tmp->touchLeft();
		}
		else
		{
			if (tmp->touchRight() == NULL)
			{
				tmp->putRight(new_node);
				return;
			}
			tmp = tmp->touchRight();
		}
	}

}
template<typename T>
void BinaryTree<T>::Delete(T _data)
{
	Node* node = Search(_data, head);
	if (node == NULL)
	{
		return;
	}
	Node* prenode = Search(_data, head);
	int side;
	if (prenode == NULL)
		side = 0;
	else if (node->GetData() < prenode->GetData())
		side = -1;
	else
		side = 1;
	if (node->touchLeft() == NULL && node->touchRight() == NULL)
	{
		if (side == 0)
			head = NULL;
		else if (side == -1)
			prenode->putLeft(NULL);
		else
			prenode->putRight(NULL);
	}
	else if (node->touchLeft() == NULL || node->touchRight() == NULL)
	{
		if (node->touchLeft() == NULL)
		{
			if (side == 0)
				head = node->touchRight();
			else if (side == -1)
				prenode->putLeft(node->touchRight());
			else
				prenode->putRight(node->touchRight());
		}
		else if (node->touchRight() == NULL)
		{
			if (side == 0)
				head = node->touchLeft();
			else if (side == -1)
				prenode->putLeft(node->touchLeft());
			else
				prenode->putRight(node->touchLeft());
		}
	}
	else
	{
		Node* tmp = node->touchRight(), * pretmp = node;
		while (tmp->touchLeft() != NULL)
		{
			pretmp = tmp;
			tmp = tmp->touchLeft();
		}
		if (pretmp == node)
			pretmp->putRight(NULL);
		else
			pretmp->putLeft(NULL);
		if (side == 0)
			head = tmp;
		else if (side == -1)
			prenode->putLeft(tmp);
		else
			prenode->putRight(tmp);
		tmp->putLeft(node->touchLeft());
		tmp->putRight(node->touchRight());
	}
	delete node;
}

template<typename T>
void BinaryTree<T>::print_pre(Node<T>* node)
{
	cout << node->GetData() << " ";
	if (node->touchLeft() != NULL)
		print_pre(node->touchLeft());
	if (node->touchRight() != NULL)
		print_pre(node->touchRight());
}
template<typename T>
void BinaryTree<T>::print_inorder(Node<T>* node)
{
	if (node->touchLeft() != NULL)
		print_inorder(node->touchLeft());
	cout << node->GetData() << " ";
	if (node->touchRight() != NULL)
		print_inorder(node->touchRight());
}
template<typename T>
void BinaryTree<T>::print_postorder(Node<T>* node)
{
	if (node->touchLeft() != NULL)
		print_postorder(node->touchLeft());
	if (node->touchRight() != NULL)
		print_postorder(node->touchRight());
	cout << node->GetData() << " ";
}

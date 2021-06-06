#include<iostream>
using namespace std;


template<class NType>
class Node
{
public:
	Node(NType _data);
	void putRight(Node* _right) { right = _right; };
	void putLeft(Node* _left) { left = _left; };
	void SetData(NType _data) { data = _data; };
	Node* touchRight() { return right; };
	Node* touchLeft() { return left; };
	NType GetData() { return data; };
	static void DelAllNode(Node* node);
	static void CopyAllNode(Node* main_node, Node* node);
private:
	NType data;
	Node* left;
	Node* right;

};
template<typename T>
Node<T>::Node(T data)
{
	this->data = data;
	left = NULL;
	right = NULL;
}
template<typename T>
void Node<T>::DelAllNode(Node* node)
{
	if (node->touchLeft() != NULL)
	{
		DelAllNode(node->touchLeft());
		node->putLeft(NULL);
	}
	if (node->touchRight() != NULL)
	{
		DelAllNode(node->touchRight());
		node->putRight(NULL);
	}
	delete node;
}
template<typename T>
void Node<T>::CopyAllNode(Node* main_node, Node* node)
{
	node->SetData(main_node->GetData());
	if (main_node->touchLeft() != NULL)
	{
		Node* new_node = new Node(0);
		node->putLeft(new_node);
		CopyAllNode(main_node->touchLeft(), new_node);
	}
	if (main_node->touchRight() != NULL)
	{
		Node* new_node = new Node(0);
		node->putRight(new_node);
		CopyAllNode(main_node->touchRight(), new_node);
	}
}
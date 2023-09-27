#pragma once
#include <iostream>

template <class T>
struct Node {
	T data;
	Node* left;
	Node* right;
};

template <class T>
class BinarySearchTree
{
private :
	Node<T>* root;
public :
	BinarySearchTree(); //�⺻ ������
	~BinarySearchTree(); //�⺻ �Ҹ���

	/**
	*	@brief	Ʈ���� �ʱ�ȭ�ϴ� �Լ�
	*	@pre	None
	*	@post	��� ����� �Ҵ��� ���� ��
	*/
	void MakeEmpty();

	/**
	*	@brief	���ο� �������� Ʈ���� �߰�
	*	@pre	�ʱ�ȭ �� Ʈ���� �ʿ���
	*	@post	Ʈ���� ���ο� �������� �߰� ��
	*   @param  T item �߰��� ������
	*/
	void AddItem(T& item);

	/**
	*	@brief	�������� �����ϴ� ��ġ�� Ž��
	*	@pre	�ʱ�ȭ �� Ʈ���� �ʿ���
	*	@post	Ʈ���� �������� �����ϴ� ��ġ�� Ž��
	*   @param  T &item ã�� ������
	*/
	void RetrieveItem(T &item, bool &isFind);

	/**
	*	@brief	Ʈ������ �������� ����
	*	@pre	�ʱ�ȭ �� Ʈ���� �ʿ���
	*	@post	Ʈ���� �����ϴ� �������� ����
	*   @param  T item ���� �� ������
	*/
	void DeleteItem(T item);

	/**
	*	@brief	Ʈ���� ���ο� ��带 �߰��� �� �ִ��� Ȯ��
	*	@pre	�ʱ�ȭ �� Ʈ���� �ʿ���
	*	@post	None
	*	@return	�� �Ҵ��� �޸𸮰� ������ false, �� �̻� �Ҵ��� �� ������ true�� ��ȯ
	*/
	bool IsFull();

	/**
	*	@brief	Ʈ���� ����ִ��� Ȯ��
	*	@pre	�ʱ�ȭ �� Ʈ���� �ʿ���
	*	@post	None
	*	@return	Ʈ���� ���̰� 0�� �ƴϸ� false, 0�̸� true�� ��ȯ
	*/
	bool IsEmpty();

	/**
	*	@brief	Ʈ���� ��Ʈ ��带 ������
	*	@pre	�ʱ�ȭ �� Ʈ���� �Ҵ�Ǿ� �ִ� ��Ʈ ��尡 �ʿ���
	*	@post	None
	*	@return	Ʈ���� ��Ʈ ��带 ��ȯ
	*/
	Node<T>* getRoot();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr; //root�� nullptr�� �ʱ�ȭ
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {

}

template <class T>
Node<T>* BinarySearchTree<T>::getRoot() {
	return root;
}

template <class T>
void BinarySearchTree<T>::MakeEmpty() {
	if (root != nullptr) { //root�� null�� �ƴϸ�
		CleanTree(root); //root�� ������ �޸� ����
		delete root;
		root = nullptr;
	}
}

template <class T>
void CleanTree(Node<T>*& root) { //Ʈ���� ���� ���� ��� �Լ�
	if (root->left != nullptr) { //Ʈ���� ���� ��尡 null�� �ƴ� ���
		CleanTree(root->left); //�ٽ� �ڽ� ������ Ž��
		delete root->left; //�ڽ� ������ ������ ������ �� ���ε� ����
	}
	else if (root->right != nullptr) { //Ʈ���� ������ ��尡 null�� �ƴ� ���
		CleanTree(root->right); //�ٽ� �ڽ� ������ Ž��
		delete root->right; //�ڽ� ������ ������ ������ �� ���ε� ����
	}
}

template <class T>
void BinarySearchTree<T>::AddItem(T& item) { //���ο� ��带 �߰��ϴ� �Լ�
	Add(root, item);
}

template <class T>
void Add(Node<T>* &root, T& item) { //Ʈ���� �������� �߰��ϱ� ���� ��� �Լ�
	if (root == nullptr) { //root�� null�� ���
		root = new Node<T>; //��带 �ϳ� �Ҵ� ��
		root->left = nullptr; //���ʰ� ������ ��带 null�� �ʱ�ȭ �� ��
		root->right = nullptr;
		root->data = item; //����� data�� item�� �߰�
	}
	else if (root->data > item) { //root�� ������ �� �� ���� ���ο� �� ���� ũ��
		Add(root->left, item); //root�� �������� �̵�
	}
	else if (root->data < item) { //root�� ������ �� �� ���� ���ο� �� ���� ������
		Add(root->right, item); //root�� ���������� �̵�
	}
}


template <class T>
void BinarySearchTree<T>::DeleteItem(T item) { //��带 �����ϴ� �Լ�
	Delete(root, item);
}

template <class T>
void Delete(Node<T>* &root, T item) {
	if (item < root->data) { //root���� item������ ũ��
		Delete(root->left, item); //root�� �������� �̵�
	}
	else if (item > root->data) { //root���� item������ ������
		Delete(root->right, item); //root�� ���������� �̵�
	}
	else if (item == root->data) { //���� ��ġ�ϸ�
		DeleteNode(root); //DeleteNode�Լ��� ��带 ����
	}
}

template <class T>
void DeleteNode(Node<T>* &root) {
	Node<T>* node; //�ӽ� ��带 ������ ��
	node = root; //root�� �ӽ� ��忡 ����

	if (root->left == nullptr) { //���� ��尡 null�� ���
		root = root->right; //������ ��尡 root�� �ǵ����ϰ�
		delete node; //�ӽ� ��� ����
	}
	else if (root->right == nullptr) { //������ ��尡 null�� ���
		root = root->left; //���� ��尡 root�� �ǵ����ϰ�
		delete node; //�ӽ� ��� ����
	}
	else { //������ ���� ��� ��尡 ���� ��
		while (node->right != nullptr) { //���� ū ���� ã�Ƽ�
			node = node->right;
		}
		root->data = node->data; //root�� ������ ���� ��
		Delete(root->left, node->data); //���� ������ ����
	}
}

template <class T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool& isFind) { //item�� ���� ���� ã�� �Լ�
	isFind = false;
	Retrieve(root, item, isFind);
}

template <class T>
void Retrieve(Node<T>* &root, T& item, bool &isFind) {
	if (root == nullptr) { //root�� null�� ��� (���� ã�� ������ ���)
		isFind = false; //isFind�� false
	}
	else if (item < root->data) { //root�� ���� item�� ������ Ŭ ��
		Retrieve(root->left, item, isFind); //���� ��带 Ž��
	}
	else if (item > root->data) { //root�� ���� item�� ������ ���� ��
		Retrieve(root->right, item, isFind); //������ ��带 Ž��
	}
	else if (item == root->data) { //���� ��ġ�� ��
		item = root->data; //item�� ��� ���� ����
		isFind = true; //isFind�� true
	}
}

template <class T>
bool BinarySearchTree<T>::IsEmpty() {
	return (root == nullptr); // root�� null�ΰ�� true, �׷��� ������� false�� ��ȯ
}

template <class T>
bool BinarySearchTree<T>::IsFull() {
	Node<T>* node; //�ӽ� ��带 ���� ��
	try {
		node = new Node<T>; //�޸𸮸� �Ҵ�
		delete node; //������ �߻����� ������ �Ҵ��� ��带 ����
		return false; //false�� ��ȯ
	}
	catch(std::bad_alloc exception){ //�Ҵ��� �� ������ �߻��ϸ� (�� �̻� �޸𸮸� �Ҵ��� �� ������)
		return true; //true�� ��ȯ
	}
}
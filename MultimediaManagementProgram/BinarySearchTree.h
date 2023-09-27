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
	BinarySearchTree(); //기본 생성자
	~BinarySearchTree(); //기본 소멸자

	/**
	*	@brief	트리를 초기화하는 함수
	*	@pre	None
	*	@post	모든 노드의 할당이 해제 됨
	*/
	void MakeEmpty();

	/**
	*	@brief	새로운 아이템을 트리에 추가
	*	@pre	초기화 된 트리가 필요함
	*	@post	트리에 새로운 아이템이 추가 됨
	*   @param  T item 추가할 아이템
	*/
	void AddItem(T& item);

	/**
	*	@brief	아이템이 존재하는 위치를 탐색
	*	@pre	초기화 된 트리가 필요함
	*	@post	트리에 아이템이 존재하는 위치를 탐색
	*   @param  T &item 찾을 아이템
	*/
	void RetrieveItem(T &item, bool &isFind);

	/**
	*	@brief	트리에서 아이템을 삭제
	*	@pre	초기화 된 트리가 필요함
	*	@post	트리에 존재하는 아이템을 삭제
	*   @param  T item 삭제 할 아이템
	*/
	void DeleteItem(T item);

	/**
	*	@brief	트리에 새로운 노드를 추가할 수 있는지 확인
	*	@pre	초기화 된 트리가 필요함
	*	@post	None
	*	@return	더 할당할 메모리가 있으면 false, 더 이상 할당할 수 없으면 true를 반환
	*/
	bool IsFull();

	/**
	*	@brief	트리가 비어있는지 확인
	*	@pre	초기화 된 트리가 필요함
	*	@post	None
	*	@return	트리의 길이가 0이 아니면 false, 0이면 true를 반환
	*/
	bool IsEmpty();

	/**
	*	@brief	트리의 루트 노드를 가져옴
	*	@pre	초기화 된 트리와 할당되어 있는 루트 노드가 필요함
	*	@post	None
	*	@return	트리의 루트 노드를 반환
	*/
	Node<T>* getRoot();
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr; //root를 nullptr로 초기화
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
	if (root != nullptr) { //root가 null이 아니면
		CleanTree(root); //root의 노드부터 메모리 해제
		delete root;
		root = nullptr;
	}
}

template <class T>
void CleanTree(Node<T>*& root) { //트리를 비우기 위한 재귀 함수
	if (root->left != nullptr) { //트리의 왼쪽 노드가 null이 아닌 경우
		CleanTree(root->left); //다시 자식 노드들을 탐색
		delete root->left; //자식 노드들의 해제가 끝났을 때 본인도 해제
	}
	else if (root->right != nullptr) { //트리의 오른쪽 노드가 null이 아닌 경우
		CleanTree(root->right); //다시 자식 노드들을 탐색
		delete root->right; //자식 노드들의 해제가 끝났을 때 본인도 해제
	}
}

template <class T>
void BinarySearchTree<T>::AddItem(T& item) { //새로운 노드를 추가하는 함수
	Add(root, item);
}

template <class T>
void Add(Node<T>* &root, T& item) { //트리에 아이템을 추가하기 위한 재귀 함수
	if (root == nullptr) { //root가 null인 경우
		root = new Node<T>; //노드를 하나 할당 후
		root->left = nullptr; //왼쪽과 오른쪽 노드를 null로 초기화 한 후
		root->right = nullptr;
		root->data = item; //노드의 data에 item을 추가
	}
	else if (root->data > item) { //root가 존재할 때 그 값이 새로운 값 보다 크면
		Add(root->left, item); //root의 왼쪽으로 이동
	}
	else if (root->data < item) { //root가 존재할 때 그 값이 새로운 값 보다 작으면
		Add(root->right, item); //root의 오른쪽으로 이동
	}
}


template <class T>
void BinarySearchTree<T>::DeleteItem(T item) { //노드를 삭제하는 함수
	Delete(root, item);
}

template <class T>
void Delete(Node<T>* &root, T item) {
	if (item < root->data) { //root값이 item값보다 크면
		Delete(root->left, item); //root의 왼쪽으로 이동
	}
	else if (item > root->data) { //root값이 item값보다 작으면
		Delete(root->right, item); //root의 오른쪽으로 이동
	}
	else if (item == root->data) { //값이 일치하면
		DeleteNode(root); //DeleteNode함수로 노드를 삭제
	}
}

template <class T>
void DeleteNode(Node<T>* &root) {
	Node<T>* node; //임시 노드를 생성한 후
	node = root; //root를 임시 노드에 복사

	if (root->left == nullptr) { //왼쪽 노드가 null일 경우
		root = root->right; //오른쪽 노드가 root가 되도록하고
		delete node; //임시 노드 삭제
	}
	else if (root->right == nullptr) { //오른쪽 노드가 null일 경우
		root = root->left; //왼쪽 노드가 root가 되도록하고
		delete node; //임시 노드 삭제
	}
	else { //오른쪽 왼쪽 모든 노드가 있을 때
		while (node->right != nullptr) { //가장 큰 값을 찾아서
			node = node->right;
		}
		root->data = node->data; //root의 값으로 삽입 후
		Delete(root->left, node->data); //왼쪽 노드들을 삭제
	}
}

template <class T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool& isFind) { //item과 같은 값을 찾는 함수
	isFind = false;
	Retrieve(root, item, isFind);
}

template <class T>
void Retrieve(Node<T>* &root, T& item, bool &isFind) {
	if (root == nullptr) { //root가 null인 경우 (값을 찾지 못했을 경우)
		isFind = false; //isFind를 false
	}
	else if (item < root->data) { //root의 값이 item의 값보다 클 때
		Retrieve(root->left, item, isFind); //왼쪽 노드를 탐색
	}
	else if (item > root->data) { //root의 값이 item의 값보다 작을 때
		Retrieve(root->right, item, isFind); //오른쪽 노드를 탐색
	}
	else if (item == root->data) { //값이 일치할 때
		item = root->data; //item에 노드 값을 복사
		isFind = true; //isFind를 true
	}
}

template <class T>
bool BinarySearchTree<T>::IsEmpty() {
	return (root == nullptr); // root가 null인경우 true, 그렇지 않을경우 false를 반환
}

template <class T>
bool BinarySearchTree<T>::IsFull() {
	Node<T>* node; //임시 노드를 만든 후
	try {
		node = new Node<T>; //메모리를 할당
		delete node; //오류가 발생하지 않으면 할당한 노드를 해제
		return false; //false를 반환
	}
	catch(std::bad_alloc exception){ //할당할 때 에러가 발생하면 (더 이상 메모리를 할당할 수 없으면)
		return true; //true를 반환
	}
}
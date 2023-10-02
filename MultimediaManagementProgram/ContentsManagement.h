#pragma once
#include <QWidget>
#include <QDialog>
#include <QFileDialog>
#include "ui_ContentsManagement.h"
#include "PhotoLoadDialog.h"
#include "VideoLoadDialog.h"

#include "BinarySearchTree.h"
#include <io.h>

class ContentsManagement : public QWidget
{
	Q_OBJECT

public:
	ContentsManagement(QWidget* parent = Q_NULLPTR); //생성자

private:
	Ui::ContentsManagement ui;

	PhotoLoadDialog* photoLoadDialog; //사진 불러오기 다이얼로그
	VideoLoadDialog* videoLoadDialog; //비디오 불러오기 다이얼로그
	QString selectedUnregisterFileName; //미등록 리스트에서 선택된 파일 이름
	QString selectedRegisterFileName; //등록 리스트에서 선택된 파일 이름
	bool isUnregisterSelected = false; //선택 여부
	bool isRegisterSelected = false;

	template<class T>
	void SaveFile(Node<T>* root, std::ofstream& fout) { //파일을 저장하기 위한 재귀 함수
		MultimediaContent content;
		content = root->data; //콘텐츠 임시 생성 후 노드에서 값을 받아옴
		content.WriteDataToFile(fout); //파일에 정보를 기록
		if (root->left != nullptr) { //만약 왼쪽 노드가 존재하면
			SaveFile(root->left, fout); //왼쪽 노드로 재귀함수 호출
		}
		if (root->right != nullptr) { //만약 오른쪽 노드가 존재하면
			SaveFile(root->right, fout); //오른쪽 노드로 재귀함수 호출
		}
	}

	template<class T>
	void UpdateMasterList(Node<T>* root, int currentIndex) {
		MultimediaContent content;
		content = root->data; //콘텐츠 임시 생성 후 노드에서 값을 받아옴
		ui.MasterList->setRowCount(currentIndex+1); //현재 위치에
		ui.MasterList->setItem(currentIndex, 0, new QTableWidgetItem(content.getFileName().c_str()));
		ui.MasterList->setItem(currentIndex, 1, new QTableWidgetItem(content.getCreateDate().c_str()));
		ui.MasterList->setItem(currentIndex, 2, new QTableWidgetItem(content.getFileType().c_str()));
		ui.MasterList->setItem(currentIndex, 3, new QTableWidgetItem(content.getInnerEvent().c_str()));
		ui.MasterList->setItem(currentIndex, 4, new QTableWidgetItem(content.getInnerPerson().c_str()));
		ui.MasterList->setItem(currentIndex, 5, new QTableWidgetItem(content.getInnerPlace().c_str())); //테이블 위젯 아이템을 추가
		currentIndex += 1; //위치를 1 증가시킨 후

		if (root->left != nullptr) { //왼쪽 노드가 존재하면
			UpdateMasterList(root->left, currentIndex); //왼쪽 노드로 재귀함수 호출
		}
		if (root->right != nullptr) { //오른쪽 노드가 존재하면
			UpdateMasterList(root->right, currentIndex); //오른쪽 노드로 재귀함수 호출
		}
	}

public slots:
	//새로 고침 버튼이 눌렸을 때
	void Reload();

private slots:
	//미등록 리스트에서 아이템이 선택 되었을 때
	void SelectUnregisterFile();
	
	//선택 리스트에서 아이템이 선택 되었을 때
	void SelectRegisterFile();

	//사진 불러오기 다이얼로그 버튼이 눌렸을 때
	void OpenPhotoLoadDialog();

	//비디오 불러오기 다이얼로그 버튼이 눌렸을 때
	void OpenVideoLoadDialog();

	//모든 리스트 비우기 버튼이 눌렸을 때
	void MakeEmpty();

	//아이템 추가 버튼이 눌렸을 때
	void AddItem();

	//아이템 삭제 버튼이 눌렸을 때
	void DeleteItem();

	//파일에 저장 버튼이 눌렸을 때
	void SaveToFile();

	//파일로부터 불러오기 버튼이 눌렸을 때
	void LoadFromFile();
};
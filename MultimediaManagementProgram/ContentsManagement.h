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
	ContentsManagement(QWidget* parent = Q_NULLPTR); //������

private:
	Ui::ContentsManagement ui;

	PhotoLoadDialog* photoLoadDialog; //���� �ҷ����� ���̾�α�
	VideoLoadDialog* videoLoadDialog; //���� �ҷ����� ���̾�α�
	QString selectedUnregisterFileName; //�̵�� ����Ʈ���� ���õ� ���� �̸�
	QString selectedRegisterFileName; //��� ����Ʈ���� ���õ� ���� �̸�
	bool isUnregisterSelected = false; //���� ����
	bool isRegisterSelected = false;

	template<class T>
	void SaveFile(Node<T>* root, std::ofstream& fout) { //������ �����ϱ� ���� ��� �Լ�
		MultimediaContent content;
		content = root->data; //������ �ӽ� ���� �� ��忡�� ���� �޾ƿ�
		content.WriteDataToFile(fout); //���Ͽ� ������ ���
		if (root->left != nullptr) { //���� ���� ��尡 �����ϸ�
			SaveFile(root->left, fout); //���� ���� ����Լ� ȣ��
		}
		if (root->right != nullptr) { //���� ������ ��尡 �����ϸ�
			SaveFile(root->right, fout); //������ ���� ����Լ� ȣ��
		}
	}

	template<class T>
	void UpdateMasterList(Node<T>* root, int currentIndex) {
		MultimediaContent content;
		content = root->data; //������ �ӽ� ���� �� ��忡�� ���� �޾ƿ�
		ui.MasterList->setRowCount(currentIndex+1); //���� ��ġ��
		ui.MasterList->setItem(currentIndex, 0, new QTableWidgetItem(content.getFileName().c_str()));
		ui.MasterList->setItem(currentIndex, 1, new QTableWidgetItem(content.getCreateDate().c_str()));
		ui.MasterList->setItem(currentIndex, 2, new QTableWidgetItem(content.getFileType().c_str()));
		ui.MasterList->setItem(currentIndex, 3, new QTableWidgetItem(content.getInnerEvent().c_str()));
		ui.MasterList->setItem(currentIndex, 4, new QTableWidgetItem(content.getInnerPerson().c_str()));
		ui.MasterList->setItem(currentIndex, 5, new QTableWidgetItem(content.getInnerPlace().c_str())); //���̺� ���� �������� �߰�
		currentIndex += 1; //��ġ�� 1 ������Ų ��

		if (root->left != nullptr) { //���� ��尡 �����ϸ�
			UpdateMasterList(root->left, currentIndex); //���� ���� ����Լ� ȣ��
		}
		if (root->right != nullptr) { //������ ��尡 �����ϸ�
			UpdateMasterList(root->right, currentIndex); //������ ���� ����Լ� ȣ��
		}
	}

public slots:
	//���� ��ħ ��ư�� ������ ��
	void Reload();

private slots:
	//�̵�� ����Ʈ���� �������� ���� �Ǿ��� ��
	void SelectUnregisterFile();
	
	//���� ����Ʈ���� �������� ���� �Ǿ��� ��
	void SelectRegisterFile();

	//���� �ҷ����� ���̾�α� ��ư�� ������ ��
	void OpenPhotoLoadDialog();

	//���� �ҷ����� ���̾�α� ��ư�� ������ ��
	void OpenVideoLoadDialog();

	//��� ����Ʈ ���� ��ư�� ������ ��
	void MakeEmpty();

	//������ �߰� ��ư�� ������ ��
	void AddItem();

	//������ ���� ��ư�� ������ ��
	void DeleteItem();

	//���Ͽ� ���� ��ư�� ������ ��
	void SaveToFile();

	//���Ϸκ��� �ҷ����� ��ư�� ������ ��
	void LoadFromFile();
};
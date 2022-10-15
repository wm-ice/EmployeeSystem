#pragma once  //��ֹͷ�ļ��ظ�����
#include<bits/stdc++.h>
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

//������
class WorkerManager
{
public:
	WorkerManager();
	//��ʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//����ְ��
	void addInfo();
	//��ʾְ��
	void showInfo();
	//ɾ��ְ��
	void deleteInfo();
	//�޸�ְ����Ϣ
	void modifyInfo();
	//����ְ��
	void findInfo();
	//����
	void sortByNumber();
	//���
	void clearInfo();

	~WorkerManager();

	//��¼ְ������
	int EmpNum;
	//ְ������ָ��
	Worker** EmpArray;

	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//�����ļ��е�����
	int getEmpNum();
	//��ʼ��ְ��
	void initEmp();
	//�ж�ְ������Ƿ���ڣ����ڷ���λ�ã������ڷ���-1
	int isExistEmp(int id);
};

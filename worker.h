#pragma once
#include<bits/stdc++.h>
using namespace std;
//ְ��������
class Worker
{
public:
	//ְ�����
	int iNum;
	//ְ������
	string cName;
	//���ű��
	int iDeptId;
	//��ʾ������Ϣ
	virtual void showWorkerInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

};
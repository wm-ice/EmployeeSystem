#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"worker.h"

class Manager :public Worker
{
public:
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showWorkerInfo();
	//��ȡ��λ����
	virtual string getDeptName();

};
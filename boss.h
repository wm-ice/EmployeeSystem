#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showWorkerInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int did);
	//�����븸����ͬ
	//��ʾ������Ϣ
	virtual void showWorkerInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};
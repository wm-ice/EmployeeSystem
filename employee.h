#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int did);
	//以下与父类相同
	//显示个人信息
	virtual void showWorkerInfo();
	//获取岗位名称
	virtual string getDeptName();
};
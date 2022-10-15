#pragma once
#include<bits/stdc++.h>
using namespace std;
#include"worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//显示个人信息
	virtual void showWorkerInfo();
	//获取岗位名称
	virtual string getDeptName();
};
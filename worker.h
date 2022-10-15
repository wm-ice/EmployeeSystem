#pragma once
#include<bits/stdc++.h>
using namespace std;
//职工抽象类
class Worker
{
public:
	//职工编号
	int iNum;
	//职工姓名
	string cName;
	//部门编号
	int iDeptId;
	//显示个人信息
	virtual void showWorkerInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

};
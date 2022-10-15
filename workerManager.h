#pragma once  //防止头文件重复包含
#include<bits/stdc++.h>
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

//管理类
class WorkerManager
{
public:
	WorkerManager();
	//显示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//增加职工
	void addInfo();
	//显示职工
	void showInfo();
	//删除职工
	void deleteInfo();
	//修改职工信息
	void modifyInfo();
	//查找职工
	void findInfo();
	//排序
	void sortByNumber();
	//清空
	void clearInfo();

	~WorkerManager();

	//记录职工人数
	int EmpNum;
	//职工数组指针
	Worker** EmpArray;

	//保存文件
	void save();
	//判断文件是否为空
	bool fileIsEmpty;
	//返回文件中的人数
	int getEmpNum();
	//初始化职工
	void initEmp();
	//判断职工编号是否存在，存在返回位置，不存在返回-1
	int isExistEmp(int id);
};

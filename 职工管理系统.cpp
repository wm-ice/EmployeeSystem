/*
公司的职员分为：普通员工、经理、老板；
显示信息：职工编号、职工姓名、职工岗位、职责
普通员工职责:完成经理交给的任务
经理职责：完成老板交给的任务，并下发任务给员工
老板职责：管理公司所有事务

系统功能：
退出管理程序，添加职工信息，显示职工信息，删除离职职工（编号），
修改职工信息（编号），查找职工信息（编号或姓名），
按照编号排序（升降序），清空所有文档

*/

#include<bits/stdc++.h>
using namespace std;
#include"workerManager.h"

int main()
{
	WorkerManager wm;
	int index = 1;
	while (index)
	{
		wm.showMenu();
		cin >> index;
		switch (index)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addInfo();
			break;
		case 2:
			wm.showInfo();
			system("pause");
			system("cls");
			break;
		case 3:
			wm.deleteInfo();
			break;
		case 4:
			wm.modifyInfo();
			break;
		case 5:
			wm.findInfo();
			break;
		case 6:
			wm.sortByNumber();
			break;
		case 7:
			wm.clearInfo();
			break;
		default:
			//输入其他则清屏操作
			system("cls");
			break;
		}
	}
	return 1;
}
#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//显示个人信息
void Manager::showWorkerInfo()
{
	cout << "职工编号：" << this->iNum << "\t姓名：" << this->cName
		<< "\t岗位：" << this->getDeptName() << "\t职责：完成老板交给的任务，并下发任务给员工" << endl;
}
//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}
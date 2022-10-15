#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//显示个人信息
void Boss::showWorkerInfo()
{
	cout << "职工编号：" << this->iNum << "\t姓名：" << this->cName
		<< "\t岗位：" << this->getDeptName() << "\t职责：管理公司所有事务" << endl;
}
//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}
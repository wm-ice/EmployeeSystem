#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//显示个人信息
void Employee::showWorkerInfo()
{
	cout << "职工编号：" << this->iNum << "\t姓名：" << this->cName
		<< "\t岗位：" << this->getDeptName()<<"\t职责：完成经理交给的任务" << endl;
}
//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
}
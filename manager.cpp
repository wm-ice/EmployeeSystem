#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//��ʾ������Ϣ
void Manager::showWorkerInfo()
{
	cout << "ְ����ţ�" << this->iNum << "\t������" << this->cName
		<< "\t��λ��" << this->getDeptName() << "\tְ������ϰ彻�������񣬲��·������Ա��" << endl;
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}
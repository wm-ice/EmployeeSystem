#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//��ʾ������Ϣ
void Employee::showWorkerInfo()
{
	cout << "ְ����ţ�" << this->iNum << "\t������" << this->cName
		<< "\t��λ��" << this->getDeptName()<<"\tְ����ɾ�����������" << endl;
}
//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}
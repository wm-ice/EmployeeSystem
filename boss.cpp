#include"boss.h"

Boss::Boss(int id, string name, int did)
{
	this->iNum = id;
	this->cName = name;
	this->iDeptId = did;
}
//��ʾ������Ϣ
void Boss::showWorkerInfo()
{
	cout << "ְ����ţ�" << this->iNum << "\t������" << this->cName
		<< "\t��λ��" << this->getDeptName() << "\tְ�𣺹���˾��������" << endl;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}
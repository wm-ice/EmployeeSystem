/*
��˾��ְԱ��Ϊ����ͨԱ���������ϰ壻
��ʾ��Ϣ��ְ����š�ְ��������ְ����λ��ְ��
��ͨԱ��ְ��:��ɾ�����������
����ְ������ϰ彻�������񣬲��·������Ա��
�ϰ�ְ�𣺹���˾��������

ϵͳ���ܣ�
�˳�����������ְ����Ϣ����ʾְ����Ϣ��ɾ����ְְ������ţ���
�޸�ְ����Ϣ����ţ�������ְ����Ϣ����Ż���������
���ձ�����������򣩣���������ĵ�

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
			//������������������
			system("cls");
			break;
		}
	}
	return 1;
}
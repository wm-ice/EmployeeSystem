#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	if (!ifs.is_open())
	{
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����
	char ch;
	ifs >> ch;
	//�ļ�Ϊ��
	if(ifs.eof())
	{
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->EmpNum = this->getEmpNum();
	this->fileIsEmpty = false;
	//�����������ٿռ�
	this->EmpArray = new Worker * [this->EmpNum];
	//���ļ������ݴ����������
	this->initEmp();
	
}

WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		//ɾ��������ÿ��ְ������
		for (int i = 0; i < this->EmpNum; i++)
		{
			delete this->EmpArray[i];
			this->EmpArray[i] = NULL;
		}
		//ɾ����������ָ��
		this->EmpNum = 0;
		delete[] this->EmpArray;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
	}
}

void WorkerManager::showMenu()
{
	cout << "��ӭʹ��ְ������ϵͳ��" << endl;
	cout << "0���˳�����ϵͳ" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ��ְ����Ϣ" << endl;
	cout << "4���޸�ְ����Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;
	cout << "6�����ձ������" << endl;
	cout << "7����������ĵ�" << endl;
	cout << "�������������ѡ��Ҫ���еĲ�����";
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addInfo()
{
	int iAddNum = 0;
	cout << "���������ְ������:" ;
	cin >> iAddNum;
	if (iAddNum > 0)
	{
		//��������¿ռ��С
		int newSize = this->EmpNum + iAddNum;
		Worker** newSpace = new Worker * [newSize];
		//��ԭ�ȿռ��ڵ����ݿ������¿ռ���
		if (this->EmpNum != 0)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				newSpace[i] = this->EmpArray[i];
			}
		}
		//���������
		for (int i = 0; i < iAddNum; i++)
		{
			int m_id;
			string m_name;
			int m_deptId;
			cout << "�������" << i + 1 << "����ְ������Ϣ��" <<endl;
			cout << "ְ�����:";
			cin >> m_id;
			while (true)
			{
				if (isExistEmp(m_id)!=-1)
				{
					cout << "��ְ������Ѵ��ڣ�����������ְ����ţ�";
					cin >> m_id;
				}
				else
				{
					break;
				}
			}
			cout << "ְ������:";
			cin >> m_name;
			cout << "��ѡ���ְ���ĸ�λ:"<<endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> m_deptId;
			Worker* worker = NULL;
			switch (m_deptId)
			{
			case 1:
				worker = new Employee(m_id, m_name, m_deptId);
				break;
			case 2:
				worker = new Manager(m_id, m_name, m_deptId);
				break;
			case 3:
				worker = new Boss(m_id, m_name, m_deptId);
				break;
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->EmpArray;
		//�����¿ռ��ָ��ָ��
		this->EmpArray = newSpace;
		//���µ�ǰְ������
		this->EmpNum = newSize;

		//д���ļ�
		this->save();
		this->fileIsEmpty = false;
		cout << "�ѳɹ������" << iAddNum << "����ְ����" << endl;
	}
	else
	{
		cout << "��������"<<endl;
	}

	//��������
	system("pause");
	system("cls");
}

void WorkerManager::showInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "��ǰ��δӵ��ְ����Ϣ��������ѡ�����!" << endl;
	}
	else
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			//���ö�̬���ý��
			this->EmpArray[i]->showWorkerInfo();
		}
	}
	
}

int WorkerManager::isExistEmp(int id)
{
	int index = -1;
	for (int i = 0; i < this->EmpNum; i++)
	{
		if (this->EmpArray[i]->iNum == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::deleteInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "ְ�������ڻ�û��ְ����Ϣ��" << endl;
		//��������
		system("pause");
		system("cls");
		return;
	}
	int delNum = 0;
	cout << "������Ҫɾ��ְ���ı�ţ�";
	cin >> delNum;
	int iLocation = isExistEmp(delNum);
	if (iLocation < 0)
	{
		cout << "��ְ�������ڣ�" << endl;
	}
	else
	{
		for (int i = iLocation; i < this->EmpNum; i++)
		{
			this->EmpArray[i] = this->EmpArray[i + 1];
		}
		this->EmpNum --;
		this->save();
		cout << "ɾ���ɹ���" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

void WorkerManager::modifyInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "ְ�������ڻ�û��ְ����Ϣ��" << endl;
		//��������
		system("pause");
		system("cls");
		return;
	}
	showInfo();
	int modNum = 0;
	cout << "������Ҫ�޸ĵ�ְ���ı�ţ�";
	cin >> modNum;
	int iLocation = isExistEmp(modNum);
	if (iLocation < 0)
	{
		cout << "��ְ�������ڣ�" << endl;
	}
	else
	{
		string m_name;
		int m_deptId;
		cout << "������ְ������:";
		cin >> m_name;
		cout << "��ѡ���ְ���ĸ�λ:" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> m_deptId;
		Worker* worker = NULL;
		switch (m_deptId)
		{
		case 1:
			worker = new Employee(modNum, m_name, m_deptId);
			break;
		case 2:
			worker = new Manager(modNum, m_name, m_deptId);
			break;
		case 3:
			worker = new Boss(modNum, m_name, m_deptId);
			break;
		default:
			break;
		}
		this->EmpArray[iLocation] = worker;
		this->save();
		cout << "���³ɹ���" << endl;
	}
	//��������
	system("pause");
	system("cls");
}

void WorkerManager::findInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "ְ�������ڻ�û��ְ����Ϣ��" << endl;
		//��������
		system("pause");
		system("cls");
		return;
	}
	int iManner = 0;
	cout << "������Ҫ���ҷ�ʽ��1��ְ����ţ�2��ְ��������";
	cin >> iManner;
	if (iManner == 1)
	{
		int modNum = 1;
		cout << "������Ҫ���ҵ�ְ���ı�ţ�";
		cin >> modNum;
		int iLocation = isExistEmp(modNum);
		if (iLocation < 0)
		{
			cout << "��ְ�������ڣ�" << endl;
		}
		else
		{
			this->EmpArray[iLocation]->showWorkerInfo();
		}
	}
	else
	{
		string modName ;
		cout << "������Ҫ���ҵ�ְ����������";
		cin >> modName;
		bool exitEmp = false;
		for (int i = 0; i < this->EmpNum; i++)
		{
			if (this->EmpArray[i]->cName == modName)
			{
				this->EmpArray[i]->showWorkerInfo();
				exitEmp = true;
			}
		}
		if (!exitEmp)
		{
			cout << "��ְ�������ڣ�" << endl;
		}
	}
	//��������
	system("pause");
	system("cls");
}

void WorkerManager::sortByNumber()
{
	if (this->fileIsEmpty)
	{
		cout << "ְ�������ڻ�û��ְ����Ϣ��" << endl;
		//��������
		system("pause");
		system("cls");
		return;
	}
	if (this->EmpNum < 2)
	{
		cout << "��ǰ��Ϣ���㣬�����������" << endl;
		showInfo();
		//��������
		system("pause");
		system("cls");
		return;
	}
	int iManner = 1;
	cout << "��ѡ������ʽ��1������2������";
	cin >> iManner;
	if (iManner == 1)
	{
		for (int i = 0; i < this->EmpNum-1; i++)
		{
			for (int j = 0; j < this->EmpNum - i - 1; j++)
			{
				if (this->EmpArray[j]->iNum > this->EmpArray[j + 1]->iNum)
				{
					Worker* workerTmp = this->EmpArray[j];
					this->EmpArray[j] = this->EmpArray[j+1];
					this->EmpArray[j+1] = workerTmp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < this->EmpNum-1; i++)
		{
			for (int j = 0; j < this->EmpNum - 1 - i; j++)
			{
				if (this->EmpArray[j]->iNum < this->EmpArray[j + 1]->iNum)
				{
					Worker* workerTmp = this->EmpArray[j];
					this->EmpArray[j] = this->EmpArray[j + 1];
					this->EmpArray[j + 1] = workerTmp;
				}
			}
		}
	}
	cout << "����ɹ���" << endl;
	showInfo();
	this->save();
	//��������
	system("pause");
	system("cls");
}

void WorkerManager::clearInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "ְ�������ڻ�û��ְ����Ϣ���޷�������ղ�����" << endl;
		//��������
		system("pause");
		system("cls");
		return;
	}
	cout << "�Ƿ�ȷ��Ҫ���ְ����Ϣ��" << endl;
	cout << "1���ǣ�2����";
	int iSelect = 2;
	cin >> iSelect;
	if (iSelect == 1)
	{
		//ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->EmpNum; i++)
			{
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			this->EmpNum = 0;
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->fileIsEmpty = true;
		}
		cout << "����ճɹ���" << endl;
	}
	
	//��������
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->EmpNum; i++)
	{
		ofs << this->EmpArray[i]->iNum << "\t"
			<< this->EmpArray[i]->cName << "\t "
			<< this->EmpArray[i]->iDeptId << endl;
	}
}

int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int dId;
	int iCount = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		iCount++;
	}
	return iCount;
}

void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int dId;
	int iCount = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId==2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->EmpArray[iCount++] = worker;
		
	}
	ifs.close();
}
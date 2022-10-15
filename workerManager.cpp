#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件
	if (!ifs.is_open())
	{
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在
	char ch;
	ifs >> ch;
	//文件为空
	if(ifs.eof())
	{
		this->EmpNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->EmpNum = this->getEmpNum();
	this->fileIsEmpty = false;
	//根据人数开辟空间
	this->EmpArray = new Worker * [this->EmpNum];
	//将文件的数据存放在数组中
	this->initEmp();
	
}

WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		//删除堆区的每个职工对象
		for (int i = 0; i < this->EmpNum; i++)
		{
			delete this->EmpArray[i];
			this->EmpArray[i] = NULL;
		}
		//删除堆区数组指针
		this->EmpNum = 0;
		delete[] this->EmpArray;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
	}
}

void WorkerManager::showMenu()
{
	cout << "欢迎使用职工管理系统！" << endl;
	cout << "0、退出管理系统" << endl;
	cout << "1、增加职工信息" << endl;
	cout << "2、显示职工信息" << endl;
	cout << "3、删除职工信息" << endl;
	cout << "4、修改职工信息" << endl;
	cout << "5、查找职工信息" << endl;
	cout << "6、按照编号排序" << endl;
	cout << "7、清空所有文档" << endl;
	cout << "请输入以上序号选择要进行的操作：";
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addInfo()
{
	int iAddNum = 0;
	cout << "请输入添加职工数量:" ;
	cin >> iAddNum;
	if (iAddNum > 0)
	{
		//计算添加新空间大小
		int newSize = this->EmpNum + iAddNum;
		Worker** newSpace = new Worker * [newSize];
		//将原先空间内的数据拷贝到新空间下
		if (this->EmpNum != 0)
		{
			for (int i = 0; i < this->EmpNum; i++)
			{
				newSpace[i] = this->EmpArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < iAddNum; i++)
		{
			int m_id;
			string m_name;
			int m_deptId;
			cout << "请输入第" << i + 1 << "个新职工的信息：" <<endl;
			cout << "职工编号:";
			cin >> m_id;
			while (true)
			{
				if (isExistEmp(m_id)!=-1)
				{
					cout << "该职工编号已存在，请重新输入职工编号：";
					cin >> m_id;
				}
				else
				{
					break;
				}
			}
			cout << "职工姓名:";
			cin >> m_name;
			cout << "请选择该职工的岗位:"<<endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建职工职责，保存到数组中
			newSpace[this->EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->EmpArray;
		//更改新空间的指针指向
		this->EmpArray = newSpace;
		//更新当前职工人数
		this->EmpNum = newSize;

		//写入文件
		this->save();
		this->fileIsEmpty = false;
		cout << "已成功添加了" << iAddNum << "名新职工！" << endl;
	}
	else
	{
		cout << "输入有误"<<endl;
	}

	//清屏操作
	system("pause");
	system("cls");
}

void WorkerManager::showInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "当前并未拥有职工信息，请重新选择操作!" << endl;
	}
	else
	{
		for (int i = 0; i < this->EmpNum; i++)
		{
			//利用多态调用借口
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
		cout << "职工不存在或没有职工信息！" << endl;
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	int delNum = 0;
	cout << "请输入要删除职工的编号：";
	cin >> delNum;
	int iLocation = isExistEmp(delNum);
	if (iLocation < 0)
	{
		cout << "该职工不存在！" << endl;
	}
	else
	{
		for (int i = iLocation; i < this->EmpNum; i++)
		{
			this->EmpArray[i] = this->EmpArray[i + 1];
		}
		this->EmpNum --;
		this->save();
		cout << "删除成功！" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}

void WorkerManager::modifyInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "职工不存在或没有职工信息！" << endl;
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	showInfo();
	int modNum = 0;
	cout << "请输入要修改的职工的编号：";
	cin >> modNum;
	int iLocation = isExistEmp(modNum);
	if (iLocation < 0)
	{
		cout << "该职工不存在！" << endl;
	}
	else
	{
		string m_name;
		int m_deptId;
		cout << "请输入职工姓名:";
		cin >> m_name;
		cout << "请选择该职工的岗位:" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
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
		cout << "更新成功！" << endl;
	}
	//清屏操作
	system("pause");
	system("cls");
}

void WorkerManager::findInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "职工不存在或没有职工信息！" << endl;
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	int iManner = 0;
	cout << "请输入要查找方式：1、职工编号；2、职工姓名：";
	cin >> iManner;
	if (iManner == 1)
	{
		int modNum = 1;
		cout << "请输入要查找的职工的编号：";
		cin >> modNum;
		int iLocation = isExistEmp(modNum);
		if (iLocation < 0)
		{
			cout << "该职工不存在！" << endl;
		}
		else
		{
			this->EmpArray[iLocation]->showWorkerInfo();
		}
	}
	else
	{
		string modName ;
		cout << "请输入要查找的职工的姓名：";
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
			cout << "该职工不存在！" << endl;
		}
	}
	//清屏操作
	system("pause");
	system("cls");
}

void WorkerManager::sortByNumber()
{
	if (this->fileIsEmpty)
	{
		cout << "职工不存在或没有职工信息！" << endl;
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	if (this->EmpNum < 2)
	{
		cout << "当前信息不足，无须进行排序" << endl;
		showInfo();
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	int iManner = 1;
	cout << "请选择排序方式：1、升序；2、降序：";
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
	cout << "排序成功！" << endl;
	showInfo();
	this->save();
	//清屏操作
	system("pause");
	system("cls");
}

void WorkerManager::clearInfo()
{
	if (this->fileIsEmpty)
	{
		cout << "职工不存在或没有职工信息，无法进行清空操作！" << endl;
		//清屏操作
		system("pause");
		system("cls");
		return;
	}
	cout << "是否确认要清空职工信息？" << endl;
	cout << "1、是；2、否：";
	int iSelect = 2;
	cin >> iSelect;
	if (iSelect == 1)
	{
		//删除文件后重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->EmpNum; i++)
			{
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			this->EmpNum = 0;
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->fileIsEmpty = true;
		}
		cout << "已清空成功！" << endl;
	}
	
	//清屏操作
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
	ifs.open(FILENAME, ios::in);//读文件
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
	ifs.open(FILENAME, ios::in);//读文件
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
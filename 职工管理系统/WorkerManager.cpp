#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	Ehead = new Employee;
	Ehead->next = NULL;
	fstream Employeefile;   //输入数据
	Employeefile.open("Employee.txt", ios::in);
	Employee* e, * eh;
	eh = Ehead;
	if (Employeefile.is_open())
	{
		while (!Employeefile.eof())
		{
			e = new Employee;
			Employeefile >> e->m_ID >> e->m_Name;
			eh->next = e;
			eh = e;
		}
		eh->next = NULL;
		Employeefile.close();
	}

	Mhead = new Manager;
	Mhead->next = NULL;
	fstream Managerfile;   //输入数据
	Managerfile.open("Manager.txt", ios::in);
	Manager* m, * mh;
	mh = Mhead;
	if (Managerfile.is_open())
	{
		while (!Managerfile.eof())
		{
			m = new Manager;
			Managerfile >> m->m_ID >> m->m_Name;
			mh->next = m;
			mh = m;
		}
		mh->next = NULL;
		Managerfile.close();
	}
	
	Bhead = new Boss;
	Bhead->next = NULL;
	fstream Bossfile;   //输入数据
	Bossfile.open("Boss.txt", ios::in);
	Boss* b,* bh;
	bh = Bhead;
	if (Bossfile.is_open())
	{
		while (!Bossfile.eof())
		{
			b = new Boss;
			Bossfile >> b->m_ID >> b->m_Name;
			bh->next = b;
			bh = b;
		}
		bh->next = NULL;
		Bossfile.close();
	}
}

WorkerManager::~WorkerManager()
{
	char choice = 0;
	while (1)
	{
		cout << "是否保存？[Y/N]" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			if (Ehead->next != NULL)
			{
				Employee* p = Ehead;
				ofstream Efile;
				Efile.open("Employee.txt", ios::out);   //保存为txt文件
				while (p->next != NULL)
				{
					p = p->next;
					Efile << endl << p->m_ID << "\t" << p->m_Name;
				}
				Efile.close();
			}

			if (Mhead->next != NULL)
			{
				Manager* p = Mhead;
				ofstream Mfile;
				Mfile.open("Manager.txt", ios::out);   //保存为txt文件
				while (p->next != NULL)
				{
					p = p->next;
					Mfile << endl << p->m_ID << "\t" << p->m_Name;
				}
				Mfile.close();
			}

			if (Bhead->next != NULL)
			{
				Boss* p = Bhead;
				/*Boss* Bend = Bhead;
				while (Bend->next != NULL)
				{
					Bend = Bend->next;
				}*/
				ofstream Bfile;
				Bfile.open("Boss.txt", ios::out);   //保存为txt文件
				while (p->next != NULL)
				{
					p = p->next;
					Bfile << endl << p->m_ID << "\t" << p->m_Name;
				}
				Bfile.close();
			}
			cout << "已保存" << endl;
			cout << "欢迎下次使用！" << endl;
			break;
		}
		else if (choice == 'N' || choice == 'n') {
			system("cls");
		};
	}
}

//判断链表是否为空
bool WorkerManager::IsEmpty()
{
	if (Bhead->next == NULL)
	{
		return true;
	}
	return false;
}

//显示菜单
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  Esc.退出程序    *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitSystem()
{
	cout << "是否确定退出？" << endl;
	cout << "是：Y\t否：N" << endl;
	char choice11 = 0;
	cin >> choice11;

	if (choice11 == 'Y' || choice11 == 'y')
	{
		cout << "欢迎下次使用" << endl;
		this->~WorkerManager();
		system("pause");
		exit(0);
	}
	else if (choice11 == 'N' || choice11 == 'n') {
		system("cls");
	};
}

//普通员工链表
//Employee* Emlink(int wm_dSelect)
//{
//	Employee* Ehead, * Enode, * Eend;
//	Ehead = (Employee*)malloc(sizeof(Employee));
//	Eend = Ehead;
//	while (_getch() != 27)
//	{
//		Enode = (Employee*)malloc(sizeof(Employee));
//		cout << "请输入新员工姓名：" << endl;
//		cin >> Enode->m_Name;
//		cout << "----------" << endl
//			<< "请输入新员工编号：" << endl;
//		cin >> Enode->m_ID;
//		Enode->m_DeptID = wm_dSelect;
//		Enode->showInfo();
//		Eend->next = Enode;
//		Eend = Enode;
//	}
//
//	Eend->next = NULL;
//	return Ehead;
//}

//经理链表
//Manager* Malink(int wm_dSelect)
//{
//	
//	Manager* Mhead, * Mnode, * Mend;
//	Mhead = (Manager*)malloc(sizeof(Manager));
//	Mend = Mhead;
//	while (_getch() != 27) 
//	{
//		Mnode = (Manager*)malloc(sizeof(Manager));
//		cout << "请输入新员工姓名：" << endl;
//		cin >> Mnode->m_Name;
//		cout << "----------" << endl
//			<< "请输入新员工编号：" << endl;
//		cin >> Mnode->m_ID;
//		Mnode->m_DeptID = wm_dSelect;
//		Mnode->showInfo();
//		Mend->next = Mnode;
//		Mend = Mnode;
//		
//	}
//	
//	Mend->next = NULL;
//	return Mhead;
//}



//增加员工
void WorkerManager::Add_Emp()
{
	int addNum = 0;
	int wm_dSelect = 0;
	Employee* Enode = NULL;
	Employee* e = Ehead;

	Manager* Mnode = NULL;
	Manager* m = Mhead;

	Boss* Bnode = NULL;
	Boss* b = Bhead;

	//输入新数据
	cout << "请选择该职工的岗位：" << endl;
	cout << "1、普通职工" << endl;
	cout << "2、经理" << endl;
	cout << "3、老板" << endl;
	cin >> wm_dSelect;
	switch (wm_dSelect)
	{
	case 1: //普通员工
		while (_getch() != 27)
		{
			Enode = (Employee *)malloc(sizeof(Employee));
			e = Ehead;
			m = Mhead;
			b = Bhead;
			cout << "请输入新员工姓名：" << endl;
			cin >> Enode->m_Name;
			cout << "----------" << endl
				<< "请输入新员工编号：" << endl;
			cin >> Enode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//防止id相同 
			{
				if (Enode->m_ID == e->m_ID || Enode->m_ID == m->m_ID || Enode->m_ID == b->m_ID)
				{
					cout << "员工编号相同，请重新输入！" << endl;
					cin >> Enode->m_ID;
					e = Ehead;
					m = Mhead;
					b = Bhead;
					continue;
				}
				if (e->next != NULL)e = e->next;
				if (m->next != NULL)m = m->next;
				if (b->next != NULL)b = b->next;
			}
			Enode->m_DeptID = wm_dSelect;
			e = Ehead;
			while (e->next != NULL)
			{
				e = e->next;
			}
			e->next = Enode;
			Enode->next = NULL;
			cout << "添加成功！" << endl;
		}
		break;
	case 2: //经理
		while (_getch() != 27)
		{
			Mnode = (Manager*)malloc(sizeof(Manager));
			e = Ehead;
			m = Mhead;
			b = Bhead;
			cout << "请输入新员工姓名：" << endl;
			cin >> Mnode->m_Name;
			cout << "----------" << endl
				<< "请输入新员工编号：" << endl;
			cin >> Mnode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//防止id相同 
			{
				if (Mnode->m_ID == e->m_ID || Mnode->m_ID == m->m_ID || Mnode->m_ID == b->m_ID)
				{
					cout << "员工编号相同，请重新输入！" << endl;
					cin >> Mnode->m_ID;
					e = Ehead;
					m = Mhead;
					b = Bhead;
					continue;
				}
				if (e->next != NULL)e = e->next;
				if (m->next != NULL)m = m->next;
				if (b->next != NULL)b = b->next;
			}
			Mnode->m_DeptID = wm_dSelect;
			m = Mhead;
			while (m->next != NULL)
			{
				m = m->next;
			}
			m->next = Mnode;
			Mnode->next = NULL;
			cout << "添加成功！" << endl;
		}
		break;
	case 3:  //老板
		
		/*if (Bhead == NULL) {
			Bhead = Bnode;
		}
		else {
			while (p->next != NULL) {
				p = p->next;
			}
		}*/
		while (_getch() != 27)
		{
			Bnode = (Boss*)malloc(sizeof(Boss));
			e = Ehead;
			m = Mhead;
			b = Bhead;
			//Bnode = Bhead;
			cout << "请输入新员工姓名：" << endl;
			cin >> Bnode->m_Name;
			cout << "----------" << endl
				<< "请输入新员工编号：" << endl;
			cin >> Bnode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//防止id相同 
			{
				if (Bnode->m_ID == e->m_ID || Bnode->m_ID == m->m_ID || Bnode->m_ID == b->m_ID)
				{
					cout << "员工编号相同，请重新输入！" << endl;
					cin >> Bnode->m_ID;
					b = Bhead;
					continue;
				}
				if (e->next != NULL)e = e->next;
				if (m->next != NULL)m = m->next;
				if (b->next != NULL)b = b->next;
			}
			Bnode->m_DeptID = wm_dSelect;
			b = Bhead;
			while (b->next != NULL)
			{
				b = b->next;
			}
			b->next = Bnode;
			Bnode->next = NULL;
			cout << "添加成功！" << endl;
		}
		break;
	default:
		break;
	}
	
}

//显示职工
void WorkerManager::Show_Emp()
{
	int wm_sh;
	string buf;
	worker a;
	cout << "请选择要显示的员工职位：" << endl;
	cout << "1、普通职工" << endl;
	cout << "2、经理" << endl;
	cout << "3、老板" << endl;
	cin >> wm_sh;
	cout<< "职工编号： " << " \t职工姓名： "
		<< " \t岗位： " <<a.getDeptName(wm_sh)
		<< " \t岗位职责：" << a.getwork(wm_sh) << endl;
	switch (wm_sh)
	{
	case 1:
		if (Ehead == NULL || Ehead->next == NULL) {
			cout << "链表为空表" << endl;
		}
		else {
			Employee* e = Ehead;                 //另指针指向头结点

			while (e->next != NULL)        //当指针的下一个地址不为空时，循环输出m的数据域
			{
				e = e->next;               //m指向m的下一个地址
				cout << e->m_ID << "\t" << e->m_Name << endl;
			}
		}
		break;
	case 2:
		if (Mhead == NULL || Mhead->next == NULL) {
			cout << "链表为空表" << endl;
		}
		else {
			Manager* m = Mhead;                 //另指针指向头结点

			while (m->next != NULL)        //当指针的下一个地址不为空时，循环输出m的数据域
			{
				m = m->next;               //m指向m的下一个地址
				cout << m->m_ID << "\t" << m->m_Name << endl;
			}
		}
		break;
	case 3:
		if (Bhead == NULL || Bhead->next == NULL) {
			cout << "链表为空表" << endl;
		}
		else {
			Boss* b = Bhead;                 //另指针指向头结点

			while (b->next != NULL)        //当指针的下一个地址不为空时，循环输出b的数据域
			{
				b = b->next;               //b指向b的下一个地址
				cout << b->m_ID << "\t" << b->m_Name << endl;
			}
		}
		break;
	}
}

//查找员工
Boss* WorkerManager::Find(int id)
{
	Boss* b = Bhead;
	if (b == NULL) {
		cout << "未找到老板文件！" << endl;
		return ERROR;
	}
	else {
		while (b->next != NULL)
		{
			if (b->m_ID == id) {
				cout << "该员工ID为：" << b->m_ID << "\t姓名为：" << b->m_Name << endl;
				return b;
			}
			b = b->next;
		}
		return NULL;
	}
}

//删除员工
void WorkerManager::DeleteWorker(int id)
{
	Boss* Btemp = Find(id);
	char Delete;
	while (true)
	{
		cout << "是否删除？(Y/N)" << endl;
		cin >> Delete;
		if (Delete == 'Y' || Delete == 'y')break;
		else if (Delete == 'N' || Delete == 'n') {
			system("cls");
			break;
		};
		cin >> Delete;
	}
	if(Btemp == NULL)
	{
		cout << "未找到该员工！" << endl;
	}
	else {
		Boss* p = Bhead;
		while (p->next != Btemp)
		{
			p = p->next;
		}
		p->next = Btemp->next;
		//delete Btemp;
		//Btemp = NULL;
		cout << "删除成功！" << endl;
	}
	
}

//修改职工
void WorkerManager::Mod_Emp(int id) 
{
	Employee* e = Ehead;
	Manager* m = Mhead;
	Boss* b = Bhead;
	int choice = 0;
	cout << "请选择该职工的岗位：" << endl;
	cout << "1、普通职工" << endl;
	cout << "2、经理" << endl;
	cout << "3、老板" << endl;
	cin >> choice;
	cout << "请输入该职工的ID：" << endl;
	cin >> id;
	switch (choice)
	{
	case 1:
		while (e->next != NULL)
		{
			if (e == NULL && e->next == NULL)
			{
				cout << "未找到该职工资料！" << endl;
				break;
			}
			if (e->m_ID == id)
			{
				cout << "该员工ID为：" << e->m_ID << "\t姓名为：" << e->m_Name << endl;
				cout << "请输入该员工新ID：" << endl;
				cin >> e->m_ID;
				cout << "请输入该员工新名字：" << endl;
				cin >> e->m_Name;
				cout << "修改成功！" << endl;
				break;
			}
			e = e->next;
		}
		break;
	case 2:
		while (m->next != NULL)
		{
			if (m == NULL && m->next == NULL)
			{
				cout << "未找到该职工资料！" << endl;
				break;
			}
			if (m->m_ID == id)
			{
				cout << "该员工ID为：" << m->m_ID << "\t姓名为：" << m->m_Name << endl;
				cout << "请输入该员工新ID：" << endl;
				cin >> m->m_ID;
				cout << "请输入该员工新名字：" << endl;
				cin >> m->m_Name;
				cout << "修改成功！" << endl;
				break;
			}
			m = m->next;
		}
		break;
	case 3:
		while (b->next != NULL)
		{
			if (b == NULL && b->next == NULL)
			{
				cout << "未找到该职工资料！" << endl;
				break;
			}
			if (b->m_ID == id)
			{
				cout << "该员工ID为：" << b->m_ID << "\t姓名为：" << b->m_Name << endl;
				cout << "请输入该员工新ID：" << endl;
				cin >> b->m_ID;
				cout << "请输入该员工新名字：" << endl;
				cin >> b->m_Name;
				cout << "修改成功！" << endl;
				break;
			}
			b = b->next;
		}
		break;
	default:
		system("cls");
		break;
	}
	
}

//排序职工
void WorkerManager::Sort_Emp()
{
	Employee * epre, * e, * eend, * etemp;
	Manager * mpre, * m, * mend, * mtemp;
	Boss* bpre, * b, * bend, * btemp;
	eend = NULL;
	mend = NULL;
	bend = NULL;
	epre = Ehead;
	mpre = Mhead;
	bpre = Bhead;

	while ((Ehead->next->next) != eend)
	{
		e = Ehead->next;
		epre = Ehead;

		while (e->next != eend)
		{
			if ((e->m_ID) > (e->next->m_ID))
			{
				epre->next = e->next;
				e->next = e->next->next;
				epre->next->next = e;
				e = epre->next;
			}
			e = e->next;
			epre = epre->next;
		}
		eend = e;
	}
	
	while ((Mhead->next->next) != mend)
	{
		m = Mhead->next;
		mpre = Mhead;

		while (m->next != mend)
		{
			if ((m->m_ID) > (m->next->m_ID))
			{
				mpre->next = m->next;
				m->next = m->next->next;
				mpre->next->next = m;
				m = mpre->next;
			}
			m = m->next;
			mpre = mpre->next;
		}
		mend = m;
	}

	while ((Bhead->next->next) != bend)
	{
		b = Bhead->next;
		bpre = Bhead;
	
		while (b->next != bend)
		{
			if ((b->m_ID) > (b->next->m_ID))
			{
				bpre->next = b->next;
				b->next = b->next->next;
				bpre->next->next = b;
				b = bpre->next;
			}
			b = b->next;
			bpre = bpre->next;
		}
		bend = b;
	}
}

//清空数据
void WorkerManager::DeleteAll()
{
	char DA_choice = 0;
	cout << "是否清空？(Y/N)" << endl;
	if (DA_choice == 'Y' || DA_choice == 'y')
	{
		Employee* e = Ehead->next;
		Employee* etemp = Ehead->next;
		Manager* m = Mhead->next;
		Manager* mtemp = Mhead->next;
		Boss* b = Bhead->next;
		Boss* btemp = new Boss;

		while (b != NULL || e != NULL || m != NULL)
		{
			btemp = b;
			etemp = e;
			mtemp = m;
			e = e->next;
			m = m->next;
			b = b->next;
			Ehead->next = e;
			Mhead->next = m;
			Bhead->next = b;
			etemp->next = NULL;
			mtemp->next = NULL;
			btemp->next = NULL;
			delete btemp, etemp, mtemp;
		}
		Bhead->next = NULL;
	}
	else system("cls");
}
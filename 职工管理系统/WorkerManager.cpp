#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	Ehead = new Employee;
	Ehead->next = NULL;
	fstream Employeefile;   //��������
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
	fstream Managerfile;   //��������
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
	fstream Bossfile;   //��������
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
		cout << "�Ƿ񱣴棿[Y/N]" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			if (Ehead->next != NULL)
			{
				Employee* p = Ehead;
				ofstream Efile;
				Efile.open("Employee.txt", ios::out);   //����Ϊtxt�ļ�
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
				Mfile.open("Manager.txt", ios::out);   //����Ϊtxt�ļ�
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
				Bfile.open("Boss.txt", ios::out);   //����Ϊtxt�ļ�
				while (p->next != NULL)
				{
					p = p->next;
					Bfile << endl << p->m_ID << "\t" << p->m_Name;
				}
				Bfile.close();
			}
			cout << "�ѱ���" << endl;
			cout << "��ӭ�´�ʹ�ã�" << endl;
			break;
		}
		else if (choice == 'N' || choice == 'n') {
			system("cls");
		};
	}
}

//�ж������Ƿ�Ϊ��
bool WorkerManager::IsEmpty()
{
	if (Bhead->next == NULL)
	{
		return true;
	}
	return false;
}

//��ʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  Esc.�˳�����    *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "�Ƿ�ȷ���˳���" << endl;
	cout << "�ǣ�Y\t��N" << endl;
	char choice11 = 0;
	cin >> choice11;

	if (choice11 == 'Y' || choice11 == 'y')
	{
		cout << "��ӭ�´�ʹ��" << endl;
		this->~WorkerManager();
		system("pause");
		exit(0);
	}
	else if (choice11 == 'N' || choice11 == 'n') {
		system("cls");
	};
}

//��ͨԱ������
//Employee* Emlink(int wm_dSelect)
//{
//	Employee* Ehead, * Enode, * Eend;
//	Ehead = (Employee*)malloc(sizeof(Employee));
//	Eend = Ehead;
//	while (_getch() != 27)
//	{
//		Enode = (Employee*)malloc(sizeof(Employee));
//		cout << "��������Ա��������" << endl;
//		cin >> Enode->m_Name;
//		cout << "----------" << endl
//			<< "��������Ա����ţ�" << endl;
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

//��������
//Manager* Malink(int wm_dSelect)
//{
//	
//	Manager* Mhead, * Mnode, * Mend;
//	Mhead = (Manager*)malloc(sizeof(Manager));
//	Mend = Mhead;
//	while (_getch() != 27) 
//	{
//		Mnode = (Manager*)malloc(sizeof(Manager));
//		cout << "��������Ա��������" << endl;
//		cin >> Mnode->m_Name;
//		cout << "----------" << endl
//			<< "��������Ա����ţ�" << endl;
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



//����Ա��
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

	//����������
	cout << "��ѡ���ְ���ĸ�λ��" << endl;
	cout << "1����ְͨ��" << endl;
	cout << "2������" << endl;
	cout << "3���ϰ�" << endl;
	cin >> wm_dSelect;
	switch (wm_dSelect)
	{
	case 1: //��ͨԱ��
		while (_getch() != 27)
		{
			Enode = (Employee *)malloc(sizeof(Employee));
			e = Ehead;
			m = Mhead;
			b = Bhead;
			cout << "��������Ա��������" << endl;
			cin >> Enode->m_Name;
			cout << "----------" << endl
				<< "��������Ա����ţ�" << endl;
			cin >> Enode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//��ֹid��ͬ 
			{
				if (Enode->m_ID == e->m_ID || Enode->m_ID == m->m_ID || Enode->m_ID == b->m_ID)
				{
					cout << "Ա�������ͬ�����������룡" << endl;
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
			cout << "��ӳɹ���" << endl;
		}
		break;
	case 2: //����
		while (_getch() != 27)
		{
			Mnode = (Manager*)malloc(sizeof(Manager));
			e = Ehead;
			m = Mhead;
			b = Bhead;
			cout << "��������Ա��������" << endl;
			cin >> Mnode->m_Name;
			cout << "----------" << endl
				<< "��������Ա����ţ�" << endl;
			cin >> Mnode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//��ֹid��ͬ 
			{
				if (Mnode->m_ID == e->m_ID || Mnode->m_ID == m->m_ID || Mnode->m_ID == b->m_ID)
				{
					cout << "Ա�������ͬ�����������룡" << endl;
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
			cout << "��ӳɹ���" << endl;
		}
		break;
	case 3:  //�ϰ�
		
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
			cout << "��������Ա��������" << endl;
			cin >> Bnode->m_Name;
			cout << "----------" << endl
				<< "��������Ա����ţ�" << endl;
			cin >> Bnode->m_ID;
			cout << "----------" << endl;
			while (e->next != NULL || m->next != NULL || b->next != NULL)				//��ֹid��ͬ 
			{
				if (Bnode->m_ID == e->m_ID || Bnode->m_ID == m->m_ID || Bnode->m_ID == b->m_ID)
				{
					cout << "Ա�������ͬ�����������룡" << endl;
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
			cout << "��ӳɹ���" << endl;
		}
		break;
	default:
		break;
	}
	
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	int wm_sh;
	string buf;
	worker a;
	cout << "��ѡ��Ҫ��ʾ��Ա��ְλ��" << endl;
	cout << "1����ְͨ��" << endl;
	cout << "2������" << endl;
	cout << "3���ϰ�" << endl;
	cin >> wm_sh;
	cout<< "ְ����ţ� " << " \tְ�������� "
		<< " \t��λ�� " <<a.getDeptName(wm_sh)
		<< " \t��λְ��" << a.getwork(wm_sh) << endl;
	switch (wm_sh)
	{
	case 1:
		if (Ehead == NULL || Ehead->next == NULL) {
			cout << "����Ϊ�ձ�" << endl;
		}
		else {
			Employee* e = Ehead;                 //��ָ��ָ��ͷ���

			while (e->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����m��������
			{
				e = e->next;               //mָ��m����һ����ַ
				cout << e->m_ID << "\t" << e->m_Name << endl;
			}
		}
		break;
	case 2:
		if (Mhead == NULL || Mhead->next == NULL) {
			cout << "����Ϊ�ձ�" << endl;
		}
		else {
			Manager* m = Mhead;                 //��ָ��ָ��ͷ���

			while (m->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����m��������
			{
				m = m->next;               //mָ��m����һ����ַ
				cout << m->m_ID << "\t" << m->m_Name << endl;
			}
		}
		break;
	case 3:
		if (Bhead == NULL || Bhead->next == NULL) {
			cout << "����Ϊ�ձ�" << endl;
		}
		else {
			Boss* b = Bhead;                 //��ָ��ָ��ͷ���

			while (b->next != NULL)        //��ָ�����һ����ַ��Ϊ��ʱ��ѭ�����b��������
			{
				b = b->next;               //bָ��b����һ����ַ
				cout << b->m_ID << "\t" << b->m_Name << endl;
			}
		}
		break;
	}
}

//����Ա��
Boss* WorkerManager::Find(int id)
{
	Boss* b = Bhead;
	if (b == NULL) {
		cout << "δ�ҵ��ϰ��ļ���" << endl;
		return ERROR;
	}
	else {
		while (b->next != NULL)
		{
			if (b->m_ID == id) {
				cout << "��Ա��IDΪ��" << b->m_ID << "\t����Ϊ��" << b->m_Name << endl;
				return b;
			}
			b = b->next;
		}
		return NULL;
	}
}

//ɾ��Ա��
void WorkerManager::DeleteWorker(int id)
{
	Boss* Btemp = Find(id);
	char Delete;
	while (true)
	{
		cout << "�Ƿ�ɾ����(Y/N)" << endl;
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
		cout << "δ�ҵ���Ա����" << endl;
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
		cout << "ɾ���ɹ���" << endl;
	}
	
}

//�޸�ְ��
void WorkerManager::Mod_Emp(int id) 
{
	Employee* e = Ehead;
	Manager* m = Mhead;
	Boss* b = Bhead;
	int choice = 0;
	cout << "��ѡ���ְ���ĸ�λ��" << endl;
	cout << "1����ְͨ��" << endl;
	cout << "2������" << endl;
	cout << "3���ϰ�" << endl;
	cin >> choice;
	cout << "�������ְ����ID��" << endl;
	cin >> id;
	switch (choice)
	{
	case 1:
		while (e->next != NULL)
		{
			if (e == NULL && e->next == NULL)
			{
				cout << "δ�ҵ���ְ�����ϣ�" << endl;
				break;
			}
			if (e->m_ID == id)
			{
				cout << "��Ա��IDΪ��" << e->m_ID << "\t����Ϊ��" << e->m_Name << endl;
				cout << "�������Ա����ID��" << endl;
				cin >> e->m_ID;
				cout << "�������Ա�������֣�" << endl;
				cin >> e->m_Name;
				cout << "�޸ĳɹ���" << endl;
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
				cout << "δ�ҵ���ְ�����ϣ�" << endl;
				break;
			}
			if (m->m_ID == id)
			{
				cout << "��Ա��IDΪ��" << m->m_ID << "\t����Ϊ��" << m->m_Name << endl;
				cout << "�������Ա����ID��" << endl;
				cin >> m->m_ID;
				cout << "�������Ա�������֣�" << endl;
				cin >> m->m_Name;
				cout << "�޸ĳɹ���" << endl;
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
				cout << "δ�ҵ���ְ�����ϣ�" << endl;
				break;
			}
			if (b->m_ID == id)
			{
				cout << "��Ա��IDΪ��" << b->m_ID << "\t����Ϊ��" << b->m_Name << endl;
				cout << "�������Ա����ID��" << endl;
				cin >> b->m_ID;
				cout << "�������Ա�������֣�" << endl;
				cin >> b->m_Name;
				cout << "�޸ĳɹ���" << endl;
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

//����ְ��
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

//�������
void WorkerManager::DeleteAll()
{
	char DA_choice = 0;
	cout << "�Ƿ���գ�(Y/N)" << endl;
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
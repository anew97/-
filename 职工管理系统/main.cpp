#pragma once
#include"head.h"
#include"0.h"



int main()
{
	WorkerManager wm;
	Password pw;
	char choice = 0;
	int id = 0;

	pw.display();
	system("cls");

	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		choice = _getch();		//��ȡ��������

		switch (choice)
		{
		case 27 : //�˳�ϵͳ
			wm.exitSystem();
			break;
		case '1': //���ְ��
			wm.Add_Emp();
			break;
		case '2': //��ʾְ��
			wm.Show_Emp();
			break;
		case '3': //ɾ��ְ��
			cout << "������Ҫ���ҵ�Ա��ID��" << endl;
			cin >> id;
			wm.DeleteWorker(id);
			break;
		case '4': //�޸�ְ��
			cout << "������Ҫ�޸ĵ�Ա��ID��" << endl;
			cin >> id;
			wm.Mod_Emp(id);
			break;
		case '5': //����ְ��
			cout << "������Ҫ���ҵ�Ա��ID��" << endl;
			cin >> id;
			wm.Find(id);
			break;
		case '6': //����ְ��
			wm.Sort_Emp();
			break;
		case '7': //����ļ�
			wm.DeleteAll();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}

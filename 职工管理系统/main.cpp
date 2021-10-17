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
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		choice = _getch();		//获取键盘输入

		switch (choice)
		{
		case 27 : //退出系统
			wm.exitSystem();
			break;
		case '1': //添加职工
			wm.Add_Emp();
			break;
		case '2': //显示职工
			wm.Show_Emp();
			break;
		case '3': //删除职工
			cout << "请输入要查找的员工ID：" << endl;
			cin >> id;
			wm.DeleteWorker(id);
			break;
		case '4': //修改职工
			cout << "请输入要修改的员工ID：" << endl;
			cin >> id;
			wm.Mod_Emp(id);
			break;
		case '5': //查找职工
			cout << "请输入要查找的员工ID：" << endl;
			cin >> id;
			wm.Find(id);
			break;
		case '6': //排序职工
			wm.Sort_Emp();
			break;
		case '7': //清空文件
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

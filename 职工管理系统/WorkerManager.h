#pragma once
#include"head.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
#include"worker.h"


//与用户的沟通菜单界面
//对职工增删改查的操作
//与文件的读写交互



class WorkerManager
{
public:

	WorkerManager();

	//判断链表是否为空
	bool IsEmpty();

	//菜单
	void Show_Menu();

	//增加职工
	void Add_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//查找员工
	Boss* Find(int id);

	//删除员工
	void DeleteWorker(int id);

	//修改职工
	void Mod_Emp(int id);

	//排序职工
	void Sort_Emp();

	//清空数据
	void DeleteAll();

	~WorkerManager();

	//退出系统
	void exitSystem();

private:
	Employee* Ehead;	//员工
	Manager* Mhead;		//经理
	Boss* Bhead;		//老板

};



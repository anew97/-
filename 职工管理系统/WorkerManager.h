#pragma once
#include"head.h"
#include"Boss.h"
#include"Manager.h"
#include"Employee.h"
#include"worker.h"


//���û��Ĺ�ͨ�˵�����
//��ְ����ɾ�Ĳ�Ĳ���
//���ļ��Ķ�д����



class WorkerManager
{
public:

	WorkerManager();

	//�ж������Ƿ�Ϊ��
	bool IsEmpty();

	//�˵�
	void Show_Menu();

	//����ְ��
	void Add_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����Ա��
	Boss* Find(int id);

	//ɾ��Ա��
	void DeleteWorker(int id);

	//�޸�ְ��
	void Mod_Emp(int id);

	//����ְ��
	void Sort_Emp();

	//�������
	void DeleteAll();

	~WorkerManager();

	//�˳�ϵͳ
	void exitSystem();

private:
	Employee* Ehead;	//Ա��
	Manager* Mhead;		//����
	Boss* Bhead;		//�ϰ�

};



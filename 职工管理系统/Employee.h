#pragma once
#include"head.h"
#include "worker.h"
class Employee :public worker
{
public:
	
	Employee* next = NULL;

	//��ʾ������Ϣ
	 void showInfo();

	//��ȡְ����λ����
	 string getDeptName();

};


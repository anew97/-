#pragma once
#include"head.h"
#include "worker.h"


class Manager :public worker
{
public:
	
	Manager* next = NULL;

	//��ʾ������Ϣ
	void showInfo();

	//��ȡְ����λ����
	string getDeptName();

};


#pragma once
#include"head.h"
#include"worker.h"
class Boss : public worker
{
public:
	
	Boss* next = NULL;

//��ʾ������Ϣ
   void showInfo();

//��ȡְ����λ����
   string getDeptName();

};


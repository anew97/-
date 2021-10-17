#pragma once
#include"head.h"
#include "worker.h"
class Employee :public worker
{
public:
	
	Employee* next = NULL;

	//显示个人信息
	 void showInfo();

	//获取职工岗位名称
	 string getDeptName();

};


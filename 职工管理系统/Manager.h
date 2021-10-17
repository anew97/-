#pragma once
#include"head.h"
#include "worker.h"


class Manager :public worker
{
public:
	
	Manager* next = NULL;

	//显示个人信息
	void showInfo();

	//获取职工岗位名称
	string getDeptName();

};


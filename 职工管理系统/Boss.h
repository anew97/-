#pragma once
#include"head.h"
#include"worker.h"
class Boss : public worker
{
public:
	
	Boss* next = NULL;

//显示个人信息
   void showInfo();

//获取职工岗位名称
   string getDeptName();

};


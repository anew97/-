#pragma once
#include"head.h"

//员工抽象基类
class worker
{
public:

	//显示个人信息
	//virtual void showInfo () = 0 ;

	//获取岗位名称
	string getDeptName(int m_DeptID)
	{
		switch (m_DeptID)
		{
		case 1:
			return string("员工");
			break;
		case 2:
			return string("经理");
			break;
		case 3:
			return string("总裁");
			break;
		}
	}

	string getwork(int m_DeptID)
	{
		switch (m_DeptID)
		{
		case 1:
			return string("完成经理交给的任务");
			break;
		case 2:
			return string("完成老板交给的任务,并下发任务给员工");
			break;
		case 3:
			return string("管理公司所有事务");
			break;
		}
	}

public:
	int m_ID;   //员工编号
	char m_Name [20];   //员工姓名
	int m_DeptID;   //员工所在部门名称编号
};
#include "Employee.h"

void Employee ::showInfo()
{
	ofstream ofs;
	ofs.open("Employee.txt", ios::app);   //保存为txt文件

	ofs << "职工编号： " << this->m_ID
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成经理交给的任务" << endl;

	ofs.close();
}

string Employee::getDeptName()
{
	return string("员工");
}
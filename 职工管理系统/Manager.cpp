#include "Manager.h"


void Manager::showInfo()
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::app);   //保存为txt文件

	ofs << "职工编号： " << this->m_ID
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;

	ofs.close();
}

string Manager::getDeptName()
{
	return string("经理");
}

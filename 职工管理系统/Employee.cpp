#include "Employee.h"

void Employee ::showInfo()
{
	ofstream ofs;
	ofs.open("Employee.txt", ios::app);   //����Ϊtxt�ļ�

	ofs << "ְ����ţ� " << this->m_ID
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;

	ofs.close();
}

string Employee::getDeptName()
{
	return string("Ա��");
}
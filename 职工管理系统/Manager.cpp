#include "Manager.h"


void Manager::showInfo()
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::app);   //����Ϊtxt�ļ�

	ofs << "ְ����ţ� " << this->m_ID
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;

	ofs.close();
}

string Manager::getDeptName()
{
	return string("����");
}

#pragma once
#include"head.h"

//Ա���������
class worker
{
public:

	//��ʾ������Ϣ
	//virtual void showInfo () = 0 ;

	//��ȡ��λ����
	string getDeptName(int m_DeptID)
	{
		switch (m_DeptID)
		{
		case 1:
			return string("Ա��");
			break;
		case 2:
			return string("����");
			break;
		case 3:
			return string("�ܲ�");
			break;
		}
	}

	string getwork(int m_DeptID)
	{
		switch (m_DeptID)
		{
		case 1:
			return string("��ɾ�����������");
			break;
		case 2:
			return string("����ϰ彻��������,���·������Ա��");
			break;
		case 3:
			return string("����˾��������");
			break;
		}
	}

public:
	int m_ID;   //Ա�����
	char m_Name [20];   //Ա������
	int m_DeptID;   //Ա�����ڲ������Ʊ��
};
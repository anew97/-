#pragma once
#include"head.h"


class Password
{
	
public:

	//������
	void display();

	//��֤����
	void Confirm_Password();
	
	//������
	void Change_password();

	//����
	void encryption(char* str);

	//��ȡ�ļ�
	void read_file();
	
	//д���ļ�
	void write_file();

	Password();

	~Password();

	char pd[15];
	
private:
	char password1[15];
	char password0[15] = "000000";
	//{ '0','0','0','0','0','0' };
	char password3[15];
	
};


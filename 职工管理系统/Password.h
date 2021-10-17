#pragma once
#include"head.h"


class Password
{
	
public:

	//主界面
	void display();

	//验证密码
	void Confirm_Password();
	
	//改密码
	void Change_password();

	//加密
	void encryption(char* str);

	//读取文件
	void read_file();
	
	//写入文件
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


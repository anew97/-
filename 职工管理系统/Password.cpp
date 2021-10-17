#include "Password.h"

Password::Password()
{
	read_file();
}

Password::~Password()
{
	write_file();
}

//主界面
void Password::display()
{
	this->read_file();
	system("cls");
	int choice = 0;

	cout << "\t\t************************************************" << endl;
	cout << "\t\t\t\t  [ 1 ] 进入系统" << endl;
	cout << "\t\t\t\t  [ 2 ] 修改密码" << endl;
	cout << "\t\t\t\t  [Esc] 退出系统" << endl;
	cout << "\t\t************************************************" << endl;
	choice = _getch();
	switch (choice)
	{
	case '1':
		this->Confirm_Password();
		break;
	case '2':
		this->Change_password();
		break;
	case 27:
		this->~Password();
		exit(0);
		break;
	default:
		system("cls");
		display();
		break;
	}
}

//读取文件
void Password::read_file()
{
	fstream Passwordfile;   //输入数据
	Passwordfile.open("password.txt", ios::in);
	int len;
	if (Passwordfile.is_open())
	{
		Passwordfile >> password1;
		len = strlen(password1);
		if (len < 6 || len>15)
		{
			cout << "文件出错！" << endl;
			for (int i = 0; i < 15; i++)
			{
				strcpy_s(password1, password0);
				//password1[i] = password0[i];
			}
		}
	}
	Passwordfile.close();
}


//写入文件
void Password::write_file()
{
	ofstream Passwordfile;
	Passwordfile.open("password.txt", ios::out);
	Passwordfile << this->password1;
	Passwordfile.close();
}

//验证密码
void Password::Confirm_Password()
{
	char ch;
	char str[15];
	int i = 0;
	cout << "请输入密码验证：";
	ch = _getch();
	while (1)
	{
		if (ch == '\r' && i > 5)break;
		else if (ch == '\r')ch = _getch();
		else if (i > 14)break;
		else
		{
			cout << "*";
			str[i] = ch;
			ch = _getch();
			
			i++;
		}
	}
	str[i] = 0;
	cout << endl;

	if (strcmp(str, password1) == 0)
	{
		cout << "验证成功!" << endl;
		
	}
	else
	{
		cout << "验证不成功!按Enter继续,任意键返回..." << endl;
		ch = _getch();
		if (ch == '\r')Confirm_Password();
		else {
			this->display();
		}
	}
}


//修改密码
void Password::Change_password() 
{
	system("cls");
	this->Confirm_Password();
	char ch;
	int i = 0;
	char str[15];   //确认密码存放处
	cout << "请输入新建密码,按Enter结束(大于等于6位数): ";
	ch = _getch();
	while (i < 100)
	{
		if (ch == 13 && i > 5)break;
		else if (ch == 13)ch = _getch();
		else
		{
			cout << "*";
			this->password1[i++] = ch;
			ch = _getch();
		}
	}
	password1[i] = '\0';        //结束标志
	i = 0;
	cout << endl << "请输入确认密码,按Enter结束(大于等于6位数): ";        //第二次输入密码
	ch = _getch();
	while (i < 100)
	{
		if (ch == '\r' && i > 5)break;
		else if (ch == '\r')ch = _getch();
		else
		{
			cout << "*";
			str[i++] = ch;
			ch = _getch();
		}
	}
	str[i] = '\0';     //结束标志
	if (strcmp(password1, str) == 0)
	{
		
		write_file();
		cout << endl << "修改密码成功!,任意键返回..." << endl;
		this->write_file();
		ch = _getch();
		display();
	}
	else
	{
		cout << "两次输入密码不一样,创建失败! 继续创建密码按Enter,任意键返回..." << endl;
		ch = _getch();
		if (ch == '\r')Change_password();
		else display();
	}
}



void Password::encryption(char* str)
{

}

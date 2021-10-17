#include "Password.h"

Password::Password()
{
	read_file();
}

Password::~Password()
{
	write_file();
}

//������
void Password::display()
{
	this->read_file();
	system("cls");
	int choice = 0;

	cout << "\t\t************************************************" << endl;
	cout << "\t\t\t\t  [ 1 ] ����ϵͳ" << endl;
	cout << "\t\t\t\t  [ 2 ] �޸�����" << endl;
	cout << "\t\t\t\t  [Esc] �˳�ϵͳ" << endl;
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

//��ȡ�ļ�
void Password::read_file()
{
	fstream Passwordfile;   //��������
	Passwordfile.open("password.txt", ios::in);
	int len;
	if (Passwordfile.is_open())
	{
		Passwordfile >> password1;
		len = strlen(password1);
		if (len < 6 || len>15)
		{
			cout << "�ļ�����" << endl;
			for (int i = 0; i < 15; i++)
			{
				strcpy_s(password1, password0);
				//password1[i] = password0[i];
			}
		}
	}
	Passwordfile.close();
}


//д���ļ�
void Password::write_file()
{
	ofstream Passwordfile;
	Passwordfile.open("password.txt", ios::out);
	Passwordfile << this->password1;
	Passwordfile.close();
}

//��֤����
void Password::Confirm_Password()
{
	char ch;
	char str[15];
	int i = 0;
	cout << "������������֤��";
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
		cout << "��֤�ɹ�!" << endl;
		
	}
	else
	{
		cout << "��֤���ɹ�!��Enter����,���������..." << endl;
		ch = _getch();
		if (ch == '\r')Confirm_Password();
		else {
			this->display();
		}
	}
}


//�޸�����
void Password::Change_password() 
{
	system("cls");
	this->Confirm_Password();
	char ch;
	int i = 0;
	char str[15];   //ȷ�������Ŵ�
	cout << "�������½�����,��Enter����(���ڵ���6λ��): ";
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
	password1[i] = '\0';        //������־
	i = 0;
	cout << endl << "������ȷ������,��Enter����(���ڵ���6λ��): ";        //�ڶ�����������
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
	str[i] = '\0';     //������־
	if (strcmp(password1, str) == 0)
	{
		
		write_file();
		cout << endl << "�޸�����ɹ�!,���������..." << endl;
		this->write_file();
		ch = _getch();
		display();
	}
	else
	{
		cout << "�����������벻һ��,����ʧ��! �����������밴Enter,���������..." << endl;
		ch = _getch();
		if (ch == '\r')Change_password();
		else display();
	}
}



void Password::encryption(char* str)
{

}

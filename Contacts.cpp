#include <iostream>

using namespace std;

#define MAX 1000
/*

*/
//�˵���ʾ
void showMenu() {
	cout << "         ͨѶ¼�˵�        " << endl;
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****"  <<endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
//��ϵ�˽ṹ��
struct person {
	string name;
	int sex;
	int age;
	string phoneNumber;
	string address;
};

//ͨѶ¼�ṹ��
struct contacts {
	person personArray[MAX];
	int size;//��¼ͨѶ¼�е�����
};

//�����ϵ��
void addPerson(contacts* c1)
{
	if (c1->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		//����
		string name;
		cout << "����������:" << endl;
		cin >> name;
		c1->personArray[c1->size].name= name;

		//�Ա�
		int sex;
		cout << "�������Ա�:" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2);
			{
				c1->personArray[c1->size].sex = sex;
				break;
			}
			cout << "�������������������Ա�";
		}

		//����
		cout << "���������䣺";
		int age = 0;
		cin >> age;
		c1->personArray[c1->size].age = age;
		
		//�绰
		cout << "��������룺";
		string phoneNumber;
		cin >> phoneNumber;
		c1->personArray[c1->size].phoneNumber = phoneNumber;

		//��ַ
		cout << "�������ַ��";
			string address;
			cin >> address;
			c1->personArray[c1->size].address = address;
	}
	
	cout << "��ӳɹ���" << endl;
	c1->size++;
	system("pause");
	system("cls");
}

//��ʾ��ϵ��
void showContacts(contacts* c1)
{
	cout << "����\t" << "�Ա�\t" << "����\t" << "�绰��\t" << "סַ" << endl;
	if (c1->size == 0)
	{
		cout << "��ǰͨѶ¼û����ϵ�ˣ�����ӣ�"<<endl;
	}
	else
	{
		for (int i = 0; i < c1->size; i++)
		{
			cout << c1->personArray[i].name << "\t" <<
				(c1->personArray[i].sex==1? "��" : "Ů") << "\t" <<
				c1->personArray[i].age << "\t" <<
				c1->personArray[i].phoneNumber << "\t\t\t" <<
				c1->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExist(contacts* c1, string name) {
	for (int i = 0; i < c1->size; i++)
	{
		if (c1->personArray[i].name ==name)
		{
			return i;//�ҵ��ˣ����ظ���ϵ�˵��±�
		}
	}
	return -1;//�����궼û���ҵ�
}

//ɾ����ϵ��
void deletPerson(contacts* c1)
{
	cout << "������Ҫɾ����ϵ�˵�������";
	string name;
	cin >> name;
	int ret = isExist(c1, name);
	if (ret == -1)
	{
		cout << "���޴���!" << endl;
	}
	else
	{
		cout << "�ҵ����ˣ�" << endl;

		for (int i = ret; i < c1->size; i++)
		{
			c1->personArray[i] = c1->personArray[i + 1];
		}
		c1->size--;
	}
}

//������ϵ��
void searchPerson(contacts* c1)
{
	cout << "��������Ҫ���ҵ���ϵ�����֣�";
	string name;
	cin >> name;
	int ret=isExist(c1, name);
	if (ret != -1)
	{
		cout << c1->personArray[ret].name << "\t"
			<< (c1->personArray[ret].sex == 1 ? "��" : "Ů") << "\t"
			<< c1->personArray[ret].age << "\t"
			<< c1->personArray[ret].phoneNumber << "\t"
			<< c1->personArray[ret].address << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(contacts* c1)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;
	int ret = isExist(c1,name);
	if (ret == -1)
	{
		cout << "ĿǰͨѶ¼û�д��ˣ�" << endl;
	}
	else
	{
		cout << "���޸ģ���Ҫ��������������0" << endl;
		cout << "��ǰ����:" << c1->personArray[ret].name << endl;
		string name;
		cout << "���������֣���������0��:";
		cin >> name;
		if (name != "0")
		{
			c1->personArray[ret].name = name;
		}

		
		cout << "��ǰ�Ա�:" << c1->personArray[ret].sex << endl;
		int sex=0;
		cout << "�������Ա���������0��:";
		cin >> sex;
		if (sex != 0)
		{
			c1->personArray[ret].sex = sex;
		}

		
		cout << "��ǰ����:" << c1->personArray[ret].age << endl;
		int age=0;
		cout << "���������䣨��������0��:";
		cin >> age;
		if (age != 0)
		{
			c1->personArray[ret].age = age;
		}

		
		cout << "��ǰ����:" << c1->personArray[ret].phoneNumber << endl;
		string phoneNumber;
		cout << "��������루��������0��:";
		cin >> phoneNumber;
		if (phoneNumber != "0")
		{
			c1->personArray[ret].phoneNumber = phoneNumber;
		}

		
		cout << "��ǰ��ַ:" << c1->personArray[ret].address << endl;
		string address;
		cout << "�������ַ����������0��:";
		cin >> address;
		if (address != "0")
		{
			c1->personArray[ret].address = address;
		}

		cout << "�޸ĳɹ���";
	}
	system("pause");
	system("cls");
}

//���ͨѶ¼
void cleanContacts(contacts* c)
{
	if (c->size == 0) {
		cout << "��ǰͨѶ¼û����ϵ�ˣ�����Ҫ��գ�" << endl;
	}
	else {
		c->size = 0;
		cout << "�����ͨѶ¼��" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	contacts c1;//ͨѶ¼c1
	c1.size = 0;//��ʼ������

	int select = 0;//�û����빦��ѡ��


	while(true)
	{
		showMenu();
		cout << "��ѡ������Ҫʹ�õĹ���:";
		cin >> select;
		switch (select) {
		case 1:     //�����ϵ��
			addPerson(&c1);
			break;
		case 2:     //��ʾ��ϵ�� 
			showContacts(&c1);
			break;
		case 3:     //ɾ����ϵ��
			deletPerson(&c1);
			break;
		case 4:     //������ϵ��
			searchPerson(&c1);
			break;
		case 5:     //�޸���ϵ��
			modifyPerson(&c1);
			break;
		case 6:     //�����ϵ��
		{
			cout << "��ȷ��Ҫ���ͨѶ¼��Y/N��";
			string clean_choose;
			cin >> clean_choose;
			if (clean_choose == "Y")
			{
				cleanContacts(&c1);
			}
		}
			break;
		case 0://�˳�ͨѶ¼
			cout << "�ټ�����ӭ�´�ʹ�ã�";
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	

	system("pause");

	return 0;
}
#include <iostream>

using namespace std;

#define MAX 1000
/*

*/
//菜单显示
void showMenu() {
	cout << "         通讯录菜单        " << endl;
	cout << "***************************" << endl;
	cout << "*****  1：添加联系人  *****"  <<endl;
	cout << "*****  2：显示联系人  *****" << endl;
	cout << "*****  3：删除联系人  *****" << endl;
	cout << "*****  4：查找联系人  *****" << endl;
	cout << "*****  5：修改联系人  *****" << endl;
	cout << "*****  6：清空联系人  *****" << endl;
	cout << "*****  0：退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//联系人结构体
struct person {
	string name;
	int sex;
	int age;
	string phoneNumber;
	string address;
};

//通讯录结构体
struct contacts {
	person personArray[MAX];
	int size;//记录通讯录中的人数
};

//添加联系人
void addPerson(contacts* c1)
{
	if (c1->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		c1->personArray[c1->size].name= name;

		//性别
		int sex;
		cout << "请输入性别:" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2);
			{
				c1->personArray[c1->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入性别：";
		}

		//年龄
		cout << "请输入年龄：";
		int age = 0;
		cin >> age;
		c1->personArray[c1->size].age = age;
		
		//电话
		cout << "请输入号码：";
		string phoneNumber;
		cin >> phoneNumber;
		c1->personArray[c1->size].phoneNumber = phoneNumber;

		//地址
		cout << "请输入地址：";
			string address;
			cin >> address;
			c1->personArray[c1->size].address = address;
	}
	
	cout << "添加成功！" << endl;
	c1->size++;
	system("pause");
	system("cls");
}

//显示联系人
void showContacts(contacts* c1)
{
	cout << "姓名\t" << "性别\t" << "年龄\t" << "电话：\t" << "住址" << endl;
	if (c1->size == 0)
	{
		cout << "当前通讯录没有联系人，请添加！"<<endl;
	}
	else
	{
		for (int i = 0; i < c1->size; i++)
		{
			cout << c1->personArray[i].name << "\t" <<
				(c1->personArray[i].sex==1? "男" : "女") << "\t" <<
				c1->personArray[i].age << "\t" <<
				c1->personArray[i].phoneNumber << "\t\t\t" <<
				c1->personArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int isExist(contacts* c1, string name) {
	for (int i = 0; i < c1->size; i++)
	{
		if (c1->personArray[i].name ==name)
		{
			return i;//找到了，返回该联系人的下标
		}
	}
	return -1;//遍历完都没有找到
}

//删除联系人
void deletPerson(contacts* c1)
{
	cout << "请输入要删除联系人的姓名：";
	string name;
	cin >> name;
	int ret = isExist(c1, name);
	if (ret == -1)
	{
		cout << "查无此人!" << endl;
	}
	else
	{
		cout << "找到此人！" << endl;

		for (int i = ret; i < c1->size; i++)
		{
			c1->personArray[i] = c1->personArray[i + 1];
		}
		c1->size--;
	}
}

//查找联系人
void searchPerson(contacts* c1)
{
	cout << "请输入您要查找的联系人名字：";
	string name;
	cin >> name;
	int ret=isExist(c1, name);
	if (ret != -1)
	{
		cout << c1->personArray[ret].name << "\t"
			<< (c1->personArray[ret].sex == 1 ? "男" : "女") << "\t"
			<< c1->personArray[ret].age << "\t"
			<< c1->personArray[ret].phoneNumber << "\t"
			<< c1->personArray[ret].address << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(contacts* c1)
{
	cout << "请输入你要修改的联系人姓名：";
	string name;
	cin >> name;
	int ret = isExist(c1,name);
	if (ret == -1)
	{
		cout << "目前通讯录没有此人！" << endl;
	}
	else
	{
		cout << "请修改，需要跳过的项请输入0" << endl;
		cout << "当前姓名:" << c1->personArray[ret].name << endl;
		string name;
		cout << "请输入名字（跳过输入0）:";
		cin >> name;
		if (name != "0")
		{
			c1->personArray[ret].name = name;
		}

		
		cout << "当前性别:" << c1->personArray[ret].sex << endl;
		int sex=0;
		cout << "请输入性别（跳过输入0）:";
		cin >> sex;
		if (sex != 0)
		{
			c1->personArray[ret].sex = sex;
		}

		
		cout << "当前年龄:" << c1->personArray[ret].age << endl;
		int age=0;
		cout << "请输入年龄（跳过输入0）:";
		cin >> age;
		if (age != 0)
		{
			c1->personArray[ret].age = age;
		}

		
		cout << "当前号码:" << c1->personArray[ret].phoneNumber << endl;
		string phoneNumber;
		cout << "请输入号码（跳过输入0）:";
		cin >> phoneNumber;
		if (phoneNumber != "0")
		{
			c1->personArray[ret].phoneNumber = phoneNumber;
		}

		
		cout << "当前地址:" << c1->personArray[ret].address << endl;
		string address;
		cout << "请输入地址（跳过输入0）:";
		cin >> address;
		if (address != "0")
		{
			c1->personArray[ret].address = address;
		}

		cout << "修改成功！";
	}
	system("pause");
	system("cls");
}

//清空通讯录
void cleanContacts(contacts* c)
{
	if (c->size == 0) {
		cout << "当前通讯录没有联系人，不需要清空！" << endl;
	}
	else {
		c->size = 0;
		cout << "已清空通讯录！" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	contacts c1;//通讯录c1
	c1.size = 0;//初始化人数

	int select = 0;//用户输入功能选项


	while(true)
	{
		showMenu();
		cout << "请选择您需要使用的功能:";
		cin >> select;
		switch (select) {
		case 1:     //添加联系人
			addPerson(&c1);
			break;
		case 2:     //显示联系人 
			showContacts(&c1);
			break;
		case 3:     //删除联系人
			deletPerson(&c1);
			break;
		case 4:     //查找联系人
			searchPerson(&c1);
			break;
		case 5:     //修改联系人
			modifyPerson(&c1);
			break;
		case 6:     //清空联系人
		{
			cout << "您确定要清空通讯录吗？Y/N：";
			string clean_choose;
			cin >> clean_choose;
			if (clean_choose == "Y")
			{
				cleanContacts(&c1);
			}
		}
			break;
		case 0://退出通讯录
			cout << "再见，欢迎下次使用！";
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
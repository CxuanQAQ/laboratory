#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Equipments
{
	public:
	void Add_Equ_Message();//添加设备
	void Equ_read();//读取设备信息
	void Del_Equ_Message();//删除设备
	void Mod_Equ_Message();//修改设备
	void Add_Stu_Message();//添加学生
	void Stu_Read();//读取学生信息
	void Del_Stu_Message();//删除学生
	void Mod_Stu_Message();//修改学生
	void Exit1();//退出
	void Display_Equ();//显示设备信息
	void Display_Stu();//显示学生信息
	void Use_Equ();//设备使用情况
	void Search_Equ();//查找设备
	void Borrow();//借出设备
	void menu1();//管理员	
	void regi();//主页面
	void xuesheng();//学生登录
	void menu2();//学生页面
	void guanli();//管理员登录
};
struct student
{
	int n;//学号 
	char name[20];//姓名 
	char major[20];//专业 
}stu[50];

struct equipment
{
	int en;//设备编号
	char rname[20];//实验室名称 
	char ename[20];//设备名称
	int nums;//可用设备量
	int Break;//维修设备量
	int bnum;//借走的数量
	char oldname[20];
}equ[50]; 

	void Equipments::Add_Equ_Message()//增加设备
	{
		FILE* fp;
		int i,n;
		if ((fp = fopen("D:\\kcsj\\equipment", "wb+")) == NULL)//如果文件为空 
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		cout<<"请输入需要录入实验室设备的种类:";
		cin>>n;
		for (i = 0; i < n; i++)
		{
			cout<<"请输入设备编号:";
			cin>>equ[i].en;
			cout<<"请输入实验室名称:";
			cin>>equ[i].rname;
			cout<<"请输入设备名称:";
			cin>>equ[i].ename;
			cout<<"请输入可用设备量:";
			cin>>equ[i].nums;
			cout<<"请输入维修设备量:";
			cin>>equ[i].Break;
			equ[i].bnum=0;
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)//写入文档 
			{
				cout<<"录入失败！"<<endl;
			}
			else cout<<"数据录入成功！"<<endl;
		}
		fclose(fp);
	}
	
	void Equipments::Equ_read()//从文件中读取 
	{
		FILE* fp;
		int i;
		if ((fp = fopen("D:\\kcsj\\equipment", "rb+")) == NULL)
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 10; i < 50; i++)
		{
			fread(&equ[i], sizeof(struct equipment), 1, fp);//读文件 
		}
		fclose(fp);
	}
	void Equipments::Del_Equ_Message()//删除设备
	{
		FILE* fp;
		int i, j; 
		if ((fp = fopen("D:\\kcsj\\equipment", "wb+")) == NULL)//打开文件 
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 0; i < 50; i++)
		{
			fread(&equ[i], sizeof(struct equipment), 1, fp);//读文件 
		}
		cout<<"请输入需要删除设备的编号:";
		cin>>j;//输入编号 
		for (i = 0; equ[i].en != 0; i++)
		{
			if (equ[i].en == j)//找到 
			{
				for (int d = i; equ[d].en != 0; d++)
				{
					equ[d] = equ[d + 1];//循环覆盖 
				}
				cout<<"删除成功！"<<endl;
				break;
			}
			else if (equ[i + 1].en == 0)//未找到 
			{
				cout<<"查无此设备，请检查！"<<endl;
				for (i = 0; equ[i].en != 0; i++)
				{
					fwrite(&equ[i], sizeof(struct equipment), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//查找下一个 
			{
				continue;
			}

		}
		for (i = 0; equ[i].en != 0; i++)//保存修改的数据 
		{
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)//写文件 
			{
				cout<<"file write error"<<endl;
			}
		}
		fclose(fp);//关闭文件 
	}
	void Equipments::Mod_Equ_Message()//按姓名查找
	{
		char name1[10];
		FILE* fp;
		int i;	
		if ((fp = fopen("D:\\kcsj\\equipment", "wb+")) == NULL)
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 0; i < 50; i++)
		{
			fread(&equ[i], sizeof(struct equipment), 1, fp);
		}
		cout<<"请输入需要修改设备的名称:";
		cin>>name1;//输入设备名称 
		for (i = 0; i < 50; i++)
		{
			if (strcmp(equ[i].ename, name1) == 0)//找到 
			{
			cout<<"选择修改项目"<<endl;
			cout<<"1.设备编号   2.实验室名称   3.设备名称    4.可用存量   5.设备维修量---";
			int choice;
			cin>>choice;
			switch (choice) 
			{
				case 1:
					cout<<"请输入新设备编号:";
								cin>>equ[i].en;
				//	cout<<"修改完成"<<endl;
					break;
				case 2:
					cout<<"请输入新实验室名称:";
								cin>>equ[i].rname;
							//	cout<<"修改完成"<<endl;
					break;
				case 3:
						cout<<"请输入新设备名称:";
								cin>>equ[i].ename;
							//	cout<<"修改完成"<<endl;
					break;
				case 4:
						cout<<"请输入新可用设备存量:";
								cin>>equ[i].nums;
							//	cout<<"修改完成"<<endl;
					break;
				case 5:
						cout<<"请输入新设备维修量:";
								cin>>equ[i].Break;
							//	cout<<"修改完成"<<endl;
					break;
					
			}
			break;
				
			}
			else if (equ[i + 1].en == 0)//未找到
			{
				//cout<<"查无此设备，请检查！"<<endl;
				for (i = 0; equ[i].en != 0; i++)
				{
					fwrite(&equ[i], sizeof(struct equipment), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//查找下一个 
			{
				continue;
			}

		}
		for (i = 0; equ[i].en != 0; i++)//保存修改后的数据 
		{
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
			else if (equ[i + 1].en == 0)
				cout<<"修改成功！"<<endl;
		}
		fclose(fp);

	}

	void Equipments::Add_Stu_Message()//增加学生
	{
		FILE* fp;
		int i,n;
		if ((fp = fopen("D:\\kcsj\\stu", "wb+")) == NULL)//如果文件为空 
		{
			cout<<("cannot open file\n");
			exit(0);
		}
		cout<<"请输入需要录入信息的数目:";
		cin>>n;
		for (i = 0; i < n; i++)
		{
			cout<<"请输入学号:";
			cin>>stu[i].n;
			cout<<"请输入姓名:";
			cin>>stu[i].name;
			cout<<"请输入专业:";
			cin>>stu[i].major;

			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)//写入文件
			{
				cout<<"录入失败！"<<endl;
			}
			else cout<<"数据录入成功！"<<endl;
		}
		fclose(fp);
	}
	void Equipments::Stu_Read()//从文件中读取 
	{
		FILE* fp;
		int i; 
		if ((fp = fopen("D:\\kcsj\\stu", "rb+")) == NULL)//以二进制读取方式打开 
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 0; i <= 50; i++) 
		{
			fread(&stu[i], sizeof(struct student), 1, fp);
		}
		fclose(fp);
	}
	void Equipments::Del_Stu_Message()//删除学生
	{
		FILE* fp;
		int i, j;
		
		if ((fp = fopen("D:\\kcsj\\stu", "wb+")) == NULL)
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 0; i < 50; i++)
		{
			fread(&stu[i], sizeof(struct student), 1, fp);
		}
		cout<<"请输入需要删除学生的学号:";
		cin>>j;
		for (i = 0; stu[i].n != 0; i++)//查找输入信息编号学生的信息 
		{
			if (stu[i].n == j)//找到 
			{
				for (int d = i; stu[d].n != 0; d++)
				{
					stu[d] = stu[d + 1];
				}
				cout<<"删除成功！"<<endl;
			
			}
			
			else if (stu[i + 1].n == 0)//未找到 
			{
				cout<<"查无此人，请检查！"<<endl;
				for (i = 0; stu[i].n != 0; i++)
				{
					fwrite(&stu[i], sizeof(struct student), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//查找下一个 
			{
				continue;
			}

		}
		for (i = 0; stu[i].n != 0; i++)//保存修改的数据 
		{
			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
		}
		fclose(fp);
	}
	void Equipments::Mod_Stu_Message()//修改学生
	{
		char name1[10];
		FILE* fp;
		int i;
		if ((fp = fopen("D:\\kcsj\\stu", "wb+")) == NULL)
		{
			cout<<"cannot open file"<<endl;
			exit(0);

		}
		
		for (i = 0; i < 50; i++)
		{
			fread(&stu[i], sizeof(struct student), 1, fp);
		}
		cout<<"请输入需要修改学生的姓名:"<<endl;
		cin>>name1;
		for (i = 0; i < 50; i++)//查找输入的学生的信息
		{
			if (strcmp(stu[i].name, name1) == 0)//找到 
			{
				cout<<"请选择要修改的项目"<<endl;
				cout<<"1.学号   2.姓名   3.专业---";
				int choice;
				int a;
				char b[20];
				char c[20];
				
				cin>>choice;
				switch (choice) 
				{
					case 1:
							cout<<"请输入新学号:";
							cin>>a;
							stu[i].n=a;				
						break;
					case 2:
							cout<<"请输入新姓名:";
							cin>>b;
							strcpy(stu[i].name,b);
						break;
					case 3:
							cout<<"请输入新专业:";
							cin>>c;		
							strcpy(stu[i].major,c);
						break;
				}
			
			
				break;
			}
			else if (stu[i + 1].n == 0)//未找到
			{
				cout<<"查无此人，请检查！"<<endl;
				for (i = 0; stu[i].n != 0; i++)
				{
					fwrite(&stu[i], sizeof(struct student), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//查找下一个 
			{
				continue;
			}

		}
		for (i = 0; stu[i].n != 0; i++)//保存修改后的数据 
		{
			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
			else if (stu[i + 1].n == 0)
				cout<<"修改成功！"<<endl;
		}
		fclose(fp);

	}

	void Equipments::Exit1()//退出
	{
		system("cls");
		exit(0);
	}
	void Equipments::Display_Equ()//显示实验室设备
	{	
		/*char name0[20];
		cout<<"输入实验室名称：";
		cin>>name0;
		
		int i; 
	
		for(i=0;equ[i].en!=0;i++)
		{
			if (strcmp(equ[i].rname, name0) == 0)
				cout<<"设备编号        实验室名称      设备名称        可用存量        设备维修"<<endl;
			cout<<equ[i].en<<" \t\t"<<equ[i].rname<<" \t\t"<<equ[i].ename<<" \t\t"<<equ[i].nums<<" \t\t"<<equ[i].Break<<endl;
			break;
		}*/
				int i;//循环值 
					cout<<"实验室名称      设备名称        设备编号        可用存量        设备维修"<<endl;
				for(i=0;equ[i].en!=0;i++)
				{
						cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
				}
			 
			 
	 } 
	 void Equipments::Display_Stu()//显示学生信息
	 {
	 	{
	 		int i;
	 		cout<<"学号            姓名            专业"<<endl;
		 		for(i=0;stu[i].n!=0;i++)
		 		{
		 			cout<<stu[i].n<<"\t\t"<<stu[i].name<<"\t\t"<<stu[i].major<<endl;
		 		}
	 	}
	 	
	 }
	 void Equipments::Use_Equ()//查看设备使用情况
	 {
	 	int name,i;
	 	cout<<"请输入您要查看的设备编号:";
	 	cin>>name;
	 	for(i=0;equ[i].en!=0;i++)
		{
			if(name==equ[i].en)
			{
				cout<<"           借出的数量        可用的数量         维修数量"<<endl;
				cout<<" \t\t"<<equ[i].bnum<<" \t\t"<<equ[i].nums<<" \t\t"<<equ[i].Break<<endl;
			}
		}
		
	 }
	 void Equipments::Search_Equ()//查找设备
	 {
	 	cout<<"选择以何种方式查找设备信息（1.设备编号  2.设备名称）:";
	 	int n;
	 	cin>>n;
	 	if(n==1)
	 	{
	 	int i,p;
	 	cout<<"请输入您要查看的设备编号: ";
	 	cin>>p;
	 	for(i=0;equ[i].en!=0;i++)
		{
			if(p==equ[i].en)
			{
				cout<<"实验室名称      设备名称        设备编号        可用存量        设备维修"<<endl;
				cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
			}
		}
	 	}
	 	else if(n==2)	
	 	{
		 	char name[20];
		 	cout<<"请输入您要查看的设备名称：";
		 	cin>>name;
		 	for(int i=0;equ[i].en!=0;i++)
			 {
			 	if(strcmp(equ[i].ename,name)==0)
				 {
				 	cout<<"实验室名称      设备名称        设备编号        可用存量        设备维修"<<endl;
					cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
				 }
			 }
	
		 }
		 
		 else
		 cout<<"无该设备"<<endl;
	 }
	 
	 void Equipments::Borrow()//学生借设备
	 {
	 	
	 	cout<<"请输入您的学号:";
	 	int a;
	 	cin>>a;
	 	for(int b=0;stu[b].n!=0;b++)
	 	{
		 if(stu[b].n==a)
		 {
		 	int i; 
		 		
			 	 	char name[20];//用户输入的名称 
			 	 	cout<<"请输入您要借用的设备名称:";
			 	 	cin>>name;		 	 	
			 	 	
			 	 	for(i=0;equ[i].en!=0;i++)
			 		{
			 			if(strcmp(name,equ[i].oldname)==0)//若和之前借用的名称不相同
			 			{
							cout<<"对不起，同一设备您只能借用一次"<<endl;
					 		break;
			 			}
			 			
			 			else if(strcmp(name,equ[i].ename)==0)
			 			{
			 				equ[i].nums=equ[i].nums-1;
			 				equ[i].bnum=equ[i].bnum+1;
			 				cout<<"借用成功！"<<endl;
			 				strcpy(equ[i].oldname,name);
			 				
			 			}
			 			else
			 		//	cout<<"无该设备信息，请联系管理员"<<endl;
			 		///	break;
			 		continue;
			 		
			 		}
			}		
		 }
	 	
	 }
	void Equipments::menu1()//管理员菜单
	{
		int i;
		cout<<"\t\t☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆"<<endl;
		cout<<"\t\t|            实验室设备管理系统          |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （1）添加学生信息             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （2）删除学生信息             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （3）修改学生信息             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （4）添加实验室设备信息       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （5）删除实验室设备信息       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （6）修改实验室设备信息       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （7）按编号统计设备情使用况   |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （8）查询设备信息             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （9）按实验室显示设备信息     |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （10）查看学生信息            |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          （11）退出管理员系统          |"<<endl;
		cout<<"\t\t☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆"<<endl;
		cout<<"请输入您的选项:";
		cin>>i;
		while (i >= 1 && i <= 11)//功能选择 
		{
			switch (i)
			{
			case 1:
				Add_Stu_Message();
				 break;
			case 2:
				Del_Stu_Message();
				 break;
			case 3:
				Mod_Stu_Message();
				 break;
			case 4:
				Add_Equ_Message();
				 break;
			case 5:
				Del_Equ_Message();
				 break;
			case 6:
				Mod_Equ_Message();
				 break;
			case 7:
				Use_Equ(); 
				 break;
			case 8:
				Search_Equ();
				 break;
			case 9:
				Display_Equ();
				 break;
			case 10:
				Display_Stu();
				 break;
			case 11:
				system("CLS");
				regi(); 
				 break;
			}
			system("pause");
			system("CLS");
			menu1();
			cin>>i;
		}
	}
		void Equipments::regi()//用户管理
		{
			int i;
			cout<<"\t\t________________________________________\n"<<endl;
			cout<<"\t\t|           实验室设备管理系统         |\n"<<endl;
			cout<<"\t\t|          （1）学生登录               |\n"<<endl;
			cout<<"\t\t|          （2）管理员登录             |\n"<<endl;
			cout<<"\t\t|          （3）退出系统               |\n"<<endl;
			cout<<"\t\t|______________________________________|\n"<<endl;
			cout<<"请输入您的选项:";
			cin>>i;
			while (i >= 1 && i <= 3)//功能选择 
			{
				switch (i)
				{
				case 1:system("CLS");xuesheng(); break;
				case 2:system("CLS");guanli(); break;
				case 3:Exit1(); break;
				}
				system("pause");
				system("CLS");//清屏 
				regi();
				cin>>i;
			}		
		}
			void Equipments::xuesheng()//学生登录
			{
				int i,key;
				char user[20];
				cout<<""<<endl;
				cout<<"\t\t请输入姓名：";
				cin>>user;
				cout<<"\t\t请输入学号：";
				cin>>key;
				system("CLS");//清屏 
				for(i=0;stu[i].n!=0;i++){
					if(strcmp(user,stu[i].name) !=0 || (key!=stu[i].n)){
						cout<<"姓名或学号不存在，请联系管理员！\n"<<endl;
					}
					else
					{
						menu2();
					}
				}
			}
			void Equipments::menu2()//学生菜单
						{
						int i;
						cout<<"\t\t☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆\n"<<endl;
						cout<<"\t\t|            实验室设备管理系统            |\n"<<endl;
						cout<<"\t\t|          （1）学生借用设备               |\n"<<endl;
						cout<<"\t\t|          （2）按实验室显示设备信息       |\n"<<endl;
						cout<<"\t\t|          （3）按名称编号查询设备         |\n"<<endl;
						cout<<"\t\t|          （4）退出学生登录               |\n"<<endl;
						cout<<"\t\t☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆══ ☆\n"<<endl;
						cout<<"请输入您的选项:";
						cin>>i;
						while (i >= 1 && i <= 4)//功能选择 
						{
							switch (i)
							{
								case 1:Borrow(); break;
								case 2:Display_Equ(); break;
								case 3:Search_Equ(); break;
								case 4:system("CLS");regi(); break;
							}
							system("pause");
							system("CLS");//清屏 
							menu2();
							cin>>i;
						}
					}
			void Equipments::guanli()//管理
					{
						char user[] = "mxx\0";//管理员用户名
						char key[] = "mxx\0";//管理员密码
						char user2[10],key2[10];
						cout<<"\t\t请输入用户名：";
						cin>>user2;
						cout<<"\t\t请输入密码：";
						cin>>key2;
						system("CLS");//清屏 
						if(strcmp(user,user2) !=0 || strcmp(key,key2) !=0)
						{
							cout<<"用户名或密码错误！\n"<<endl;
							return ;
						}
						else
						{
							menu1();	
						}
					}

int main()
{
	Equipments e;
	e.Stu_Read();
	e.Equ_read(); 
	e.regi();
}

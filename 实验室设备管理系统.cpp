#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Equipments
{
	public:
	void Add_Equ_Message();//����豸
	void Equ_read();//��ȡ�豸��Ϣ
	void Del_Equ_Message();//ɾ���豸
	void Mod_Equ_Message();//�޸��豸
	void Add_Stu_Message();//���ѧ��
	void Stu_Read();//��ȡѧ����Ϣ
	void Del_Stu_Message();//ɾ��ѧ��
	void Mod_Stu_Message();//�޸�ѧ��
	void Exit1();//�˳�
	void Display_Equ();//��ʾ�豸��Ϣ
	void Display_Stu();//��ʾѧ����Ϣ
	void Use_Equ();//�豸ʹ�����
	void Search_Equ();//�����豸
	void Borrow();//����豸
	void menu1();//����Ա	
	void regi();//��ҳ��
	void xuesheng();//ѧ����¼
	void menu2();//ѧ��ҳ��
	void guanli();//����Ա��¼
};
struct student
{
	int n;//ѧ�� 
	char name[20];//���� 
	char major[20];//רҵ 
}stu[50];

struct equipment
{
	int en;//�豸���
	char rname[20];//ʵ�������� 
	char ename[20];//�豸����
	int nums;//�����豸��
	int Break;//ά���豸��
	int bnum;//���ߵ�����
	char oldname[20];
}equ[50]; 

	void Equipments::Add_Equ_Message()//�����豸
	{
		FILE* fp;
		int i,n;
		if ((fp = fopen("D:\\kcsj\\equipment", "wb+")) == NULL)//����ļ�Ϊ�� 
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		cout<<"��������Ҫ¼��ʵ�����豸������:";
		cin>>n;
		for (i = 0; i < n; i++)
		{
			cout<<"�������豸���:";
			cin>>equ[i].en;
			cout<<"������ʵ��������:";
			cin>>equ[i].rname;
			cout<<"�������豸����:";
			cin>>equ[i].ename;
			cout<<"����������豸��:";
			cin>>equ[i].nums;
			cout<<"������ά���豸��:";
			cin>>equ[i].Break;
			equ[i].bnum=0;
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)//д���ĵ� 
			{
				cout<<"¼��ʧ�ܣ�"<<endl;
			}
			else cout<<"����¼��ɹ���"<<endl;
		}
		fclose(fp);
	}
	
	void Equipments::Equ_read()//���ļ��ж�ȡ 
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
			fread(&equ[i], sizeof(struct equipment), 1, fp);//���ļ� 
		}
		fclose(fp);
	}
	void Equipments::Del_Equ_Message()//ɾ���豸
	{
		FILE* fp;
		int i, j; 
		if ((fp = fopen("D:\\kcsj\\equipment", "wb+")) == NULL)//���ļ� 
		{
			cout<<"cannot open file"<<endl;
			exit(0);
		}
		for (i = 0; i < 50; i++)
		{
			fread(&equ[i], sizeof(struct equipment), 1, fp);//���ļ� 
		}
		cout<<"��������Ҫɾ���豸�ı��:";
		cin>>j;//������ 
		for (i = 0; equ[i].en != 0; i++)
		{
			if (equ[i].en == j)//�ҵ� 
			{
				for (int d = i; equ[d].en != 0; d++)
				{
					equ[d] = equ[d + 1];//ѭ������ 
				}
				cout<<"ɾ���ɹ���"<<endl;
				break;
			}
			else if (equ[i + 1].en == 0)//δ�ҵ� 
			{
				cout<<"���޴��豸�����飡"<<endl;
				for (i = 0; equ[i].en != 0; i++)
				{
					fwrite(&equ[i], sizeof(struct equipment), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//������һ�� 
			{
				continue;
			}

		}
		for (i = 0; equ[i].en != 0; i++)//�����޸ĵ����� 
		{
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)//д�ļ� 
			{
				cout<<"file write error"<<endl;
			}
		}
		fclose(fp);//�ر��ļ� 
	}
	void Equipments::Mod_Equ_Message()//����������
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
		cout<<"��������Ҫ�޸��豸������:";
		cin>>name1;//�����豸���� 
		for (i = 0; i < 50; i++)
		{
			if (strcmp(equ[i].ename, name1) == 0)//�ҵ� 
			{
			cout<<"ѡ���޸���Ŀ"<<endl;
			cout<<"1.�豸���   2.ʵ��������   3.�豸����    4.���ô���   5.�豸ά����---";
			int choice;
			cin>>choice;
			switch (choice) 
			{
				case 1:
					cout<<"���������豸���:";
								cin>>equ[i].en;
				//	cout<<"�޸����"<<endl;
					break;
				case 2:
					cout<<"��������ʵ��������:";
								cin>>equ[i].rname;
							//	cout<<"�޸����"<<endl;
					break;
				case 3:
						cout<<"���������豸����:";
								cin>>equ[i].ename;
							//	cout<<"�޸����"<<endl;
					break;
				case 4:
						cout<<"�������¿����豸����:";
								cin>>equ[i].nums;
							//	cout<<"�޸����"<<endl;
					break;
				case 5:
						cout<<"���������豸ά����:";
								cin>>equ[i].Break;
							//	cout<<"�޸����"<<endl;
					break;
					
			}
			break;
				
			}
			else if (equ[i + 1].en == 0)//δ�ҵ�
			{
				//cout<<"���޴��豸�����飡"<<endl;
				for (i = 0; equ[i].en != 0; i++)
				{
					fwrite(&equ[i], sizeof(struct equipment), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//������һ�� 
			{
				continue;
			}

		}
		for (i = 0; equ[i].en != 0; i++)//�����޸ĺ������ 
		{
			if (fwrite(&equ[i], sizeof(struct equipment), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
			else if (equ[i + 1].en == 0)
				cout<<"�޸ĳɹ���"<<endl;
		}
		fclose(fp);

	}

	void Equipments::Add_Stu_Message()//����ѧ��
	{
		FILE* fp;
		int i,n;
		if ((fp = fopen("D:\\kcsj\\stu", "wb+")) == NULL)//����ļ�Ϊ�� 
		{
			cout<<("cannot open file\n");
			exit(0);
		}
		cout<<"��������Ҫ¼����Ϣ����Ŀ:";
		cin>>n;
		for (i = 0; i < n; i++)
		{
			cout<<"������ѧ��:";
			cin>>stu[i].n;
			cout<<"����������:";
			cin>>stu[i].name;
			cout<<"������רҵ:";
			cin>>stu[i].major;

			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)//д���ļ�
			{
				cout<<"¼��ʧ�ܣ�"<<endl;
			}
			else cout<<"����¼��ɹ���"<<endl;
		}
		fclose(fp);
	}
	void Equipments::Stu_Read()//���ļ��ж�ȡ 
	{
		FILE* fp;
		int i; 
		if ((fp = fopen("D:\\kcsj\\stu", "rb+")) == NULL)//�Զ����ƶ�ȡ��ʽ�� 
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
	void Equipments::Del_Stu_Message()//ɾ��ѧ��
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
		cout<<"��������Ҫɾ��ѧ����ѧ��:";
		cin>>j;
		for (i = 0; stu[i].n != 0; i++)//����������Ϣ���ѧ������Ϣ 
		{
			if (stu[i].n == j)//�ҵ� 
			{
				for (int d = i; stu[d].n != 0; d++)
				{
					stu[d] = stu[d + 1];
				}
				cout<<"ɾ���ɹ���"<<endl;
			
			}
			
			else if (stu[i + 1].n == 0)//δ�ҵ� 
			{
				cout<<"���޴��ˣ����飡"<<endl;
				for (i = 0; stu[i].n != 0; i++)
				{
					fwrite(&stu[i], sizeof(struct student), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//������һ�� 
			{
				continue;
			}

		}
		for (i = 0; stu[i].n != 0; i++)//�����޸ĵ����� 
		{
			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
		}
		fclose(fp);
	}
	void Equipments::Mod_Stu_Message()//�޸�ѧ��
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
		cout<<"��������Ҫ�޸�ѧ��������:"<<endl;
		cin>>name1;
		for (i = 0; i < 50; i++)//���������ѧ������Ϣ
		{
			if (strcmp(stu[i].name, name1) == 0)//�ҵ� 
			{
				cout<<"��ѡ��Ҫ�޸ĵ���Ŀ"<<endl;
				cout<<"1.ѧ��   2.����   3.רҵ---";
				int choice;
				int a;
				char b[20];
				char c[20];
				
				cin>>choice;
				switch (choice) 
				{
					case 1:
							cout<<"��������ѧ��:";
							cin>>a;
							stu[i].n=a;				
						break;
					case 2:
							cout<<"������������:";
							cin>>b;
							strcpy(stu[i].name,b);
						break;
					case 3:
							cout<<"��������רҵ:";
							cin>>c;		
							strcpy(stu[i].major,c);
						break;
				}
			
			
				break;
			}
			else if (stu[i + 1].n == 0)//δ�ҵ�
			{
				cout<<"���޴��ˣ����飡"<<endl;
				for (i = 0; stu[i].n != 0; i++)
				{
					fwrite(&stu[i], sizeof(struct student), 1, fp);
				}
				fclose(fp);
				return;
			}
			else//������һ�� 
			{
				continue;
			}

		}
		for (i = 0; stu[i].n != 0; i++)//�����޸ĺ������ 
		{
			if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			{
				cout<<"file write error"<<endl;
			}
			else if (stu[i + 1].n == 0)
				cout<<"�޸ĳɹ���"<<endl;
		}
		fclose(fp);

	}

	void Equipments::Exit1()//�˳�
	{
		system("cls");
		exit(0);
	}
	void Equipments::Display_Equ()//��ʾʵ�����豸
	{	
		/*char name0[20];
		cout<<"����ʵ�������ƣ�";
		cin>>name0;
		
		int i; 
	
		for(i=0;equ[i].en!=0;i++)
		{
			if (strcmp(equ[i].rname, name0) == 0)
				cout<<"�豸���        ʵ��������      �豸����        ���ô���        �豸ά��"<<endl;
			cout<<equ[i].en<<" \t\t"<<equ[i].rname<<" \t\t"<<equ[i].ename<<" \t\t"<<equ[i].nums<<" \t\t"<<equ[i].Break<<endl;
			break;
		}*/
				int i;//ѭ��ֵ 
					cout<<"ʵ��������      �豸����        �豸���        ���ô���        �豸ά��"<<endl;
				for(i=0;equ[i].en!=0;i++)
				{
						cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
				}
			 
			 
	 } 
	 void Equipments::Display_Stu()//��ʾѧ����Ϣ
	 {
	 	{
	 		int i;
	 		cout<<"ѧ��            ����            רҵ"<<endl;
		 		for(i=0;stu[i].n!=0;i++)
		 		{
		 			cout<<stu[i].n<<"\t\t"<<stu[i].name<<"\t\t"<<stu[i].major<<endl;
		 		}
	 	}
	 	
	 }
	 void Equipments::Use_Equ()//�鿴�豸ʹ�����
	 {
	 	int name,i;
	 	cout<<"��������Ҫ�鿴���豸���:";
	 	cin>>name;
	 	for(i=0;equ[i].en!=0;i++)
		{
			if(name==equ[i].en)
			{
				cout<<"           ���������        ���õ�����         ά������"<<endl;
				cout<<" \t\t"<<equ[i].bnum<<" \t\t"<<equ[i].nums<<" \t\t"<<equ[i].Break<<endl;
			}
		}
		
	 }
	 void Equipments::Search_Equ()//�����豸
	 {
	 	cout<<"ѡ���Ժ��ַ�ʽ�����豸��Ϣ��1.�豸���  2.�豸���ƣ�:";
	 	int n;
	 	cin>>n;
	 	if(n==1)
	 	{
	 	int i,p;
	 	cout<<"��������Ҫ�鿴���豸���: ";
	 	cin>>p;
	 	for(i=0;equ[i].en!=0;i++)
		{
			if(p==equ[i].en)
			{
				cout<<"ʵ��������      �豸����        �豸���        ���ô���        �豸ά��"<<endl;
				cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
			}
		}
	 	}
	 	else if(n==2)	
	 	{
		 	char name[20];
		 	cout<<"��������Ҫ�鿴���豸���ƣ�";
		 	cin>>name;
		 	for(int i=0;equ[i].en!=0;i++)
			 {
			 	if(strcmp(equ[i].ename,name)==0)
				 {
				 	cout<<"ʵ��������      �豸����        �豸���        ���ô���        �豸ά��"<<endl;
					cout<<equ[i].rname<<"\t\t"<<equ[i].ename<<"\t\t"<<equ[i].en<<"\t\t"<<equ[i].nums<<"\t\t"<<equ[i].Break<<endl;
				 }
			 }
	
		 }
		 
		 else
		 cout<<"�޸��豸"<<endl;
	 }
	 
	 void Equipments::Borrow()//ѧ�����豸
	 {
	 	
	 	cout<<"����������ѧ��:";
	 	int a;
	 	cin>>a;
	 	for(int b=0;stu[b].n!=0;b++)
	 	{
		 if(stu[b].n==a)
		 {
		 	int i; 
		 		
			 	 	char name[20];//�û���������� 
			 	 	cout<<"��������Ҫ���õ��豸����:";
			 	 	cin>>name;		 	 	
			 	 	
			 	 	for(i=0;equ[i].en!=0;i++)
			 		{
			 			if(strcmp(name,equ[i].oldname)==0)//����֮ǰ���õ����Ʋ���ͬ
			 			{
							cout<<"�Բ���ͬһ�豸��ֻ�ܽ���һ��"<<endl;
					 		break;
			 			}
			 			
			 			else if(strcmp(name,equ[i].ename)==0)
			 			{
			 				equ[i].nums=equ[i].nums-1;
			 				equ[i].bnum=equ[i].bnum+1;
			 				cout<<"���óɹ���"<<endl;
			 				strcpy(equ[i].oldname,name);
			 				
			 			}
			 			else
			 		//	cout<<"�޸��豸��Ϣ������ϵ����Ա"<<endl;
			 		///	break;
			 		continue;
			 		
			 		}
			}		
		 }
	 	
	 }
	void Equipments::menu1()//����Ա�˵�
	{
		int i;
		cout<<"\t\t��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��"<<endl;
		cout<<"\t\t|            ʵ�����豸����ϵͳ          |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��1�����ѧ����Ϣ             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��2��ɾ��ѧ����Ϣ             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��3���޸�ѧ����Ϣ             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��4�����ʵ�����豸��Ϣ       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��5��ɾ��ʵ�����豸��Ϣ       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��6���޸�ʵ�����豸��Ϣ       |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��7�������ͳ���豸��ʹ�ÿ�   |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��8����ѯ�豸��Ϣ             |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��9����ʵ������ʾ�豸��Ϣ     |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��10���鿴ѧ����Ϣ            |"<<endl;
		cout<<"\t\t|                                        |"<<endl;
		cout<<"\t\t|          ��11���˳�����Աϵͳ          |"<<endl;
		cout<<"\t\t��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��"<<endl;
		cout<<"����������ѡ��:";
		cin>>i;
		while (i >= 1 && i <= 11)//����ѡ�� 
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
		void Equipments::regi()//�û�����
		{
			int i;
			cout<<"\t\t________________________________________\n"<<endl;
			cout<<"\t\t|           ʵ�����豸����ϵͳ         |\n"<<endl;
			cout<<"\t\t|          ��1��ѧ����¼               |\n"<<endl;
			cout<<"\t\t|          ��2������Ա��¼             |\n"<<endl;
			cout<<"\t\t|          ��3���˳�ϵͳ               |\n"<<endl;
			cout<<"\t\t|______________________________________|\n"<<endl;
			cout<<"����������ѡ��:";
			cin>>i;
			while (i >= 1 && i <= 3)//����ѡ�� 
			{
				switch (i)
				{
				case 1:system("CLS");xuesheng(); break;
				case 2:system("CLS");guanli(); break;
				case 3:Exit1(); break;
				}
				system("pause");
				system("CLS");//���� 
				regi();
				cin>>i;
			}		
		}
			void Equipments::xuesheng()//ѧ����¼
			{
				int i,key;
				char user[20];
				cout<<""<<endl;
				cout<<"\t\t������������";
				cin>>user;
				cout<<"\t\t������ѧ�ţ�";
				cin>>key;
				system("CLS");//���� 
				for(i=0;stu[i].n!=0;i++){
					if(strcmp(user,stu[i].name) !=0 || (key!=stu[i].n)){
						cout<<"������ѧ�Ų����ڣ�����ϵ����Ա��\n"<<endl;
					}
					else
					{
						menu2();
					}
				}
			}
			void Equipments::menu2()//ѧ���˵�
						{
						int i;
						cout<<"\t\t��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��\n"<<endl;
						cout<<"\t\t|            ʵ�����豸����ϵͳ            |\n"<<endl;
						cout<<"\t\t|          ��1��ѧ�������豸               |\n"<<endl;
						cout<<"\t\t|          ��2����ʵ������ʾ�豸��Ϣ       |\n"<<endl;
						cout<<"\t\t|          ��3�������Ʊ�Ų�ѯ�豸         |\n"<<endl;
						cout<<"\t\t|          ��4���˳�ѧ����¼               |\n"<<endl;
						cout<<"\t\t��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��T�T ��\n"<<endl;
						cout<<"����������ѡ��:";
						cin>>i;
						while (i >= 1 && i <= 4)//����ѡ�� 
						{
							switch (i)
							{
								case 1:Borrow(); break;
								case 2:Display_Equ(); break;
								case 3:Search_Equ(); break;
								case 4:system("CLS");regi(); break;
							}
							system("pause");
							system("CLS");//���� 
							menu2();
							cin>>i;
						}
					}
			void Equipments::guanli()//����
					{
						char user[] = "mxx\0";//����Ա�û���
						char key[] = "mxx\0";//����Ա����
						char user2[10],key2[10];
						cout<<"\t\t�������û�����";
						cin>>user2;
						cout<<"\t\t���������룺";
						cin>>key2;
						system("CLS");//���� 
						if(strcmp(user,user2) !=0 || strcmp(key,key2) !=0)
						{
							cout<<"�û������������\n"<<endl;
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

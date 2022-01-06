//import statements
#include<string.h>
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
#include<process.h>

//class declaration
class customer
{
	int custm_id;
	int custm_age;
	int check_inyear;
	int check_inmonth;
	int check_inday;
	char roomtype[20];
	int room_charge;
	int roomno;
	char custm_name[25];
	char custm_occupation[20];

public:
	long room;
	long total; //variable for Generate Bill
	int food;
	float ser;
	int t;
	int oc;
	int r_day;

public:
	void getdata();
	void welcomescreen();
	void login_screen();
	void add_customer();
	void delete_customer();
	void update_customer();
	void search_customer();
	void main_screen();
	void display_customer();
	void checkout_customer();
	void room_detail();
	void generate_bill();
	void room_bill();
	char* getscustmname()
	{
		return(custm_name);
	}
};

class Generatebill:public customer
{
	public :
		int r_charge;
		char custm_name[25];
		int b;

	public:

		void calculate()
		{
			system("cls");

			cout<<"\n Enter Room type:";
			cout<<"\n Select 1 for Super Luxury \n Select 2 for Luxury \n Select 3 for Deluxe \n";
			cout<<" ";
			cin>>b;
						  if(b==1)
						  {
							r_charge=4000;
						  }
						  else
						  if(b==2)
						  {
							r_charge=3000;
						  }
						  else
						  if(b==3)
						  {
							r_charge=2000;
						  }


	   cout<<"\n Enter the bill amount of restaurant:";
	   cin>>food;
	   cout<<"\n Enter other charges:";
	   cin>>oc;
	   cout<<"\n Enter customer name:";
	   cin>>custm_name;
	   cout<<"\n Enter number of days:";
	   cin>>r_day;
	   room= r_charge * r_day;
	   t=(int) room + food + oc;
	   ser=(int)(0.05*t);
	   total=t+ser;
	  }

      void display_bill()
	  {
	   system("cls");
	   cout<<"\n______________________________________________________________";
	   cout<<"\n                   Oberoi Luxury Hotel                       ";
	   cout<<"\n               ____________________________                 ";
	   cout<<"\n--------------------------------------------------------------";
	   cout<<"\n      Customer name : "<<custm_name;
	   cout<<"\n                              ";
	   cout<<"\n      Stayed for "<<r_day<<" days";
	   cout<<"\n      Room charges    : "<<r_charge<<"(Per day)";
	   cout<<"\n      Room charges    : "<<room<<"(total)";
	   cout<<"\n      Restaurant bill : "<<food;
	   cout<<"\n      Other charges   : "<<oc;
	   cout<<"\n                          Ser.tax % = 5%";
	   cout<<"\n                          Ser.tax   ="<<ser;
	   cout<<"\n      Bill Amount >>>>>> Rs "<<total;
	   cout<<"\n                              ";
	   cout<<"\n      THANK YOU !!!!!";
	   cout<<"\n      Visit Again !";
	  }
	  getch();

  };

void customer::welcomescreen()
{
	system("cls");
	cout<<  endl << endl << endl<< endl;
	cout<<"                        COMPUTERISED HOTEL MANAGEMENT SYSTEM  "<<endl;
	cout<<"                                GROUP  ASSINGMENT         "<<endl;
	cout<<"                                       ON                   "<<endl;
	cout<<"                       Further Programming Concepts in C++  "<<endl;
	cout<<"              ____________________________________________________  "<<endl;
	cout<<endl<<endl<<endl<<endl;
	cout<<"                  SUBMITTED BY:		           "<<endl;
	cout<<"                  Derick, Numan, Haseebudin, Fawzan             "<<endl;
	getch();
}
void customer::login_screen()
{
	time_t t;
	system("cls");
	t=time(NULL);
	cout<<"\n                                                        "<<ctime(&t);
	customer c;
	t -= 24L*60L*60L;
	int choice;
	cout<<  endl << endl << endl<< endl;
	cout<<"                            LOGIN SCREEN\n";
	cout<<"              ___________________________________________  "<< endl;
	cout<<"                          1.Administrator Login\n";
	cout<<"                          2.Exit\n";
	cout<<"\n\n\n";
	cout<<"Enter Choice::   ";
	cin>>choice;
	switch(choice)
	{
	 case 1 :
		system("cls");
		c.main_screen();
		break;

	 case 2 :
		exit(0);

	 default:
		cout<<"wrong choice entered";
	}
}
void customer::main_screen()
{
	char username[10],pass[10];
	int chce,i;
	customer c;
	cout<<"\t\t\t\tUser Name = ";
	gets(username);
	if(strcmp(username,"admin")==0)
	{
		char ch;
		cout<<"\t\t\t\tEnter password: ";
		for(i=0;i<5;i++)
		{

			 ch=getch();
			 pass[i]=ch;
			 ch='*';
			 cout<<ch;


		}
		pass[i]='\0';
		if(strcmp(pass,"admin")==0)
		{
			cout <<"\n\t\t"<< "Access granted\n";
			getch();
			system("cls");
			do
			{
				system("cls");
				cout<<"         ______________________________________________________\n\n";
				cout<<"                              OBEROI HOTEL                   \n\n";
				cout<<"         ______________________________________________________\n\n";
				cout<<"                       1.Add Customer\n";
				cout<<"                       2.Search Customer\n";
				cout<<"                       3.Check out Customer\n";
				cout<<"                       4.Update Customer\n";
				cout<<"                       5.Display Customer\n";
				cout<<"                       6.Delete Customer\n";
				cout<<"                       7.Room Details\n";
				cout<<"                       8.Generate bill\n";
				cout<<"                       9.Exit\n";
				cout<<"                         Enter your choice : ";
				cin>>chce;
				switch(chce)
				{
					case 1:c.add_customer();
							break;
					case 2:c.search_customer();
							break;
					case 3:c.checkout_customer();
							break;
					case 4:c.update_customer();
							break;
					case 5:c.display_customer();
							break;
					case 6:c.delete_customer();
							break;
					case 7:c.room_detail();
							break;
					case 8:c.generate_bill();
							break;
					case 9: cout<<"Ending programn...\n";
						exit(0);
					default:cout<<"Invalid option!";
				}
			 }
			 while(chce!=9);
	    }
      }
}
void customer::getdata()
{
	system("cls");
	cout<<"Enter Customer ID : ";
	cin>>custm_id;
	cout<<"\nEnter Customer name : ";
	cin>>custm_name;
	cout<<"\nEnter Customer Age : ";
	cin>>custm_age;
	cout<<"\nEnter Customer Occupation : ";
	cin>>custm_occupation;

	cout<<"\nEnter customer CheckIn Date : ";
	START:
	cout<<"\n--------------------------------";
	cout<<"\nYear : ";
	cin>>check_inyear;
	cout<<"\nMonth : ";
	cin>>check_inmonth;
	cout<<"\nDay : ";
	cin>>check_inday;
  if((check_inmonth==2) && (check_inday>29))
  {
	cout<<"Wrong input!!!\n";
	cout<<"\nEnter the date again....\n";
	goto START;
  }
  if((check_inmonth>12)||(check_inday>31))
  {
	cout<<"Wrong input!!!\n";
	cout<<"\nEnter the date again....\n";
	 goto START;
  }
  if((check_inmonth==4||check_inmonth==6||check_inmonth==9||check_inmonth==11) && (check_inday>30))
  {
	cout<<"Wrong input!!!\n";
	cout<<"\nEnter the date again....\n";
	goto START;
  }
  if((check_inyear%4)!=0 && (check_inmonth==2) && (check_inday>28))
  {
	cout<<"Wrong input!!!\n";
	cout<<"\nEnter the date again....\n";
	goto START;
  }
	cout<<"\nEnter Room Type : ";
	gets(roomtype);
	cout<<"\nEnter Room No : ";
	cin>>roomno;
}
void customer::add_customer()
{
	customer c;
	char ch;
	fstream outf;
	outf.open("customer.dat",ios::out|ios::app|ios::binary);
	do
	{
		c.getdata();
		outf.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to continue(Y/N) : ";
		cin>>ch;
	}
	while(ch!='n');
	outf.close();
	getch();
}
void customer::delete_customer()
{
	system("cls");
	fstream file;
	fstream temp;
	temp.open("tempdata.dat",ios::out|ios::binary);
	file.open("customer.dat",ios::in|ios::binary);
	customer c;
	int found=1;
	char name[25];
	cout<<"\t\t\t\t  All customer Detail \n";
	cout<<"\t\t\t_____________________________\n\n";
	cout<<"\t\t\t\t\n Enter name to Delete: ";
	gets(name);
	while(file.read((char*)&c, sizeof(c)))
	{
		if(strcmpi(c.getscustmname(),name)!=0)
		{
			 temp.write((char*)&c,sizeof(c));
		}
		else
		{
			cout<<"Record deleted\n";
			found=0;
		}
	}
	file.close();
	temp.close();
	remove("customer.dat");
	rename("tempfile.dat","customer.dat");
	if(found)
	cout<<"Record not found\n";
	getch();
}
void customer::generate_bill()
{
	Generatebill b;
	b.calculate();
	b.display_bill();
	getch();

}
void customer::checkout_customer()
{
	system("cls");
	fstream file;
	fstream temp;
	temp.open("tempdata.dat",ios::out|ios::binary);
	file.open("customer.dat",ios::in|ios::binary);
	customer c;
	int found=1;
	char name[25];
	cout<<"\n\t\t\t_______________________________________"<<endl;
	cout<<"\n\t\t\t\t  HOTEL MANAGEMENT SYSTEM "<<endl;
	cout<<"\n\t\t\t_______________________________________\n\n"<<endl;
	cout<<"Enter customer name : \n";
	gets(name);
	while(file.read((char*)&c, sizeof(c)))
	{
		if(strcmpi(c.getscustmname(),name)!=0)
		{

			temp.write((char *)&c,sizeof(c));

		}
		else
		{
			cout<<"   Custm ID          Custm Name\n";
			cout<<"__________________________________\n"<<endl;
			cout<<"   ";
			printf("%-18d",c.custm_id);
			printf("%s",c.custm_name);
			found=0;
		}
	}
	file.close() ;
	temp.close();
	remove("customer.dat");
	rename("tempfile.dat","customer.dat");
	if(found)
	cout<<"\nRecord does not exist\n";
	else
	cout<<"\nCheckout Successfull\n";
	getch();
}
void customer::room_detail()
{
	system("cls");
	fstream file;
	customer c;
	file.open("customer.dat",ios::in|ios::binary);
	cout<<"  Customer ID   Name        Room\n";
	cout<<"__________________________________\n";
	while(file.read((char*)&c, sizeof(customer)))
	{
		cout<<"  ";
		printf("%-14d",c.custm_id);
		printf("%-12s",c.custm_name);
		printf("%d",c.roomno);
	}
	file.close();
	getch();
}
void customer::search_customer()
{
	system("cls");
	fstream file;
	customer c;
	int found=1;
	char name[25];
	file.open("customer.dat",ios::in|ios::binary);
	cout<<"\t\t\t\t    Customer Detail \n";
	cout<<"\t\t\t_________________________________ \n\n";
	cout<<"\t\t\t\t\n Enter name to Search: ";
	cin>>name;
	file.seekg(0,ios::beg);
	while(file.read((char *) &c, sizeof(customer)))
	{
		if(strcmpi(c.getscustmname(),name)==0)
		{
			cout<<"   Custm ID         Custm Name \n";
			cout<<"__________________________________\n"<<endl;
			cout<<"   ";
			printf("%-18d",c.custm_id);
			printf("%s",c.custm_name);
			cout<<"\n\n\n   Room Type        Room No. \n";
			cout<<"__________________________________\n";<<endl;
			cout<<"   ";
			printf("%-18s",c.roomtype);
			printf("%d",c.roomno);
			cout<<"\n\t\t\t_________________________________________ ";
			cout<<"\n\t\t\t     ...Thank you for using... ";
			found=0;
			break ;
		}
	}
	file.close();
	if(found)
	{
		cout<<"Sorry!!!! Record Not found";
	}
	getch();
}
void customer::display_customer()
{
	fstream file;
	system("cls");
	customer c;
	file.open("customer.dat",ios::in|ios::binary);
	cout<<"  Customer ID   Name        Occupation   Room Type  CheckIn Date\n";
	cout<<"___________________________________________________________________________\n";
	while(file.read((char*)&c, sizeof(customer)))
	{
		cout<<"  ";
		printf("%-14d",c.custm_id);
		printf("%-12s",c.custm_name);
		printf("%-13s",c.custm_occupation);
		printf("%-11s",c.roomtype);
		printf("%d",c.check_inday);
		cout<<" "<<c.check_inmonth<<' '<<c.check_inyear<<endl;
	}
	file.close();
	getch();
}
void customer::update_customer()
{
	system("cls");
	fstream file;
	customer c;
	int found=1;
	char name[25];
	file.open("customer.dat",ios::in|ios::out|ios::binary);
	cout<<"\t\t\t\t    Customer Detail \n";
	cout<<"\t\t\t_________________________________ \n\n";
	cout<<"\t\t\t\t\n  Enter name to Update: ";
	cin>>name;
	file.seekg(0,ios::beg);
	while(file.read((char *) &c, sizeof(customer)))
	{
		if(strcmpi(c.getscustmname(),name)==0)
		{
			c.getdata();
			int pos=-1*sizeof(c);
			file.seekp(pos,ios::cur);
			file.write((char *) &c, sizeof(customer));
			cout<<"Record updated\n";
			found=0;
		}
	}
	file.close() ;
	if(found)
	{
		cout<<"Sorry!!!! Record Not found";
	}
	getch();
}

void main()
{
	customer view;
	view.welcomescreen();
	view.login_screen();
}


#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<dos.h>


using namespace std;
int k=7 ,r=0 , flag = 0;

COORD coord = {0,0};
void gotoxy(int x ,int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class password
{
	string code;
public:
	void get_password();
	int verify_password(string);
};
void password::get_password()
{
	cout << ".................................     Golden Jewelers .......................................\n";
	cout << "                                   ENTER YOUR PASSWORD ";
START:
	code.clear();
	char ch;
	int count = 0;
	ch = _getch();
	while (ch != 13)
	{
		if (ch == 8)
		{
					cout << "\b \b";
					code.pop_back();
		}
		if (ch != 8)
		{
			cout << "*";
			code.push_back(ch);
		}
		ch = _getch();
		count++;
	}
	if (count < 5)
	{
		cout << "\n\nYour Password Should Have Minimum Of 5 Characters!!!\n";
		cout << "\n Please Choose A Password For Your System :";
		goto START;
	}
}
//int password::verify_password(string pass)
//{
	//if (pass == code){
      //  return true;}

//}

struct date
{
    int mm,dd,yy;
};
ofstream fout;
ifstream fin;
class item
{
    int  itemno ;
    char itname[25];
    char nme[25];
    int kart;
    date d;
public:
    void add()
    {
       cout<<"\n\n\t                  Date(dd-mm-yy): ";
       cin>>d.mm>>d.dd>>d.yy;
       cout<<"\n\n\t                  Customer ID :";
       cin>>itemno;
       cout<<"\n\n\t                  Name of Customer :";
       cin>>nme;
       cout<<"\n\n\t                  SELECT CATEGOIES NAME"
           <<"\n\n\t                  <1> Rings"
           <<"\n\n\t                  <2> Ear-Rings"
           <<"\n\n\t                  <3> Bracelet"
           <<"\n\n\t                  <4> Pendant"
           <<"\n\n\t                  <5> Chain"
           <<"\n\n\t                  <6> Jewelery_Set"
           <<"\n\n\t                  Enter Categories :";
           getch();
       cin>>itname;
       cout<<"\n\n\t                  karat:";
       cin>>kart;
       }
    void show()
    {
        cout<<"\n\n\tCustomer  Number: "<<itemno;
        cout<<"\n\n\tCustomer Name   :"<<nme;
        cout<<"\n\n\tItem Name       :"<<itname;
        cout<<"\n\n\tKarat           :"<<kart;
        cout<<"\n\n\tDate            : "<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
     void report()
    {
        gotoxy(4,4);
        cout<<itemno;
        gotoxy(4,5);
        puts(nme);
        gotoxy(4,6);
        cout<<itname;
    }
    int retno()
    {
        return(itemno);

    }

};

class amount: public item
{

    float chr,wgh,rte,gross,dis,netamt,wastage;
public:

    void add();
    void show();
    void report();
    void calculate();
    void pay();
    float retnetamt()
    {
        return(netamt);
    }

} amt;

void amount::add()
{
   item::add();
   cout<<"\n\n\t                   Enter the Weight (In Gram) :";
   cin>>wgh;
   cout<<"\n";
   cout<<"\n\n\t                   Enter Making Charges : ";
   cin>>chr;
   cout<<"\n";
   cout<<"\n\n\t                   Enter Current Gold/Silver  rate In Gram : ";
   cin>>rte;
   cout<<"\n";
   cout<<"\n\n\t                   Enter Wastage In Percent ";
   cin>>wastage;
   cout<<"\n";
   cout<<"\n\n\t                   Discount Amount Rs. : ";
   cin>>dis;
    calculate();
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}
void amount::calculate()
{
   gross = ((rte*wgh+chr+(wgh*rte*wastage/100))-dis); //calculation process
   netamt = gross;
}
void amount::show()

{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    item::show();
    cout<<"\n\n\tNet amount : "<<netamt;
    fin.close();
}
void amount::report()
{
    item::report();
    gotoxy(4,4);
    cout<<wgh;
    gotoxy(4,5);
    cout<<chr;
    gotoxy(4,6);
    cout<<rte;
    gotoxy(4,7);
    cout<<dis;
    gotoxy(4,8);
    cout<<netamt;
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<"Customer DETAILS ";
        gotoxy(3,5);
        cout<<"NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"Weight";
        gotoxy(33,5);
        cout<<"Making Charges";
        gotoxy(44,5);
        cout<<"Gold/Silver Rate";
        gotoxy(52,5);
        cout<<"DEDUCTION";
        gotoxy(64,5);
        cout<<"NET AMOUNT";
    }
}

void amount::pay()
{
   cout<<"\n\t\t===============Jewellery Bill================\n";
   item::show();
   cout<<"\n\n\tMaking Charges  :"<<chr;
   cout<<"\n";
   cout<<"\n\n\tTotal Wastage   :"<<wastage<<"%";
   cout<<"\n";
   cout<<"\n\n\tTotal Weight    :"<<wgh<<"Gram";
   cout<<"\n";
   cout<<"\n\n\tCurrent Rate Gold/silver :"<<rte;
   cout<<"\n\n\tDiscount Amount :"<<dis;
   cout<<"\n";
   cout<<"\n\n\tNet Amount Paid By the Customer     :"<<netamt;
   cout<<"\n\n\t===========================================";
}

int main()
{
    cout<<"\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
    password p;
    p.get_password();
     cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
menu:
    system("cls");
    cout<<"=================================================================================================================\n\n";
    cout<<"********************************************* GOLDEN JWELLERS ****************************************************\n\n";
    cout<<" ==================================================================================================================\n\n";
    cout<<"\t\t        (1).Bill Report\n\n";
    cout<<"\t\t        (2).Add New Customer/Renew Customer / Delete Customer Detail\n\n";
    cout<<"\t\t        (3).Show All Customer Details\n\n";
    cout<<"\t\t        (4).Exit\n\n";
    cout<<"\t\tPlease Enter Required Option: ";
    int ch,ff;
    cin>>ch;
    switch(ch)
    {
    case 1:
ss:
        system("cls");
        gotoxy(25,2);
        cout<<"*****************Bill Details***************";
        gotoxy(25,3);
        cout<<"================\n\n";
        cout<<"\n\t\t******1.All Details******\n\n";
        cout<<"\t\t******2.Back to Main menu******\n\n";
        cout<<"\t\t******Please Enter Required Option******: ";
        int cho;
        cin>>cho;
        if(cho==1)
        {
            system("cls");
            cout<<"\n\n\t\t*****************************************************************";
            cout<<"\n\t\t*********************Bill Details**********************************";
            cout<<"\n\t\t*******************************************************************";
            //amt.show();
            //gotoxy(5,5);
            amt.pay();
            //cout<<"Patient Number :";
            //gotoxy(5,7);
            //cout<<"Patient NAME :";
            //gotoxy(5,9);
            //cout<<"Doctor Fee :";
            //gotoxy(5,11);
            //cout<<"Blood Pressure Charges :";
            //gotoxy(5,13);
            //cout<<"Sugar Test charges :";
            //gotoxy(5,15);
            //cout<<"Dispensary Charges :";
            //gotoxy(5,17);
            //cout<<"DISCOUNT % :";
            //gotoxy(5,19);
            //cout<<"NET AMOUNT :";
            //cout<<"*******************************************************************";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
           float gtotal=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    gtotal=amt.retnetamt();
                    ff=0;
                }
                if(ff!=0) gtotal=0;
            }
            //gotoxy(40,20);
            cout<<"\n\n\t\tGrand Total="<<gtotal;
            getch();
            fin.close();
        }
        if(cho==2)
        {
            goto menu;
        }
        goto ss;
    case 2:
db:
        system("cls");
        cout<<"===================================================================================\n\n";
        cout<<"*************************************Bill Editor************************************\n\n";
        cout<<"=====================================================================================\n\n";
        cout<<"\t\t(1).Add New Customer\n\n";
        cout<<"\t\t(2).Edit Customer Details\n\n";
        cout<<"\t\t(3).Delete Customer Details\n\n";
        cout<<"\t\t(4).Back to Main Menu ";
        int apc;
        cin>>apc;
        switch(apc)
        {
        case 1:
            fout.open("itemstore.dat",ios::binary|ios::app);
            amt.add();
            cout<<"\n\t\tCustomer Added Successfully!";
            getch();
            goto db;

        case 2:
            int ino;
            flag=0;
            cout<<"\n\n\tEnter Customer Number to be Edited :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            fout.open("itemstore.dat",ios::binary|ios::app);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    int x=amt.retno();
                    if(x==ino)
                    {
                        flag=1;
                        fout.seekp(r*sizeof(amt));
                        system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        amt.show();
                        cout<<"\n\n\t\tEnter New Details\n";
                        amt.add();
                        cout<<"\n\t\tCustomer Details Edited";
                        getch();
                        goto db;
                    }
                }
                r++;
            }
            if(flag==0)
            {
                cout<<"\n\t\tCustomer No does not exist...Please Retry!";
                getch();
                goto db;
            }
            fin.close();
            getch();
            goto db;

        case 3:
            flag =0;
            cout<<"\n\nm Enter Customer Number To Be Deleted :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\n File Not Found ";
                goto menu;
            }
            fin.seekg(0);
            while(fin.read((char*)&amt,sizeof(amt)))
            {
                int x= amt.item::retno();
                if(x!=ino)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    flag = 1;
                }
            }
            fin.close();
            tmp.close();
           fout.open("itemstore.dat",ios::trunc | ios::binary);
           fout.seekp(0);
           tmp.open("temp.dat",ios::binary | ios::in);
           if(!tmp)
           {
               cout<<"Error In file ";
               goto db;
           }
           while(tmp.read((char*)&amt,sizeof(amt)))
               fout.write((char*)&amt,sizeof(amt));
               tmp.close();
               fout.close();
               if (flag == 1 )
               cout<<"\n\t Customer Successfully Deleted ";
               else if (flag==0)
                cout<<"\n\t Customer Does Not Exit   Please Retry";
               getch();
               goto db;
        case 4:
            goto  menu;
        default:
            cout<<"\n\n\t Wrong Choice !!!Retry ";
            getch();
            goto db ;
           }
        case 3:
            system("cls");
            flag =0;
            int ino;
            cout<<"\n\n\t Enter Customer Id Number ";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\n File Not Found ........ \n Program Terminated ";
                goto menu;
            }
             fin.seekg(0);
             while(fin.read((char*)&amt,sizeof(amt)))
             {
                 int x = amt.item::retno();
                 if ( x== ino)
                 {
                     //amt.show();
                     amt.pay();
                     flag =1;
                     break;
                 }
             }
            if(flag==0)
                cout<<"\n\t Item Does Not Exist ........... Please Retry ";
            getch();
            fin.close();
            goto menu;
        case 4:
            system("cls");
            gotoxy(10,20);
            cout<< "Are You Sure You want To Exist (Y/N)";
            char yn;
            cin>>yn;
            if((yn=='Y')||(yn=='y'))
            {
                gotoxy(12,20);
                system("cls");
                cout<<"******* THANKS ******";
                getch();
                exit(0);
            }
                else if((yn=='N')||(yn=='n'))
                    goto menu ;
                else
                {
                    goto menu;
                }
                default:
                cout<<"\n\n\t Wrong Choice ............Please Retry";
                getch();
                goto menu;

        }
        return 0;
    }

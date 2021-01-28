
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>
#include<iomanip>



#define size 100

using namespace std;

void clrscr()
{
    system("cls");
}

struct user_head
{
    int count;
    struct users* top;
}*userhead;

struct users
{
      long int password;
      char username[size];
      struct users *next;
}*new_user;
void create_user()
{
    userhead=new user_head();
    userhead->count=0;
    userhead->top=NULL;
}
struct admin_head
{
    int count;
    struct admins* top;
}*adminhead;

struct admins
{
    long int password;
    char username[size];
    struct admins *next;
}*new_admin;

void create_admin()
{
    adminhead=new admin_head();
    adminhead->count=0;
    adminhead->top=NULL;

}

struct business_head
{
    int count;
    struct business* top;
}*businesshead;

struct business
{
    char start[size];
    char destination[size];
    char plane[size];
    int flight_time;
    int day;
    int month;
    int year;
    int dep_time;
    struct business* next;
}*new_business;

void create_business()
{
    businesshead= new business_head();
    businesshead->count=0;
    businesshead->top=NULL;
}
struct economy_head
{
    int count;
    struct economy* top;
}*economyhead;

struct economy
{
    char start[size];
    char destination[size];
    char plane[size];
    int flight_time;
    int day;
    int month;
    int year;
    int dep_time;
    struct economy* next;
}*new_economy;

void create_economy()
{
    economyhead= new economy_head();
    economyhead->count=0;
    economyhead->top=NULL;
}

struct vip_head
{
    int count;
    struct vip* top;
}*viphead;

struct vip
{
    char start[size];
    char destination[size];
    char plane[size];
    int flight_time;
    int day;
    int month;
    int year;
    int dep_time;
    struct vip* next;
}*new_vip;

void create_vip()
{
    viphead= new vip_head();
    viphead->count=0;
    viphead->top=NULL;
}

void supermenu();
void administration();
void user();
void cancel_flight();
void add_flight();
void add_business();
void add_economy();
void add_vip();
void user_signup();
void admin_signup();
void admin_available_flights();
void user_available_flights();
void user_status();
void print_user(); //For Test!! Not present in the main code

void supermenu()
{

    int choice;
    cout<<"\n\n\t\t\t\tFLY WITH JACWO\t\t\t\n\n\n\n\n";
    cout<<"\n Press 1 to Log in as User\n";
    cout<<"\n Press 2 to Log in as Admin\n";
    cout<<"\n Press 3 to Sign up as User\n";
    cout<<"\n Press 4 to Sign up as Admin\n";
    cout<<"\n Press 0 to exit\n";
    cout<<"\n Enter your choice:\n";
    cin>>choice;
    switch(choice)
	{
		case 1:
		    clrscr();
            user();
            break;
		case 2:
		    clrscr();
            administration();
            break;

        case 3:
            clrscr();
            user_signup();
            break;
        case 4:
            clrscr();
        	admin_signup();
        	break;
        case 5:
            clrscr;
            print_user();
            system("PAUSE");
            break;

       	case 0:
       		return;
       		break;


		default:
            cout << "\n\n CAUTION!! INVALID CHOICE!!~~~Enter again!!\n\n";
            system("PAUSE");
            break;
	}

}

int main()
{
    create_user();
    create_admin();
    create_business();
    create_economy();
    create_vip();
    supermenu();

return 0;
}

void user_signup()
{
    long int pass;
    char name[size];
    cout<<"\n\n New Username:";
    cin>>name;
    cout<<"\n\n New Password (max. 8 number character):";
    cin>>pass;
    if(userhead->top==NULL)
    {
        new_user= new users();
        new_user->password= pass;
        strcpy(new_user->username,name);
        new_user->next=NULL;
        userhead->top=new_user;

    }
    else
    {
        new_user= new users();
        new_user->password=pass;
        strcpy(new_user->username,name);
        new_user->next=userhead->top;
        userhead->top=new_user;

    }
    userhead->count++;


}
void print_user()
{
    int n=1;
    new_user=userhead->top;
    if(userhead->top == NULL)
        cout<<"NO USERS AVAILABLE";
    else
    {
        cout<<"\n\nUSERS:\n\n";
        while(new_user!= NULL)
        {
           cout<<n<<":\n\n";
           cout<<new_user->username<<endl<<endl;
           cout<<new_user->password<<endl<<endl;
           new_user= new_user->next;
           n++;
        }
    }


}
void administration()
{
    long int pass;
    char admin[size];
    cout<<"\n\n Enter Username: ";
    cin>>admin;
    cout<<"\n\n Enter Password: ";
    cin>>pass;
    if(adminhead->top==NULL)
        cout<<"\n Program Error\n";
    else
    {
        while(new_admin!=NULL)
        {
            if(pass==new_admin->password)
            {
                admin_available_flights();
            }
        }
    }
}

void admin_available_flights()
{
    int b=1;
    int e=1;
    int v=1;
    int choice;
    new_business=businesshead->top;
    new_economy=economyhead->top;
    new_vip=viphead->top;
    if(businesshead->top == NULL)
        cout<<"\n\nNO BUSINESS CLASS Tickets AVAILABLE!!!";
    else
    {
        cout<<"\n\n Business Class Flights:\n\n";
        while(new_business!= NULL)
        {
           cout<<b<<":\n";
           cout<<"\n From: "<<new_business->start<<endl<<endl;
           cout<<"\n To: "<<new_business->destination<<endl<<endl;
           cout<<"\n Flight Date: "<<new_business->day<<"/"<<new_business->month<<"/"<<new_business->year<<endl<<endl;
           cout<<"\n Flight Time: "<<new_business->flight_time<<endl<<endl;
           cout<<"\n Departure Time: "<<new_business->dep_time<<endl<<endl;
           new_business= new_business->next;
           b++;

        }
    }
    if(economyhead->top == NULL)
        cout<<"\n\nNO ECONOMY CLASS Tickets AVAILABLE!!!";
     else
     {
        cout<<"\n\n Economy Class Flights:\n\n";
        while(new_economy!= NULL)
        {
           cout<<e<<":\n";
           cout<<"\n From: "<<new_economy->start<<endl<<endl;
           cout<<"\n To: "<<new_economy->destination<<endl<<endl;
           cout<<"\n Flight Date: "<<new_economy->day<<"/"<<new_economy->month<<"/"<<new_economy->year<<endl<<endl;
           cout<<"\n Flight Time: "<<new_economy->flight_time<<endl<<endl;
           cout<<"\n Departure Time: "<<new_economy->dep_time<<endl<<endl;
           new_economy= new_economy->next;
           e++;

        }
     }
    if(viphead->top == NULL)
        cout<<"\n\nNO VIP Tickets AVAILABLE!!!";
    else
        {
        cout<<"\n\n VIP Flights:\n\n";
        while(new_vip!= NULL)
        {
           cout<<v<<":\n";
           cout<<"\n From: "<<new_vip->start<<endl<<endl;
           cout<<"\n To: "<<new_vip->destination<<endl<<endl;
           cout<<"\n Flight Date: "<<new_vip->day<<"/"<<new_vip->month<<"/"<<new_vip->year<<endl<<endl;
           cout<<"\n Flight Time: "<<new_vip->flight_time<<endl<<endl;
           cout<<"\n Departure Time: "<<new_vip->dep_time<<endl<<endl;
           new_vip= new_vip->next;
           v++;

        }
        }
        system("PAUSE");
        clrscr();
        cout<<"\n\n ADD TICKETS??\n\n 1=Yes\n 0=NO";
        cin>>choice;
        if(choice==1)
        {
        clrscr();
        add_flight();
        }
        if(choice==0)
        {
        clrscr();
        supermenu();
        }

    }

void user()
{
    cout<<"code yet to be written";
}
void admin_signup()
{
    long int pass;
    char name[size];
    cout<<"\n\n New Username:";
    cin>>name;
    cout<<"\n\n New Password (max. 8 number character):";
    cin>>pass;
    if(adminhead->top==NULL)
    {
        new_admin= new admins();
        new_admin->password= pass;
        strcpy(new_admin->username,name);
        new_admin->next=NULL;
        adminhead->top=new_admin;

    }
    else
    {
        new_admin= new admins();
        new_admin->password=pass;
        strcpy(new_admin->username,name);
        new_admin->next=adminhead->top;
        adminhead->top=new_admin;

    }
    userhead->count++;
    cout<<"\n Sign UP successfull!!\n";
    system("PAUSE");
    clrscr();
    supermenu();

}
void add_flight()
{
    int choice;
    cout<<"\n\n\t\t\t\t ADD FLIGHTS\t\t\t\n\n\n\n\n";
    cout<<"\n\n Press 1 to add business class ticket";
    cout<<"\n\n Press 2 to add Economy class ticket";
    cout<<"\n\n Press 3 to add VIP ticket";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add_business();
        break;
    case 2:
        add_economy();
        break;
    case 3:
        add_vip();
        break;
    default:
        cout<<"\n\n INVALID ENTRY!!! TRY AGAIN";
        add_flight();
        break;
    }

}

void add_business()
{
    int stime, dtime, d, m, y;
    char from[size];
    char to[size];
    char aeroplane[size];
    cout<<"\n\n Starts From?:";
    cin>>from;
    cout<<"\n\n Destination?:";
    cin>>to;
    cout<<"\n\n  Flight Date? (DD <space> MM <space> YYYY)";
    cin>>d>>m>>y;
    cout<<"\n\n Flight Time?";
    cin>>stime;
    cout<<"\n\n Departure time?:";
    cin>>dtime;
    if(businesshead->top==NULL)
    {
        new_business= new business();
        new_business->flight_time= stime;
        new_business->dep_time= dtime;
        new_business->day= d;
        new_business->month= m;
        new_business->year= y;
        strcpy(new_business->start,from);
        strcpy(new_business->destination,to);
        strcpy(new_business->plane,aeroplane);
        new_business->next=NULL;
        businesshead->top=new_business;

    }
    else
    {
        new_business= new business();
        new_business->flight_time= stime;
        new_business->dep_time= dtime;
        new_business->day= d;
        new_business->month= m;
        new_business->year= y;
        strcpy(new_business->start,from);
        strcpy(new_business->destination,to);
        new_business->next=businesshead->top;
        businesshead->top=new_business;

    }
    businesshead->count++;
}

void add_economy()
{
    int stime, dtime, d, m, y;;
    char from[size];
    char to[size];
    char type[size];
    cout<<"\n\n Starts From?:";
    cin>>from;
    cout<<"\n\n Destination?:";
    cin>>to;
    cout<<"\n\n  Flight Date? (DD <space> MM <space> YYYY)";
    cin>>d>>m>>y;
    cout<<"\n\n Flight Time?";
    cin>>stime;
    cout<<"\n\n Departure time?:";
    cin>>dtime;
    if(economyhead->top==NULL)
    {
        new_economy= new economy();
        new_economy->flight_time= stime;
        new_economy->dep_time= dtime;
        new_economy->day= d;
        new_economy->month= m;
        new_economy->year= y;
        strcpy(new_economy->start,from);
        strcpy(new_economy->destination,to);
        new_economy->next=NULL;
        economyhead->top=new_economy;

    }
    else
    {
        new_economy= new economy();
        new_economy->flight_time= stime;
        new_economy->dep_time= dtime;
        new_economy->day= d;
        new_economy->month= m;
        new_economy->year= y;
        strcpy(new_economy->start,from);
        strcpy(new_economy->destination,to);
        new_economy->next=economyhead->top;
        economyhead->top=new_economy;

    }
    economyhead->count++;

}
void add_vip()
{
    int stime, dtime, d, m, y;
    char from[size];
    char to[size];
    char type[size];
    cout<<"\n\n Starts From?:";
    cin>>from;
    cout<<"\n\n Destination?:";
    cin>>to;
    cout<<"\n\n  Flight Date? (DD <space> MM <space> YYYY)";
    cin>>d>>m>>y;
    cout<<"\n\n Flight Time?";
    cin>>stime;
    cout<<"\n\n Departure time?:";
    cin>>dtime;
    if(viphead->top==NULL)
    {
        new_vip= new vip();
        new_vip->flight_time= stime;
        new_vip->dep_time= dtime;
        new_vip->day= d;
        new_vip->month= m;
        new_vip->year= y;
        strcpy(new_vip->start,from);
        strcpy(new_vip->destination,to);
        new_vip->next=NULL;
        viphead->top=new_vip;

    }
    else
    {
        new_vip= new vip();
        new_vip->flight_time= stime;
        new_vip->dep_time= dtime;
        new_vip->day= d;
        new_vip->month= m;
        new_vip->year= y;
        strcpy(new_vip->start,from);
        strcpy(new_vip->destination,to);
        new_vip->next=viphead->top;
        viphead->top=new_vip;

    }
    viphead->count++;
}

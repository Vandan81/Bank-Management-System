#include<bits/stdc++.h>
using namespace std;

int i,j,k;
int main_exit;
  

  void menu();

   struct  date
   {
       int month,day,year;
   };

struct 
{
    char name[60];
    int acc_no,age;
    char citizenship[15];
    char address[60];
    double phone;
    char acc_type[60];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

}add,upd,check,rem,trans;

float interest(float i,float amt,int rate)
{
   float SI;
   SI=(rate*i*amt)/100.0;
   return  (SI);
}
void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
            k=i;
} 

void new_acc()
{
    FILE *p;
    int choice;
    p=fopen("record.dat","a+");
    account_no:
    system("cls");
    cout<<"\t\t\t\xB2\xB2 ADD REcord\t\t\t\xB2\xB2";
    cout<<"enter the today date(MM/DD/YYYY):";
    cin>>add.deposit.month>>add.deposit.day>>add.deposit.year;
    cout<<"Enter the account number  ";
    cin>>check.acc_no;
    while(fscanf(p,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
       if(check.acc_no==add.acc_no)
       {
            cout<<"account no. already in use  \n";
            fordelay(10000);
            goto account_no;
       }     
    }
    add.acc_no=check.acc_no;
    cout<<"Enter the Name   ";
    cin>>add.name;
    cout<<"enter the date of birth(MM/DD/YYYY)  ";
    cin>>add.dob.month>>add.dob.day>>add.dob.year;
    cout<<"enter the age  ";
    cin>>add.age;
    cout<<"enter the address  ";
    cin>>add.address;
    cout<<"enter the cictinzenshipn number \n";
    cin>>add.citizenship;
    cout<<"enter the phone   ";
    cin>>add.phone;
    cout<<"enter the amount to be deposited   \n";
    cin>>add.amt;
     cout<<"\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:";
    cin>>add.acc_type;

        fprintf(p,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(p);
    cout<<"\n Account created successfully\n";
    add_invalid:
    cout<<"\n\n\n Enter 1 to go the menu and 0 to exit  ";
    cin>>main_exit;
    system("cls");
    if(main_exit==1)
    {
        menu();
    }
    else if(main_exit==0)
            close();
    else
    {
        cout<<"\ninvalid data\n";
        goto add_invalid;

    }
}



void view_list()
{

    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    cout<<"\nACC NO.\t Name\t\t ADDRESS\t\t PHONE\n";
    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
       fclose(view);
       if(test==0)
       {
           system("cls");
           cout<<"\n No records\n";
       }

       view_list_invalid:
       cout<<"\n enter 1 to go the main menu and 0 to exit\n";
       cin>>main_exit;
       system("cls");
       if(main_exit==1)
            menu();
        else if(main_exit==0)
                close();
        else
        {
            cout<<"\n Invalid  \n";
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("new.dat","r");
    newrec=fopen("new,dat","w");


    cout<<"\n Enter the account NUmber of the customer  whose info you want to change  ";
    cin>>upd.acc_no;
       while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==upd.acc_no)
            {
                test=1;
                cout<<"\n Which information do u want o tchange  1.Address\n2.phone\n3.enter your choice (1 or 2)";
                cin>>choice;
                system("cls");
                if(choice==1)
                {
                    cout<<"ente rhte new address \n";
                    cin>>upd.address;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    cout<<"changes saved";
                
                }
                else if(choice==2)
                {
                    cout<<"enter the new phone number  ";
                    cin>>upd.phone;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    cout<<"changes saved\n";
                }
                else 
                {
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                }
            }
            fclose(old);
            fclose(newrec);
            remove("record.dat");
            rename("new.dat","record.dat");

            if(test!=1)
            {
                system("cls");
                cout<<"trecord not found\n";
                edit_invalid:
                cout<<"ENte r0 tot ry again ,1 to return main menu and 2 to exit \n";
                cin>>main_exit;
                system("cls");
                if(main_exit==1)
                {
                    menu();

                }
                else if(main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                {
                    cout<<"\n invalid\n";
                    goto edit_invalid;
                }
            }
            else
            {
                cout<<"\n\n enter 1 to go the main menu and 0 to exit  \n";
                cin>>main_exit;
                system("cls");
                if(main_exit==1)
                    menu();
                    else
                        close();
            }
        }
}




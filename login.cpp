#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;

void user()
{
    fstream f,f1,f2;
    int ch;
    string user,pass;
    cout<<"Enter 1.Set Up New Account, 2.Login"<<endl;
    cin>>ch;
    if(ch==1)
    {
        set:
        string u;
        int j=0;
        cout<<endl<<"Set Up : "<<endl<<endl<<"Enter your User name"<<endl;
        cin>>user;
        cout<<"Enter your password"<<endl;
        cin>>pass;
        f.open("User.txt",ios::app);
        if(!f)
        {
            cout<<"File could not open"<<endl;
            return;
        }
        f1.open("User.txt",ios::in);
        if(!f1)
        {
            cout<<"File could not open"<<endl;
            return;
        }
        else
        {
            while(!f1.eof())
            {
                j++;
                getline(f1,u);
                if(j%3==1)
                {
                    if(u==user)
                    {
                        cout<<"User name Already exists. Enter another User name."<<endl;
                        f1.close();
                        f.close();
                        goto set;
                    }
                }
            }
            f1.close();
            f<<user<<endl<<pass<<endl<<endl;
            cout<<"Set up completed."<<endl;
            goto log;
        }
        f.close();
    }
    else if(ch==2)
    {
        log:
        string u,p;
        int i=0,flag=0;
        cout<<endl<<"Log In : "<<endl<<endl<<"Enter Your User name"<<endl;
        cin>>user;
        cout<<"Enter your password"<<endl;
        cin>>pass;
        f2.open("User.txt",ios::in);
        if(!f2)
        {
            cout<<"File could not open"<<endl;
            return;
        }
        while(!f2.eof())
        {
            i++;
            getline(f2,u);
            if(i%3==1)
            {
                if(u==user)
                {
                    flag=1;
                    getline(f2,p);
                    i++;
                    if(p==pass)
                    {
                        cout<<"Login Successful!!"<<endl<<"Your User name : "<<user<<endl;
                    }
                    else
                    {
                        cout<<"Wrong Password!"<<endl<<"Enter your information again"<<endl;
                        f2.close();
                        goto log;
                    }
                    break;
                }
            }
        }
        if(flag==0)
        {
            cout<<"User name not found"<<endl;
            f2.close();
            goto log;
        }
        f2.close();
        return;
    }
}
int main()
{
    user();
    return 0;
}

#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;

void user()
{
    fstream f,f1;
    int ch;
    string user,pass;
    cout<<"Enter 1.Set Up New Account, 2.Login"<<endl;
    cin>>ch;
    if(ch==1)
    {
        set:
        string u;
        int j=0;
        cout<<"Enter the Username"<<endl;
        cin>>user;
        cout<<"Enter your password"<<endl;
        cin>>pass;
        f.open("User.txt",ios::app);
        if(!f)
        {
            cout<<"File could not open2"<<endl;
            return;
        }
        f1.open("User.txt",ios::in);
        if(!f1)
        {
            cout<<"File could not open1"<<endl;
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
                        cout<<"Username Already exists.Enter another Username."<<endl;
                        f1.close();
                        f.close();
                        goto set;
                    }
                }
            }
            f1.close();
            f<<user<<endl<<pass<<endl<<endl;
            cout<<"Set up completed"<<endl;
        }

        f.close();
        return;
    }
    else if(ch==2)
    {
        string u,p;
        int i=0,flag=0;
        cout<<"Enter Your Username"<<endl;
        cin>>user;
        cout<<"Enter your password"<<endl;
        cin>>pass;
        f.open("User.txt",ios::in);
        if(!f)
        {
            cout<<"File could not open"<<endl;
            return;
        }
        while(!f.eof())
        {
            i++;
            getline(f,u);
            if(i%3==1)
            {
                if(u==user)
                {
                    flag=1;
                    getline(f,p);
                    i++;
                    if(p==pass)
                        cout<<"Login Successful!!"<<endl;
                    else
                        cout<<"Wrong Password!"<<endl;
                    break;
                }
            }
        }
        if(flag==0)
            cout<<"Username not found"<<endl;
        return;
    }
}
int main()
{
    user();
    return 0;
}

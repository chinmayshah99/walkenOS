#include<stdio.h>
#include<fstream>
#include<iostream>
using namespace std;


int getInt() 
{
    while(true) {
        int input;
        std::cin >> input;
        std::cin.ignore(32767, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Input not an integer! Re-enter key: ";
            std::cout << std::endl;
        }
        else 
            return input;
    }
}

std::string user()
{
    fstream f,f1,f2;
    int ch;
    std::string user,pass;
    std::cout<<"Enter 1.Set Up New Account, 2.Login"<<std::endl;
    ch = getInt();
    if(ch==1)
    {
        set:
        std::string u;
        int j=0;
        std::cout<<std::endl<<"Set Up : "<<std::endl<<std::endl<<"Enter your User name"<<std::endl;
        cin>>user;
        std::cout<<"Enter your password"<<std::endl;
        cin>>pass;
        f.open("User.txt",ios::app);
        if(!f)
        {
            std::cout<<"File could not open1"<<std::endl;
            return nullptr;
        }
        f1.open("User.txt",ios::in);
        if(!f1)
        {
            std::cout<<"File could not open"<<std::endl;
            return nullptr;
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
                        std::cout<<"User name Already exists. Enter another User name."<<std::endl;
                        f1.close();
                        f.close();
                        goto set;
                    }
                }
            }
            f1.close();
            f<<user<<std::endl<<pass<<std::endl<<std::endl;
            std::cout<<"Set up completed."<<std::endl;
            f.close();
            goto log;
        }
    }
    else if(ch==2)
    {
        log:
        std::string u,p;
        int i=0,flag=0;
        std::cout<<std::endl<<"Log In : "<<std::endl<<std::endl<<"Enter Your User name"<<std::endl;
        cin>>user;
        std::cout<<"Enter your password"<<std::endl;
        cin>>pass;
        f2.open("User.txt",ios::in);
        if(!f2)
        {
            std::cout<<"File could not open"<<std::endl;
            return nullptr;
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
                        std::cout<<"Login Successful!!"<<std::endl<<"Your User name : "<<user<<std::endl;
                        return user;
                    }
                    else
                    {
                        std::cout<<"Wrong Password!"<<std::endl<<""<<"Enter your information again"<<std::endl;
                        f2.close();
                        goto log;
                    }
                    break;
                }
            }
        }
        if(flag==0)
        {
            std::cout<<"User name not found"<<std::endl;
            while(1) {
                std::cout<<"\nMenu:\n1.Set up a new account \n2.Login with another user name\n"<<std::endl;
                int c;
                c = getInt();
                f2.close();
                if(c==1)
                    goto set;
                else if(c==2)
                    goto log;
                else 
                    cout<<"Wrong Input"<<std::endl;
                }
        }
        f2.close();
        return user;
    }
}
int main()
{
    user();
    return 0;
}

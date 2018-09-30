#include<stdio.h>
#include<fstream>
#include<iostream>
#include <chrono>
#include <thread>

#include "validation.h"

using namespace std;



std::string user()
{   
    system("clear");
    std::cout << std::string(10,'\n');
    std::cout << std::string(11,'\t'); //full
    fstream f,f1,f2;
    int ch;
    std::string user,pass;
    std::cout<<"Enter\n\n";
    std::cout << std::string(11,'\t');
    std::cout << "1.Set Up New Account\n"<< std::string(11,'\t') <<"2.Login"<<std::endl;
    std::cout << std::string(11,'\t');
    ch = getInt();
    if(ch==1)
    {
        set:
        system("clear");
        std::cout << std::string(10,'\n');
        std::cout << std::string(11,'\t'); //full
        std::string u;
        int j=0;
        
        std::cout<<"Set Up : "<<std::endl;
        std::cout << std::string(11,'\t'); //full
        std::cout<<"Enter your User name"<<std::endl;
        std::cout << std::string(11,'\t'); //full
        cin>>user;
        std::cout << std::string(11,'\t'); //full
        std::cout<<"Enter your password"<<std::endl;
        std::cout << std::string(11,'\t'); //full
        cin>>pass;
        f.open("User.txt",ios::app);
        if(!f)
        {
            std::cout<<"File could not open1"<<std::endl;
            return NULL;
        }
        f1.open("User.txt",ios::in);
        if(!f1)
        {
            std::cout<<"File could not open"<<std::endl;
            return NULL;
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
                    {   std::cout << std::string(11,'\t'); //full
                        std::cout<<"User name Already exists. Enter another User name."<<std::endl;
                        f1.close();
                        f.close();
                        std::this_thread::sleep_for (std::chrono::seconds(2));
                        system("clear");
                        std::cout << std::string(10,'\n');
                        std::cout << std::string(11,'\t'); //full
                        goto set;
                    }
                }
            }
            f1.close();
            f<<user<<std::endl<<pass<<std::endl<<std::endl;
            std::cout << std::string(11,'\t'); //full
            std::cout<<"Set up completed."<<std::endl;
            f.close();
            std::this_thread::sleep_for (std::chrono::seconds(2));
            goto log;
        }
    }
    else if(ch==2)
    {
        log:                   
        system("clear");
        std::cout << std::string(10,'\n');
        std::cout << std::string(11,'\t'); //full
        std::string u,p;
        int i=0,flag=0;
        std::cout <<"Log In : "<<std::endl<<std::endl;
        std::cout << std::string(11,'\t'); //full
        std::cout << "Enter Your User name" << std::endl;
        std::cout << std::string(11,'\t'); //full
        cin>>user;
        std::cout << std::string(11,'\t'); //full
        std::cout<<"Enter your password"<<std::endl;
        std::cout << std::string(11,'\t'); //full
        cin>>pass;
        f2.open("User.txt",ios::in);
        if(!f2)
        {
            std::cout<<"File could not open"<<std::endl;
            return NULL;
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
                        std::cout << std::string(11,'\t'); //full
                        std::cout<<"Login Successful!!"<<std::endl;
                        std::this_thread::sleep_for (std::chrono::seconds(2));
                        return user;
                    }
                    else
                    {   
                        std::cout << std::string(11,'\t'); //full
                        std::cout<<"Wrong Password!"<<std::endl<<std::string(11,'\t')<<"Enter your information again"<<std::endl;
                        f2.close();
                        std::this_thread::sleep_for (std::chrono::seconds(2));
                        goto log;
                    }
                    break;
                }
            }
        }
        if(flag==0)
        {   
            std::cout << std::string(11,'\t'); //full
            std::cout<<"User name not found"<<std::endl;
            std::this_thread::sleep_for (std::chrono::seconds(2));
            system("clear");
            std::cout << std::string(10,'\n');
            std::cout << std::string(11,'\t'); //full
            while(1) {
                std::cout<<"Menu:\n" << std::string(11,'\t')<<"1.Set up a new account \n"<< std::string(11,'\t') <<"2.Login with another user name\n"<<std::endl;
                int c;
                c = getInt();
                f2.close();
                if(c==1)
                    goto set;
                else if(c==2)
                    goto log;
                else 
                    std::cout << std::string(10,'\n');
                    cout<<"Wrong Input"<<std::endl;
                    std::this_thread::sleep_for (std::chrono::seconds(2));
                    system("clear");
                    std::cout << std::string(10,'\n');
                    std::cout << std::string(11,'\t'); //full
                }
        }
        f2.close();
        return user;
    }
}

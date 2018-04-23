//uncomment startup
//hello user change back to 4s



#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;
void startup();
void user();
void submenu(int procno[],std::string proc[]);
int mainmenu();

int getInt() 
{
    while(true) {
        int input;
        std::cin >> input;
        std::cin.ignore(32767, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cout << std::string(11,'\t'); //full
            std::cin.ignore(32767, '\n');
            std::cout << "Input not an integer! Re-enter key: ";
            std::cout << std::endl;
            std::cout << std::string(11,'\t');
        }
        else 
            return input;
    }
}

int main() {
    //std::string username;
    //startup();
    
    user();
    
    return 0;
}

void startup() {
    
    //full-screen
    int width = 100;
    //split-screen
	//int width = 50;
	
	for(int p = 0; p <= 100; ++p) {
        
		int full = (double)p/100*width;
		
		std::cout << std::string(50,'\n');
        std::cout << std::string(10,'\t'); //full
        std::cout << "Starting WalkenOS, Please Wait...\n\n\t\t";
		std::cout << std::string(3,'\t') << "|";
		for(int i = 0; i < full; ++i) std::cout << "░";
		std::cout << std::string(width-full, ' ');
        std::cout << "|" << p << "%";
		std::cout << std::string(22,'\n');
        std::this_thread::sleep_for (std::chrono::milliseconds(50));
	}
    std::this_thread::sleep_for (std::chrono::seconds(2));
    system("clear");
    system("play -q daemon_process/vista.wav");
}

void user()
{   
    system("clear");
    std::cout << std::string(10,'\n');
    std::cout << std::string(11,'\t'); //full
    fstream f,f1,f2;
    int ch;
    std::string user,pass;
    std::cout<<"Enter\n\n";
    std::cout << std::string(11,'\t');
    std::cout << "1.Set Up New Account\n"<< std::string(11,'\t') <<"2.Login"<<std::endl << std::string(11,'\t') <<"3.Power Off"<<std::endl;
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
            return;
        }
        f1.open("User.txt",ios::in);
        if(!f1)
        {
            std::cout<<"File could not open"<<std::endl;
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
                        std::cout << std::string(11,'\t'); //full
                        std::cout<<"Login Successful!!"<<std::endl;
                        std::this_thread::sleep_for (std::chrono::seconds(2));
                        std::cout << std::string(100,'\n');
                        std::cout << std::string(11,'\t') << "Welcome "<< user << "!\n"; //full
                        std::cout << std::string(22,'\n');
                        std::this_thread::sleep_for (std::chrono::seconds(1));
                        std::cout << std::string(100,'\n');
    
                        mainmenu();
                        return;
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
                std::cout << std::string(11,'\t'); //full
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
        return;
    }else if(ch==3){
        system("clear");
        system("exit");
        return;
    }
}

int mainmenu()
{
    std::string proc[]={"File manager","Audio Player","Calculator","System Monitor","Text Editor"};
    int procno[]={0,0,0,0,0};
	while (1) {
		abc:
		int c;
		system("clear");
		std::cout<<std::string(10,'\n')<<std::string(12, '\t')<<"Menu\n\n"<<std::string(10,'\t');
		std::cout<<"Press the number to enter the program"<<std::string(4,'\n');
		std::cout << std::string(11,'\t');

		std::cout<<"1. File Manager\n";
		std::cout << std::string(11,'\t');
		std::cout<<"2. Audio Player\n";
		std::cout << std::string(11,'\t');
		std::cout<<"3. Calculator\n";
		std::cout << std::string(11,'\t');
		std::cout<<"4. Text Editor\n";
		std::cout << std::string(11,'\t');
		std::cout<<"5. System Monitor\n";
		std::cout << std::string(11,'\t');
        std::cout<<"6. Logout\n";
		std::cout << std::string(11,'\t');
		std::cout<<"7. Power Off\n";
		std::cout << std::string(2,'\n')<<std::string(11,'\t')<<"Input:";

		while(true) {
			std::cin >>c;
			std::cin.ignore(32767, '\n');
			if(std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				pqr:
				std::cout << "\n\n" << std::string(10,'\t') <<"Not a valid input! Re-enter key";
				std::cout << std::endl;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				system("clear");
				goto abc;
			}
			else break;
		}

		switch(c)
		{
			case 1:
				system("clear");
			    procno[0]=1;
			break;
			case 2:
			    procno[1]=1;
                system("cmus");
                system("clear");
			break;
			case 3:
			    procno[2]=1;
                system("clear");
                system("gcalccmd");
                system("clear");
			break;
			case 6:
                user();
                return 1;
			break;
			case 5:
                procno[3]=1;
                system("clear");
                submenu(procno,proc);
				return 1;
			break;
			case 4:
				system("clear");
				procno[4]=1;
                system("clear");
                system("vim");
                system("clear");
			break;
			case 7:
				system("clear");
                system("exit");
			return 0;
			break;
			default:
                goto pqr;
			break;
		}
	}
}


void submenu(int procno[],std::string proc[])
{
  while (1) {
		abc:
		int d;
		system("clear");
		std::cout<<std::string(10,'\n')<<std::string(12, '\t')<<"System Monitor\n\n"<<std::string(10,'\t');
		std::cout<<"Press the number to enter the option"<<std::string(4,'\n');
		std::cout << std::string(11,'\t');

		std::cout<<"1. Process\n";
		std::cout << std::string(11,'\t');
		std::cout<<"2. Memory\n";
		std::cout << std::string(11,'\t');
		
		std::cout<<"3. Back\n";
		std::cout << std::string(11,'\t');
		std::cout << std::string(2,'\n')<<std::string(11,'\t')<<"Input:";


		while(true) {
			std::cin >>d;
			std::cin.ignore(32767, '\n');
			if(std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				pqr:
				std::cout << "\n\n" << std::string(10,'\t') <<"Not a valid input! Re-enter key";
				std::cout << std::endl;
				std::this_thread::sleep_for (std::chrono::seconds(1));
				system("clear");
				goto abc;
			}
			else break;
		}
    int num;
		switch(d)
		{
			case 1:
			    xyz:
			    system("clear");
			    std::cout << std::string(10,'\n')<<std::string(11,'\t')<<"Running Process";
			     num=0;
			     for(int i=0;i<5;i++)
			     {
			       if(procno[i]==1)
			       {
			         std::cout << std::string(2,'\n')<<std::string(11,'\t')<<++num<<". "<<proc[i];
			       }
			     }
			     std::cout<<std::string(3,'\n')<<std::string(11, '\t')<<"Press 0 to go back \n\n";
    		   std::cout << std::string(3,'\n')<<std::string(11,'\t')<<"Input:";
    		  while(true) {
    			std::cin >>d;
    			std::cin.ignore(32767, '\n');
    			if(std::cin.fail()) {
    				std::cin.clear();
    				std::cin.ignore(32767, '\n');
    				lmn:
    				std::cout << "\n\n" << std::string(10,'\t') <<"Not a valid input! Re-enter key";
    				std::cout << std::endl;
    				std::this_thread::sleep_for (std::chrono::seconds(1));
    				system("clear");
    				goto xyz;

    			}
    			else break;
    		}
    		if(d==0)
    		{
    		  break;
    		}
    		else{
    		  goto lmn;
    		}

			case 2:
                std::cout << std::string(2,'\n');
                std::cout << std::string(11,'\t'); //full
          		system("free -m");
                std::this_thread::sleep_for (std::chrono::seconds(10));
			break;
			case 3:
			    system("clear");
			    mainmenu();
				return;
			break;

			default:
                goto pqr;
			break;
		}
	}



}


/*

file manager

play audio

logout

power off

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>


void submenu(int procno[],std::string proc[]);

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
		std::cout<<"4. Logout\n";
		std::cout << std::string(11,'\t');
		std::cout<<"5. System Monitor\n";
		std::cout << std::string(11,'\t');
		std::cout<<"6. Text Editor\n";
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
			case 4:
                system("clear");
			break;
			case 5:
                procno[3]=1;
                system("clear");
                submenu(procno,proc);
				return 1;
			break;
			case 6:
				system("clear");
				procno[4]=1;
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
          		std::cout<<"Option 2"<<std::endl;
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
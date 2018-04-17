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



void mainmenu()
{
     abc:
     	int c; // TODO, NEEDS VISIT as line 42 re-defines 'c'

        std::cout<<std::string(10,'\n')<<std::string(12, '\t')<<"Menu\n\n"<<std::string(10,'\t');
        std::cout<<"Press the number to enter the program"<<std::string(4,'\n');
 		std::cout << std::string(11,'\t');

 		std::cout<<"1.File Manager\n";
 		std::cout << std::string(11,'\t');
 		std::cout<<"2.Audio Player\n";
        std::cout << std::string(11,'\t');
 		std::cout<<"3.Logout\n";
        std::cout << std::string(11,'\t');
 		std::cout<<"4.Power Off\n";
 	    std::cout << std::string(2,'\n')<<std::string(11,'\t')<<"Input:";

        
        while(true) {
            std::cin >>c;
            std::cin.ignore(32767, '\n');
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
     pqr:       std::cout << "\n\n" << std::string(10,'\t') <<"Input not an integer! Re-enter key";
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
        	break;
        	case 2:
        		std::cout<<"Hello"<<std::endl;
        	break;
        	case 3:
        	   system("clear");
        	break;
        	case 4:
        	   system("exit");
        	break;
        	default:
        	break;


        }
}

 int main()
 {

 	mainmenu();
 	return 0;
 }

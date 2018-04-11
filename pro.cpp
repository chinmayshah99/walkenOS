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

using namespace std;


void mainmenu()
{
     abc:
     char c; // TODO, NEEDS VISIT as line 42 re-defines 'c'

        std::cout<<string(10,'\n')<<string(12, '\t')<<"Menu\n\n"<<string(10,'\t')<<"Press the number to enter the program"<<string(4,'\n');
 		std::cout << std::string(11,'\t');

 		cout<<"1.File Manager\n";
 		std::cout << std::string(11,'\t');
 		cout<<"2.Audio Player\n";
        std::cout << std::string(11,'\t');
 		cout<<"3.Logout\n";
        std::cout << std::string(11,'\t');
 		cout<<"4.Power Off\n";
 	    std::cout << string(2,'\n')<<std::string(11,'\t')<<"Input:";

        
        while(true) {
            int c;
            std::cin >>c;
            std::cin.ignore(32767, '\n');
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "\n\n" << std::string(10,'\t') <<"Input not an integer! Re-enter key";
                std::cout << std::endl;
                std::this_thread::sleep_for (std::chrono::seconds(3));
                system("clear");
                goto abc;
            }
            else break;
        }

        switch(c)
        {
        	case '1':
        	break;
        	case '2':
        	break;
        	case '3':
        	   system("clear");
        	break;
        	case '4':
        		return;
        	break;


        }
}

 int main()
 {

 	mainmenu();
 	return 0;
 }

/*

file manager

play audio

logout

power off

*/

#include <iostream>
#include <cstdlib>
#include<conio.h>

#include<time.h>

using namespace std;


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void mainmenu()
 {
     abc:
     char c;

        cout<<string(5,'\n')<<string(8,'\t')<<"Menu\n\n"<<string(6,'\t')<<"Press the number to enter the program"<<string(4,'\n');

 		std::cout << std::string(60,' ');

 		cout<<"1.File Manager\n";
 		std::cout << std::string(60,' ');
 		cout<<"2.Audio Player\n";
        std::cout << std::string(60,' ');
 		cout<<"3.Logout\n";
        std::cout << std::string(60,' ');
 		cout<<"4.Power Off\n";
 	    std::cout << string(2,'\n')<<std::string(62,' ')<<"Input:";




        while(true) {
        int c;
        std::cin >>c;
        std::cin.ignore(32767, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout <<std::string(50,' ') <<"Input not an integer! Re-enter key";
            std::cout << std::endl;
            delay(1000);
            system("cls");
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
        	   system("clr");
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

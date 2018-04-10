/*

file manager

play audio

logout

power off

*/

#include <iostream>
#include <cstdlib>
#include<conio.h>

using namespace std;

 void mainmenu()
 {

     char c;

 		cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tMenu\n\n\t\t\t\t\t\tPress the number to enter the program\n\n\n\n";

 		for (int i = 0; i < 60; ++i)
 		{
 			cout<<" ";
 		}
 		cout<<"1.File Manager\n";
 		for (int i = 0; i < 60; ++i)
 		{
 			cout<<" ";
 		}
 		cout<<"2.Audio Player\n";
 		for (int i = 0; i < 60; ++i)
 		{
 			cout<<" ";
 		}
 		cout<<"3.Logout\n";
 		for (int i = 0; i < 60; ++i)
 		{
 			cout<<" ";
 		}
 		cout<<"4.Power Off\n";


        cin>>c;
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

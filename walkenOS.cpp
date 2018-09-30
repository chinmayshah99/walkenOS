#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


#include "pro.h"
#include "login.h"

void startup();

int main() {
    startup();
    
    user();
    
    return 0;
}

void startup() 
{    
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
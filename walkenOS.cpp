
#include <iostream>
#include <chrono>
#include <thread>

void startup();

int main() {
    startup();
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
    system("play -q vista.wav");
    std::cout << std::string(100,'\n');
    std::cout << std::string(11,'\t') << "Welcome User!\n"; //full
    //std::cout << std::string(5,'\t') << "Welcome User!\n"; //split
    std::cout << std::string(22,'\n');
    std::this_thread::sleep_for (std::chrono::seconds(4));
    std::cout << std::string(100,'\n');
}





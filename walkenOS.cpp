//uncomment startup
//hello user change back to 4s

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void startup();
void user();
void submenu(int procno[],std::string proc[]);
bool if_file_exists(string file_name);
char* string_char(std::string command);

// opens the file in vim
void open_file(std::string file_name);

// renames the file
void rename_file(std::string old_file_name, std::string new_file_name);

// creates a new folder
void create_folder(std::string folder_name);

// dispay the list of files and folderes
void dispay();

// deletes the file
void delete_file(std::string file_name);

// creates a copy of file
void copy_file(std::string file_name, std::string destination_file_name);

// shell interpreter 
void shell_interpreter(std::string input);

// file manager for main integration
void file_manager();

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
    startup();
    
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
    std::cout << std::string(16,'\n');
    std::cout << std::string(11,'\t'); //full
    fstream f,f1,f2;
    int ch;
    std::string user,pass;
    std::cout<<"Enter\n\n";
    std::cout << std::string(11,'\t');
    std::cout << "1.Set Up New Account\n"<< std::string(11,'\t') <<"2.Login"<<std::endl << std::string(11,'\t') <<"3.Power Off\n"<<std::endl;
    std::cout << std::string(11,'\t'); 
    ch = getInt();
    if(ch==1)
    {
        set:
        system("clear");
        std::cout << std::string(16,'\n');
        std::cout << std::string(11,'\t'); //full
        std::string u;
        int j=0;
        
        std::cout<<"Set Up Account: "<<std::endl;
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
                        std::cout<<"Username already exists. Enter another username."<<std::endl;
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
        std::cout << std::string(16,'\n');
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
                        std::this_thread::sleep_for (std::chrono::seconds(4));
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
		std::cout<<"Press a number for executing its process"<<std::string(4,'\n');
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
				std::cout << "\n\n" << std::string(11,'\t') <<"Not a valid input! Re-enter key";
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
                std::cout << std::string(10,'\n') << std::string(9,'\t');
                std::cout << "You are now entering Shell Interpreter mode...\n\n\n";
                std::cout << std::string(9,'\t');
                std::cout << "Use commands from the documentation to perform file management operations\n\n";
                std::this_thread::sleep_for (std::chrono::seconds(5));
                system("clear");
                file_manager();
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
		std::cout<<"Enter the number to view current system status"<<std::string(4,'\n');
		std::cout << std::string(11,'\t');

		std::cout<<"1. Running Processes\n";
		std::cout << std::string(11,'\t');
		std::cout<<"2. System Memory Usage\n";
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

// check whether the given file exists
// if the file exists then returns true
// else in all cases returns false
bool if_file_exists(string file_name)
{
	try {
        ifstream in;
        in.open(file_name);
        in.exceptions(std::ifstream::failbit);
        return true;
    } catch (std::ios_base::failure &fail) {
        // handle exception here

        return false;
    }
    return false;
}

// converts the std::string to char*
char* string_char(string command)
{
	char * writable = new char[command.size() + 1];
	std::copy(command.begin(), command.end(), writable);
	writable[command.size()] = '\0'; // the terminating 0
	return writable;
}

// opens the file in vim
// checks whether the file already exists
// if it exists then opens it in vim
// else exits
void open_file(string file_name)
{
	bool check = if_file_exists(file_name);
	if(check == true)
	{
		// proceed with openning of file
		// call the vim function
		string command  = "vim " + file_name;
		system(string_char(command));
	}
	else
	{
		cout<<"error locating file"<<endl;
		return;
	}
	return;
}

// renames the file
// checks whether if there exists a  file with a new file_name
// incase it is  present, exits right-away
// else renames the file
void rename_file(string old_file_name, string new_file_name)
{
	bool check_new_exists = if_file_exists(new_file_name);
	if(check_new_exists == true)
		{
			cout<<"this file alredy exists, try some other file name"<<endl;
			return;
		}
		
	int result= rename( string_char(old_file_name) ,string_char(new_file_name));
	if ( result == 0 )
    	cout<<"File successfully renamed"<<endl;
  	else
    	cout<< "Error renaming file";
}


// cut 

// creates a new folder
void create_folder(string folder_name)
{
	string command = "mkdir " + folder_name;
	system(string_char(command));
}

// creates a new file in the current working directory and opens it
void create_file(string file_name)
{
	bool check_new_exists = if_file_exists(file_name);
	if(check_new_exists == true)
		{
			cout<<"this file alredy exists, try some other file name"<<endl;
			return;
		}
	else{	
		string command = "touch " + file_name;
		system(string_char(command));
		open_file(file_name);
	}
}

// dispay the list of files and folderes
void dispay()
{
	system("ls -a -ls");
}

// deletes the file
// checks whether the file exists
// if it exists then deletes it
// else shows an error message and exits the functions
void delete_file(std::string file_name)
{
	bool check = if_file_exists(file_name);
	if(check == true)
	{
		if( remove(string_char(file_name))== 0)
		{
			cout<<" ";
			std::cout << file_name;
			cout<<" file deleted successfully"<<endl;
		}
		else
			cout<<"couldn't delete file :("<<endl;
	}
	else
	{
		cout<<"error locating file"<<endl;
	}
	return;
}

// creates a copy of file
// checks if the soruce file exists
// checks if the destination file already exists
// if none then copies the file.
void copy_file(string file_name, string destination_file_name)
{	
	bool check = if_file_exists(file_name);
	bool check2 = if_file_exists(destination_file_name);
	if(check != true)
	{
		cout<<"error locating file"<<endl;
		return;
	}
	if(check2 != true)
	{
		cout<<"the new filea lready exists"<<endl;
		return;
	}
	else
	{
		// remember filenames
		char* infile = string_char(file_name);
		char* outfile = string_char(destination_file_name);

		// open input file 
		FILE* inptr = fopen(infile, "r");
		if (inptr == NULL)
		{
			printf("Could not open %s.\n", infile);
			return;
		}

		// open output file
		FILE* outptr = fopen(outfile, "w");
		if (outptr == NULL)
		{
			fclose(inptr);
			
			(stderr, "Could not create %s.\n", outfile);
			return;
		}

		// file copying starts, one char at a time
		char c = fgetc(inptr);
		while (c != EOF)
		{
			fputc(c, inptr);
			c = fgetc(outptr);
		}
	
		cout<<"\nContents copied to";
		std::cout<< destination_file_name<<endl;
		// closes the  file
		fclose(inptr);
		fclose(outptr);
	}
}

// splits the i/p string according to the ch specified and stores it in vector strs
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

void shell_interpreter(string input)
{
	// splits the commands and stores it in vector
	std::vector<std::string> v;
    split(input, v, ' ' );

	string command_name = v[0];
	// copy command
	if(command_name.compare("copy") == 0 )
	{
		string dest_file = v[2];
		if(dest_file.empty())
		{
			copy_file(v[1], "Copy of " + v[1]);
		}
		else
			copy_file(v[1], v[2]);
	}
	// delete command
	else if(command_name.compare("delete") == 0 )
	{
		delete_file(v[1]);
	}
	// display command
	else if(command_name.compare("display") == 0 )
	{
		dispay();
	}
	else if(command_name.compare("cfolder") == 0 )
	{
		create_folder(v[1]);
	}
	else if(command_name.compare("cfile") == 0 )
	{
		create_file(v[1]);
	}
	else if(command_name.compare("rename") == 0 )
	{
		string dest_file = v[2];
		if(dest_file.empty() || v[1].empty())
		{
			cout<<"provide name of the file"<<endl;
		}
		else{
			rename_file(v[1], v[2]);
		}
	}
	else if(command_name.compare("open") == 0 )
	{
		open_file(v[1]);
    }
	else
	{
		system(string_char(input));
	}	
}

void file_manager()
{
    while(true){
        string user_input;
        getline(cin,user_input);
        if(user_input.compare("exitsi") == 0)
            return;
        else
            shell_interpreter(user_input);
    }
}
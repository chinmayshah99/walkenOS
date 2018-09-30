// validates whehter file exists and then deletes it

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <algorithm>

#include "file.h"

using namespace std;

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

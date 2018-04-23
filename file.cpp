// validates whehter file exists and then deletes it

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;

// check whether the given file exits
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
		
	result= rename( string_char(old_file_name) ,string_char(new_file_name));
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

// dispay the list of files and folderes
void dispay()
{
	system("ls -a -ls")
}

// deletes the file
// checks whether the file exists
// if it exists then deletes it
// else shows an error message and exits the functions
void delete_file(string file_name)
{
	bool check = if_file_exists(file_name);
	if(check == true)
	{
		if( remove(string_char(file_name))== 0);
			cout<<" "<<file_name<<" file deleted successfully"<<endl;
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
	
		cout<<"\nContents copied to"<<destination_file_name;
		// closes the  file
		fclose(inptr);
		fclose(outptr);
	}
}

void shell_interpreter(string input)
{
	if(input[0] )
}

#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <cstring>

using namespace std;

// check whether the given file exists
bool if_file_exists(string file_name);

// converts the std::string to char*
char* string_char(string command);

// opens the file in vim
void open_file(string file_name);

// renames the file
void rename_file(string old_file_name, string new_file_name);

// creates a new folder
void create_folder(string folder_name);

// dispay the list of files and folderes
void dispay();

// deletes the file
void delete_file(string file_name);

// creates a copy of file
void copy_file(string file_name, string destination_file_name);

// shell interpreter 
void shell_interpreter(string input);

// file manager for main integration
void file_manager()

#endif


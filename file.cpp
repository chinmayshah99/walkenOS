#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

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


void open_file(string file_name)
{
	bool check = if_file_exists(file_name);
	if(check == true)
	{
		// proceed with openning of file
		// call the vim function
	}
	else
	{
		cout<<"error locating file"<<endl;
		return;
	}
	return;
}


void delete_file(string file_name)
{
	bool check = if_file_exists(file_name);
	if(check == true)
	{
		// calling 
		string delete_command = "rm "+ file_name;
		//system(delete_command);
		cout<<" "<<file_name<<" file deleted successfully"<<endl;
	}
	else
	{
		cout<<"error locating file"<<endl;
	}
	return;
}


int main(int argc, char const *argv[])
{
	// fopen check for if file exists and then move 
	// if not then go back to previous menu 

	std::string file_name_1;
	std::cin>>file_name_1;
	open_file(file_name_1);

	// delete file 
	// eror checking and use 
	// system calls to delete 

	delete_file(file_name_1);


	




	return 0;
}

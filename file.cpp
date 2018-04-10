#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;



bool if_file_exists(string file_name)
{
	try {
        ifstream in(file_name);
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
	bool check = if_file_exists("fcfs");
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
	bool check = if_file_exists("fcfs");
	if(check == true)
	{
		// calling 
		string delete_command = "rm ";
		strcat(delete_command,file_name);
		system(delete_command);
		cout<<" "<<file_name<<" file deleted successfully"<<endl;
	}
	else
	{
		cout<"error locating file"<<endl;
	}
	return;
}


int main(int argc, char const *argv[])
{
	/* code */


	// fopen check for if file exists and then move 
	// if not then go back to previous menu 


	open_file("fcfs");
	delete_file("fcfs");





	// delete file 
	// eror checking and use 
	// system calls to delete 




	return 0;
}

#include <iostream>
#include <fstream.h>
#include <stdlib.h>
using namespace std;
int main (int argc, char **argv)
{
	char buffer[256];
	ifstream in("input");
	if(!in.is_open())
	{
		exit(1);	
	}
	while(!in.eof()) {
		in.getline(buffer, 2)
		cout << buffer <<endl;
	}
	return 0;
}

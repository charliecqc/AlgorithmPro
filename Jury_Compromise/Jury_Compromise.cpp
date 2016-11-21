#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string.h>
#include <list>
using namespace std;
/*Global varibles*/

class Pair 
{
public:
	int p;
	int d;
	Pair(int a, int b)
	{
		p = a;
		d = b;
	}
};

typedef list <class Pair > UDT_LIST_INT_INT;
UDT_LIST_INT_INT pairs; /*<di, pi>*/
vector <UDT_LIST_INT_INT> container;/*for store all pairs in each round */


int readInput(char *path);

int main ()
{
	char *path = "input";
	int r = readInput(path);
	UDT_LIST_INT_INT::iterator i;
	for(i = pairs.begin(); i != pairs.end(); ++i) {
		cout << i->p << " " << i->d << endl;
	}
	return r;
}

int readInput(char *path) 
{
	int r = 0;
	fstream file;
	char buffer[4];
	file.open(path, ios::in);
	if(file.fail()) {
		cout << "file does't exist" << endl;
		file.close();
		r = -1;
		return r;
	}else {	
		while(!file.eof()) {
			file.getline(buffer, 4, '\n');
			if(!strlen(buffer)) {
				class Pair one(0,0);
				pairs.push_back(one);
				continue;
			}
			else {
				class Pair one(buffer[0] - '0', (int)buffer[2] - '0');
				pairs.push_back(one);
			}
			
		}
	}
	file.close();
	return r;
}

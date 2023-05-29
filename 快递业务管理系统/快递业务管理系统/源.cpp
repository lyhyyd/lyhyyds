#include<iostream>
#include<iomanip>
#include<fstream>
#include"express.h"
using namespace std;
int main()
{

	menu();
	express* head;
	head = creat();
	zhixing(head);
	save(head);
}
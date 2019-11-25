// StackImplementation.cpp : Defines the entry point for the console application.
//
#include "LinkedQueue.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	std::ifstream myFile;
	myFile.open("names.txt");
	QueueType<int> *queue1;
	queue1 = new QueueType<int>;
	QueueType<string> *queue2;
	queue2 = new QueueType<string>;
	string temp;
	
	for(int i = 0 ; i<15 ; i++)
	{
		myFile>>temp;
		queue1->Enqueueu(i*i);
		queue2->Enqueueu(temp);
	}
	for(int i = 0; i<15 ;i++)
	{
		cout<<queue1->RetrieveItem(i)<<endl;
	
	}
	for(int i = 0; i<15 ;i++)
	{
		cout<<queue2->RetrieveItem(i)<<endl;
	
	}
	cout<<"Size of the queue1 is "<<queue1->size()<<endl;
	queue1->MakeEmpty();
	cout<<"Size of the queue1 after MakeEmpty method is "<<queue1->size()<<endl;
	for(int i = 0; i<10 ;i++)
	{
		queue2->Dequeue();
	}

	for(int i = 0; i<5 ;i++)
	{
		cout<<queue2->RetrieveItem(i)<<endl;
	}
	return 0;
}


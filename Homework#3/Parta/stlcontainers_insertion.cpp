#include <stdio.h>
#include <stdlib.h>

int temp = 0 ;
int i = 0 ;


for( int j = 1 ; j < mymap.size() ; j++ )
{
	temp = mymap[j];
	i = j -1 ;

	while(i > 0 && mymap[i] > temp)
	{
		mymap[i+1] = mymap[i];
		i = i -1 ;
	}
	mymap[i + 1] = temp;

}


// useful stl containers 

stack<int> mystack ;

mystack.size() ; mystack.push(number); mystack.pop(); mystack.empty() ; my stack.top() // to access top element LIFO

queue<int> myqueue;

myqueue.push( number ); // in the back ( the beginning)
myqueue.front();   myqueue.back();

vector<int> myvector;
myvector.push_back(number);

map<int, string> mymap;
mymap[0] = "hello";

// or we can do this 
for( int i = 0 ; i < value.size(); i++)
mymap[i] = value[i];

int myarray[5];

int size = sizeof(myarray);









#include <iostream>
#include <vector>
#include "CuckooHashTable.h"

using namespace std;

CuckooHashTable::CuckooHashTable(){
	vector<string> T1 (LOGICAL_SIZE);
	vector<string> T2 (LOGICAL_SIZE);
	contents.push_back(vector<string> (T1));
	contents.push_back(vector<string> (T2));
	this->currentSize = 0 ;
}


void CuckooHashTable::add(string value)
{ 
		


	 static int which = 0;
		
	int times_rehashed = 0;	
	string temp;

	which = 0 ;

	

while(true)
{

	

		if ((contents[which][hashCode(value,which)]).empty() == true)
			{
				contents[which][hashCode(value,which)] = value ;
				currentSize++;	
				break;			
			}

		else 
			{	
			  														// NEED: figure out how to default first time hashing use h1 
						
					temp = contents[which][hashCode(value,which)];				// swap old num with new num
					contents[which][hashCode(value,which)] = value;
					
					if(which == 1)
				  {
				  	which = 0;
				  }
			  		else
				  {
				  	which = 1 ;
				  	}	

					if((contents[which][hashCode(temp,which)]).empty() == true)
					{	
						contents[which][hashCode(temp,which)] = temp;
						currentSize++;
						break;
						//which = 0;
						}				// this which is the table
					else
					{
						//cout<< " rehashed once " << endl ;
							if(times_rehashed == currentSize)
								{
							cout << "Error hashtable is caught in an infinite loop\n" << endl;
							exit(EXIT_FAILURE);
						}	
					
						times_rehashed++;

						
						//add(value);
					
					}


					

			}

			
}
	
}

int CuckooHashTable::hashCode(string value, int which)
{
	

	int h1 = 0;
	int h2 = 0; 
	int number = stoi(value);	

		if (which == 1)
		{
			h2 = 11-(number%11);
			return h2;
		}

	else
		{
			h1 = number%13;
			return h1;

		} 

		
}





void CuckooHashTable::print()
{


cout << "Table 1:" << endl ;
for(int i = 0 ; i < 13 ; i++)
	{

	if(contents[0][i].empty() == true)
		cout<< "-" << endl;
	else
		cout << contents[0][i] << endl;

	}


cout << "Table 2:" << endl ;
for(int i = 0 ; i < 13 ; i++)
	{
	
	if(contents[1][i].empty() == true)
		cout<< "-" << endl;
	else
		cout << contents[1][i] << endl;

	}	




}
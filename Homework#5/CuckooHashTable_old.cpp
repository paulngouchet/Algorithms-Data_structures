#include <iostream>
#include <vector>
#include "CuckooHashTable.h"

using namespace std;

CuckooHashTable::CuckooHashTable(){
	vector<string> T1 (LOGICAL_SIZE);
	vector<string> T2 (LOGICAL_SIZE);
	contents.push_back(vector<string> (T1));
	contents.push_back(vector<string> (T2));
}


void CuckooHashTable::add(string value)
{ 
		


	int which = 0;
		
	int times_rehashed;	
	string temp;
	bool stored = false;



	while(stored == false){

		if ((contents[which][hashCode(value,which)]).empty() == true)
			{
				contents[which][hashCode(value,which)] = value ;
				stored = true;
			}

		else if((contents[which][hashCode(value,which)]).empty() == false)
			{


				
																				// NEED: figure out how to default first time hashing use h1 
						
					temp = contents[which][hashCode(value,which)];				// swap old num with new num
					contents[which][hashCode(value,which)] = value;
					which = 1;	
					if((contents[which][hashCode(value,which)]).empty() == true)
					{	
						contents[which][hashCode(temp,which)] = temp;
						}				// this which is the table
					else
					{
					temp = contents[which][hashCode(value,which)];				// swap old num with new num
					contents[which][hashCode(value,which)] = value;
					which = 0;
					contents[which][hashCode(temp,which)] = temp;	

					}


					stored = true ;
					times_rehashed++;

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
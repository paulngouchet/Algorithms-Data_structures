#include <iostream>
#include <vector>
#include <string>
#include <map>
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
		
	
	int line_num;						
	int number = stoi(value);								
	int collisions = 0;					
	int num[2] = {number, collisions}
	static map<int ,int* > coll_map;
	coll_map[line_num] = num;			// Set coll_map keys of line numbers to give each number uniq collision number (account duplicate inputs). 
										//    The values = num[2] num[1] = number and num[2] = number's collisions. Number of collisions dictate hash 
										//	  function. 

	int table;							// designate table to Set value to. 

	static int num_stored = 0;			// detect infintie while loop
	int times_rehashed = 0;	

	string temp;
	bool stored = false;



	while(stored == false){

		

		if ((contents[which][hashCode(value,which)]).empty() == true)
			{
				contents[which][hashCode(value,which)] = value ;
				stored = true;
				num_stored++;
			}

		else if((contents[which][hashCode(value,which)]).empty() == false)
			{
					// switch(coll_map[value]){
					// 	case 2%2:

					// 	case
					// }
					
					if(times_rehashed == num_stored){
						cout << "Error hashtable is caught in an infinite loop\n" << endl;
						exit(EXIT_FAILURE);
					}												

					temp = contents[which][hashCode(value,which)];	// swap old num with new num (for two more collisions in a row use 
					//   add to move collidied into number)	
					contents[which][hashCode(value,which)] = value;
					which = 1;		
					contents[which][hashCode(temp,which)] = temp;				// this which is the table

					stored = true ;
					times_rehashed++;	
					

			}

	}

	line_num++;

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

#include <string>
#include <fstream>
#include "Pangram.h"
#include <algorithm>


 vector<Pangram*> vec_pangram;



 struct compare {
    bool operator()( Pangram* first,  Pangram* second) {
        return first->size() < second->size();
    }
};



void ispangram(string &str)
{
	int count = 0 ;
	  vector<bool> used(26, false);
 
    int index;
int length = str.length() ;
    int actualstart = 0;
     int actualend = 0 ;
int a = 0 ;
int b = 0  ;


    while( true )
    {
 
    for (int i=actualstart; i<length; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';
 
        
        else if('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
 
        
        used[index] = true;



         for (int j=0; j<=25; j++)
	         {
	        if (used[j] == false)
	        {	
	        	count = 0 ;
	          	break;
	          }

	          count++;

	            }
	           
	      if( count == 26)
		      {
		      	
		      	count = 0 ;
		      	actualend = i;
		      	
		      	Pangram* pangram = new Pangram(actualstart , actualend);
		      	vec_pangram.push_back(pangram);
		     
		     for(int z = 0 ; z < used.size() ; z++)
		     	used[z] = false ;


		      	break;
		      
	    }

	    b = i ;
	   
	}
		

    for (int i= (actualend+1) ; ; i--)
    {
    	
        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';
 
        
        else if('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
 
        
        used[index] = true;

      

         for (int j=0; j<=25; j++)
	         {
		        if (used[j] == false)
		        {	
		        	count = 0 ; 
		          	break;
		          }

		          count++;

		            }
		  
	      if( count == 26)
			      {
			      	count = 0 ;
			      
			      	actualstart = i + 1;
			  	
			      	Pangram* pangram = new Pangram(i, actualend);
			      vec_pangram.push_back(pangram);
			        
		     for(int z = 0 ; z < used.size() ; z++)
		     	used[z] = false ;

			      	break;
			      
		    }


}
a = b;


			if(vec_pangram.size() > 3)
			{
			if( ((vec_pangram[vec_pangram.size() - 1]->first) == (vec_pangram[vec_pangram.size() - 3]->first) )&& ((vec_pangram[vec_pangram.size() - 1]->end) == (vec_pangram[vec_pangram.size() - 3]->end) )  )
				break;
	}

if( actualend == (length - 1) )
	break;



}




    }
 


int main()
{

	string line;
  ifstream myfile ("BigData.txt");
     getline (myfile,line) ;
       
    myfile.close();

    ispangram(line);


/*for(int i = 0 ; i < vec_pangram.size() ; i++)
{
	cout<< "pangram " << i << endl ;
	vec_pangram[i]->content();
}*/

compare c;
sort(vec_pangram.begin(), vec_pangram.end(), c);

 cout<< "size of pangram is " << vec_pangram[0]->size() << endl;

for(int i = vec_pangram[0]->first ; i <= vec_pangram[0]->end ; i++)
	cout<< line[i] ;

cout<< endl ;
}



























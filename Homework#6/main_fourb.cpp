#include "Trie.h"
#include <fstream>
#include <map>


int main()
{


 string line;
  ifstream myfile ("words1.txt");
     getline (myfile,line) ;
       
    myfile.close();


    vector< map<int, int> > vec_map(26);


int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
a = 0 ;b = 0 ;c = 0 ;d = 0 ;e = 0 ;f = 0 ;g= 0 ; h = 0 ;i = 0 ;j = 0 ;k = 0 ;l = 0 ;
m = 0 ;n = 0 ;o = 0 ;p = 0 ;q = 0 ;r = 0;s= 0 ;t = 0; u = 0 ;v = 0 ; w = 0; x = 0; y = 0; z=0;
 

for( int i = 0 ; i < line.length() ; i++)
{
	if(line[i] == 'a' || line[i] == 'A' )
	{
		vec_map[0][a] = i ;
		a++;
		}

		else if(line[i] == 'b' || line[i] == 'B' )
	{
		vec_map[1][b] = i ;
		b++;
		}

		else if(line[i] == 'c' || line[i] == 'C' )
	{
		vec_map[2][c] = i ;
		c++;
		}


	else if(line[i] == 'd' || line[i] == 'D' )
	{
		vec_map[3][d] = i ;
		d++;
		}

		else if(line[i] == 'e' || line[i] == 'E' )
	{
		vec_map[4][e] = i ;
		e++;
		}

		else if(line[i] == 'f' || line[i] == 'F' )
	{
		vec_map[5][f] = i ;
		f++;
		}


	else if(line[i] == 'g' || line[i] == 'G' )
	{
		vec_map[6][g] = i ;
		g++;
		}

		else if(line[i] == 'h' || line[i] == 'H' )
	{
		vec_map[7][h] = i ;
		h++;
		}

		else if(line[i] == 'i' || line[i] == 'I' )
	{
		vec_map[8][a] = i ;
		i++;
		}


	else if(line[i] == 'j' || line[i] == 'J' )
	{
		vec_map[9][j] = i ;
		j++;
		}

		else if(line[i] == 'k' || line[i] == 'K' )
	{
		vec_map[10][k] = i ;
		k++;
		}

		else if(line[i] == 'l' || line[i] == 'L' )
	{
		vec_map[11][l] = i ;
		l++;
		}


	else if(line[i] == 'm' || line[i] == 'M' )
	{
		vec_map[12][m] = i ;
		m++;
		}

		else if(line[i] == 'n' || line[i] == 'N' )
	{
		vec_map[13][n] = i ;
		n++;
		}

		else if(line[i] == 'o' || line[i] == 'O' )
	{
		vec_map[14][o] = i ;
		o++;
		}


	else if(line[i] == 'p' || line[i] == 'P' )
	{
		vec_map[15][p] = i ;
		p++;
		}

		else if(line[i] == 'q' || line[i] == 'Q' )
	{
		vec_map[16][q] = i ;
		q++;
		}

		else if(line[i] == 'r' || line[i] == 'R' )
	{
		vec_map[17][r] = i ;
		r++;
		}


	else if(line[i] == 's' || line[i] == 'S' )
	{
		vec_map[18][a] = i ;
		a++;
		}

		else if(line[i] == 't' || line[i] == 'T' )
	{
		vec_map[19][a] = i ;
		a++;
		}

		else if(line[i] == 'u' || line[i] == 'U' )
	{
		vec_map[20][u] = i ;
		u++;
		}



	else if(line[i] == 'v' || line[i] == 'V' )
	{
		vec_map[21][v] = i ;
		v++;
		}

		else if(line[i] == 'w' || line[i] == 'W' )
	{
		vec_map[22][w] = i ;
		w++;
		}

		else if(line[i] == 'x' || line[i] == 'X' )
	{
		vec_map[23][x] = i ;
		x++;
		}


		else if(line[i] == 'y' || line[i] == 'Y' )
	{
		vec_map[24][y] = i ;
		y++;
		}


	
		else if(line[i] == 'z' || line[i] == 'Z' )
	{
		vec_map[25][z] = i ;
		z++;
		}


}

/*for( int i = 0 ; i < 26 ; i++)
{
	for( int a = 0 ; a < vec_map[i].size() ; a++)
		cout << i << "  " << vec_map[i][a] << endl ;
}*/

   Trie* trie = new Trie();
    trie->addWord("Hello");
    trie->addWord("Balloon");
    trie->addWord("Ball");


  return 0;
}



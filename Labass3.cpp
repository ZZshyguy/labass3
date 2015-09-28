#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

/*
Zachary Lapointe
Assignment 3:
Read a file and make a dictionary of words found
*/

const int ROW = 5;
const int COL = 20;

int main() {

	char ch;
	int newLine= 0;
	char dic[ROW][COL]; //char array with 5 rows and 20 columns
	// cout<<a[0]; will print string in first row (array) of a
	// for(i=0;i< NewWords; i++) cout<<a[i]<<endl; will print strings in the rows (arrays) of a
	int len = 0;
	char buffer[256]; // collect the word in a buffer, LEN is its length STRLEN(buffer); will return a length
	int NumWords; //number of words in dictionary
	int CNT[ROW]; //number of each individual words in dictionary
	/*
	int i;
	for(i=0;i<NumWords;i++)
		if(!strcmp(a[i],buffer)){CNT[i]++;break;}; //Compares word in buffer to words in dictionary
	if(i==NumWords){addwordto a[NumWords]; NumWords++;} //if word not found put it into array
	*/
	
	while( cin.good() )
	{
	 ch = cin.get();
	 if ( isalpha(ch) )  // function test is ch  is A-Z or a-z, then prints chars
	    {
	       buffer[len++] = ch;
	       newLine = 1;
	    }
	 else
	       if (newLine) //were you making a word? if word is over end line
		  {
		      if(!searchDic(buffer, dic)){ //Write searchDic
			addwordto(dic[NumWords], buffer); //Write addwordto
			NumWords++;
		      }
		      len = 0;	
		      newLine = 0;
		  }
	}
	outputDic(dic, CNT); //Write outputDic
	return 0;
}


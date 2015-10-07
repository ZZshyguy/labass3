#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

/*
Zachary Lapointe
CS2010
Assignment 3:
Read a file and make a dictionary of unique words found
Has space for 10 unique words (ROW)
Words can be up to 20 characters
*/

const int ROW = 10;
const int COL = 20;
int NumWords = 0; 	//number of words in dictionary
int CNT[ROW]; 		//number of each individual words in dictionary
char dic[ROW][COL]; 	//char array with 5 rows and 20 columns
int count = 0;		//Count of words not able to be put into dictionary

int searchDic(char *buffer)	//Search dictionary for buffer, returns a 1 if found
{

	int found = 0;
	int i;
	for(i=0;i<NumWords;i++)
		if(!strcmp(dic[i],buffer))	//strcmp() returns 0 if they are equal
		{
			CNT[i]++;
			found = 1;
			break;
		};
	return found;

}

void addwordtoDic(char *buffer)	//Add word to dictionary
{

	if(NumWords<ROW){
		strcpy(dic[NumWords],buffer);
		CNT[NumWords] = 1;
		NumWords++;
	}
	else{
		count++;
	}
	
}

void outputDic(void) 	//Displays words in dictionary and the count of how many times that word appeared, also prints count of words not included
{

	cout<<"Word              Frequency"<<endl;
	cout<<"---------------------------"<<endl;

	//for(int i=0;i< NumWords; i++) cout<<dic[i]<<"    "<<CNT[i]<<endl; Alternate printing method (not formatted)
	for(int i=0; i<ROW; i++)
	{
	cout<<dic[i];
	for(int j=0; j< 20- strlen(dic[i]); j++) cout<< ' ';	//This will print a fixed amount of spaces based off length of word
	cout<<CNT[i]<<endl;
	}

	cout<<endl<<"Number of words not included =    "<<count<<endl;

}

int main() {

	char ch;
	int newLine = 0;
	int len = 0;		//Length of word collected in buffer
	char buffer[256]; 	//collect the word in a buffer, len is its length or STRLEN(buffer); will return length
	
	while( cin.good() )
	{
	 ch = cin.get();
	 if ( isalpha(ch) )  	// function test is ch  is A-Z or a-z, then prints chars
	    {
	       buffer[len++] = ch;
	       newLine = 1;
	    }
	 else
	       if (newLine) 	//were you making a word? if word is over end line
		  {
		      buffer[len] = '\0';	//Makes buffer a c style string
		      if(strlen(buffer)>19){	//Checks word length
		        cout<<"Word too long"<<endl;
			count++;
		      }
		      else{
			      if(!searchDic(buffer)){ 			
				addwordtoDic(buffer); 	
			      }
		      }
		      len = 0;	
		      newLine = 0;
		  }
	}
	outputDic(); 
	return 0;
}


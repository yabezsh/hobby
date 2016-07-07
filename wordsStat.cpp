#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
typedef std::map<std::string, int> StrIntMap;

using namespace std;

vector<pair<char, int> > sort(StrIntMap dict){
	vector<pair<char, int> > dictVect;//{dict.begin(),dict.end()};
	for(StrIntMap::iterator it=dict.begin();it!=dict.end();++it)
	{
//		dictVect.push_back(*it);
	}
	
} 


void noCharact(string str, vector<string>& vect){
	vect.clear();
	
	char *cstr=new char[str.length()+1];
	strcpy(cstr,str.c_str());
	for(char *ptr=strtok(cstr," ,.-:");ptr!=NULL;ptr=strtok(NULL," ,.-:")){
		vect.push_back(ptr);
	}	
	if(vect.empty()){ vect.push_back(str);}
}


string convertToLower(string str)
{
	for(int iStr=0;iStr<str.length();iStr++)
	{	
		if(str[iStr] != ' ')
		{
			str[iStr]=tolower(str[iStr]);
		}
	}
	return str;
}

void countWords(ifstream& file, map<string,int>& dict)
{
	string s;
	vector<string> separatedWords;
	while(file>>s){
		s = convertToLower(s);
		noCharact(s,separatedWords);
		for(vector<string>::size_type it = 0; it!=separatedWords.size(); ++it){
			++dict[separatedWords[it]];
}
}
}

int main(){
	map <string,int> dictionary;
	string line;
	ifstream bookFile;
	bookFile.open("book.txt");
	if(bookFile.is_open()){
		while(getline(bookFile,line))
		{	
		countWords(bookFile,dictionary);
		}
	}
	else cout<<"Unable to open file" <<endl;
	bookFile.close();
	
	for(StrIntMap::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
		cout<<it->first<<" occured "<<it->second<<" times. \n";
	}
}

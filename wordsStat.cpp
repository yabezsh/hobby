#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>	// for sort() function
#include <iterator>
typedef std::map<std::string, int> StrIntMap;
typedef std::pair<std::string, int> PairVect;
//typedef std::istream_iterator<char> istream_iterator;

using namespace std;

vector<string> readFileToVector()
{
	ifstream fileOfknownWords("my_vocabluary.txt");
        vector<string> inputWords;
	fileOfknownWords >> skipws;
	copy(istream_iterator<string>(fileOfknownWords),istream_iterator<string>() ,back_inserter(inputWords));
	return inputWords;
}

bool checkWord(vector<string> words, const char* search)
{	
	bool inVocab;
	if(find(words.begin(),words.end(),search)!=words.end()){inVocab=1;}
	else{inVocab=0;}
	return inVocab;        
}



//we create template class. That means we should not define some specific type as input for function. but when we call this class (structure) we should define in <> brackets which type of inputs will be there.
template<class T>
struct less_second : std::binary_function<T,T,bool>
{
	inline bool operator()(const T& lhs,const T& rhs)
	{
		return lhs.second > rhs.second;
	}
};


void writeStatToFile( const std::vector<PairVect>& vec )
{
    ofstream output_file;
    output_file.open("wordsAnalysis.txt");
    for ( vector<PairVect>::const_iterator vec_it = vec.begin(); vec_it != vec.end(); vec_it++ )
    {
        output_file<< (*vec_it).second << " "
                  << (*vec_it).first   << std::endl;
    }
    output_file.close();
}

vector<PairVect > sort_by_weight(StrIntMap& s_map)
{
	std::vector<PairVect> vec(s_map.begin(), s_map.end());
	std::sort(vec.begin(),vec.end(),less_second<PairVect>());
	return vec;
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

void countWords(ifstream& file, map<string,int>& dict, vector<string> my_vocabluary)
{
	string s;
	vector<string> separatedWords;
	while(file>>s){
		s = convertToLower(s);
		noCharact(s,separatedWords);
		for(vector<string>::size_type it = 0; it!=separatedWords.size(); ++it){
			if(checkWord(my_vocabluary,separatedWords[it].c_str())==1) continue;
			++dict[separatedWords[it]];
}
}
}

int main(){
	map <string,int> dictionary;
	string line;
	const char* a = "five";
	ifstream bookFile;
	vector<PairVect> sortedWords;
	vector<string> my_vocabluary;
	my_vocabluary=readFileToVector();
	bookFile.open("book.txt");
	if(bookFile.is_open()){
		while(getline(bookFile,line))
		{	
		 countWords(bookFile,dictionary,my_vocabluary);
		}
	}
	else cout<<"Unable to open file" <<endl;
	bookFile.close();
	sortedWords=sort_by_weight(dictionary);
	writeStatToFile(sortedWords);
	for(StrIntMap::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
		cout<<it->first<<" occured "<<it->second<<" times. \n";
	}
}

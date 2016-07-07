#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>	// for sort() function
typedef std::map<std::string, int> StrIntMap;
typedef std::pair<std::string, int> PairVect;

using namespace std;


//we create template class. That means we should not define some specific type as input for function. but when we call this class (structure) we should define in <> brackets which type of inputs will be there.
template<class T>
struct less_second : std::binary_function<T,T,bool>
{
	inline bool operator()(const T& lhs,const T& rhs)
	{
		return lhs.second > rhs.second;
	}
};


void PrintSorted( const std::vector<PairVect>& vec )
{
    std::vector<PairVect>::const_iterator vec_it = vec.begin();
    std::cout << std::endl;
    for ( ; vec_it != vec.end(); vec_it++ )
    {
        std::string s = (*vec_it).first;
        double weight = (*vec_it).second;
        std::cout << s << " "
                  << weight   << std::endl;
    }
}

vector<PairVect > sort_by_weight(StrIntMap& s_map)
{
	std::vector<PairVect> vec(s_map.begin(), s_map.end());
	std::sort(vec.begin(),vec.end(),less_second<PairVect>());
	PrintSorted(vec);
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
	sort_by_weight(dictionary);
	for(StrIntMap::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
		cout<<it->first<<" occured "<<it->second<<" times. \n";
	}
}

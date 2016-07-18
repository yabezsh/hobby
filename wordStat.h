#ifndef WORDSTAT_H
#define WORDSTAT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>    // for sort() function
#include <iterator>

using namespace std;
typedef std::map<std::string, int> StrIntMap;
typedef std::pair<std::string, int> PairVect;

class WordStat
{
   public:
	WordStat(){};
	std::vector<std::string> readFileToVector(const char* fileName = "my_vocabluary.txt");
	bool checkWord(std::vector<std::string> words, const char* search);
	void writeStatToFile(const std::vector<PairVect>& vec,const char* fileName = "wordsAnalysis.txt",bool justWords=1);
	std::vector<PairVect > sort_by_weight(StrIntMap& s_map);
        void noCharact(std::string str, std::vector<std::string>& vect);
	std::string convertToLower(std::string str);
	void countWords(ifstream& file, std::map<std::string,int>& dict, std::vector<std::string> my_vocabluary);
	
};
#endif

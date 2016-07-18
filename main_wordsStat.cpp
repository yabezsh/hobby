#include "wordStat.h"
int main(int argc, char* argv[]){
         if (argc < 2) {
                std::cerr << "Usage: " << argv[0] << " <name of analysed file in .txt format>" << std::endl;
                return 1;
         }
        const char* bookName = argv[1];
        map <string,int> dictionary;
        string line;
        ifstream bookFile;
        vector<PairVect> sortedWords;
        vector<string> my_vocabluary;
	WordStat wordsWork;
        my_vocabluary=wordsWork.readFileToVector();
        bookFile.open(bookName);
        if(bookFile.is_open()){
                while(getline(bookFile,line))
                {       
                 wordsWork.countWords(bookFile,dictionary,my_vocabluary);
                }
        }
        else cout<<"Unable to open file" <<endl;
        bookFile.close();
        sortedWords=wordsWork.sort_by_weight(dictionary);
        wordsWork.writeStatToFile(sortedWords);
        wordsWork.writeStatToFile(sortedWords,"listOfwordsForQT.txt",1);
        for(StrIntMap::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
//                cout<<it->first<<" occured "<<it->second<<" times. \n";
      }
}

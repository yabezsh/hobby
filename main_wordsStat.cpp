#include "wordsStat.cpp"
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
        my_vocabluary=readFileToVector();
        bookFile.open(bookName);
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

#include "question.h"
Question::Question(QWidget *parent) : QWidget(parent)
{
	question = new QLabel("test",this);
	question->setGeometry(450,100,1500,500);
	ListOfWords(translation);
}

void Question::ListOfWords(std::vector<std::string> &translation){
	WordStat bookAnal;
        translation=bookAnal.readFileToVector("../listOfwordsForQT.txt");
        }

void Question::GetListOfWords(std::vector<std::string> &translation){
        ListOfWords(translation);
}


#include "question.h"
#include <iostream>
Question::Question(QWidget *parent) : QWidget(parent)
{
	ListOfWords(translation);
	questionNumber = rand()%translation.size();
	question = new QLabel(translation[questionNumber].c_str(),this);
	question->setGeometry(450,100,1500,500);
}

void Question::ListOfWords(std::vector<std::string> &translation){
	WordStat bookAnal;
        translation=bookAnal.readFileToVector("../listOfwordsForQT.txt");
        }

void Question::GetListOfWords(std::vector<std::string> &translation){
        ListOfWords(translation);
}


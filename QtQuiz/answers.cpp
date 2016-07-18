#include "answers.h"
#include <iostream>
using namespace std;
Answers::Answers(QWidget *parent) : QWidget(parent)
{
 Question question;
 vector<string> translation;
 question.GetListOfWords(translation);
 for(int iAns=0;iAns<4;iAns++)
 {
  const char* c=translation[rand()%translation.size()].c_str();
  answer[iAns]= new QPushButton(c,this);
  if (iAns%2==0) {answer[iAns]->setGeometry(QRect(QPoint(250, 400+iAns*25), QSize(200, 50)));}
  else {answer[iAns]->setGeometry(QRect(QPoint(450, 400+(iAns-1)*25), QSize(200, 50)));}
 }
}
void Answers::ListOfAnswers(vector<string> &translation){
//	translation=readFileToVector("../listOfwordsForQT.txt");
	}

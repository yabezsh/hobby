#include "answers.h"
#include <iostream>
#include "../wordsStat.cpp"
using namespace std;
Answers::Answers(QWidget *parent) : QWidget(parent)
{
 for(int iAns=0;iAns<4;iAns++)
 {
  vector<string> translation;
  ListOfAnswers(translation);
  const char* c=translation[rand()%100].c_str();
  answer[iAns]= new QPushButton(c,this);
  if (iAns%2==0) {answer[iAns]->setGeometry(QRect(QPoint(250, 400+iAns*25), QSize(200, 50)));}
  else {answer[iAns]->setGeometry(QRect(QPoint(450, 400+(iAns-1)*25), QSize(200, 50)));}
 }
}
void Answers::ListOfAnswers(vector<string> &translation){
	translation=readFileToVector("../listOfwordsForQT.txt");
	}

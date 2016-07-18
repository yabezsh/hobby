#include "answers.h"
#include <iostream>
using namespace std;
Answers::Answers(int questionNumber,QWidget *parent) : QWidget(parent)
{
 Question question;
 vector<string> translation;
 question.GetListOfWords(translation);
 rightAnswer=rand()%3;
 for(int iAns=0;iAns<4;iAns++)
 {
  if(iAns==rightAnswer){answer[iAns]= new QPushButton(translation[questionNumber].c_str(),this);}
  else{answer[iAns]= new QPushButton(translation[rand()%translation.size()].c_str(),this);}
  if (iAns%2==0) {answer[iAns]->setGeometry(QRect(QPoint(250, 400+iAns*25), QSize(200, 50)));}
  else {answer[iAns]->setGeometry(QRect(QPoint(450, 400+(iAns-1)*25), QSize(200, 50)));}
 }
}

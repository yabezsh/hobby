#ifndef ANSWERS_H
#define ANSWERS_H
#include <string>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "question.h"
class QPushButton;
class Answers : public QWidget
{
   Q_OBJECT
   public:
	explicit Answers(int questionNumber,QWidget *parent);
	void setName(int buttonNumber=0,const char* textName="" ){answer[buttonNumber]->setText(textName);}
   signals:
   private slots:
   private:
	QPushButton *answer[4];
	int rightAnswer;
};
#endif // ANSWERS_H

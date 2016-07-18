#ifndef QUESTION_H
#define QUESTION_H
#include <QLabel>
#include <vector>
#include "../wordStat.h"
class QLabel;
class Question : public QWidget
{
   Q_OBJECT
   public:
	explicit Question(QWidget *parent);
	Question(){};
	void GetListOfWords(std::vector<std::string> &translation);
	int GetQuestionNumber(){return questionNumber;}
   private:
	QLabel *question;
	std::vector<std::string> translation;
	void ListOfWords(std::vector<std::string>& translation);
	int questionNumber;
};

#endif

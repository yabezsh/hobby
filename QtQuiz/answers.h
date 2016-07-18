#ifndef ANSWERS_H
#define ANSWERS_H
#include <string>
#include <QLabel>
#include <QPushButton>
#include <vector>
class QPushButton;
class Answers : public QWidget
{
   Q_OBJECT
   public:
	explicit Answers(QWidget *parent);
	void setName(int buttonNumber=0,const char* textName="" ){answer[buttonNumber]->setText(textName);}
   signals:
   private slots:
   private:
	QPushButton *answer[4];
        void ListOfAnswers(std::vector<std::string>& translation);
	const char* answerOption[10];
};
#endif // ANSWERS_H

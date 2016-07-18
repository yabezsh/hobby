#include "window.h"
#include <QPushButton>
#include <QApplication>
#include <QRect>
#include <QSize>
#include "answers.h"
Window::Window(QWidget *parent) :
   QWidget(parent)
   {
	setFixedSize(1000,1000);
//	question = new QLabel("test",this);
//	question->setGeometry(100,100,800,100);
	m_button = new QPushButton("Hi",this);
	m_button->setGeometry(10,10,80,30);
	m_button->setCheckable(true);
	m_counter = 0;
	Answers choiceOfAnswers(this);
//	choiceOfAnswers.show();

	connect(m_button,SIGNAL(clicked(bool)),this,SLOT(slotButtonClicked(bool)));
	connect(this,SIGNAL(counterReached()),QApplication::instance(),SLOT(quit()));
   }
void Window::slotButtonClicked(bool checked)
{
	if(checked){m_button->setText("Checked");}
	else{m_button->setText("Hi");}

	m_counter ++;
	if(m_counter==3){
	emit counterReached();
}
}

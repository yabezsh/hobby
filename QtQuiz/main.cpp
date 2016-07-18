#include <QApplication> 
#include <window.h>
#include <answers.h>
#include <question.h>
#include <QProgressBar>
#include <QSlider>
int main(int argc, char *argv[ ])
{
QApplication app(argc, argv);

Window window;
Question wordToTranslate(&window);
Answers choiceOfAnswers(wordToTranslate.GetQuestionNumber(),&window);
window.show();

//QObject::connect(slider,SIGNAL(valueChanged(int)),progressBar,SLOT(setValue(int)));
return app.exec();
}

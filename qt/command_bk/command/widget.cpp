#include "widget.h"
#include <QProcess>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    text_edit = new QTextEdit;
    lineEdit = new QLineEdit;
    execute_button = new QPushButton;
    execute_button->setText("Execute");
    exit_button = new QPushButton;
    exit_button->setText("Exit");

    vblayout = new QVBoxLayout;
    vblayout->addWidget(text_edit);
    vblayout->addStretch();
    vblayout->addWidget(lineEdit);
    vblayout->addWidget(execute_button);
    vblayout->addStretch();
    vblayout->addWidget(exit_button);

    this->setLayout(vblayout);

    connect(execute_button, SIGNAL(clicked(bool)), this, SLOT(execute()));
    connect(exit_button, SIGNAL(clicked(bool)), this, SLOT(exit()));
}
void Widget::execute(){
    QProcess *input_proc = new QProcess;
    QString input_str = lineEdit->text();
    input_proc->start(input_str);
    input_proc->waitForFinished();
    QString output_str = input_proc->readAllStandardOutput();
    text_edit->setText(output_str);

}

void Widget::exit(){
    this->close();
}
Widget::~Widget()
{

}

#include "widget.h"
#include <QProcess>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    output_label = new QLabel;
    output_label->setText("Output area:");
    input_label = new QLabel;
    input_label->setText("Input area:");
    text_edit = new QTextEdit;
    lineEdit = new QLineEdit;
    execute_button = new QPushButton;
    execute_button->setText("Execute");
    //execute_button->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    exit_button = new QPushButton;
    exit_button->setText("Exit");

    hblayout = new QHBoxLayout;
    hblayout->addStretch();
    hblayout->addWidget(execute_button);
    hblayout->addStretch();
    hblayout->addWidget(exit_button);
    hblayout->addStretch();

    vblayout = new QVBoxLayout;
    vblayout->addWidget(output_label);
    vblayout->addWidget(text_edit);
    vblayout->addWidget(input_label);
    vblayout->addWidget(lineEdit);
    vblayout->addStretch();
    vblayout->addLayout(hblayout);
    //vblayout->addWidget(execute_button);
    //vblayout->addWidget(exit_button);

    vblayout->setStretch(0, 1);
    vblayout->setStretch(1, 20);
    vblayout->setStretch(2, 1);
    vblayout->setStretch(3, 1);
    vblayout->setStretch(4, 1);
    vblayout->setStretch(5, 1);


    this->setLayout(vblayout);
    //this->setWindowFlags(Qt::WindowSystemMenuHint);
    //this->setWindowState(Qt::WindowFullScreen);

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

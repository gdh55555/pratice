#include "widget.h"
#include <QProcess>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    open_button = new QPushButton;
    close_button = new QPushButton;
    open_button->setText("Open");
    close_button->setText("Close");

    hblayout = new QHBoxLayout;
    hblayout->addStretch();
    hblayout->addWidget(open_button);
    hblayout->addStretch();
    hblayout->addWidget(close_button);
    hblayout->addStretch();

    vblayout = new QVBoxLayout;
    vblayout->addStretch();
    vblayout->addLayout(hblayout);
    vblayout->addStretch();

    this->setLayout(vblayout);

    connect(open_button, SIGNAL(clicked(bool)), this, SLOT(open_android()));
    connect(close_button, SIGNAL(clicked(bool)), this, SLOT(close_android()));

}
void Widget::open_android()
{
    QProcess *open_proc = new QProcess;
    QString cmd = "sh";
    QStringList argument;
    //argument << "/home/gudh" << "/lxc_start";
    open_proc->start("lxc-start -n android /init");

}

void Widget::close_android()
{
    QProcess *close_proc = new QProcess;
    QString cmd = "sh";
    QStringList argument;
    //argument << "/" << "/second.sh";
//    close_proc->start("/usr/lxc_stop");
    close_proc->start("lxc-stop -n android");
}

Widget::~Widget()
{

}

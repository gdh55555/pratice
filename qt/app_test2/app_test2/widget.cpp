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

    name_hblayout = new QHBoxLayout;
    name_label = new QLabel(trUtf8("启动android系统"));
    name_hblayout->addStretch();
    name_hblayout->addWidget(name_label);
    name_hblayout->addStretch();

    hblayout = new QHBoxLayout;
    hblayout->addStretch();
    hblayout->addWidget(open_button);
    hblayout->addStretch();
    hblayout->addWidget(close_button);
    hblayout->addStretch();

    vblayout = new QVBoxLayout;
    vblayout->addStretch();
    vblayout->addLayout(name_hblayout);
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
    open_proc->start("lxc-start -n android -l debug -o log.s /init");

}

void Widget::close_android()
{
    QProcess *close_proc = new QProcess;
    close_proc->start("lxc-attach -l debug -o log.a -n android busybox poweroff -f");
    //close_proc->start("pkill lxc-start");
}

Widget::~Widget()
{

}

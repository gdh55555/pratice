#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *open_button;
    QPushButton *close_button;
    QGridLayout *gridLayout;
    QHBoxLayout *hblayout;
    QVBoxLayout *vblayout;
private slots:
    void open_android();
    void close_android();
};

#endif // WIDGET_H

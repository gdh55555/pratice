#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

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
    QHBoxLayout *name_hblayout;
    QHBoxLayout *team_hblayout;
    QVBoxLayout *vblayout;
    QLabel *name_label;
    QLabel *team_label;
private slots:
    void open_android();
    void close_android();
};

#endif // WIDGET_H

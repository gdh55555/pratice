#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QTextEdit *text_edit;
    //QTextEdit *input_text_edit;
    QLineEdit *lineEdit;
    QVBoxLayout *vblayout;
    QHBoxLayout *hblayout;
    QPushButton *execute_button;
    QPushButton *exit_button;
    QLabel *output_label;
    QLabel *input_label;

private slots:
    void execute();
    void exit();
};

#endif // WIDGET_H

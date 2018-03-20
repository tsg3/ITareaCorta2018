//
// Created by racso on 17/03/18.
//

#ifndef TAREACORTA_MAINWINDOW_H
#define TAREACORTA_MAINWINDOW_H

#include <QWidget>

class QPushButton;
class QLabel;
class QScrollBar;
class Window : public QWidget
{
Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);

private slots:
    void slotButtonClicked();
    void slotButton2Clicked();

private:
    QPushButton *m_button;
    QPushButton *m2_button;
    QScrollBar *bar;
};

#endif //TAREACORTA_MAINWINDOW_H


//
// Created by racso on 17/03/18.
//

#ifndef TAREACORTA_MAINWINDOW_H
#define TAREACORTA_MAINWINDOW_H

#include <QWidget>

class QPushButton;
class QMessageBox;
class Window : public QWidget
{
Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);

private slots:
    void slotButtonClicked();
    void slotButton2Clicked();
    void slotButton3Clicked();

private:
    QPushButton *m_button;
    QPushButton *m2_button;
    QPushButton *m3_button;
    QMessageBox *alerta;
};

#endif //TAREACORTA_MAINWINDOW_H


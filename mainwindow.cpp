//
// Created by racso on 17/03/18.
//

#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QDebug>


Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(1000, 1000);

    m_button = new QPushButton("Scroll UP", this);
    m_button->setGeometry(10, 10, 90, 40);
    m_button->setCheckable(true);

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));

    m2_button = new QPushButton("Scroll DOWN", this);
    m2_button->setGeometry(10, 70, 90, 40);

    //label = new QLabel(this);

    QString pages[4];

    pages[0] =  "-------------------Pagina 1--------------------\n"
                "Se preparo ------ Ozuna\n"
                "Se preparó, se puso linda, a su amiga llamaba\n"
                "Salió de rumba, nada le importó\n"
                "Porque su novio a ella la engañaba\n"
                "Como si nada \n";

    pages[1] =  "-------------------Pagina 2--------------------\n"
                "Sale a olvidar las penas y el sufrimiento\n"
                "El novio la hizo llorar, mató su sentimiento\n"
                "prometió palabras que se fueron con el viento\n"
                "Ahora ella le dice lo lamento, lo siento\n";

    pages[2] =  "-------------------Pagina 3--------------------\n"
                "Sale a olvidar las penas y el sufrimiento\n"
                "El novio la hizo llorar, mató su sentimiento\n"
                "prometió palabras que se fueron con el viento\n"
                "Ahora ella le dice lo lamento, lo siento\n";

    pages[3] =  "-------------------Pagina 4--------------------\n"
                "Hoy ella hace lo que quiera\n"
                "Se monta en su nave, a quemar la carretera\n"
                "Le mete al baile con la música buena\n"
                "Dale champagne y se prende en candela, esa es mi nena\n"
                "Hoy ella hace lo que quiera\n"
                "Se monta en su nave, a quemar la carretera\n"
                "Le mete al baile con la música buena\n"
                "Dame la champagne y se me prende en candela, esa es mi nena\n";


    QList<QLabel *> labels;
    for (int i = 0; i < 4; ++i)
        labels << new QLabel(this);

    for (int i = 0; i < 4; ++i)
        labels.at(i)->setText(pages[i]);

    //labels.at(0)->setGeometry(120,10,1000,200);     /// cuando se tenga el tamaño de pagina definido se le mete un for
    //labels.at(1)->setGeometry(120,120,1000,200);
    //labels.at(2)->setGeometry(120,250,1000,200);
    //labels.at(3)->setGeometry(120,400,1000,200);

    if (labels.at(0) == NULL){
        labels.at(0)->setGeometry(120,10,1000,200);
        labels.at(1)->setGeometry(120,120,1000,200);
        labels.at(2)->setGeometry(120,250,1000,200);
    }else{
        int x = 100;
        for(int i = 0; i<2;i++){
            labels.at(i)->setGeometry(120,10 + x,1000,200);
        }
    }


   /* label->setText(pages[1]);           //buscar array de labels con los datos de las paginas

    if (label->text().isNull()) {
        label->setText(pages[1] + "#pass_page#"+pages[2] + pages[3]);
    }else if(label->text(). == pages[1]){
        qDebug() << "Si lo detecta";
    }else{
            QString temp = label->text();
            label->clear();
            label->setText(pages[4]+temp);

        //label->setText(label->text() + " #PAGE2# " + pages[2]);
    }

    label->setGeometry(40, 10, 1000, 1000);

    qDebug() << label->text();
*/
}

void Window::slotButtonClicked(bool checked)
{
    if (checked) {
        qDebug()<<"WORKS";
    } else {
        qDebug()<<"HELP :(";
    }
}



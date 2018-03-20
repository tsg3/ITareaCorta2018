//
// Created by racso on 17/03/18.
//

#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QScrollBar>
#include <QInputDialog>

int posx = 100;
int posy = 10;

Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(1300, 1300);
    setWindowTitle("Tarea Corta #1");

    bar = new QScrollBar(this);
    bar->setGeometry(1000,10,90,650);

    m_button = new QPushButton("Buscar Texto", this);
    m_button->setGeometry(1100, 10, 150, 40);
    m_button->setCheckable(true);
    connect(m_button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

    m2_button = new QPushButton("Cambiar Texto", this);
    m2_button->setGeometry(1100, 70, 150, 40);
    m2_button->setCheckable(true);
    connect(m2_button, SIGNAL(clicked()), this, SLOT(slotButton2Clicked()));

    //Paginas de prueba

    QString pages[8];

    pages[0] =  "-------------------Pagina 1--------------------\n"
                "Se preparo ------ Ozuna\n"
                "Se preparó, se puso linda, a su amiga llamaba\n"
                "Salió de rumba, nada le importó\n"
                "Porque su novio a ella la engañaba\n";

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
                "Dale champagne y se prende en candela, esa es  \n";

    pages[4] = "-------------------Pagina 4--------------------\n"
                "Hoy ella hace lo quePagina4PagiPagina  quiera\n"
                "Se monta en su nave,Pagina 4uemar la carretera\n"
                "Le mete al baile con la música buena\n"
                "Dale champagne y se prende en cndela, esa es  \n";

    pages[5] = "-------------------Pagina 5--------------------\n"
            "Hoy ella hace lo que Pagina 4Pagina 4Pagina quiera\n"
            "Se monta en su nave, a quemar la carretera\n"
            "Le mete al baile con la música buena\n"
            "Dale champagne y se prende en candela, esa es  \n";

    pages[6] = "-------------------Pagina 6--------------------\n"
            "Hoy ella hace lo que quiePagina 6Pagina 6Pagina ra\n"
            "Se monta en su naPaginaPave, a quemar la carretera\n"
            "Le mete al baile con la músiPagina 6Paginaca buena\n"
            "Dale champagne y se prende Pagen candela, esa es  \n";

    pages[7] = "-------------------Pagina 7--------------------\n"
            "Hoy ella hace lo qaklsdkljasjdljlsdsdsdsaue quiera\n"
            "Se monta en su nave, a quemar ldkjashdja carretera\n"
            "Le mete al baile con dehfhadsfkjhahla música buena\n"
            "Dale champagne y se prende en candefsdla, esa es  \n";

    QList<QLabel *> labels;

    for (int i = 0; i < 8; ++i) {                       //en vez de 8 serian la cantidad de paginas que se van a desplejar

        labels << new QLabel(this);                     //cambiar el posx y el posy de acuerdo a la longitud de la pagina
        labels.at(i)->setText(pages[i]);

        if(posx >= 1000){
            posx=100;
            posy+=200;
            labels.at(i)->setGeometry(0 + posx,10+posy,300,200);
        }else{
            labels.at(i)->setGeometry(0 + posx,10+posy,300,200);
            posx+=300;
        }
    }
}

void Window::slotButtonClicked()
{
    bool ok;
    QString text = QInputDialog().getText(0, "Input", "Insert text name", QLineEdit::Normal, "",&ok );
}

void Window::slotButton2Clicked()
{
    bool ok;
    QString text2 = QInputDialog().getText(0, "Input", "Insert new text", QLineEdit::Normal, "",&ok );
}

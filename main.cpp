#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QFrame frame;
    frame.setFixedSize(40,40);
    frame.show();

    return app.exec();

}
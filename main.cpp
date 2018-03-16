#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtGui>
#include <QTextEdit>


int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QTextEdit Edit;
    QTextDocument *myDocument = new QTextDocument(&Edit);
    Edit.setDocument(myDocument);
    QTextCursor *myCursor = new QTextCursor(myDocument);

    QTextBlockFormat format;
    myCursor->insertBlock(format);
    myCursor->insertText("gdsckjsajkdhakjshdjnjasndkasjbcbkjdbaskjcbkbdbsbvbkhffkjbskjbckjbdskjbckjbs");
    myCursor->deleteChar();
    myCursor->position();
    myCursor->setPosition(2, static_cast<QTextCursor::MoveMode>(8));


    Edit.setEnabled(false);
    Edit.show();


/*int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Label label;
    label.setText("Qt Centre");
    label.show();
    return app.exec();
}QTextBlockFormat format;
    format.setBackground(Qt::red);
    myCursor->setBlockFormat(format);
    myCursor->insertText("the ");

    format.setBackground(Qt::green);
    myCursor->insertBlock(format);
    myCursor->insertText("fish");
    myCursor->deletePreviousChar();
    myCursor->StartOfLine;
    myCursor->insertText("ESTE......");
    myCursor->atEnd();
    //myCursor->insertText("ESTE......");

    format.setBackground(Qt::yellow);
    myCursor->insertBlock(format);
    myCursor->insertText("are ");

    format.setBackground(Qt::red);
    myCursor->insertBlock(format);
    myCursor->insertText("coming!");

    format.setBackground(Qt::green);
    myCursor->insertBlock(format);
    myCursor->insertText(QString("%1 blocks").arg(myDocument->blockCount()));
    myEdit.show();
*/
   return app.exec();

}
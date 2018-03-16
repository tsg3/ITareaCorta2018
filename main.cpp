/*#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QFrame frame;
    frame.setFixedSize(40,40);
    frame.show();

    return app.exec();

    string name;
    char letra;
    ifstream infile;
    infile.open("/home/estebandcg1999/CLionProjects/TareaCorta/textos.txt");
    if(infile.is_open())
    {
        infile.get(letra);
        while (!infile.eof()){
            cout << letra;
            infile.get(letra);
        }
    }
    else
        cout << "Unable to open file";

    cout << name;
    return 0;

}*/
#include <stdio.h>

enum {EXITO, FALLO, LONGITUD_MAXIMA = 6};

int error_msg(char *nombre_fichero)
{
    printf("Falló algo con el fichero %s.\n", nombre_fichero);
    return FALLO;
}

int main(void)
{
    FILE *ptr_fich1, *fich_ptr2;
    char nombre_fich1[] = "/home/estebandcg1999/CLionProjects/TareaCorta/textos.txt";
    char nombre_fich2[] = "/home/estebandcg1999/CLionProjects/TareaCorta/resumen.txt";
    int resultado = EXITO;

    if ( (ptr_fich1 = fopen(nombre_fich1, "w")) == NULL )
    {
        resultado = error_msg(nombre_fich1);
    }
    else
    {
        if ( (fich_ptr2 = fopen(nombre_fich2, "r")) == NULL )
        {
            resultado = error_msg(nombre_fich2);
        }
        else
        {
            int num;
            char buffer[LONGITUD_MAXIMA + 1];
            while(!feof(fich_ptr2))
            {
                num = fread(buffer,sizeof(char), LONGITUD_MAXIMA, fich_ptr2);
                buffer[num*sizeof(char)] = '\0';
                printf("%s | ",buffer);
                if (fwrite(buffer, sizeof(char), num, ptr_fich1) != num)
                {
                    resultado = error_msg(nombre_fich1);
                    break;
                }
            } //end of while
            printf("\n");
            if (fclose(fich_ptr2)!=0)
            {
                resultado = error_msg(nombre_fich2);
            }
        }
        /*if (fclose(fich_ptr2)!=0)
        {
            resultado = error_msg(nombre_fich1);
        }*/
    }
    return resultado;
}
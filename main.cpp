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
#include <iostream>

enum {EXITO, FALLO, LONGITUD_MAXIMA = 5};

int pags[3] = {0,0,0};

int error_msg(char *nombre_fichero)
{
    printf("Falló algo con el fichero %s.\n", nombre_fichero);
    return FALLO;
}

int lector()
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
            int counter = 0;
            while(!feof(fich_ptr2))
            {
                num = fread(buffer,sizeof(char), LONGITUD_MAXIMA, fich_ptr2);
                buffer[num*sizeof(char)] = '\0';
                if ((pags[0] == counter) && !(pags[0]==pags[1])) {
                    printf("%s | ", buffer);
                    if (fwrite(buffer, sizeof(char), num, ptr_fich1) != num) {
                        resultado = error_msg(nombre_fich1);
                        break;
                    }
                }
                else if (pags[1] == counter) {
                    printf("%s | ", buffer);
                    if (fwrite(buffer, sizeof(char), num, ptr_fich1) != num) {
                        resultado = error_msg(nombre_fich1);
                        break;
                    }
                }
                else if ((pags[2] == counter) && !(pags[2]==pags[1])) {
                    printf("%s | ", buffer);
                    if (fwrite(buffer, sizeof(char), num, ptr_fich1) != num) {
                        resultado = error_msg(nombre_fich1);
                        break;
                    }
                }
                counter++;
            }
            printf("\n");
            if (fclose(fich_ptr2)!=0)
            {
                resultado = error_msg(nombre_fich2);
            }
            fclose(ptr_fich1);
        }
    }
    return resultado;
}

int main(){
    lector();
    char button;
    int counter;
    int limit = 8;
    std::cout << "{" << pags[0] << ", " << pags[1] << ", " << pags[2] << "}" << std::endl;
    while (button != 'e'){
        std::cin >> button;
        if (!((pags[0] == pags[1]) && (pags[0] == pags[2]) && ((pags[2] == 0) || (pags[2] == limit)))) {
            if (button == 'b') {
                counter = 0;
                if (pags[1] == limit)
                    pags[2]++;
                if (pags[2] != 0) {
                    while (counter < 3) {
                        if (pags[counter] != 0)
                            pags[counter] -= 1;
                        counter++;
                    }
                }
            }
            if (button == 'm') {
                counter = 0;
                if (pags[1] == 0)
                    pags[0]--;
                if (pags[0] != limit) {
                    while (counter < 3) {
                        if (pags[counter] != limit)
                            pags[counter] += 1;
                        counter++;
                    }
                }
            }
        }
        else {
            if (pags[2]==0){
                if (button == 'm') {
                    pags[2] = 1;
                }
            }
            if (pags[0]==limit){
                if (button == 'b') {
                    pags[0] = limit-1;
                }
            }
        }
        std::cout << "{" << pags[0] << ", " << pags[1] << ", " << pags[2] << "}" << std::endl;
        lector();
    }
    return 0;
}
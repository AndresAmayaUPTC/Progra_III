#include <stdio.h>
#include <ctype.h>



void mainMenu(){

    char *opciones=">>>>>MENU PRINCIPAL<<<<<\n\n"
                   "\t1 - Numero Romano\n"
                   "\t2 - Fatores Primos\n"
                   "\t3 - Borrar Espacios\n"
                   "\t4 - Numeros Egolatras\n"
                   "\t5 - Numero Mágico\n"
                   "\t6 - Fechas\n"
                   "\t7 - Producto Punto\n"
                   "\t8 - Multiplicación de Matrices\n"
                   "\t9 - Matriz Mágica\n"
                   "\tX - Salir\n";
    char option;
    do {
        printf("%s",opciones);
        scanf("%c",&option);

        switch (option) {

            //swich case para cada opcion
            case 1  :

        }


    }while (toupper(option)!='X');
}

int main() {
   mainMenu();
    return 0;
}

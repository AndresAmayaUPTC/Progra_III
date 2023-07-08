#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


void romanNum() {

    printf("\t***Numero Romano***\n"
           "\t1 - Convertir Numero Romano a decimal\n"
           "\t0 - Volver\n");
    char op;
    scanf("%c", &op);
    getchar();
    switch (op) {

        case '1':
            printf("Ingrese el Numero Romano\n");
            char romanNum[10];
            scanf("%c", &romanNum);
            getchar();
            int i;
            int decimalNum = 0;
            for (i = strlen(romanNum) - 1; i >= 0; i--) {
                switch (romanNum[i]) {
                    case 'I':
                        if (decimalNum >= 5) {
                            decimalNum -= 1;
                        } else {
                            decimalNum += 1;
                        }
                        break;
                    case 'V':
                        decimalNum += 5;
                        break;
                    case 'X':
                        if (decimalNum >= 50) {
                            decimalNum -= 10;
                        } else {
                            decimalNum += 10;
                        }
                        break;
                    case 'L':
                        decimalNum += 50;
                        break;
                    case 'C':
                        if (decimalNum >= 500) {
                            decimalNum -= 100;
                        } else {
                            decimalNum += 100;
                        }
                        break;
                    case 'D':
                        decimalNum += 500;
                        break;
                    case 'M':
                        decimalNum += 1000;
                        break;
                    default:
                        printf("Número romano inválido\n");
                        return -1;  // Valor de retorno inválido para indicar error
                }

            }


            printf("El caracter ingresado equiale a %d en decimal\n",decimalNum);


            sleep(2);
            break;

        case '0':
            printf("Regresando....\n");
            break;

        default:
            printf("Opcion no Valida!!\n");
            break;


    }
}




void mainMenu() {

    char *opciones = ">>>>>MENU PRINCIPAL<<<<<\n\n"
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
        printf("%s", opciones);
        scanf("%c", &option);
        getchar();

        switch (option) {

            //swich case para cada opcion
            case '1':
                romanNum();
                break;

            case '2':
                printf("Hola");
                break;

        }


    } while (toupper(option) != 'X');
}

int main() {
    mainMenu();
    return 0;
}

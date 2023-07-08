#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>




void esEgolatra(){
    int numero;
    int suma = 0;

    printf("\n   DIGITE EL NUMERO\n");
    scanf("%d",&numero);
    getchar();

    int longitud = floor(log10(numero)) + 1;
    char numeroCadena[longitud + 1];

    sprintf(numeroCadena,"%d",numero);

    for (int i = 0; i < longitud; ++i) {
        int actual = numeroCadena[i] - '0';
        int potencia = pow(actual,longitud);
        suma += potencia;
    }

    if(suma == numero){
        printf("\n   EL NUMERO ES EGOLATRA\n");
    }else {
        printf("\n   EL NUMERO NO ES EGOLATRA\n");
    }
    sleep(3);
}

void factoresPrimos() {
    long numero;
    long numeroAux;
    long iterador = 0;

    printf("   INGRESE UN NUMERO (NO MAYOR A 2147483646)\n");

    scanf("%d", &numero);
    getchar();

    numeroAux = numero;

    printf("\n  %d = ", numeroAux);

    for (long i = 2; numero > 1; ++i) {
        if (iterador != 0) {
            printf(" * ");
        }
        iterador = 0;
        if (numero % i == 0) {
            while (numero % i == 0) {
                iterador += 1;
                numero = numero / i;
            }
            if (iterador > 1) {
                printf("%d^%d", i, iterador);
            } else if (iterador == 1) {
                printf("%d", i);
            }
        }
    }
    printf("\n\n");
    sleep(3);
}


void romanNum() {

    printf("\t        ***Numero Romano***\n"
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

            int k = 0;
            while (romanNum[k] != '\0') {
                romanNum[k] = toupper(romanNum[k]);
                k++;
            }

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
                        printf("!!Número romano inválido!!\n");
                        sleep(2);
                        return -1;  // Valor de retorno inválido para indicar error
                }

            }


            printf("El caracter ingresado equiale a %d en decimal\n", decimalNum);


            sleep(3);
            break;

        case '0':
            printf("Regresando....\n");
            break;

        default:
            printf("Opcion no Valida!!\n");
            sleep(2);
            break;


    }
}


void mainMenu() {

    char *opciones = "          >>>>>MENU PRINCIPAL<<<<<\n\n"
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


            case '1':
                romanNum();
                break;

            case '2':
                factoresPrimos();
                break;

                case '3':
                    break;
                case '4':
                    esEgolatra();
                    break;

            default:
                break;

        }


    } while (toupper(option) != 'X');
}

int main() {
    mainMenu();
    return 0;
}

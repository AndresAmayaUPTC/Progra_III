#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void magicMatrix() {

    int numero;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &numero);
    getchar();


    if (numero <= 0 || numero % 2 == 0) {
        printf("El número de elementos debe ser un número impar y mayor a cero.\n");
        sleep(2);
        return;
    }

    int matriz[numero][numero];
    int fila = 0;
    int columna = numero / 2;
    int valor = 1;

    while (valor <= numero * numero) {
        matriz[fila][columna] = valor;

        int siguienteFila = (fila - 1 + numero) % numero;
        int siguienteColumna = (columna + 1) % numero;

        if (matriz[siguienteFila][siguienteColumna] == 0) {
            fila = siguienteFila;
            columna = siguienteColumna;
        } else {
            fila = (fila + 1) % numero;
        }

        valor++;
    }

    printf("Matriz mágica:\n");
    for (int i = 0; i < numero; i++) {
        for (int j = 0; j < numero; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    sleep(4);
    printf("\n \n");
}

void matrixProduct() {
    int fm1, cm1, fm2, cm2;

    printf("   INGRESE EL NUMERO DE FILAS DE LA PRIMERA MATRIZ\n");
    scanf("%d", &fm1);
    getchar();
    printf("   INGRESE EL NUMERO DE COLUMNAS DE LA PRIMERA MATRIZ\n");
    scanf("%d", &cm1);
    getchar();
    printf("   INGRESE EL NUMERO DE FILAS DE LA SEGUNDA MATRIZ\n");
    scanf("%d", &fm2);
    getchar();
    printf("   INGRESE EL NUMERO DE COLUMNAS DE LA SEGUNDA MATRIZ\n");
    scanf("%d", &cm2);
    getchar();

    int m1[fm1][cm1];
    int m2[fm2][cm2];
    int m3[fm1][cm2];


    if (cm1 == fm2) {
        for (
                int i = 0;
                i < fm1;
                ++i) {
            for (
                    int j = 0;
                    j < cm1;
                    ++j) {
                m1[i][j] =

                        rand()

                        % 9 + 1;
            }
        }
        for (
                int i = 0;
                i < fm2;
                ++i) {
            for (
                    int j = 0;
                    j < cm2;
                    ++j) {
                m2[i][j] =

                        rand()

                        % 9 + 1;
            }
        }
        for (
                int i = 0;
                i < fm1;
                ++i) {
            for (
                    int j = 0;
                    j < cm2;
                    ++j) {
                m3[i][j] = 0;
                for (
                        int k = 0;
                        k < cm1;
                        ++k) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        printf("\nPRIMERA MATRIZ\n\n");
        for (
                int i = 0;
                i < fm1;
                ++i) {
            printf("  [");
            for (
                    int j = 0;
                    j < cm1;
                    ++j) {
                printf(" %d ", m1[i][j]);
            }
            printf("]\n");
        }
        printf("\nSEGUNDA MATRIZ\n\n");
        for (
                int i = 0;
                i < fm2;
                ++i) {
            printf("  [");
            for (
                    int j = 0;
                    j < cm2;
                    ++j) {
                printf(" %d ", m2[i][j]);
            }
            printf("]\n");
        }
        printf("\n    RESULTADO:\n\n");
        for (
                int i = 0;
                i < fm1;
                ++i) {
            printf("  [");
            for (
                    int j = 0;
                    j < cm2;
                    ++j) {
                if (m3[i][j] < 100) {
                    printf("  %d ", m3[i][j]);
                } else {
                    printf(" %d ", m3[i][j]);
                }
            }
            printf("]\n");
        }
        printf("\n");
    } else {
        printf("\n   LAS MATRICES NO SON MULTIPLICABLES\n");
    }
    sleep(3);
}


int funtionProduct(int matrizA[], int matrizB[]) {
    int sizeTotal = 0;
    size_t sizeMatrizA = sizeof(matrizA) / sizeof(matrizA[0]);
    for (int i = 0; i < sizeMatrizA; ++i) {
        sizeTotal += matrizA[i] * matrizB[i];
    }
    return sizeTotal;
}

void menuProduct() {

    int sizeA, sizeB;
    int bucleProduct = 1;

    while (bucleProduct) {
        printf("\t---> Producto punto <---\n"
               "\t[0] Volver al menu principal\n\n"
               "- Ingrese el tamano del vector A: \n");

        scanf("%d", &sizeA);
        if (sizeA == 0) {
            printf("Regresando...");
            getchar();
            bucleProduct = 0;
        } else {
            printf("[0] Volver al menu principal\n\n"
                   "- Ingrese el tamano del vector B: \n");
            scanf("%d", &sizeB);

            if (sizeB == 0) {
                printf("Regresando...");
                sleep(1);
                bucleProduct = 0;
            } else {
                if (sizeA == sizeB) {
                    int matrizA[sizeA], matrizB[sizeB];
                    for (int i = 0; i < sizeA; i++) {
                        printf("A [%d] = ", i + 1);
                        scanf("%d", &matrizA[i]);
                        getchar();
                    }

                    for (int j = 0; j < sizeB; j++) {
                        printf("B [%d] = ", j + 1);
                        scanf("%d", &matrizB[j]);
                        getchar();
                    }

                    printf("El producto punto de ambas matrices es: %d \n", funtionProduct(matrizA, matrizB));
                    sleep(3);
                    bucleProduct = 0;
                } else {
                    printf("Ambas matrices deben ser iguales...\n");
                    bucleProduct = 1;
                }
            }
        }
    }
}


void dates() {

    char fecha[11];

    printf("Ingrese una fecha en formato dd/mm/aaaa: ");
    scanf("%s", fecha);
    getchar();

    int dia, mes, anio;
    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre",
                     "noviembre", "diciembre"};

    // Validar el formato de la fecha
    if (sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio) != 3) {
        printf("!!Fecha inválida!!\n");
        sleep(2);
        return;
    }

    // Validar los rangos de día, mes y año
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 0) {
        printf("!!Fecha inválida!!\n");
        sleep(2);
        return;
    }

    // Validar días específicos para algunos meses
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("!!Fecha inválida!!\n");
        return;
    }

    if (mes == 2) {
        // Validar febrero y los años bisiestos
        int esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
        if ((esBisiesto && dia > 29) || (!esBisiesto && dia > 28)) {
            printf("!!Fecha inválida!!\n");
            sleep(2);
            return;
        }
    }

    // Obtener y mostrar la descripción de la fecha
    printf("%d de %s de %d\n", dia, meses[mes - 1], anio);
    sleep(3);
}

void esNumeroMagico() {

    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    getchar();


    int invertido = 0;
    int ordenadoAsc = 0;
    int ordenadoDesc = 0;
    int temp = num;

    // Invertir el número
    while (temp != 0) {
        invertido = invertido * 10 + temp % 10;
        temp /= 10;
    }

    // Ordenar los dígitos en forma ascendente
    temp = num;
    while (temp != 0) {
        int digito = temp % 10;
        ordenadoAsc = ordenadoAsc * 10 + digito;
        temp /= 10;
    }

    // Ordenar los dígitos en forma descendente
    while (num != 0) {
        int digito = num % 10;
        ordenadoDesc = ordenadoDesc * 10 + digito;
        num /= 10;
    }

    // Calcular el resultado
    int resultado = invertido - ordenadoAsc;

    // Comprobar si es un número mágico
    if (resultado == num) {
        printf("*SI* es un numero magico\n");
    } else {
        printf("*NO* es un numero magico\n");
    }
    sleep(3);
}

void esEgolatra() {
    int numero;
    int suma = 0;

    printf("\n   DIGITE EL NUMERO\n");
    scanf("%d", &numero);
    getchar();

    int longitud = floor(log10(numero)) + 1;
    char numeroCadena[longitud + 1];

    sprintf(numeroCadena, "%d", numero);

    for (int i = 0; i < longitud; ++i) {
        int actual = numeroCadena[i] - '0';
        int potencia = pow(actual, longitud);
        suma += potencia;
    }

    if (suma == numero) {
        printf("\n   EL NUMERO ES EGOLATRA\n");
    } else {
        printf("\n   EL NUMERO NO ES EGOLATRA\n");
    }
    sleep(3);
}

void quitaEspacios() {

    char cadena[100], cadenasin[100];

    printf("Introduzca la cadena: ");

    fgets(cadena, 100, stdin);


    int i, j;
    i = 0;
    j = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] != ' ') {
            cadenasin[j] = cadena[i];
            j++;
        }
        i++;
    }
    printf("La cadena es %s", cadenasin);
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
                quitaEspacios();
                break;
            case '4':
                esEgolatra();
                break;
            case '5':
                esNumeroMagico();
                break;

            case '6':
                dates();
                break;
            case '7':
                menuProduct();
                break;
            case '8':
                matrixProduct();
                break;

            case '9':
                magicMatrix();
                break;

            default:
                if(option != 'x' && option != 'X'){
                    printf("Opcion No valida\n");
                    sleep(2);
                }
                break;

        }


    } while (toupper(option) != 'X');
}

int main() {
    mainMenu();
    return 0;
}

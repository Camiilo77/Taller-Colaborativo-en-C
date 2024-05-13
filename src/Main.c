//
// Created by Camilo Andres on 8/05/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    void addCharacter(char cadena[], char caracter, int posicion, int longitud);
    int integerException(int min, int max);
    int w = 0;
    int option = 0;
    do {
        printf("Ingrese la opcion a realizar: \n [1] Ej.1 |"
               " [2] Ej.2 \n [3] Ej.3 | [4] Ej.4\n [5] Ej.5 |"
               " [6] Ej.6 \n [7] Ej.7 | [8] Ej.8\n [9] Ej.9 | [0]. Finalizar\n");

        scanf("%d", &option, integerException(0, 9));
        switch (option) {
            case 1:
                //segundo punto
                break;
            case 2:
                char string[100];
                char character;
                int position;
                int length;
                int z = 0;
                do {
                    printf("\nIngrese una cadena\n");
                    scanf("%s", &string);
                    printf("\nLa cadena actual es: %s\n", string);
                    do {
                        printf("Ingrese el caracter a rellenar\n");
                        scanf("%s", &character);
                        printf("\nIngrese [0] si rellena por izquierda o [1] si rellena por derecha\n");
                        scanf("%d", &position, integerException(0, 1));
                        printf("\ningrese el numero de caracteres que desea rellenar\n");
                        scanf("%d", &length, integerException(1,100000));
                        addCharacter(string, character, position, length);
                        printf("La nueva cadena es: %s", string);
                        printf("\n[1] Ingresar caracteres \n[2] Volver\n");
                        int aux;
                        scanf("%d", &aux, integerException(1,2));
                        if (aux == 2) {
                            z = 2;
                        }
                    } while (z != 2);
                    printf("\n[1] Ingresar otra cadena \n [2] Volver al menú inicial\n");
                    int aux;
                    scanf("%d", &aux, integerException(1,2));
                    if (aux == 2) {
                        z = 1;
                    }
                } while (z != 1);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 0:
                printf("Ejecucion finalizada con exito, gracias por probar el sistema");
                w = 1;
                break;
            default:
                printf("Opcion invalida, ingrese un numero entre 0 y 9");
                break;
        }
    } while (w != 1);
}

//metodo para agregar caracteres dependiendo la poscicion elegida
void addCharacter(char string[], char character, int position, int length) {
    int len = strlen(string);
    int i;

    if (position == 0) {
        // Agregar al principio
        memmove(string + length, string, len + 1);  // Desplazar los datos existentes
        for (i = 0; i < length; i++) {
            string[i] = character;
        }
    } else {
        // Agregar al final
        for (i = len; i < len + length; i++) {
            string[i] = character;
        }
    }
}

//Manejo de excepcion de enteros
int integerException(int min, int max) {
    int valor = 0;
    int valido = 0;

    while (!valido) {
        char entrada[100];

        printf("Ingrese un numero entre %d y %d: ", min, max);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            perror("Error al leer la entrada");
            exit(EXIT_FAILURE);
        }
        if (sscanf(entrada, "%d", &valor) == 1) {
            if (valor >= min && valor <= max) {
                valido = 1;
            } else {
                printf("Numero fuera de rango. Intente nuevamente.\n");
            }
        } else {
            printf("Informacion invalida. Intente nuevamente.\n");
        }
    }
    return valor;
}

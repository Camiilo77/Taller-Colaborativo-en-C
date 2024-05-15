
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    void addCharacter(char cadena[], char caracter, int posicion, int longitud);
    int integerException(int min, int max);
    char *removeDuplicateCharacters(const char inputString[]);
    char *insertSubstring(char *baseString, char *substring, int position);
    int w = 0;
    int option = 0;
    do {
        printf("Ingrese la opcion a realizar: \n [1] Ej.1 |"
               " [2] Ej.2 \n [3] Ej.3 | [4] Ej.4\n [5] Ej.5 |"
               " [6] Ej.6 \n [7] Ej.7 | [8] Ej.8\n [9] Ej.9 | [0]. Finalizar\n");

        option = integerException(0, 9);
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
                        position = integerException(0, 1);
                        printf("\ningrese el numero de caracteres que desea rellenar\n");
                        length = integerException(1, 100000);
                        addCharacter(string, character, position, length);
                        printf("La nueva cadena es: %s", string);
                        printf("\n[1] Ingresar caracteres \n[2] Volver\n");
                        int aux;
                        aux = integerException(1, 2);
                        if (aux == 2) {
                            z = 2;
                        }
                    } while (z != 2);
                    printf("\n[1] Ingresar otra cadena \n [2] Volver al menu inicial\n");
                    int aux;
                    aux = integerException(1, 2);
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
                z = 0;
                do {
                    char inputString[100];
                    char *outputString;
                    printf("Ingrese una cadena de texto\n");
                    scanf("%s", inputString);
                    printf("\nCadena ingresada: %s", inputString);
                    outputString = removeDuplicateCharacters(inputString);
                    printf("\nscadena modificada sin caracteres repetidos: %s\n", outputString);
                    printf("[1] Ingresar otra cadena | [2] Volver al menu inicial");
                    int aux;
                    aux = integerException(1, 2);
                    if (aux == 2) {
                        z = 1;
                    }
                } while (z != 1);
                break;
            case 7:
                break;
            case 8:
                z = 0;
                do {
                    char baseString[100];
                    char subString[100];
                    char *newString; // Pointer to store the new string
                    int position;

                    printf("Ingrese una cadena de texto\n");
                    scanf("%s", baseString);
                    printf("Ingrese la cadena a agregar\n");
                    scanf("%s", subString);
                    printf("\nIngrese la posicion para agregar la cadena\n");
                    fflush(stdout);
                    position = integerException(0, 100);
                    newString = insertSubstring(baseString, subString, position);
                    printf("Nueva cadena: %s\n", newString);
                    free(newString);
                    printf("[1] Ingresar otra cadena | [2] Volver al menu inicial");
                    int aux;
                    aux = integerException(1, 2);
                    if (aux == 2) {
                        z = 1;
                    }
                } while (z != 1);
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

/**Ejercicio 2*/
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

/**Ejercicio 6*/
//Metodo que remueve los caracteres repetidos de una cadena
char *removeDuplicateCharacters(const char inputString[]) {
    int i, j;
    int len = strlen(inputString);
    char *outputString = (char *) malloc(len + 1);

    if (outputString == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    char visited[256] = {0};
    for (i = 0, j = 0; i < len; i++) {
        if (!visited[inputString[i]]) {
            outputString[j] = inputString[i];
            visited[inputString[i]] = 1;
            j++;
        }
    }
    outputString[j] = '\0';
    return outputString;
}

/**Ejercicio 8*/
//Metodo que inserta una cadena en una poscion especifica de otra
char *insertSubstring(char *baseString, char *substring, int position) {
    if (baseString == NULL || substring == NULL || position < 0 || position > strlen(baseString)) {
        return NULL;
    }
    int baseStringLength = strlen(baseString);
    int substringLength = strlen(substring);
    int newStringLength = baseStringLength + substringLength + 1;
    char *newString = (char *) malloc(newStringLength * sizeof(char));
    if (newString == NULL) {
        return NULL;
    }
    int i;
    for (i = 0; i < position; i++) {
        newString[i] = baseString[i];
    }
    for (i = 0; i < substringLength; i++) {
        newString[position + i] = substring[i];
    }
    for (i = position + substringLength; i < newStringLength - 1; i++) {
        newString[i] = baseString[i - substringLength];
    }
    newString[newStringLength - 1] = '\0';
    return newString;
}


//Manejo de excepcion de enteros
int integerException(int min, int max) {
    int valor = 0;
    int valido = 0;

    while (!valido) {
        char entrada[100];

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            perror("Error al leer la entrada");
            exit(EXIT_FAILURE);
        }
        if (sscanf(entrada, "%d", &valor) == 1) {
            if (valor >= min && valor <= max) {
                valido = 1;
            } else {
                printf("\nNumero fuera de rango. Intente nuevamente Ingrese un numero entre %d y %d ", min, max);
            }
        } else {
            printf("Ingrese un valor numerico.\n");
        }
    }
    return valor;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void searchString(char string[], char subString[]);

void replaceCharacter(char string[], char oldChar, char newChar);

void sortStringIgnoreCase(char *string);

void addCharacter(char cadena[], char caracter, int posicion, int longitud);

int integerException(int min, int max);

char *removeDuplicateCharacters(const char inputString[]);

char *insertSubstring(char *baseString, char *substring, int position);

char *obtenerSubcadena(const char cadena[], int inicio, int fin);

int cadenaEmpiezaCon(const char cadenaBase[], const char cadenaVerificar[]);

char *diferenciaCadenas(const char cadena1[], const char cadena2[]);

char *insertSubstring(char *baseString, char *substring, int position);

int main(void) {
    int position, length, z, option = 0, aux, inicio, fin;
    char cadena[100], character, inputString[100], *outputString, string[100], subString[100], input[10], oldChar,
            newChar;
    do {
        printf("Ingrese la opcion a realizar: \n [1] Ej.1 |"
            " [2] Ej.2 \n [3] Ej.3 | [4] Ej.4\n [5] Ej.5 |"
            " [6] Ej.6 \n [7] Ej.7 | [8] Ej.8\n [9] Ej.9 | [0]. Finalizar\n");

        option = integerException(0, 9);
        switch (option) {
            case 1:
                do {
                    system("cls");
                    printf("Ingrese una cadena \n");
                    scanf("%s", string);
                    printf("Ingrese la subcadena a buscar dentro de la cadena anterior \n");
                    scanf("%s", subString);
                    while (strlen(subString) > strlen(string)) {
                        printf("La subcadena no puede ser mas larga que la cadena. Intente de nuevo \n");
                        scanf("%s", subString);
                    }
                    searchString(string, subString);
                    printf("\n[1] Ingresar otra cadena \n[2] Menu Principal\n");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            case 2:
                do {
                    printf("\nIngrese una cadena\n");
                    scanf("%s", string);
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
                        aux = integerException(1, 2);
                    } while (aux != 2);
                    printf("\n[1] Ingresar otra cadena \n [2] Volver al menu inicial\n");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            case 3:
                // Ingresar cadena
                printf("Ingrese una cadena: ");
                scanf("%s", cadena);

            // Ingresar posiciones de inicio y fin para obtener subcadena
                printf("Ingrese posicion inicial y posicion final (0 para final): ");
                printf("\nInicio: ");
                scanf("%d", &inicio);
                printf("\nFin: ");
                scanf("%d", &fin);

            // Obtener subcadena
                char *subcadena = obtenerSubcadena(cadena, inicio, fin);
                printf("Subcadena obtenida: %s\n", subcadena);

            // Liberar memoria asignada a la subcadena
                free(subcadena);
                break;
            case 4:
                do {
                    system("cls");
                    printf("Ingrese una cadena \n");
                    scanf("%s", string);
                    printf("Ingrese el caracter que desea reemplazar \n");
                    scanf("%s", input);
                    oldChar = input[0];
                    printf("El caracter que será reemplazado es %c \n", oldChar);
                    printf("Ingrese el caracter que reemplazará al anterior\n");
                    scanf("%s", input);
                    newChar = input[0];
                    printf("El caracter a reemplazar es %c \n", newChar);
                    replaceCharacter(string, oldChar, newChar);
                    printf("\n[1] Ingresar otra cadena \n[2] Menu Principal\n");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            case 5:
                // Punto //quinto punto: Validar si una cadena inicia con otra
                    printf("Ingrese la cadena base: ");
            scanf("%s", string);
            printf("Ingrese la cadena a verificar: ");
            scanf("%s", subString);

            int resultado = cadenaEmpiezaCon(string, subString);
            if (resultado)
                printf("La cadena base empieza con la cadena a verificar.\n");
            else
                printf("La cadena base no empieza con la cadena a verificar.\n");
                break;
            case 6:
                do {
                    printf("Ingrese una cadena de texto\n");
                    scanf("%s", inputString);
                    printf("\nCadena ingresada: %s", inputString);
                    outputString = removeDuplicateCharacters(inputString);
                    printf("\nscadena modificada sin caracteres repetidos: %s\n", outputString);
                    printf("[1] Ingresar otra cadena | [2] Volver al menu inicial\n");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            case 7:
                // Punto //septimo punto: Realizar operación de diferencia entre dos cadenas
                    printf("Ingrese la primera cadena: ");
            scanf("%s", string);
            printf("Ingrese la segunda cadena: ");
            scanf("%s", subString);

            char *diferenciaCadena = diferenciaCadenas(string, subString);
            printf("La diferencia entre las cadenas es: %s\n", diferenciaCadena);

            // Liberar memoria asignada a la diferencia de cadenas
            free(diferenciaCadena);
                break;
            case 8: {
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
                    position = integerException(0, strlen(baseString));
                    newString = insertSubstring(baseString, subString, position);
                    printf("Nueva cadena: %s\n", newString);
                    free(newString);
                    printf("[1] Ingresar otra cadena | [2] Volver al menu inicial");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            }

            case 9:
                do {
                    system("cls");
                    printf("Ingrese una cadena: \n");
                    getchar();
                    fgets(string, sizeof(string), stdin);
                    string[strcspn(string, "\n")] = '\0';
                    sortStringIgnoreCase(string);
                    printf("\n[1] Ingresar otra cadena \n[2] Menu Principal\n");
                    aux = integerException(1, 2);
                } while (aux != 2);
                break;
            case 0:
                printf("Ejecucion finalizada con exito, gracias por probar el sistema");
                break;
            default:
                printf("Opcion invalida, ingrese un numero entre 0 y 9");
                break;
        }
    } while (option != 0);
}

/**Ejercicio 1*/
// Metodo para buscar una ocurrencia de una subcadena en una cadena
void searchString(char string[], char subString[]) {
    char aux[strlen(subString) + 1];
    for (int i = 0; i <= strlen(string) - strlen(subString); i++) {
        if (string[i] == subString[0]) {
            for (int j = 0; j < strlen(aux); j++) {
                aux[j] = string[i + j];
            }
            if (strcmp(subString, aux)) {
                printf("La subcadena coincide en: %d \n", i);
                break;
            }
        }
    }
}

/**Ejercicio 2*/
// metodo para agregar caracteres dependiendo la poscicion elegida
void addCharacter(char string[], char character, int position, int length) {
    int len = strlen(string);
    int i;

    if (position == 0) {
        // Agregar al principio
        memmove(string + length, string, len + 1); // Desplazar los datos existentes
        for (i = 0; i < length; i++) {
            string[i] = character;
        }
    } else {
        // Agregar al final

        for (i = len; i < len + length; i++) {
            string[i] = character;
        }
    }
    string[len + length] = '\0';
}

/**Ejercicio 3*/
// Función para obtener una subcadena de una cadena dada
char *obtenerSubcadena(const char cadena[], int inicio, int fin) {
    int longitud = strlen(cadena);
    char *subcadena;

    // Validar posiciones
    if (inicio < 0 || inicio >= longitud || fin < 0 || fin >= longitud || inicio > fin) {
        printf("Error: Posiciones de inicio y/o fin inválidas.\n");
        return NULL;
    }

    // Calcular longitud de la subcadena
    int subLongitud = (fin == 0) ? longitud - inicio : fin - inicio + 1;

    // Asignar memoria para la subcadena
    subcadena = (char *) malloc(sizeof(char) * (subLongitud + 1)); // +1 para el terminador nulo

    // Copiar subcadena
    strncpy(subcadena, cadena + inicio, subLongitud);
    subcadena[subLongitud] = '\0'; // Terminador nulo

    return subcadena;
}

/**Ejercicio 4*/
// Metodo para reemplazar una caracter por otro elegido
void replaceCharacter(char string[], char oldChar, char newChar) {
    int length = strlen(string), change = 0;
    for (int i = 0; i < length; ++i) {
        if (string[i] == oldChar) {
            string[i] = newChar;
            change++;
        }
    }

    if (change == 0) {
        printf("\nNo se encontraron caracteres a reemplazar \n");
    } else if (change == 1) {
        printf("\nSe reemplazo %d caracter \n", change);
    } else {
        printf("\nSe reemplazaron %d caracteres \n", change);
    }
    for (int i = 0; i < strlen(string); ++i) {
        printf("%c \n", string[i]);
    }
}

/**Ejercicio 5*/
// Función para validar si una cadena inicia con otra
int cadenaEmpiezaCon(const char cadenaBase[], const char cadenaVerificar[]) {
    return strncmp(cadenaBase, cadenaVerificar, strlen(cadenaVerificar)) == 0;
}

/**Ejercicio 6*/
// Metodo que remueve los caracteres repetidos de una cadena
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

/**Ejercicio 7*/
// Función para realizar la diferencia entre dos cadenas
char *diferenciaCadenas(const char cadena1[], const char cadena2[]) {
    char diferencia[100]; // Supongamos que la longitud máxima de las cadenas es de 100 caracteres
    int diferenciaIndex = 0;

    // Marcar caracteres de cadena2
    int marcado[256] = {0}; // Suponemos un conjunto de caracteres ASCII extendido

    for (int i = 0; i < strlen(cadena2); i++) {
        marcado[(int) cadena2[i]] = 1;
    }

    // Construir la diferencia
    for (int i = 0; i < strlen(cadena1); i++) {
        if (!marcado[(int) cadena1[i]]) {
            diferencia[diferenciaIndex++] = cadena1[i];
        }
    }
    diferencia[diferenciaIndex] = '\0'; // Terminador nulo

    return strdup(diferencia); // Devolvemos una copia de la diferencia
}

/**Ejercicio 8*/
// Metodo que inserta una cadena en una poscion especifica de otra
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

/**Ejercicio 9*/
// Metodo que ordena una cadena de menos a mayor ignorando mayusculas o minusculas

void sortStringIgnoreCase(char *string) {
    int length = strlen(string);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (strcasecmp(&string[j], &string[j + 1]) > 0) {
                char temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
    printf("La cadena ordenada es: %s \n", string);
}

// Manejo de excepcion de enteros
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
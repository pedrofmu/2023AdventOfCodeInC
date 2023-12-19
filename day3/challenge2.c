#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedList.h"

struct gear{
    struct gear *nex_node;
    int x, y;

    int num1;
    int num2;

    bool counts;
};

void manageGear(struct gear **first_gear, int j, int i, int value) {
    printf("Nodo [%d][%d] con el valor %d\n", j, i, value);
    if (*first_gear == NULL) {
        *first_gear = (struct gear *)malloc(sizeof(struct gear));
        (*first_gear)->nex_node = NULL;
        (*first_gear)->x = -1; // Inicializar a valores por defecto
        (*first_gear)->y = -1;
        (*first_gear)->num1 = -1;
        (*first_gear)->num2 = -1;
        (*first_gear)->counts = true;
    }

    struct gear *temp_gear = *first_gear;

    if (temp_gear->x == -1 || temp_gear->y == -1) {
        temp_gear->x = i;
        temp_gear->y = j;
    }

    while (temp_gear != NULL) {
        if (temp_gear->x == i && temp_gear->y == j) {
            // Ya existe
            if (temp_gear->num1 == -1) {
                temp_gear->num1 = value;
                return;
            } else if (temp_gear->num2 == -1) {
                temp_gear->num2 = value;
                return;
            } else {
                temp_gear->counts = false;
                return;
            }
        }

        if (temp_gear->nex_node == NULL) {
            break;
        }

        temp_gear = temp_gear->nex_node;
    }

    struct gear *new_gear = (struct gear *)malloc(sizeof(struct gear));

    new_gear->nex_node = NULL;
    new_gear->x = i;
    new_gear->y = j;
    new_gear->num1 = value;
    new_gear->num2 = -1;
    new_gear->counts = true;

    temp_gear->nex_node = new_gear;
}

int solution(char **input_file, int height, int width){
    int return_value = 0;

    struct gear *first_gear = NULL; 

    int digit_lenght = 0;
    for (int j = 0; j < height; j++){
        for (int i = 0; i < width; i++){
            //This character is a number
            if(isdigit(input_file[j][i])){
                Nodo* lista = NULL;
                //Count the lenght of the number 
                int tempi = i;
                while (isdigit(input_file[j][tempi])){
                    //Comprobar posiciones
                    if(j - 1 >= 0)
                        //Comprobar arriba
                        if (input_file[j - 1][tempi] == '*' && existeValor(lista, j - 1, tempi) == 0){
                            manageGear(&first_gear, j - 1, tempi, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j - 1, tempi);
                        }

                    if(j + 1 <= height - 1)
                        //Comprobar abajo
                        if (input_file[j + 1][tempi] == '*' && existeValor(lista, j + 1, tempi) == 0){
                            manageGear(&first_gear, j + 1, tempi, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j + 1, tempi);
                        }

                    if (i - 1 >= 0)
                        //Comprobar izquierda
                        if (input_file[j][tempi - 1] == '*' && existeValor(lista, j, tempi - 1) == 0){
                            manageGear(&first_gear, j, tempi - 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j, tempi - 1);
                        }

                    if (i + 1 < width - 1)
                        //Comprobar derecha
                        if (input_file[j][tempi + 1] == '*' && existeValor(lista, j, tempi + 1) == 0){
                            manageGear(&first_gear, j, tempi + 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j, tempi + 1);
                        }

                    if (j - 1 >= 0 && i - 1 >= 0)
                        //Uper left
                        if (input_file[j - 1][tempi - 1] == '*' && existeValor(lista, j - 1, tempi -1) == 0){
                            manageGear(&first_gear, j - 1, tempi - 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j - 1, tempi - 1);
                        }

                    if (j - 1 >= 0 && i + 1 < width - 1)
                        //Uper right
                        if (input_file[j - 1][tempi + 1] == '*' && existeValor(lista, j - 1, tempi + 1) == 0){
                            manageGear(&first_gear, j - 1, tempi + 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j - 1, tempi + 1);
                        }

                    if (j + 1 < height - 1 && i - 1 >= 0)
                        //Bottom left
                        if (input_file[j + 1][tempi - 1] == '*' && existeValor(lista, j + 1, tempi - 1) == 0){
                            manageGear(&first_gear, j + 1, tempi - 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j + 1, tempi - 1);
                        }

                    if (j + 1 < height - 1 && i + 1 <  width - 1)
                        //Bottom right 
                        if (input_file[j + 1][tempi + 1] == '*' && existeValor(lista, j + 1, tempi + 1) == 0){
                            manageGear(&first_gear, j + 1, tempi + 1, atoi(&input_file[j][i]));
                            insertarNodo(&lista, j + 1, tempi + 1);
                        } 

                    tempi++;
                    digit_lenght += 1;

                    if (tempi >= width - 1)
                        break;
                }

                free(lista);

                i += digit_lenght - 1;
                digit_lenght = 0;
            }
        }
    } 

    struct gear *temp_gear = first_gear;

    while (temp_gear != NULL){
        if (temp_gear->num2 != -1 && temp_gear->num1 != -1 && temp_gear->counts == true){
            return_value += temp_gear->num1 * temp_gear->num2;
        }

        printf("Nodo [%d][%d]\n", temp_gear->num1, temp_gear->num2);

        temp_gear = temp_gear->nex_node;
    }

    return return_value; 
}



































#define LINE_MAX_LENGTH 500
int main()
{
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs2.txt", "r");

    // Count the number of lines in the file
    int lines = 0;
    int char_width = 0;
    int char_count = 0;
    char ch;
    while ((ch = fgetc(inputs)) != EOF) {
        char_count++;

        if (ch == '\n') {
            char_count = 0;
            lines++;
        }

        if (char_width < char_count)
            char_width = char_count;

    }
    //Return to the start of the file
    fseek(inputs, 0, SEEK_SET);

    char **text_inputs = (char**)malloc(lines * sizeof(char*));

    int count = 0;
    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        text_inputs[count] = strdup(line);
        count++; 
    }

    printf("%d", solution(text_inputs, lines, char_width));

    fclose(inputs);
    return 0;
}

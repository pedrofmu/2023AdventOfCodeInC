#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int solution(char **input_file, int height, int width){
    int return_value = 0;

    int digit_lenght = 0;
    for (int j = 0; j < height; j++){
        for (int i = 0; i < width; i++){
            //This character is a number
            if(isdigit(input_file[j][i])){
                //Count the lenght of the number 
                int tempi = i;
                bool count = false;
                while (isdigit(input_file[j][tempi])){
                    //Comprobar posiciones
                    if(j - 1 >= 0)
                        //Comprobar arriba
                        if (!isdigit(input_file[j - 1][tempi]) && input_file[j - 1][tempi] != '.')
                            count = true;         

                    if(j + 1 <= height - 1)
                        //Comprobar abajo
                        if (!isdigit(input_file[j + 1][tempi]) && input_file[j + 1][tempi] != '.')
                            count = true;

                    if (i - 1 >= 0)
                        //Comprobar izquierda
                        if (!isdigit(input_file[j][tempi - 1]) && input_file[j][tempi - 1] != '.')
                            count = true;

                    if (i + 1 < width - 1)
                        //Comprobar derecha
                        if (!isdigit(input_file[j][tempi + 1]) && input_file[j][tempi + 1] != '.')
                            count = true;

                    if (j - 1 >= 0 && i - 1 >= 0)
                        //Uper left
                        if (!isdigit(input_file[j - 1][tempi - 1]) && input_file[j - 1][tempi - 1] != '.')
                            count = true;

                    if (j - 1 >= 0 && i + 1 < width - 1)
                        //Uper right
                        if (!isdigit(input_file[j - 1][tempi + 1]) && input_file[j - 1][tempi + 1] != '.')
                            count = true;

                    if (j + 1 < height - 1 && i - 1 >= 0)
                        //Bottom left
                        if (!isdigit(input_file[j + 1][tempi - 1]) && input_file[j + 1][tempi - 1] != '.')
                            count = true;

                    if (j + 1 < height - 1 && i + 1 <  width - 1)
                        //Bottom right 
                        if (!isdigit(input_file[j + 1][tempi + 1]) && input_file[j + 1][tempi + 1] != '.')
                            count = true;

                    tempi++;
                    digit_lenght += 1;

                    if (tempi >= width - 1)
                        break;
                }
                
                //Chech if you have to add the number after all
                if (count){
                    return_value += atoi(&input_file[j][i]); 
                }

                i += digit_lenght - 1;
                digit_lenght = 0;
            }
        }
    } 
    return return_value; 
}



































#define LINE_MAX_LENGTH 500
int main()
{
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs1.txt", "r");

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

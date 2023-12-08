#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Returns 0 if it is a imposible game, returns the game number if not
//only 12 red cubes, 13 green cubes, and 14 blue cubes
int isAPosibleGame(char *input, int game){ 
    int thisGame = game; 
    char *colors[] = {"red", "green", "blue"};

    signed int redCount = 12;
    signed int greenCount = 13;
    signed int blueCount = 14;

    size_t i = 0;
    while (input[i] != ':'){
        i++;
    }

    while (i < strlen(input)){
        if (input[i] == ';'){
            if (redCount < 0 || greenCount < 0 || blueCount < 0){
                return 0;
            }

            redCount = 12;
            greenCount = 13;
            blueCount = 14;
        } 

        if (isdigit(input[i])){
            char *digit_end;
            int number = strtol(&input[i], &digit_end, 10);
            i = digit_end - input;

            for (size_t j = 0; j <= 2; j++){
                 if(strncmp(&input[i + 1], colors[j], strlen(colors[j])) == 0){
                     switch (j) {
                         case 0:
                             redCount -= number;
                             i+= strlen(colors[j]);
                         break;
                         case 1:
                             greenCount -= number;
                             i+= strlen(colors[j]);
                         break;
                         case 2:
                             blueCount -= number;
                             i+= strlen(colors[j]);
                         break;
                     }
                 }
            }
        }

        i++;
    }   


    if (redCount < 0 || greenCount < 0 || blueCount < 0){
        return 0;
    }

    return thisGame; 
}

#define LINE_MAX_LENGTH 500
int main(){
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs1.txt", "r");

    //The sum of all input
    int sum = 0;

    int gameCount = 1;
    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        sum += isAPosibleGame(line, gameCount); 
        printf("%d\n", isAPosibleGame(line, gameCount));
        gameCount++;
    }

    fclose(inputs);
    printf("%d\n", sum);

    return 0;
}

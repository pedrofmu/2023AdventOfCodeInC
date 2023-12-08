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

    signed int redCount = 0;
    signed int greenCount = 0;
    signed int blueCount = 0;

    signed int tempRedCount = 0;
    signed int tempGreenCount = 0;
    signed int tempBlueCount = 0;

    size_t i = 0;
    while (input[i] != ':'){
        i++;
    }

    while (i < strlen(input)){
        if (input[i] == ';'){
            if (redCount < tempRedCount)
                redCount = tempRedCount;
          
            if (greenCount < tempGreenCount)
                greenCount = tempGreenCount;

            if (blueCount < tempBlueCount)
                blueCount = tempBlueCount;

            tempRedCount = 0;
            tempBlueCount = 0;
            tempGreenCount = 0;
        } 

        if (isdigit(input[i])){
            char *digit_end;
            int number = strtol(&input[i], &digit_end, 10);
            i = digit_end - input;

            for (size_t j = 0; j <= 2; j++){
                 if(strncmp(&input[i + 1], colors[j], strlen(colors[j])) == 0){
                     switch (j) {
                         case 0:
                             tempRedCount += number;
                             i+= strlen(colors[j]);
                         break;
                         case 1:
                             tempGreenCount += number;
                             i+= strlen(colors[j]);
                         break;
                         case 2:
                             tempBlueCount += number;
                             i+= strlen(colors[j]);
                         break;
                     }
                 }
            }
        }

        i++;
    }   

    if (redCount < tempRedCount)
        redCount = tempRedCount;
    
    if (greenCount < tempGreenCount)
        greenCount = tempGreenCount;

    if (blueCount < tempBlueCount)
        blueCount = tempBlueCount;

    return greenCount * redCount * blueCount; 
}

#define LINE_MAX_LENGTH 500
int main(){
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs2.txt", "r");

    //The sum of all input
    int sum = 0;

    int gameCount = 1;
    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        sum += isAPosibleGame(line, gameCount); 
        gameCount++;
    }

    fclose(inputs);
    printf("%d\n", sum);

    return 0;
}

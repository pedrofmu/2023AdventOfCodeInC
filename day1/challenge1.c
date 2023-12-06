#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTwoDigits(char *input){
    char respons[2];
   
    //First number
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            respons[0] = input[i];
            break;
        }
    }

    //Second caracter
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            respons[1] = input[i];
        }
    } 

    return atoi(respons);
}


#define LINE_MAX_LENGTH 500
int main(){
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs.txt", "r");

    //The sum of all input
    int sum = 0;

    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        sum += findTwoDigits(line); 
    }

    fclose(inputs);
    printf("%d", sum);

    return 0;
}

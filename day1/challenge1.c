#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findTwoDigits(char *input){
    char respons[2] ={-1, -1};
   
    for (int i = 0; i < strlen(input); i++){
        if (isdigit(input[i])){
            if (respons[0] == -1)
                respons[0] = input[i] - '0';

            respons[1] = input[i] - '0';
        }
    }

    if (respons[0] == -1){
        return 0;
    }

    return respons[0] * 10 + respons[1];
}


#define LINE_MAX_LENGTH 500
int main(){
    //Open the input file
    FILE *inputs;
    char line[LINE_MAX_LENGTH];
    inputs = fopen("inputs1.txt", "r");

    //The sum of all input
    int sum = 0;

    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        sum += findTwoDigits(line); 
        printf("%d\n", findTwoDigits(line));
    }

    fclose(inputs);
    printf("%d\n", sum);

    return 0;
}

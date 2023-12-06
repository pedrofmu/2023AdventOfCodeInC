#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int findTwoDigits(char *input){
    char respons[2] = {-1, -1};
    char *number[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    //Iterate thouht the list
    for (int i = 0; i < strlen(input); i++){
        //If it is a digit
        if (isdigit(input[i])){
            if (respons[0] == -1){
                respons[0] = input[i] - '0';
            }
            respons[1] = input[i] - '0';
            
        }/*If it is a writed number*/else{
            for (int j = 0; j <= 8; j++){
                //Check if one of the numbers is ecual to the chars in the index i + lenght
                if (strncmp(&input[i], number[j], strlen(number[j])) == 0){
                    if (respons[0] == -1){
                        respons[0] = (char)j + 1;
                    }
                    respons[1] = (char)j + 1;
                }
            }
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
    inputs = fopen("inputs2.txt", "r");

    //The sum of all input
    int sum = 0;

    while(fgets(line, LINE_MAX_LENGTH, inputs) != NULL){
        int result = findTwoDigits(line);
        printf("%d\n", result);
        sum += result; 
    }

    fclose(inputs);
    printf("%d\n", sum);

    return 0;
}

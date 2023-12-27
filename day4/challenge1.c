#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include <ctype.h>

int solution(char* line){
    int i = 0;
    int wins = 0;

    Nodo *wining_numbers = NULL;
    Nodo *my_numbers = NULL;

    //Skip the card part
    while(line[i] != ':' && i < strlen(line)){
        i++;         
    }

    //Obtain the wining numbers
    while(line[i] != '|' && i < strlen(line)){
        if (isdigit(line[i])){
            insertarNodo(&wining_numbers, atoi(&line[i]));       
            i++;
        } 
        i++;         
    } 

    //Obtain my numbers
    while(i < strlen(line)){
        if (isdigit(line[i])){
            insertarNodo(&my_numbers, atoi(&line[i]));       
            i++;
        } 
        i++;         
    }

    //Iterate thought number list
    Nodo* tmp_node = wining_numbers;
    while(tmp_node != NULL){
        if (existeValor(my_numbers, tmp_node->entero1) == 1){
            if (wins == 0){
                wins++;
            }else{
                wins = wins * 2;
            }
        }
        tmp_node = tmp_node->siguiente;
    }
    
    return wins;
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
        sum += solution(line);
    }

    fclose(inputs);
    printf("%d\n", sum);

    return 0;
}

/********************************************
* File Name : hashImplementation.c
* Purpose : Implementation of the hash ADT
* Creation Date : 10-01-2012
* Last Modified : Fri 05 Oct 2012 07:24:31 PM EDT
* Created By :  Calvin Nichols  
********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputInterface.h"

#define MAX_WORD_SIZE 30
#define TRUE  1
#define FALSE 0
#define INVALID -1

void takeInput(char *word, int MAX_SIZE){
    fgets(word, MAX_SIZE, stdin);
    word[strlen(word)-1] = '\0';
}

/*word MUST be null terminated*/
int alphabeticInput(char *word, int MIN_INPUT, int MAX_INPUT){
    int i;

    if (word[0] == '\0')
        return FALSE;

    forceLowercase(word);
    if (strlen(word) > MIN_INPUT-1 && strlen(word) < MAX_INPUT+1){  /* within specified size and character range */
        for (i=0; i<strlen(word); i++){
            if ( (word[i] < 'a' || word[i] > 'z') /*&& (word[i] < 'A' || word[i] > 'Z')*/ ){
                return FALSE;
            }
        }
    }
    else {
        return FALSE;
    }

    return TRUE;
}

void forceLowercase(char *str){
    int i;
    for (i=0; i<strlen(str); i++){
        if (str[i] < 'a' || str[i] > 'z')
            str[i] = str[i] + 32;
    }
}

/*
 *  1 = true
 *  0 = false
 * -1 = invalid input
 */
int booleanInput(char *word){

    if (word[0] == '\0')
        return INVALID;

    forceLowercase(word);
    if ( (strncmp(word, "yes", strlen(word)) == 0) || (strncmp(word, "y", strlen(word)) == 0) ){
        return TRUE;
    }
    else if ( (strncmp(word, "no", strlen(word)) == 0) || (strncmp(word, "n", strlen(word)) == 0) ){
        return FALSE;
    }

    return INVALID;
}

void cleanInputLine(char *buffer)
{
    if (buffer[strlen(buffer)-1] == '\n')
    {
        buffer[strlen(buffer)-1] = '\0';
    }
}

int numberSelection(char *input, char *max)
{

    if (input[0] == '\0')
    {
        return FALSE;
    }

    if (strlen(input) == 1)
    {
        if (input[0] < '1' || input[0] > max[0])
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }

    return FALSE;
}
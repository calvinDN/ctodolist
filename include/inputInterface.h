/********************************************
* File Name : inputInterface.h
* Purpose : Interface for the input functions
* Creation Date : 10-20-2012
* Last Modified : Sun 25 Nov 2012 09:49:34 PM EDT
* Created By :  Calvin Nichols  
********************************************/

/*********************************************************************
* function name: takeInput
* purpose: take user input and return input with newline excluded.
* preconditions: none.
* postconditions: a string.
* notes: .
*********************************************************************/
void takeInput(char *, int);

/*********************************************************************
* function name: alphabeticInput
* purpose: ensure input is only letters.
* preconditions: a string.
* postconditions: none.
* notes: .
*********************************************************************/
int alphabeticInput(char *, int, int);

/*********************************************************************
* function name: forceLowercase
* purpose: take alphabetic input and set it to lowercase
* preconditions: a string of alphabetic characters
* postconditions: a string of lowercase alphabetic characters
* notes: .
*********************************************************************/
void forceLowercase(char *);

/*********************************************************************
* function name: booleanInput
* purpose: ensure input means yes or no.
* preconditions: a string.
* postconditions: none.
* notes: 1 = true, 0 = false, -1 = invalid input
*********************************************************************/
int booleanInput(char *word);

/*********************************************************************
* function name: cleanInputLine
* purpose: removes newline.
* preconditions: a string.
* postconditions: a string with a newline removed.
* notes: .
*********************************************************************/
void cleanInputLine(char *line);

/*********************************************************************
* function name: numberSelection
* purpose: checks and limits user input to numbers 1 through 3.
* preconditions: user input.
* postconditions: a sorted array.
* notes: .
*********************************************************************/
int numberSelection(char *input, char *max);
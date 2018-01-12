
/********************************************************
 *  creditcardValidator.c
 *  Personal Project
 *
 *  Created by Nihal Pai on 09/01/18.
 *
 *  Solution by Nihal Pai, Tufts University
 ********************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef enum {FALSE = 0, TRUE = 1} boolean;

/* 
 * Name: double_digits(char[], int)
 * Parameters: Char array, Integer
 * Return: None
 * Purpose: - Step 1 in the Luhn Algorithm -
            Excluding the checknumber, every second digit in the
            provided credit card number is doubled (RHS to LHS)
            If the result exceeds 9, 9 is subtracted from the digit.
            The digit is then saved into the array.
 */
void double_digits (char card_num[], int num_digits)
{
    int int_temp;

    /* Start at second last digit */
    for (int i = num_digits - 2; i >= 0; i -= 2) {

        int_temp = card_num[i] - '0'; /* Convert char to int */

        int_temp *= 2;

        if (int_temp > 9) {
            int_temp -= 9;
        }

        card_num[i] = int_temp + '0'; /* Convert int back to char */
    }
}

/* 
 * Name: sum_digits(char[], int)
 * Parameters: Char array, Integer
 * Return: Integer
 * Purpose: - Step 2 in the Luhn Algorithm -
            Sums every resulting integer digit (converted from char)
            from step 1 (and the checknumber) in the credit card number array.
            Returns this sum.
 */
int sum_digits (char card_num[], int num_digits)
{
    int total_sum = 0;

    for (int i = 0; i < num_digits; i++) {
        total_sum += (card_num[i] - '0');
    }

    return total_sum;
}

/* 
 * Name: luhn_algorithm(char[], int)
 * Parameters: Char array, Integer
 * Return: Integer
 * Purpose: - Step 3 in the Luhn Algorithm -
            Calls steps 1 & 2.
            If the total sum ends in a 0, the credit card number is valid.
            If not, it is invalid.
 */
int luhn_algorithm (char card_num[], int num_digits)
{
    double_digits(card_num, num_digits);
    int total_sum = sum_digits(card_num, num_digits);

    if (total_sum % 10 == 0) {
        return TRUE;
    }
    return FALSE;
}

/* Main */
int main() 
{
    int issuing_network = 0;
    int num_digits = 0;
    boolean valid_input = FALSE;

    /* Alternate input method: */
    // char *issuing_network;
    // printf("What is your card's issuing network?\n");
    // fgets(issuing_network, 100, stdin);

    /* Menu of networks */
    printf("\n-------- CREDIT CARD VALIDATOR --------\n");
    printf("This programme utilises Hans Peter Luhn's\nchecksum algorithm ");
    printf("to determine the validity of\ncredit cards from a select list of");
    printf("\nissuing networks.\n\n");

    while (issuing_network != 11) {
        do {
            printf("Enter the corresponding number of your card's issuing network\n");
            printf("or enter 11 to quit:\n");
            printf("1. American Express\n2. Bankcard\n3. China Union Pay (16 digits)\n");
            printf("4. China Union Pay (17 digits)\n5. China Union Pay (18 digits)\n");
            printf("6. China Union Pay (19 digits)\n7. Visa (13 digits)\n8. Visa (16 digits)\n");
            printf("9. Visa (19 digits)\n10. Mastercard\n11. Quit\n\n");
            scanf("%d", &issuing_network);

            if (issuing_network == 1) {
                num_digits = 15;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 2) {
                num_digits = 16;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 3) {
                num_digits = 16;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 4) {
                num_digits = 17;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 5) {
                num_digits = 18;
                valid_input = TRUE;
                break;
            } else if(issuing_network == 6) {
                num_digits = 19;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 7) {
                num_digits = 13;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 8) {
                num_digits = 16;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 9) {
                num_digits = 19;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 10) {
                num_digits = 19;
                valid_input = TRUE;
                break;
            } else if (issuing_network == 11) {
                return EXIT_SUCCESS;
            } else {
                valid_input = FALSE;
                printf("Invalid selection. Please try again.\n\n");
            }       

        } while (valid_input == FALSE);

        /* Declare char array to hold credit card number: */
        char card_num[num_digits];

        /* User dialogue: */
        printf("Enter your credit card number: \n");
        scanf("%s", card_num);
        printf("Checking for validity...\n");
        
        if (luhn_algorithm(card_num, num_digits) == TRUE) {
            printf("Your credit card is valid!\n\n");
        } else {
            printf("Your credit card is invalid.\n\n");
        }
    }

    return EXIT_SUCCESS;
}
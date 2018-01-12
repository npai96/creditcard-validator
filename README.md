# creditcard-validator
A simple C programme that utilises the Luhn Algorithm to validate credit card numbers from a select list of issuing networks 
(American Express, Bankcard, China Union Pay, Visa, and Mastercard).

Compiling & Running Instructions:
Since the programme only involves one file, I felt it did not warrant the need to provide a Makefile.
Simply enter the following to compile: gcc -Wall -g -o [desired_executable] creditcardValidator.c
And the following to run: ./[desired_executable]

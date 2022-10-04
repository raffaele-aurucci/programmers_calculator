#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "functions.h"


/* binary conversion */

int * insert_binary_number(void) {

    int *binary_array, number_of_bit;

    binary_array = calloc(32, sizeof(int));

    do {
        printf("\nHow many bits do you want to insert? (max 32): ");
        scanf("%d", &number_of_bit);

        if(number_of_bit < 0 || number_of_bit > 32)
            printf("\nInput not valid, try again...");

    } while (number_of_bit < 0 || number_of_bit > 32);


    int i;

	for(i = 0; i < number_of_bit; i++) {
        printf("\nInsert bit in position %d: ", i);
        scanf("%d", &binary_array[i]);
	}
	
	//invert the order of elements in binary_array
	for(i = 0; i < 16; i++) {
	    int tmp = binary_array[i];
        binary_array[i] = binary_array[31-i];
        binary_array[31-i] = tmp;
	}

    return binary_array;
}


long unsigned int convert_binary_to_decimal(const int binary_array[]) {

    int i; long unsigned int decimal_number = 0;

	for(i = 0; i < 32; i++){

        decimal_number = decimal_number + (binary_array[i] * pow(2, 31 - i));
    }

	return decimal_number;
}


int * convert_binary_to_hexadecimal(const int binary_array[]) {

    int *hexadecimal_array;

    hexadecimal_array = calloc(8, sizeof(int));

    int index_slot_bin; int index_bin_array=0; int index_hex_array = 0;

	//convert array from binary to hexadecimal
	while(index_bin_array < 32) {
		for(index_slot_bin=0; index_slot_bin < 4; index_slot_bin++, index_bin_array++)
		    hexadecimal_array[index_hex_array] = hexadecimal_array[index_hex_array] + (binary_array[index_bin_array] * pow(2, 3 - index_slot_bin));
		
		index_hex_array++;
	}

    return hexadecimal_array;
}



/* decimal conversion */

long unsigned int insert_decimal_number(void) {

    int decimal_number;

    printf("\nInsert a decimal number (>=0): ");
    scanf("%d", &decimal_number);

    return decimal_number;
}


int * convert_decimal_to_binary(long unsigned int decimal_number) {

    int i = 0, *binaryArray, tmp;
    long unsigned int copy_decimal_number = decimal_number;

	binaryArray = calloc(32, sizeof(int));

	while(copy_decimal_number > 0) {
	    binaryArray[i] = copy_decimal_number % 2;
        copy_decimal_number = copy_decimal_number / 2;
	    i++;
	}

	//invert the order of elements in binary_array
	for(i = 0; i < 16; i++) {
	    tmp = binaryArray[i];
        binaryArray[i] = binaryArray[31 - i];
        binaryArray[31 - i] = tmp;
	}

    return binaryArray;
}


int * convert_decimal_to_hexadecimal(long unsigned int decimal_number){

    int * hexadecimal_array, i = 0, tmp;

    hexadecimal_array = calloc(8, sizeof(int));

    while (decimal_number > 0){
        hexadecimal_array[i] = decimal_number % 16;
        decimal_number = decimal_number / 16;
        i++;
    }

    //invert the order of element in hexadecimal array
    for(i = 0; i < 4; i++){
        tmp = hexadecimal_array[i];
        hexadecimal_array[i] = hexadecimal_array[7 - i];
        hexadecimal_array[7 - i] = tmp;
    }

    return hexadecimal_array;
}



/* hexadecimal conversion */

int * insert_hexadecimal_number(void) {

    int dimension_hex_array, *hexadecimal_array;
    char *hexadecimal_array_string, tmp;

    hexadecimal_array_string = calloc(9, sizeof(char));
    hexadecimal_array = calloc(8, sizeof(int));

    printf("\nInsert hexadecimal number (max 8 cipher): ");
    scanf("%s", hexadecimal_array_string);

    dimension_hex_array = strlen(hexadecimal_array_string);

    for (int i = dimension_hex_array; i < 8; i++)
        hexadecimal_array_string[i] = '0';

    hexadecimal_array_string[8] = '\0';

    //invert the order of ciphers in hexadecimal_array
    for (int i = 0; i < dimension_hex_array / 2; i++) {
        tmp = hexadecimal_array_string[i];
        hexadecimal_array_string[i] = hexadecimal_array_string[dimension_hex_array - 1 - i];
        hexadecimal_array_string[dimension_hex_array - 1 - i] = tmp;
    }

    //invert the order of element in hexadecimal_array
    for (int i = 0; i < 4; i++) {
        tmp = hexadecimal_array_string[i];
        hexadecimal_array_string[i] = hexadecimal_array_string[7 - i];
        hexadecimal_array_string[7 - i] = tmp;
    }

    //create hexadecimal_array with int element
    for (int i = 0; i < 8; i++) {
        char char_value = hexadecimal_array_string[i];

        switch (char_value) {

            case 'A':
                hexadecimal_array[i] = 10;
            break;

            case 'B':
                hexadecimal_array[i] = 11;
            break;

            case 'C':
                hexadecimal_array[i] = 12;
            break;

            case 'D':
                hexadecimal_array[i] = 13;
            break;

            case 'E':
                hexadecimal_array[i] = 14;
            break;

            case 'F':
                hexadecimal_array[i] = 15;
            break;

            case '0':
                hexadecimal_array[i] = 0;
            break;

            case '1':
                hexadecimal_array[i] = 1;
            break;

            case '2':
                hexadecimal_array[i] = 2;
            break;

            case '3':
                hexadecimal_array[i] = 3;
            break;

            case '4':
                hexadecimal_array[i] = 4;
            break;

            case '5':
                hexadecimal_array[i] = 5;
            break;

            case '6':
                hexadecimal_array[i] = 6;
            break;

            case '7':
                hexadecimal_array[i] = 7;
            break;

            case '8':
                hexadecimal_array[i] = 8;
            break;

            case '9':
                hexadecimal_array[i] = 9;
            break;

        }
    }

    return hexadecimal_array;

}

int * convert_hexadecimal_to_binary(const int hexadecimal_array[]) {

    int *binary_array, i, index_bin = 0, j, tmp;

    binary_array = calloc(32, sizeof(int));

    int *hexadecimal_array_copy = calloc(8, sizeof(int));

    for (i = 0; i < 8; i++) {
        hexadecimal_array_copy[i] = hexadecimal_array[i];
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (hexadecimal_array_copy[i] == 0)
                binary_array[index_bin] = 0;
            else if (hexadecimal_array_copy[i] != 0) {
                binary_array[index_bin] = hexadecimal_array_copy[i] % 2;
                hexadecimal_array_copy[i] = hexadecimal_array_copy[i] / 2;
            }

            index_bin++;
        }

        //swap slot binary
        tmp = binary_array[index_bin - 1];
        binary_array[index_bin - 1] = binary_array[index_bin - 4];
        binary_array[index_bin - 4] = tmp;

        tmp = binary_array[index_bin - 2];
        binary_array[index_bin - 2] = binary_array[index_bin - 3];
        binary_array[index_bin - 3] = tmp;

    }

    return binary_array;
}


long unsigned int convert_hexadecimal_to_decimal(const int hexadecimal_array[]){

}


void show_binary_array(const int binary_array[]){

    printf("\nBinary number: ");

    for(int i = 0; i < 32; i++)
        printf("%d", binary_array[i]);
}


void show_decimal_number(long unsigned int decimal_number){

    printf("\nDecimal number: %lu", decimal_number);
}


void show_hexadecimal_array(const int hexadecimal_array[]){

    int i;

    printf("\nHexadecimal number: ");

    for(i = 0; i < 8; i++) {

        int int_value = hexadecimal_array[i];

        switch (int_value) {

            case 10:
                printf("A");
            break;

            case 11:
                printf("B");
            break;

            case 12:
                printf("C");
            break;

            case 13:
                printf("D");
            break;

            case 14:
                printf("E");
                break;

            case 15:
                printf("F");
            break;

            default:
                printf("%d", hexadecimal_array[i]);
            break;
        }
    }
}

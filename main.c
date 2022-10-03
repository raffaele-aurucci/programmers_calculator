#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {

    char choose;
    int *binary_array = calloc(32, sizeof(int));
    long unsigned int decimal_number;
    int *hexadecimal_array = calloc(8, sizeof(int));

    printf("\nWhat type of conversion do you want to do?\n\n");
    printf("Binary\t\t--->\t   Decimal\t--->\tHexadecimal\t(Insert B/b)\n");
    printf("Decimal\t\t--->\t   Binary\t--->\tHexadecimal\t(Insert D/d)\n");
    printf("Hexadecimal\t--->\t   Binary\t--->\tDecimal\t\t(Insert H/h)\n");

    do {
        printf("\nInsert choose: ");
        scanf("%s", &choose);

        switch(choose) {
            case 'B': case 'b':
                binary_array = insert_binary_number();
                decimal_number = convert_binary_to_decimal(binary_array);
                hexadecimal_array = convert_binary_to_hexadecimal(binary_array);
                show_binary_array(binary_array);
                show_decimal_number(decimal_number);
                show_hexadecimal_array(hexadecimal_array);
            break;

            case 'D': case 'd':
                decimal_number = insert_decimal_number();
                binary_array = convert_decimal_to_binary(decimal_number);
//                hexadecimal_array = convert_decimal_to_hexadecimal(decimal_number);
                hexadecimal_array = convert_binary_to_hexadecimal(binary_array);
                show_binary_array(binary_array);
                show_decimal_number(decimal_number);
                show_hexadecimal_array(hexadecimal_array);
            break;

            case 'H': case 'h':
                hexadecimal_array = insert_hexadecimal_number();
                binary_array = convert_hexadecimal_to_binary(hexadecimal_array);
                decimal_number = convert_binary_to_decimal(binary_array);
                show_binary_array(binary_array);
                show_decimal_number(decimal_number);
                show_hexadecimal_array(hexadecimal_array);
            break;

            default:
                printf("Input not valid, try again...\n");
            break;
        }

    }while(choose != 'B' && choose != 'b' && choose != 'D' && choose != 'd' && choose != 'H' && choose != 'h');

    return 0;
}

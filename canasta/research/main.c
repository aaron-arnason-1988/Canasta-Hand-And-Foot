#include <stdio.h>


typedef struct {
    int x;
    int y;
    void (*cal)(int, int);      // pointer to a function taking int, int and return nothing.
} calculate;


void print_addition(int x, int y) {
    printf("%d+%d=%d\n", x, y, x+y);
}

void print_subtraction(int x, int y) {
    printf("%d-%d=%d\n", x, y, x-y);
}

void print_multiplication(int x, int y) {
    printf("%d*%d=%d\n", x, y, x*y);
}

void print_division(int x, int y) {
    printf("%d/%d=%d\n", x, y, x/y);
}

typedef void (*funcPtr)(int, int);


int main() {

    funcPtr calculator_functions[4] = { print_addition, print_subtraction, print_multiplication, print_division };
    calculate d = { 54, 12, NULL };
    

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &d.x);
        printf("\n");

        printf("Enter a number: ");
        scanf("%d", &d.y);
        printf("\n");

        printf("Enter a function: \n");
        printf("(1) add\n");
        printf("(2) sub\n");
        printf("(3) mul\n");
        printf("(4) div\n");
        int temp;
        scanf("%d", &temp);
        printf("\n");

        d.cal = calculator_functions[temp - 1];
        d.cal(d.x, d.y);
    }

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool a = true;
    while (a) {
        char operation;
        double first, second;
        printf("Enter an operator (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &operation); // Add a space before %c to consume the newline character
        if (operation == 'q') {
            printf("Goodbye, Have a nice day!\n");
            a = false;
        } else {
            printf("Enter both numbers (space separated): ");
            scanf("%lf %lf", &first, &second);
            switch (operation) {
                case '+':
                    printf("%.1lf + %.1lf = %.1lf\n", first, second, first + second);
                    break;
                case '-':
                    printf("%.1lf - %.1lf = %.1lf\n", first, second, first - second);
                    break;
                case '*':
                    printf("%.1lf * %.1lf = %.1lf\n", first, second, first * second);
                    break;
                case '/':
                    if (second != 0) {
                        printf("%.1lf / %.1lf = %.1lf\n", first, second, first / second);
                    } else {
                        printf("Error! Division by zero is not allowed.\n");
                    }
                    break;
                default:
                    printf("Error! Operator is not correct\n");
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, userGuess;
    int attempts = 0;

    srand(time(NULL));

    answer = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a random number between 1 and 100. Try to guess it.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess < answer) {
            printf("Higher! Try again, attempts = %d.\n", attempts);
        } else if (userGuess > answer) {
            printf("Lower! Try again, attempts = %d.\n", attempts);
        } else {
            printf("Congratulations! You guessed the number %d correctly in %d attempts!\n", answer, attempts);
        }
    } while (userGuess != answer);

    return 0;
}

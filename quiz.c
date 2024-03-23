#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[200];
    char options[4][50];
    int correctOption;
};

void displayQuestion(struct Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

void playQuiz(struct Question quiz[], int numQuestions) {
    int score = 0;

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        displayQuestion(quiz[i]);

        int userAnswer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &userAnswer);

        if (userAnswer >= 1 && userAnswer <= 4) {
            if (userAnswer == quiz[i].correctOption) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %d. %s\n", quiz[i].correctOption, quiz[i].options[quiz[i].correctOption - 1]);
            }
        } else {
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            i--;
        }
    }

    printf("\nQuiz completed!\nYour score: %d/%d\n", score, numQuestions);
}

int main() {
    struct Question quiz[] = {
        {"how is the winner of ballon d'or 2021?", {"messi", "levandoski", "gorgino", "benzema"}, 1},
        {" how many time real madrid play the final of ucl?", {"14", "20", "16", "17"}, 4},
        {"how is the winner of world cup 1994?", {"italy", "brasil", "germany", "france"}, 2},
        {"how score the winner goa in wc final 2014 ?", {"muller", "gotz", "kross", "ozil"}, 1},
        {"how is the winner of ucl 2003/2004", {"real madrid", "porto", "bayren ", "milan"}, 2}
    };

    int numQuestions = sizeof(quiz) / sizeof(quiz[0]);

    printf("Welcome to the Quiz Game!\n");
    printf("You will be presented with a series of multiple-choice questions.\n");
    printf("Choose the correct option (1-4).\n\n");

    playQuiz(quiz, numQuestions);

    return 0;
}




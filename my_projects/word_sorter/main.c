#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* order_words(char* ordered, const char* words)
{
    char* word = malloc(20);
    memset(word, 0, 20);
    char* ordered_words[9];
    int word_index = 0;
    int max_index = 0;

    for (int i = 0, j = 0; *(words + i) != 0; i++) {
        *(word + j) = *(words + i);

        if (*(word + j) > 47 && *(word + j) < 58) {
            word_index = *(word + j) - 49;
            if (word_index > max_index)
                max_index = word_index;
        }

        if (*(words + i) == ' ') {
            *(word + j) = 0;
            ordered_words[word_index] = word;
            word = malloc(20);
            memset(word, 0, 20);
            j = 0;
            continue;
        }

        j++;
    }

    ordered_words[word_index] = word;

    for (int i = 0, j = 0, k = 0; i <= max_index; i++) {
        while (*(ordered_words[i] + j) != 0) {
            *(ordered + k) = *(ordered_words[i] + j);
            k++;
            j++;
        }

        if (i < max_index) {
            *(ordered + k) = ' ';
        }
        else {
            *(ordered + k) = 0;
            break;
        }

        k++;
        j = 0;

    }
    
    return ordered;
}

int main(void) {
    char* ordered = malloc(600);
    printf("%s", order_words(ordered, "is2 Thi1s T4est 3a", "Thi1s is2 3a T4est"));
}
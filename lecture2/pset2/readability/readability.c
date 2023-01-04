#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

float avarage_per_100(float number, float word);

int main(void) 
{
    string text = get_string("Text: ");
    
    int letter = 0;
    int word = 1;
    int sentece = 0;
    int i = 0;
    float result;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z')
        {
            letter++;
        }
        else if(text[i] == ' ')
        {
            word++;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentece++;
        }
    }
    
    result = 0.0588 * avarage_per_100(letter, word) - 0.296 * avarage_per_100(sentece, word) - 15.8;

    printf("letter: %i\n", letter);
    printf("word: %i\n", word);
    printf("sentece: %i\n", sentece);
    if ((int) round(result) > 16)
    {
        printf("Grade: 16+\n");
    }
    else
    {
        printf("Grade: %i\n",(int) round(result));
    }


    printf("test1 = EXPECTED: 464.29 | RESULT: %f\n", avarage_per_100(65, 14));
    printf("test2 = EXPECTED: 28.57 | RESULT: %f\n", avarage_per_100(4, 14));
    printf("test3= EXPECTED: 382.14 | RESULT: %f\n", avarage_per_100(214, 56));
    printf("test4 = EXPECTED: 7.14 | RESULT: %f\n", avarage_per_100(4, 56));

}

float avarage_per_100(float number, float word)
{
    float result;
    result = number / word * 100;
    return result;
}

// coleman-liau is: index = 0.0588 * L - 0.296 * S 15.8
// L is avarege number of letters per 100 words in the text
// S is avarage number of senteces per 100 words in the text

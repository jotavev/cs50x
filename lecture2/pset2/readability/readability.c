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

    if ((int) round(result) > 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int) round(result) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",(int) round(result));
    }

}

float avarage_per_100(float number, float word)
{
    float result;
    result = number / word * 100;
    return result;
}

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string strUpper(string s);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2) 
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int result = 0;
    word = strUpper(word);
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < strlen(alphabet); j++)
        {
            if (word[i] == alphabet[j])
            {
                result += POINTS[j];
            }
        }
    }
    return result;
}

string strUpper(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) != 0)
        {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}

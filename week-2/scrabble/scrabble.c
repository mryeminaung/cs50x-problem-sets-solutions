#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[26] = {
    1,  // A
    3,  // B
    3,  // C
    2,  // D
    1,  // E
    4,  // F
    2,  // G
    4,  // H
    1,  // I
    8,  // J
    5,  // K
    1,  // L
    3,  // M
    1,  // N
    1,  // O
    3,  // P
    10, // Q
    1,  // R
    1,  // S
    1,  // T
    1,  // U
    4,  // V
    4,  // W
    8,  // X
    4,  // Y
    10  // Z
};

int compute_score(string word);

int main(void)
{
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // compute the score of each word
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  if (score1 > score2)
  {
    printf("Player 1 wins!\n");
  }
  else if (score1 < score2)
  {
    printf("Player 2 wins!\n");
  }
  else
  {
    printf("Tie!\n");
  }
}

int compute_score(string word)
{
  int score = 0;
  int len = strlen(word);

  // compute score for each character
  for (int i = 0; i < len; i++)
  {
    if (isupper(word[i]))
    {
      score += POINTS[word[i] - 'A'];
    }
    else if (islower(word[i]))
    {
      score += POINTS[word[i] - 'a'];
    }
  }

  return score;
}

#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
  // prompt the user for some text
  string text = get_string("Text: ");

  // count the number of letters, words, and sentences in the text
  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  // L => average number of letters per 100 words
  float L = (letters / (float)words) * 100;

  // S => average number of sentences per 100 words
  float S = (sentences / (float)words) * 100;

  // Coleman-Liau index formula
  int index = round(0.0588 * L - 0.296 * S - 15.8);

  // printf("Letters: %d\n", letters);
  // printf("Words: %d\n", words);
  // printf("Sentences: %d\n", sentences);
  // printf("L: %f\t", L);
  // printf("S: %f\t", S);
  // printf("Index: %d\n", index);

  // print the grade level
  if (index < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (index >= 1 && index <= 15)
  {
    printf("Grade %d\n", index);
  }
  else
  {
    printf("Grade 16+\n");
  }
}

int count_letters(string text)
{
  // return the number of letters in text
  int no_of_letters = 0;
  int len = strlen(text);

  for (int i = 0; i < len; i++)
  {
    if (isalpha(text[i]))
    {
      no_of_letters++;
    }
  }
  return no_of_letters;
}

int count_words(string text)
{
  // return the number of words in text
  int spaces = 0;
  int len = strlen(text);

  for (int i = 0; i < len; i++)
  {
    if (isblank(text[i]))
    {
      spaces++;
    }
  }
  return spaces + 1;
}

int count_sentences(string text)
{
  // return the number of sentences in text
  int no_of_sentences = 0;
  int len = strlen(text);

  for (int i = 0; i < len; i++)
  {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
      no_of_sentences++;
    }
  }
  return no_of_sentences;
}

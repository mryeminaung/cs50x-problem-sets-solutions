#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  // Make sure program was run with just one command-line argument
  if (argc == 1 || argc >= 3)
  {
    printf("Enter exactly one command-line argument\n");
    return 1;
  }

  if (argc == 2)
  {
    // Make sure every character in argv[1] is a digit
    bool isAllDigit = false;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
      if (!isdigit(argv[1][i]))
      {
        isAllDigit = false;
        break;
      }
      isAllDigit = true;
    }

    if (isAllDigit)
    {
      // Convert argv[1] from a `string` to an `int`
      int k = atoi(argv[1]);

      // Prompt user for plaintext
      string plainText = get_string("plaintext:  ");
      char cipherText[strlen(plainText) + 1];

      // For each character in the plaintext:
      for (int i = 0; i < strlen(plainText); i++)
      {
        // Rotate the character if it's a letter
        if (isdigit(plainText[i]) || ispunct(plainText[i]) || isspace(plainText[i]))
        {
          cipherText[i] = plainText[i];
        }
        else if (islower(plainText[i]))
        {
          cipherText[i] = ((plainText[i] - 'a' + k) % 26) + 'a';
        }
        else if (isupper(plainText[i]))
        {
          cipherText[i] = ((plainText[i] - 'A' + k) % 26) + 'A';
        }
      }
      cipherText[strlen(plainText)] = '\0';
      printf("ciphertext: %s\n", cipherText);
      return 0;
    }
    else
    {
      printf("Usage: ./caesar [non-negative integer]\n");
      return 1;
    }
  }
}

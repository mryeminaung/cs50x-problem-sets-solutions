#include <cs50.h>
#include <stdio.h>

int main()
{

  int height = 0;
  int space = 0;
  int gap = 2;

  do
  {
    height = get_int("Height: ");
  } while (!(height >= 1 && height <= 8));

  space = height - 1;

  for (int row = 0; row < height; row++)
  {
    // add space before #
    for (int s = 0; s < space; s++)
    {
      printf(" ");
    }

    // print left pyramid
    for (int hash = 0; hash < row + 1; hash++)
    {
      printf("#");
    }

    // add gap size 2 as space before #
    for (int g = 0; g < gap; g++)
    {
      printf(" ");
    }

    // print right pyramid
    for (int hash = 0; hash < row + 1; hash++)
    {
      printf("#");
    }

    space -= 1;
    printf("\n");
  }
}

#include <cs50.h>
#include <stdio.h>

int main()
{
  // get name from the user
  string name = get_string("What's your name? ");
  // display typed name
  printf("hello, %s\n", name);
}

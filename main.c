#include <stdio.h>
int main()
{
int stack[1000];
int cein = 0; 
while (!feof(stdin))
{
  int symbol = getchar();
  int x;
  switch (symbol)
  {
    case ' ':
    case '\n':
        break;
    case '=':
        printf("Result = %d\n", stack[cein - 1]);
        cein--;
        break;
    case '+':
        stack[cein - 2] = stack[cein - 2] + stack[cein - 1];
        cein--;
        break;
    case '-':
        stack[cein - 2] = stack[cein - 2] - stack[cein - 1];
        cein--;
        break;
    case '*':
        stack[cein - 2] = stack[cein - 1] * stack[cein - 2];
        cein--;
        break;
    case '/':
        stack[cein - 2] = stack[cein - 2] / stack[cein - 1];
        cein--;
        break;
    default:
        ungetc(symbol, stdin);
        if (scanf("%d", &x) != 1)
        {
          fprintf(stderr, "Can't read this symbol/number\n");
          return -1;
        }
        else
        {
          stack[cein] = x;
          cein++;
        }
   }
 }
    printf("Result = %d\n", stack[cein - 1]);
    return 0;
}

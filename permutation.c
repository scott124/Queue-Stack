#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
void swap(char *x, char *y)
{
    char tmp;
    
    tmp = *x;
    *x  = *y;
    *y  = tmp;
}
void permutation(char *start, char *end)
{
    char *cp;
    if (start == end)
        printf("%s\n", start);
    else
        for (cp=start; cp<=end; cp++)
        {
            swap(cp, end);
            permutation(start, end-1);
            swap(cp, end);
        }
}
int main(int argc, char ** argv)
{
    char str[] = {'1', '2', '3','\0'};
    permutation(str, &str[2]);
    return 0;
}


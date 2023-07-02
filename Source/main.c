#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ReversingString(char *);

int main(int argc, const char *argv[])
{
    char *Context;
    char *ReversedContext;

    printf("%s", "Please Enter Your Text : ");
    scanf("%s", Context);

    ReversedContext = ReversingString(Context);

    if (strstr(Context, ReversedContext))
        printf("%s%c", "Your Text Is A Palindrome", '\n');
    else
        printf("%s%c", "Your Text Is Not A Palindrome", '\n');

    return (int)0;
}

char *ReversingString(char *String)
{
    unsigned short int StringLength = (unsigned short int)strlen(String);
    char *ReversedString = (char *)calloc(sizeof(char), StringLength);

    for (unsigned short int Counter = (unsigned short int)0, ReverseCounter = (StringLength - (unsigned short int)1); Counter < StringLength; Counter++, ReverseCounter--)
    {
        (*(ReversedString + Counter)) = (*(String + ReverseCounter));
    }

    return ReversedString;
}
#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    long long int UserNumber = (long long int)0;

    while (true)
    {
        printf("%s", "Please Enter Your Number : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%lld", &UserNumber);

        if (ResultOfReading == (int)1)
        {
            break;
        }
        else
        {
            printf("%c%s%c", '\a', "Error: Please Just Enter A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    if ((UserNumber % (long long int)2) == (long long int)0)
        printf("%s%c", "Your Number Is Even", '\n');
    else
        printf("%s%c", "Your Number Is Odd", '\n');

    return (int)0;
}

void ClearInputBuffer(void)
{
    int Character = (int)0;

    while (true)
    {
        Character = (int)getchar();

        if ((Character != (int)'\n') && (Character != (int)EOF))
            continue;
        else
            break;
    }
}
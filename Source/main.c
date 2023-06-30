#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);
unsigned long long int GenerateFibonacci(unsigned long long int);

int main(int argc, const char *argv[])
{
    unsigned long long int UserNumber = (unsigned long long int)0;
    unsigned long long int FibonacciNumber = (unsigned long long int)0;

    while (true)
    {
        printf("%s", "Please Enter A Number : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%llu", &UserNumber);

        if (ResultOfReading == (int)1)
        {
            if (UserNumber < (unsigned long long int)0)
            {
                printf("%c%s%c", "\a", "Error: Your Number Have To Be Bigger Than Zero", '\n');

                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("%c%s%c", '\a', "Error: Please Just Enter A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    FibonacciNumber = GenerateFibonacci(UserNumber);

    printf("%s%llu%c", "Fibonacci Of Your Number Is : ", FibonacciNumber, '\n');

    return 0;
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

unsigned long long int GenerateFibonacci(unsigned long long int Number)
{
    if (Number == (unsigned long long int)0)
        return (unsigned long long int)0;
    else if (Number == (unsigned long long int)1)
        return (unsigned long long int)1;
    else
        return (GenerateFibonacci(Number - (unsigned long long int)1) + GenerateFibonacci(Number - (unsigned long long int)2));
}
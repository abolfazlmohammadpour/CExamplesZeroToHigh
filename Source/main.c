#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);
unsigned long long int GenerateFactorial(unsigned long long int);

int main(int argc, const char *argv[])
{
    unsigned long long int Number = (unsigned long long int)0;
    unsigned long long int FactorialOfNumber = (unsigned long long int)0;

    while (true)
    {
        printf("%s", "Please Enter Your Number : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%llu", &Number);

        if (ResultOfReading == 1)
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

    FactorialOfNumber = GenerateFactorial(Number);
    printf("%s%llu%c", "Factorial Of Your Number Is : ", FactorialOfNumber, '\n');

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

unsigned long long int GenerateFactorial(unsigned long long int Number)
{
    unsigned long long int FactorialOfNumber = (unsigned long long int)1;

    for (unsigned long long int Counter = (unsigned long long int)1; Counter <= Number; Counter++)
    {
        FactorialOfNumber = FactorialOfNumber * Counter;
    }

    return FactorialOfNumber;
}
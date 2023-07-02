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

unsigned long long int GenerateFibonacci(unsigned long long int Number)
{
    unsigned long long int Fibonaccis[(Number + 1)];
    unsigned long long int FibonacciOfNumber = (unsigned long long int)0;

    // Calculate Fibonaccis
    Fibonaccis[0] = (unsigned long long int)0;
    Fibonaccis[1] = (unsigned long long int)1;
    for (unsigned long long int Counter = (unsigned long long int)0; Counter < Number; Counter++)
    {
        if (Counter > 1)
            Fibonaccis[Counter] = (Fibonaccis[(Counter - 1)] + Fibonaccis[(Counter - 2)]);
    }

    // Calculate Fibonacci Of Number
    if (Number == 0)
        FibonacciOfNumber = Fibonaccis[0];
    else if (Number == 1)
        FibonacciOfNumber = Fibonaccis[1];
    else
        FibonacciOfNumber = (Fibonaccis[(Number - 1)] + Fibonaccis[(Number - 2)]);

    return FibonacciOfNumber;
}
#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    unsigned long long int Number = (unsigned long long int)0;
    unsigned long long int SumOfDivisors = (unsigned long long int)0;

    // Getting Number Value From User
    while (true)
    {
        printf("%s", "Please Enter Your Number : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%llu", &Number);

        if (ResultOfReading == 1)
        {
            if (Number != 0)
            {
                break;
            }
            else
            {
                printf("%c%s%c", '\a', "Error: Your Number Have To Be Bigger Than Zero.", '\n');
                continue;
            }
        }
        else
        {
            printf("%c%s%c", '\a', "Error: Please Just Enter A Number.", '\n');
            continue;
        }
    }

    // Calculation Sum Of Divisors Of Number
    for (unsigned long long int Counter = (unsigned long long int)1; Counter < Number; Counter++)
    {
        if (((Number % Counter) == 0))
            SumOfDivisors += Counter;
    }

    if ((Number == SumOfDivisors))
        printf("%s%c", "Your Number Is A Perfect Number", '\n');
    else
        printf("%s%c", "Your Number Is Not A Perfect Number", '\n');

    return (int)0;
}

void ClearInputBuffer(void)
{
    int Character = (int)0;

    while (true)
    {
        Character = (int)getchar();

        if (((Character != (int)'\n') && (Character != (int)EOF)))
            continue;
        else
            break;
    }
}
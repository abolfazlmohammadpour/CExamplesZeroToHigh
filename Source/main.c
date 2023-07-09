#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    unsigned long long int Number = (unsigned long long int)0;
    bool IsPrime = (bool)true;

    while (true)
    {
        printf("%s", "Please Enter Your Number : ");

        int ResultOfReading = (int)0;
        ResultOfReading = scanf("%llu", &Number);

        if (ResultOfReading == 1)
        {
            if (Number != (unsigned long long int)0)
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
            printf("%c%s%c", '\a', "Error: Please Enter Just A Number.", '\n');
            continue;
        }
    }

    for (unsigned long long int Counter = (unsigned long long int)2; Counter < Number; Counter++)
    {
        if (((Number % Counter) == 0))
        {
            IsPrime = (bool)false;
            break;
        }
    }

    if (IsPrime == true)
        puts("Your Number Is A PrimeNumber");
    else
        puts("Your Number Is Not A PrimeNumber");

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
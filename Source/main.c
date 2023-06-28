#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ClearInputBuffer(void);
unsigned short int GenerateRandomNumber(unsigned short int);

int main(int argc, const char *argv[])
{
    unsigned short int UserNumber = (unsigned short int)0;
    unsigned short int GeneratedNumber = (unsigned short int)0;

    while (true)
    {
        printf("%s", "Please Guess A Number (The Number Have To Be From 0 To 9) : ");
        int ResultOfReading = (int)scanf("%hu", &UserNumber);

        if (ResultOfReading == 1)
        {
            if ((UserNumber >= 0) && (UserNumber <= 9))
            {
                break;
            }
            else
            {
                printf("%c%s%c", '\a', "Error: The Number Have To Be From 0 To 9.", '\n');
                continue;
            }
        }
        else
        {
            ClearInputBuffer();
            printf("%c%s%c", '\a', "Error: Please Enter Just A Number.", '\n');
            continue;
        }
    }

    GeneratedNumber = (unsigned short int)GenerateRandomNumber((unsigned short int)UserNumber);

    if (UserNumber == GeneratedNumber)
        printf("%s%c", "You Are A Winner", '\n');
    else
        printf("%s%c", "You Are A Loser", '\n');

    return 0;
}

void ClearInputBuffer(void)
{
    int Chracter = (int)0;
    while (((Chracter = getchar()) != '\n') && (Chracter != EOF));
}

unsigned short int GenerateRandomNumber(unsigned short int UserNumber)
{
    unsigned short int GeneratedNumber = (unsigned short int)0;
    srand((unsigned int)((UserNumber * ((UserNumber / 2) - (UserNumber * 2))) + 18));
    GeneratedNumber = (unsigned short int)(rand() % 10);

    return GeneratedNumber;
}
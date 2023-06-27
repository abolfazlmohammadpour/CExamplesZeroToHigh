#include <stdio.h>
#include <stdbool.h>

#define Sum (unsigned short int)1
#define Subtraction (unsigned short int)2
#define Multiplication (unsigned short int)3
#define Division (unsigned short int)4

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    long double NumberOne = (long double)0, NumberTwo = (long double)0;
    unsigned short int Operation = (unsigned short int)0;

    // Getting Number One Value From User
    while (true)
    {
        printf("%s", "Please Enter Number One : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%LF", &NumberOne);

        if (ResultOfReading == (int)1) // Valid Value : Break Getting Number From User And Continue The Program
        {
            break;
        }
        else // Invalid Value : Get Again Number One Of User
        {
            ClearInputBuffer();
            printf("%c%s%c", '\a', "Error: Please Enter Just A Number.", '\n');
            continue;
        }
    }

    // Getting Number Two Value From User
    while (true)
    {
        printf("%s", "Please Enter Number Two : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%LF", &NumberTwo);

        if (ResultOfReading == (int)1) // Valid Value : Break Getting Number From User And Continue The Program
        {
            break;
        }
        else // Invalid Value : Get Again Number One Of User
        {
            ClearInputBuffer();
            printf("%c%s%c", '\a', "Error: Please Enter Just A Number.", '\n');
            continue;
        }
    }

    // Getting Opertaion Value From User
    while (true)
    {
        printf("%s%c", "Please Enter Number Of An Operation : ", '\n');
        printf("%hu%s%c", Sum, ") Sum", '\t');
        printf("%hu%s%c", Subtraction, ") Subtraction", '\t');
        printf("%hu%s%c", Multiplication, ") Multiplication", '\t');
        printf("%hu%s%c", Division, ") Division", '\n');

        int ResultOfReading = (int)0;
        ResultOfReading = scanf("%hu", &Operation);

        if (ResultOfReading == (int)1) // Valid Value : Break Getting Number From User And Continue The Program
        {
            if ((Operation >= Sum) && (Operation <= Division))
            {
                break;
            }
            else
            {
                printf("%c%s%c", '\a', "Please Enter A Valid Operation", '\n');
                continue;
            }
        }
        else // Invalid Value : Get Again Number One Of User
        {
            ClearInputBuffer();
            printf("%c%s%c", '\a', "Error: Please Enter Just A Number.", '\n');
            continue;
        }
    }

    switch (Operation)
    {
    case Sum:
    {
        long double SumIs = (NumberOne + NumberTwo);

        printf("%s%0.2LF%c", "Sum Is : ", SumIs, '\n');

        break;
    }
    case Subtraction:
    {
        long double SubtractionIs = (NumberOne - NumberTwo);

        printf("%s%0.2LF%c", "Subtraction Is : ", SubtractionIs, '\n');

        break;
    }
    case Multiplication:
    {
        long double MultiplicationIs = (NumberOne * NumberTwo);

        printf("%s%0.2LF%c", "Multiplication Is : ", MultiplicationIs, '\n');

        break;
    }
    case Division:
    {
        long double DivisionIs = (long double)0;

        if (NumberTwo == 0)
        {
            printf("%c%s%c", '\a', "Error: You Can Not Divide To Zero.", '\n');

            break;
        }
        else
        {
            DivisionIs = (NumberOne / NumberTwo);

            printf("%s%0.2LF%c", "Division Is : ", DivisionIs, '\n');

            break;
        }
    }
    }

    return 0;
}

void ClearInputBuffer(void)
{
    int Character = 0;

    while (((Character = getchar()) != '\n') && (Character != EOF));
}
#define FahrenheitToCelcius 1
#define CelciusToFahrenheit 2

#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    short int UserTemperature = 0, ConvertedTemperature = 0;
    unsigned short int Operation = 0;

    while (true)
    {
        printf("%s%c", "1) Fahrenheit To Celcius", '\n');
        printf("%s%c", "2) Celcius To Fahrenheit", '\n');
        printf("%s", "Please Select A Mode Of Converting : ");

        int ResultOfReading = 0;
        ResultOfReading = scanf("%hu", &Operation);

        if (ResultOfReading == 1)
        {
            if ((Operation >= FahrenheitToCelcius) && (Operation <= CelciusToFahrenheit))
            {
                break;
            }
            else
            {
                printf("%s%c", "Error: Invalid Operation, Please Try Again.", '\n');

                continue;
            }
        }
        else
        {
            printf("%s%c", "Error: Please Enter Just A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    while (true)
    {
        printf("%s", "Please Enter Your Temperature : ");

        int ResultOfReading = 0;
        ResultOfReading = scanf("%hd", &UserTemperature);

        if (ResultOfReading == 1)
        {
            break;
        }
        else
        {
            printf("%s%c", "Error: Please Enter Just A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    switch (Operation)
    {
    case FahrenheitToCelcius:
    {
        ConvertedTemperature = ((UserTemperature - 32) / 1.8);
        printf("%hd%s%hd%s%c", UserTemperature, "Fahrenheit Degree Is Equal To ", ConvertedTemperature, "Celcius Degree", '\n');

        break;
    }
    case CelciusToFahrenheit:
    {
        ConvertedTemperature = ((UserTemperature * 1.8) + 32);
        printf("%hd%s%hd%s%c", UserTemperature, "Celcius Degree Is Equal To ", ConvertedTemperature, "Fahrenheit Degree", '\n');

        break;
    }
    }

    return 0;
}

void ClearInputBuffer(void)
{
    int Character = 0;

    while (true)
    {
        Character = getchar();

        if ((Character != '\n') && (Character != EOF))
            continue;
        else
            break;
    }
}
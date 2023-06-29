#include <stdio.h>
#include <stdbool.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    long double UserWeight = (long double)0, UserHeight = (long double)0;
    long double UserBMI = (long double)0;

    while (true)
    {
        printf("%s", "Please Enter Your Weight : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%LF", &UserWeight);

        if (ResultOfReading == 1)
        {
            break;
        }
        else
        {
            printf("%s%c", "Error: Please Just Enter A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    while (true)
    {
        printf("%s", "Please Enter Your Height : ");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%LF", &UserHeight);

        if (ResultOfReading == 1)
        {
            break;
        }
        else
        {
            printf("%s%c", "Error: Please Just Enter A Number.", '\n');
            ClearInputBuffer();

            continue;
        }
    }

    UserBMI = (long double)((UserWeight / (UserHeight * UserHeight)) * 10000);

    printf("%s%LF%c", "Your BMI Is : ", UserBMI, '\n');

    return 0;
}

void ClearInputBuffer(void)
{
    int Character = (int)0;

    while (true)
    {
        Character = (int)getchar();

        if ((Character != (int)'\n') && (Character != (int)EOF))
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
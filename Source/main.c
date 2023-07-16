#define Yes "Yes"
#define No "No"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void ClearInputBuffer(void);

int main(int argc, const char *argv[])
{
    const char CapitalAlphabetic[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const char SmallAlphabetic[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    const char SpecialCharacters[] = {'@', '_'};
    const char Numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    const unsigned short int CapitalAlphabeticLength = 26;
    const unsigned short int SmallAlphabeticLength = 26;
    const unsigned short int SpecialCharactersLength = 2;
    const unsigned short int NumbersLength = 10;

    char *UserRequest = (char *)calloc(sizeof(char), 32);
    char *UserPassword = (char *)calloc(sizeof(char), 32);

    int UserRandomNumber = (int)0;

    // Getting User Request
    while (true)
    {
        printf("%s%s%s%s%s", "Would You Like To Generate A Password?(", Yes, "/", No, "):");

        int ResultOfReading = (int)0;
        ResultOfReading = (int)scanf("%s", UserRequest);

        if (ResultOfReading == 1)
        {
            if ((strstr(UserRequest, Yes) || strstr(UserRequest, No)))
            {
                break;
            }
            else
            {
                printf("%c%s%s%s%s%s%c", '\a', "Error: Invalid Input, The Input Have To Be ", Yes, " Or ", No, ".", '\n');
                continue;
            }
        }
        else
        {
            ClearInputBuffer();

            printf("%c%s%c", '\a', "Error: Please Try Again.", '\n');
            continue;
        }
    }

    // Calculating User Request
    if (strstr(UserRequest, "Yes"))
    {
        while (true)
        {
            printf("%s", "Please Enter A Random Number For Generating Password : ");

            int ResultOfReading = (int)0;
            ResultOfReading = (int)scanf("%d", &UserRandomNumber);

            if (ResultOfReading == 1)
            {
                break;
            }
            else
            {
                ClearInputBuffer();

                printf("%c%s%c", '\a', "Error: Please Just Enter A Number.", '\n');
                continue;
            }
        }
    }
    else
    {
        free(UserRequest);
        free(UserPassword);

        return (int)0;
    }

    // Generating Password
    srand(((int)time(NULL) / UserRandomNumber));

    for (unsigned short int Counter = (unsigned short int)0; Counter < (unsigned short int)32; Counter += 4)
    {
        UserPassword[Counter] = CapitalAlphabetic[(rand() % CapitalAlphabeticLength)];
        UserPassword[Counter + 1] = SmallAlphabetic[(rand() % SmallAlphabeticLength)];
        UserPassword[Counter + 2] = SpecialCharacters[(rand() % SpecialCharactersLength)];
        UserPassword[Counter + 3] = Numbers[(rand() % NumbersLength)];
    }

    printf("%s%s%c", "Your Password Is : ", UserPassword, '\n');

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
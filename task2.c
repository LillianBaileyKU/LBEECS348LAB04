//task 2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    double temperature;
    double converted;
    double celsius;
    char originalScale;
    char targetScale;
    char input[100];
    char extra;
    char *end;

    while (1)
    {
        printf("Enter the temperature value: ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        temperature = strtod(input, &end);

        while (isspace((unsigned char)*end))
        {
            end++;
        }

        if (end == input || *end != '\0')
        {
            printf("Invalid temperature. Please enter a number.\n");
            continue;
        }

        printf("Enter the original scale (C, F, or K): ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        if (sscanf(input, " %c %c", &originalScale, &extra) != 1)
        {
            printf("Invalid scale. Please enter C, F, or K.\n");
            continue;
        }

        originalScale = toupper((unsigned char)originalScale);

        if (originalScale != 'C' && originalScale != 'F' && originalScale != 'K')
        {
            printf("Invalid original scale. Please enter C, F, or K.\n");
            continue;
        }

        if (originalScale == 'K' && temperature < 0)
        {
            printf("Invalid temperature. Kelvin cannot be negative.\n");
            continue;
        }

        printf("Enter the scale to convert to (C, F, or K): ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            return 0;
        }

        if (sscanf(input, " %c %c", &targetScale, &extra) != 1)
        {
            printf("Invalid scale. Please enter C, F, or K.\n");
            continue;
        }


        targetScale = toupper((unsigned char)targetScale);

        if (targetScale != 'C' && targetScale != 'F' && targetScale != 'K')
        {
            printf("Invalid target scale. Please enter C, F, or K.\n");
            continue;
        }

        if (originalScale == 'C')
        {
            celsius = temperature;
        }
        else if (originalScale == 'F')
        {
            celsius = (temperature - 32) * 5.0 / 9.0;
        }
        else
        {
            celsius = temperature - 273.15;
        }

        if (targetScale == 'C')
        {
            converted = celsius;
        }
        else if (targetScale == 'F')
        {
            converted = celsius * 9.0 / 5.0 + 32;
        }
        else
        {
            converted = celsius + 273.15;
        }

        printf("Converted temperature: %.2f %c\n", converted, targetScale);

        if (celsius < 0)
        {
            printf("Temperature category: Freezing\n");
            printf("Weather advisory: Wear a heavy coat!\n");
        }
        else if (celsius < 10)
        {
            printf("Temperature category: Cold\n");
            printf("Weather advisory: Wear a jacket.\n");
        }
        else if (celsius < 25)
        {
            printf("Temperature category: Comfortable\n");
            printf("Weather advisory: Enjoy the weather!\n");
        }
        else if (celsius < 35)
        {
            printf("Temperature category: Hot\n");
            printf("Weather advisory: Drink lots of water!\n");
        }
        else
        {
            printf("Temperature category: Extreme Heat\n");
            printf("Weather advisory: Stay indoors and stay hydrated!\n");
        }

        printf("\n");
    }

    return 0;
}
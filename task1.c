#include <stdio.h>

int main(void)
{
    int score;
    char input[100];

    while (1)
    {
        printf("Enter the NFL score (Enter 1 to stop): ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        if (sscanf(input, "%d", &score) != 1)
        {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }

        if (score == 1)
        {
            break;
        }

        if (score < 0)
        {
            printf("Invalid score. Please enter a non-negative score.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        int td2, tdfg, td, fg, safety;

        for (td2 = 0; td2 * 8 <= score; td2++)
        {
            for (tdfg = 0; td2 * 8 + tdfg * 7 <= score; tdfg++)
            {
                for (td = 0; td2 * 8 + tdfg * 7 + td * 6 <= score; td++)
                {
                    for (fg = 0; td2 * 8 + tdfg * 7 + td * 6 + fg * 3 <= score; fg++)
                    {
                        for (safety = 0; td2 * 8 + tdfg * 7 + td * 6 + fg * 3 + safety * 2 <= score; safety++)
                        {
                            int total;

                            total = td2 * 8 + tdfg * 7 + td * 6 + fg * 3 + safety * 2;

                            if (total == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, " "%d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
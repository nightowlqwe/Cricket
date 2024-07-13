#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

struct batsman
{
    char name[25];
    int runs, score, balls, toruns, ones, twos, threes, fours, sixes;
    int max_run, max_four, max_six;
    float str;
} player1[100], player3;

struct bowler
{
    char name[25];
    int runsgiv, over, wic;
    int max_wic;
    float eco;
} player2[100], player4;

void input_batsman_details(int m)
{
    forn(i, m)
    {
        printf("Enter name of Batsman %d\n", i + 1);
        scanf("%s", player1[i].name);

        printf("Enter number of ONES scored\n");
        scanf("%d", &player1[i].ones);

        printf("Enter number of TWOS scored\n");
        scanf("%d", &player1[i].twos);

        printf("Enter number of THREES scored\n");
        scanf("%d", &player1[i].threes);

        printf("Enter number of FOURS scored\n");
        scanf("%d", &player1[i].fours);

        printf("Enter number of SIXES scored\n");
        scanf("%d", &player1[i].sixes);

        printf("Enter number of BALLS played\n");
        scanf("%d", &player1[i].balls);
    }
}

void input_bowler_details(int n)
{
    forn(i, n)
    {
        printf("Enter name of the Bowler %d\n", i + 1);
        scanf("%s", player2[i].name);

        printf("Enter number of OVERS bowled\n");
        scanf("%d", &player2[i].over);

        printf("Enter number of RUNS given\n");
        scanf("%d", &player2[i].runsgiv);

        printf("Enter number of WICKETS taken\n");
        scanf("%d", &player2[i].wic);
    }
}

void print_batsman_details(int m)
{
    printf("Batsman Details:\n");
    printf("================================================================\n");
    printf(" Batsman          Runs    Balls   Fours   Sixes   Strike Rate\n");
    printf("================================================================\n");
    forn(i, m)
    {
        player1[i].runs = (1 * player1[i].ones) + (2 * player1[i].twos) + (3 * player1[i].threes) + (4 * player1[i].fours) + (6 * player1[i].sixes);
        player1[i].str = (player1[i].runs * 100.0) / player1[i].balls;
        printf(" %-15s %-7d %-7d %-7d %-7d %-7.2f\n", player1[i].name, player1[i].runs, player1[i].balls, player1[i].fours, player1[i].sixes, player1[i].str);
    }
}

void print_bowler_details(int n)
{
    printf("Bowler Details:\n");
    printf("================================================================\n");
    printf(" Bowler           Overs   Runs    Wickets Economy\n");
    printf("================================================================\n");
    forn(i, n)
    {
        player2[i].eco = player2[i].runsgiv / (float)player2[i].over;
        printf(" %-15s %-7d %-7d %-7d %-7.2f\n", player2[i].name, player2[i].over, player2[i].runsgiv, player2[i].wic, player2[i].eco);
    }
}

void calculate_and_print_records(int m, int n)
{
    player3.max_run = player3.max_four = player3.max_six = 0;
    player4.max_wic = 0;

    forn(i, m)
    {
        player1[i].runs = (1 * player1[i].ones) + (2 * player1[i].twos) + (3 * player1[i].threes) + (4 * player1[i].fours) + (6 * player1[i].sixes);
        if (player1[i].runs > player3.max_run)
        {
            player3.max_run = player1[i].runs;
            strcpy(player3.name, player1[i].name);
        }
        if (player1[i].fours > player3.max_four)
        {
            player3.max_four = player1[i].fours;
            strcpy(player3.name, player1[i].name);
        }
        if (player1[i].sixes > player3.max_six)
        {
            player3.max_six = player1[i].sixes;
            strcpy(player3.name, player1[i].name);
        }
    }

    forn(i, n)
    {
        if (player2[i].wic > player4.max_wic)
        {
            player4.max_wic = player2[i].wic;
            strcpy(player4.name, player2[i].name);
        }
    }

    printf("Record Details:\n");
    printf("================================================================\n");
    printf(" Highest Runs Scored: %-15s %-7d\n", player3.name, player3.max_run);
    printf(" Most Fours Scored:   %-15s %-7d\n", player3.name, player3.max_four);
    printf(" Most Sixes Scored:   %-15s %-7d\n", player3.name, player3.max_six);
    printf(" Most Wickets Taken:  %-15s %-7d\n", player4.name, player4.max_wic);
    printf("================================================================\n");
}

int main()
{
    int player_no, choice;
    int m, n;

    cout << "Enter Batsman Details" << endl;
    cout << "Enter No of Batsman: ";
    cin >> m;
    input_batsman_details(m);

    printf("----------------------------------------------------------------\n\n");

    cout << "Enter Bowler Details" << endl;
    cout << "Enter No of Bowler: ";
    cin >> n;
    input_bowler_details(n);

    printf("----------Thank you all details are recorded-------------\n");

    do
    {
        printf("Enter the choice:\n 1)Batsman detail:\n 2)Bowler detail:\n 3)Match summary:\n 4)Record:\n 5)Exit\n ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print_batsman_details(m);
            break;
        case 2:
            print_bowler_details(n);
            break;
        case 3:
            printf("Match Summary:\n");
            printf("----------------------------\n");
            print_batsman_details(m);
            print_bowler_details(n);
            break;
        case 4:
            calculate_and_print_records(m, n);
            break;
        case 5:
            printf("Exiting...\n");
            printf("Developed by Alif Sarkar CSE-15\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

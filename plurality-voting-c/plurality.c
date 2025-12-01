#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9
#define NAME_LENGTH 100

// Candidates have name and vote count
typedef struct
{
    char name[NAME_LENGTH];
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(const char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        strncpy(candidates[i].name, argv[i + 1], NAME_LENGTH - 1);
        candidates[i].name[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        candidates[i].votes = 0;
    }

    // Get number of voters
    int voter_count;
    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1)
    {
        printf("Invalid number.\n");
        return 3;
    }

    // Consume leftover newline
    getchar();

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[NAME_LENGTH];
        printf("Vote: ");
        if (!fgets(name, sizeof(name), stdin))
        {
            printf("Error reading vote.\n");
            continue;
        }

        // Remove trailing newline
        name[strcspn(name, "\n")] = '\0';

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(const char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

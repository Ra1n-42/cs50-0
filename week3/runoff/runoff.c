#include <cs50.h>
#include <stdio.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}



// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Durchlaufe die Kandidaten, um den Index des Kandidaten mit dem gegebenen Namen zu finden
    for (int i = 0; i < candidate_count; i++)
    {
        // Wenn der Name mit dem Namen eines gültigen Kandidaten übereinstimmt
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Aktualisiere die Präferenz des Wählers, um den Index des gefundenen Kandidaten zu speichern
            preferences[voter][rank] = i;
            return true; // Rückgabe von true, da die Präferenz erfolgreich aufgezeichnet wurde
        }
    }

    // Wenn kein gültiger Kandidat mit dem gegebenen Namen gefunden wurde, gib false zurück
    return false;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Gehe jeden Wähler durch
    for (int i = 0; i < voter_count; i++)
    {
        // Gehe jede Präferenz des aktuellen Wählers durch
        for (int j = 0; j < candidate_count; j++)
        {
            // Erhalte den Index des Kandidaten basierend auf der aktuellen Präferenz des Wählers
            int kandidaten_index = preferences[i][j];

            // Wenn der Kandidat nicht eliminiert ist, erhöhe die Anzahl ihrer Stimmen
            if (!candidates[kandidaten_index].eliminated)
            {
                candidates[kandidaten_index].votes++;
                break; // Hör auf, Stimmen für diesen Wähler zu zählen, nachdem du die Stimmen für den am höchsten gerankten nicht eliminierten Kandidaten aktualisiert hast
            }
        }
    }
}


// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Berechne die Anzahl der Stimmen, die benötigt werden, um die Wahl zu gewinnen
    int votes_needed_to_win = voter_count / 2 + 1;

    // Gehe jeden Kandidaten durch
    for (int i = 0; i < candidate_count; i++)
    {
        // Wenn ein Kandidat mehr als die Hälfte der Stimmen hat, drucke seinen Namen und gib true zurück
        if (candidates[i].votes > votes_needed_to_win)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    // Wenn kein Kandidat die Mehrheit hat, gib false zurück
    return false;
}



// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Setze die minimale Stimmenanzahl auf einen großen Wert
    int min_votes = MAX_VOTERS;

    // Gehe jeden Kandidaten durch
    for (int i = 0; i < candidate_count; i++)
    {
        // Überprüfe, ob der Kandidat noch im Rennen ist und ob seine Stimmenanzahl kleiner als die bisherige minimale Stimmenanzahl ist
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            // Wenn ja, aktualisiere die minimale Stimmenanzahl
            min_votes = candidates[i].votes;
        }
    }

    // Gib die minimale Stimmenanzahl zurück
    return min_votes;
}


// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Gehe jeden Kandidaten durch
    for (int i = 0; i < candidate_count; i++)
    {
        // Überprüfe, ob der Kandidat nicht eliminiert ist und ob seine Stimmenanzahl nicht gleich dem Minimum ist
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            // Wenn ja, gibt es keine Gleichheit, also gib false zurück
            return false;
        }
    }

    // Wenn alle verbleibenden Kandidaten die gleiche Anzahl von Stimmen haben, gib true zurück
    return true;
}


// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Gehe jeden Kandidaten durch
    for (int i = 0; i < candidate_count; i++)
    {
        // Überprüfe, ob der Kandidat nicht eliminiert ist und ob seine Stimmenanzahl gleich dem Minimum ist
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            // Wenn ja, markiere den Kandidaten als eliminiert
            candidates[i].eliminated = true;
        }
    }
}


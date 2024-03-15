#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

const int MAXVOTERS = 100;
const int MAXCANDIDATES = 9;
bool vote(int voter, int rank , string name );
void tabulate(void);
int find_min();
bool print_winner(void);
bool is_tie(int min);
void eliminate (int min);

int preferences [MAXVOTERS][MAXCANDIDATES];

typedef struct{
    string name;
    int votes;
    bool eliminated;

}candidate;
candidate candidates[MAXCANDIDATES];

int voter_count;
int candidate_count;
float minimum_vote;
int main (int argc , string argv[]){
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    candidate_count = argc -1;
    if(candidate_count >MAXCANDIDATES){
         printf("Maximum number of candidates is %i\n", MAXCANDIDATES);
        return 2;
    }
    voter_count = get_int("Enter the number of voter : ");


    if(voter_count >MAXVOTERS){
         printf("Maximum number of voter is %i\n", MAXVOTERS);
        return 3;
    }
    for(int i=0;i<candidate_count;i++){
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    for (int i = 0; i < voter_count;i++ )
    {
        for(int j =0; j<candidate_count ; j++)
        {
            string name = get_string(" voter %i voting for the rank %i: ",i+1,j+1);
            while(!vote(i,j,name))
            {
                printf("Invalid vote \n");
                return 2;
            }
        }
        printf("\n");
    }

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

    }
    return 0;
}

bool vote(int voter,int rank ,string name )
{
    for(int i =0 ;i < candidate_count;i++)
    {
        if(strcmp(name,candidates[i].name)== 0)
        {

            preferences[voter][rank]=i;
            printf("The preference is %i \n",preferences[voter][rank]);
            return true;

        }
    }
    return false;

}

void tabulate(void)
{
    for(int i=0; i<voter_count;i++)
    {
        for(int j=0;j<candidate_count;j++)
        {
            int preference = preferences[i][j];
            for(int k =0;k<candidate_count;k++)
            {
                if(candidates[preference].eliminated==false)
                {
                    candidates[preference].votes = candidates[preference].votes +1;
                    break;
                }

            }

        }
    }
    return;
}


bool print_winner(void)

{
    minimum_vote = round(voter_count/2.0);
    for(int i=0;i < candidate_count;i++)
    {
        if(candidates[i].votes >= minimum_vote){
            printf("The winner is %s \n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(){
    int min =1;

    for(int i =0;i<candidate_count;i++)
    {
        if(candidates[i].votes <= min)
        {
            if(candidates[i].eliminated == false)
            {
                min=candidates[i].votes;
            }
        }
    }
    return min;
}

bool is_tie(int min){
    int count = 0;
    int eliminated =0;
    for(int i =0;i<candidate_count;i++)
    {
        if(candidates[i].votes == min)
        {
            if(candidates[i].eliminated == false)
            {
                count++;
            }
        }
        if(candidates[i].eliminated == false)
        {
            eliminated++;
        }
    }

    if(count == eliminated)
        return true ;
    else
        return false;


}

void eliminate (int min){

    for(int i =0;i<candidate_count;i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;

        }

    }
}

/*Program for the presidential election
Author : Jonathan Earle
Programming Assignment.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define PREFERENCE 3
#define VOTER 20
#define VOTES 7
// These #defines are for the arrays that i will be using. I will be using a 2-d array to read in the votes and then for the counting i will use 4 separate 1-d arrays.
// The 1-d arrays are to copy the first and second and third votes into a single array VOTES to find the winner.

main()
{
    
    int Election[VOTER][PREFERENCE];
    
    int Count[VOTES];
    
    int quota, num_of_voters = 0, i, Valid_Votes = 0,j, spoiled = 0, winner = 0, end = 0;
    
    int candidate_1 = 0, candidate_2 = 0,candidate_3 = 0, candidate_4 = 0,candidate_5 = 0,candidate_6 = 0,candidate_7 = 0 ;
    
    int voter_no = 1,Seats = 1;
    
    int candidates = 7;
    
    /* Above are the initialised variables i will be using throughout my program, namely the 2-d and 1-d array are significantly important for storing votes
        but the other int variables are equally important such as the quota, winner, and valid_votes as well as the variables for each candidate storing how many votes they got each.
        */
    
    printf("~~~~~~~~~~~~~~~Welcome to the Presidential Election 2011~~~~~~~~~~~~~~~\n\n");
    
    printf("There are Seven candidates, You must choose the maximum of three and minimum of one in order of preference\n\n");
    
    printf("The Seven candidates are as listed as:\n\n");
    
    printf("No1: MICHAEL D HIGGINS\n");
    
    printf("No2: SEAN GALLAGHER\n");
    
    printf("No3: MARTIN MCGUINNESS\n");
    
    printf("No4: GAY MITCHELL\n");
    
    printf("No5: DAVID NORRIS\n");
    
    printf("No6: DANA ROSEMARY SCALLON\n");
    
    printf("No7: MARY DAVIS\n");
    
    printf("If you do not want to cast a vote enter in 0 while entering in your vote\n\n");
    
    // The above print statements are to inform the voter of the instructions of how to vote.
    // It print the names of the candidates and prints the instructions in case a voter doesnt want to vote
    
    do
    {
        printf("Please Enter How Many Voters There are. There Must Be Between 5-20 Voters\n\n");
        scanf("%d", &num_of_voters);
    }
    
    while(num_of_voters <5 || num_of_voters > 10);
    
    /* The above loop is to ask the user how many voters will be voting, it will loop around until the amount of
        voters is between 5-20.
        */
    
    do
    {
        for(i=0; i<num_of_voters;i++)
        {
            printf("\nVoter No. %d Please Enter Your First Preference\n\n", voter_no);
            scanf("%d", &Election[i][0]);
            
            if(Election[i][0] <= candidates && Election[i][0]>0)
            {
                printf("\nYour First Vote Has Been Registered\n\n");
                Valid_Votes ++;
            }
            else 
            if(Election[i][0] == 0)
            {
                printf("\nYou Have Chosen Not To Vote\n\n");
            }
            else
            {
                printf("\nYour Vote Has Been Spoiled.\n\n");
                spoiled = spoiled++;
            }
        
            printf("\nVoter No. %d Please Enter Your Second Preference\n\n", voter_no);
            scanf("%d", &Election[i][1]);
            
            if(Election[i][1] <= candidates && Election[i][1]>0)
            {
                printf("\nYour Second Vote Has Been Registered\n\n");
                Valid_Votes++;
            }
            else 
            if(Election[i][0] == 0)
            {
                printf("\nYou Have Chosen Not To Vote\n\n");
            }
            else
            {
                printf("\nYour Vote Has Been Spoiled.\n\n");
                spoiled = spoiled++;
            }
        
            printf("\nVoter No. %d Please Enter Your Third Preference\n\n", voter_no);
            scanf("%d", &Election[i][2]);
            
            if(Election[i][2] <= candidates && Election[i][2]>0)
            {
                printf("\nYour Third Vote Has Been Registered\n\n");
                Valid_Votes++;
            }
            else 
            if(Election[i][0] == 0)
            {
                printf("\nYou Have Chosen Not To Vote\n");
            }
            else
            {
                printf("\nYour Vote Has Been Spoiled.\n");
                spoiled = spoiled++;
            }
            
            voter_no++;
        }
        
    }
    while(voter_no <= num_of_voters);
        
    /* The above do -while loop with a nested for loop is used to read in the votes into the 2-d array. If the user enters in a number between 1-7
        the program will print your vote has been registered, if the voter enters 0 the program will print that the user does not want to vote,
        if the voter enters in anything but a number between 0-7 the program will print that your vote has been spoiled
        */
    

    Valid_Votes = (Valid_Votes - spoiled) ;
    
    quota = (Valid_Votes/(Seats +1)) + 1 ;
    
    printf("The Quota For Any Candidate to win is %d\n\n", quota);
    
    // The above assignment operations is to assign the quota which is important in the program to find the winner.
    
    for(i = 0; i <= candidates; i++)
    {
        for(j = 0;j < 1; j++)
        {
            if(Election[i][j] == 1)
            {
                candidate_1+= 3;
            }
            
            if(Election[i][j] == 2)
            {
                candidate_2+=3;
            }
            if(Election[i][j] == 3)
            {
                candidate_3+=3;
            }
            if(Election[i][j] == 4)
            {
                candidate_4+=3;
            }
            if(Election[i][j] == 5)
            {
                candidate_5+=3;
            }
            if(Election[i][j] == 6)
            {
                candidate_6+=3;
            }
            if(Election[i][j] == 7)
            {
                candidate_7+= 3;
            }
            
        }
        
    }
    
    /* The above nested for loops is to check the users voters and add each first preference vote into the candidates variable ie: candidate_1.
        This is to help count the first preference votes
        */
    
    system("cls");
    
    printf("The results from the first count are:\n\n\n");
    
    printf("Candidate 1 has %d points\n\n", candidate_1);
    printf("Candidate 2 has %d points\n\n", candidate_2);
    printf("Candidate 3 has %d points\n\n", candidate_3);
    printf("Candidate 4 has %d points\n\n", candidate_4);
    printf("Candidate 5 has %d points\n\n", candidate_5);
    printf("Candidate 6 has %d points\n\n", candidate_6);
    printf("Candidate 7 has %d points\n\n", candidate_7);
    
    Count[0] = candidate_1 ;
    Count[1] = candidate_2 ;
    Count[2] = candidate_3 ;
    Count[3] = candidate_4 ;
    Count[4] = candidate_5 ;
    Count[5] = candidate_6 ;
    Count[6] = candidate_7 ;
    
    /* The above print statements and assignment operations are to print the amount of votes each candidate has, and then to transfer the votes into a 1-d array.
        The votes are tranferred to help to check if any of the candidates has reached the quota and maybe if they have won.
        
        */
        
    while(winner == 0 && end == 0)
    {
        if(candidate_1 >= quota)
        {
            printf("Candidate 1 Has Reached The Quota On The First Count\n\n");
            printf("Candidate 1 Is The Winner\n\n");
            winner++;
        }
        else
            if(candidate_2 >= quota)
            {
                printf("Candidate 2 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 2 Is The Winner\n\n");
                winner++;
            }
        else
            if(candidate_3 >=quota)
            {
                printf("Candidate 3 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 3 Is The Winner\n\n");
                winner++;
            }
        else
            if(candidate_4 >=quota)
            {
                printf("Candidate 4 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 4 Is The Winner\n\n");
                winner++;
            }
        else
            if(candidate_5>=quota)
            {
                printf("Candidate 5 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 5 Is The Winner\n\n");
                winner++;
            }
        else
            if(candidate_6 >= quota)
            {
                printf("Candidate 6 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 6 Is The Winner\n\n");
                winner++;
            }
        else
            if(candidate_7>=quota)
            {
                printf("Candidate 7 Has Reached The Quota On The First Count\n\n");
                printf("Candidate 7 Is The Winner\n\n");
                winner++;
            }
        else
        {
            printf("No Candidate Has Reached The Quota On The First Count\n\n");
            printf("The second and third preference vote will now be taken into account\n\n");
            end++;
            break;
        }
    }
    
    // The above if-else statements is to check the amount of votes each candidate has against the quota and check if there is a winner after the first count.
    
    
    if (winner == 0)
    {
        
        for(i = 0; i <= candidates; i++)
        {
            for(j = 1;j < 2; j++)
            {
                if(Election[i][j] == 1)
                {
                    candidate_1 += 2;
                }
                
                if(Election[i][j] == 2)
                {
                    candidate_2 += 2;
                }
                if(Election[i][j] == 3)
                {
                    candidate_3 += 2;
                }
                if(Election[i][j] == 4)
                {
                    candidate_4 += 2;
                }
                if(Election[i][j] == 5)
                {
                    candidate_5 += 2;
                }
                if(Election[i][j] == 6)
                {
                    candidate_6 += 2;
                }
                if(Election[i][j] == 7)
                {
                    candidate_7 += 2;
                }
                
            }
            
        }
       
         for(i = 0; i <= candidates; i++)
        {
            for(j = 2;j < 3; j++)
            {
                if(Election[i][j] == 1)
                {
                    candidate_1++;
                }
                
                if(Election[i][j] == 2)
                {
                    candidate_2++;
                }
                if(Election[i][j] == 3)
                {
                    candidate_3++;
                }
                if(Election[i][j] == 4)
                {
                    candidate_4++;
                }
                if(Election[i][j] == 5)
                {
                    candidate_5++ ;
                }
                if(Election[i][j] == 6)
                {
                    candidate_6++;
                }
                if(Election[i][j] == 7)
                {
                    candidate_7++;
                }
                
            }
            
        }
        
        Count[0] = candidate_1 ;
        Count[1] = candidate_2 ;
        Count[2] = candidate_3 ;
        Count[3] = candidate_4 ;
        Count[4] = candidate_5 ;
        Count[5] = candidate_6 ;
        Count[6] = candidate_7 ;
        
    
        printf("After the consideration of the second and third preferences the results are now\n\n");
        
        printf("Candidate 1 has %d points\n\n", candidate_1);
        printf("Candidate 2 has %d points\n\n", candidate_2);
        printf("Candidate 3 has %d points\n\n", candidate_3);
        printf("Candidate 4 has %d points\n\n", candidate_4);
        printf("Candidate 5 has %d points\n\n", candidate_5);
        printf("Candidate 6 has %d points\n\n", candidate_6);
        printf("Candidate 7 has %d points\n\n", candidate_7);
    }
    
    if(winner == 0)
    {
        if(candidate_1 >= quota)
        {
            printf("Candidate 1 Has Reached The Quota After The Vote Transfer\n\n");
            printf("Candidate 1 Is The Winner\n\n");
            winner++;
        }
            else
                if(candidate_2 >= quota)
                {
                    printf("Candidate 2 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 2 Is The Winner\n\n");
                    winner++;
                }
            else
                if(candidate_3 >=quota)
                {
                    printf("Candidate 3 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 3 Is The Winner\n\n");
                    winner++;
                }
            else
                if(candidate_4 >=quota)
                {
                    printf("Candidate 4 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 4 Is The Winner\n\n");
                    winner++;
                }
            else
                if(candidate_5>=quota)
                {
                    printf("Candidate 5 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 5 Is The Winner\n\n");
                    winner++;
                }
            else
                if(candidate_6 >= quota)
                {
                    printf("Candidate 6 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 6 Is The Winner\n\n");
                    winner++;
                }
            else
                if(candidate_7>=quota)
                {
                    printf("Candidate 7 Has Reached The Quota After The Vote Transfer\n\n");
                    printf("Candidate 7 Is The Winner\n\n");
                    winner++;
                }
            else
            {
                printf("No Candidate Has Reached The Quota\n\n");
                end++;
            }
                // The above for loops and if statements followed by assignment operations and print statements are to accomodate vote transfer if no candidate has reached the quota on the first count
    }
    // The above while statement is to re-check the votes for each candidate against the quota after vote transfer has taken place.
    getch();
    getch();
}

    
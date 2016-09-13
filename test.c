#include <stdio.h>

#include <time.h>

#include <stdlib.h>


int game()

{
    
int horses[13] = {0};
    
int prev[13] = {0};
    
int d1, d2, result, i, winner = 0;
    
int done = 0;

    
    
while (winner == 0)
    
{
        
d1 = rand() % 6 + 1;
        
d2 = rand() % 6 + 1;
        
result = d1 + d2;
        
        

if (prev[result] == 0) //if we didn't roll the same number multiple times in a row
        
{
            
for (i = 0; i < 13; i++) //clears the array that keeps track of the previous rolls
                
prev[i] = 0;
        
}
        
prev[result] = prev[result] + 1;
 //increments the number of times rolled in a row by 1
        
        

        if (horses[result] > -1) //as long as the horse hasn't been disqualified 
{ if (prev[result] > 1)
   //if the number has been rolled multiple times                 

horses[result] = horses[result] - prev[result];
          //total is subtracted by the number of consecutive rolls else
                                 
horses[result] = horses[result] + 1;
        //total is incremented by 1
}
        
        

for (i = 2; i < 13; i++)
   //check for the winner 
{
            
if (horses[i] >= 10)
           //if any of horses have reached 10 points 
winner = i;
        
}
        
    
}
    
return winner;

}


int main()

{
    
srand(time(0));
    
int i = 0;
    
int x = 0;
    
int res[13] = {0};
    
    

for (i = 0; i < 1000000; i++)
    //run the game x number of times and store the results 
{
        
x = game();
        
++res[x];
    
}
    
   
 
for (i = 2; i < 13; i++)
    //print the results 
{
        
printf("%d: %d\n", i, res[i]);
    
}
    

return 0;

}

1. How did you structure your Player?
I used a class to build my player, with this i was able to keep info about each player together easily and was able to modify player info with ease.

2. How did you structure your Game?
I chose to just build my game int he main() due to it being a realitively simple game and i saw no need to make an extra class for the game. though I could have also done this in a class.

3. How did you make use of classes and functions? What went where?
I used classes for the player and the circularlly linked list, I had member function of each of the classes that allowed for the modification of the objects with ease. 



Extra Credit
# Players | # Turns | # Iterations
----------|---------|-------------
     2    |   7.97  |     286
     3    |  26.97  |     976
     4    |  48.91  |     519
     5    |  71.98  |     841
    10    | 207.14  |     1731
    20    | 528.03  |     2535
   100    |4281.08  |     1941

1. How many simulations did you need to run to reach a stable average?
I chose to take my original game code and modify it to run a simulation. I contninued running games on each player count until the change in average between iterations was less than 0.0001 turns. I ran testing on each player set a couple of times, to ensure the numbers were realitively consistant

2. What is the relationship between the number of players and the number of turns? Linear? Quadratic? Exponential? Other?
While the trend wasnt immediatly noticable, after ploting these results, the relationship between players and truns in for sure a linear one. These average turn counts make an almost perfect linear scale.



main_sim Raw data sample output(change makefile if you want to run sim)
--------------------------------------------------------
How many Players would you like to simulate?
> 2
Game #1 - 14 Turns - 14 Average Turns
Game #2 - 16 Turns - 15 Average Turns
Game #3 - 9 Turns - 13 Average Turns
Game #4 - 16 Turns - 13.75 Average Turns
Game #5 - 9 Turns - 12.8 Average Turns
Game #6 - 15 Turns - 13.1667 Average Turns
Game #7 - 3 Turns - 11.7143 Average Turns
Game #8 - 8 Turns - 11.25 Average Turns
Game #9 - 5 Turns - 10.5556 Average Turns
Game #10 - 3 Turns - 9.8 Average Turns
.
.
.
Game #277 - 8 Turns - 7.83032 Average Turns
Game #278 - 13 Turns - 7.84892 Average Turns
Game #279 - 4 Turns - 7.83513 Average Turns
Game #280 - 9 Turns - 7.83929 Average Turns
Game #281 - 10 Turns - 7.84698 Average Turns
Game #282 - 8 Turns - 7.84752 Average Turns
Game #283 - 21 Turns - 7.89399 Average Turns
Game #284 - 17 Turns - 7.92606 Average Turns
Game #285 - 21 Turns - 7.97193 Average Turns
Game #286 - 8 Turns - 7.97203 Average Turns
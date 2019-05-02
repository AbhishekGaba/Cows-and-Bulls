// Abhishek Gaba
// comp sci 1 final project
// worked very hard on this hope you like it


void filler(int random[]);
void printer(int random[]);
#include <iostream>
#include <ctime>
#include<string>
#include<random>
using namespace std;

// I will be using the main function to employ most of my code because I dont like functions or anything fancy. I keep it simple

int main()
{
    int guess[4]; // the array that the user enters info into
    int first;
    int second; // first second third and fourth are the numbers that the user enters into the array I chose to do it this way because i thought it was easier
    int third;
    int fourth;
    int bulls;
    int cows;
    int games_played = 1; // This counts the number of games played.It is iniatialized to one because by the time the Y comes around the user has played once already 
    int guesses = 0;
    int total_guesses = 0;
    int best = RAND_MAX;
    int worst = 0;
    double average; // used static cast on this thing to make it work, hope you are proud of me 
    char play = 'Y';
    int random[4];

    filler(random);
    if (DEBUG) 
       printer(random);
    
    // Welcome Statment
    cout << "Welcome to bulls and cows. Ready to play? Enter your guess " << endl;
    
    // Functions needed to play the game
    do 
    {
        bulls = 0;
        cows = 0;
       
        cin >> first >> second >> third >> fourth; // leave an empty space in between the inputs
        guesses++;

        guess[0] = first;
        guess[1] = second;  // set them equal in order to put the values into the array, that's just how i do it.
        guess[2] = third;
        guess[3] = fourth; 

        // counting bulls

        if (guess[0] == random[0])
            bulls++;
        if (guess[1] == random[1])
            bulls++;
        if (guess[2] == random[2]) 
            bulls++;
        if (guess[3] == random[3])
            bulls++;

        // counting cows
        
        if ((guess[0] == random[1]) || (guess[0] == random[2]) || (guess[0] == random[3]))
            cows++;
        if ((guess[1] == random[0]) || (guess[1] == random[2]) || (guess[1] == random[3]))
            cows++;
        if ((guess[2] == random[0]) || (guess[2] == random[1]) || (guess[2] == random[3])) // the way i did this is pretty cool. The human mind is so powerful
            cows++;
        if ((guess[3] == random[0]) || (guess[3] == random[1]) || (guess[3] == random[2]))
            cows++;
        
        cout << "Cows : " << cows << endl;
        cout << "Bulls : " << bulls << endl;

        if ( bulls == 4 ) // once the user wins only then will the program end and ask to play again
        {
            cout << "Congratulations, You made your mama proud " << endl;
            cout << "Enter 'Y' to play again or any other letter to quit" << endl;
            cin >> play;

            if (guesses > worst)
                worst = guesses;
            if (guesses < best)
                best = guesses;

            total_guesses += guesses;
            guesses = 0;

            if ( play == 'Y' )
            {
                games_played++;
                filler(random);
                printer(random);
            }
        }
    } while ( play == 'Y' ); // cool loop

    average = total_guesses /(static_cast <double>(games_played));

    cout << "Best Game: " << best << " guesses" << endl;
    cout << "Worst Game: " << worst << " guesses" << endl;
    cout << "Average Guesses: " << average << " guesses" << endl;

    return 0;
}

// Function Definitions

void filler(int random[])
{
    const int size = 4;
    using namespace std;
    default_random_engine randeng(time(0)*time(0));
    uniform_int_distribution<unsigned>unifdist(0,9);
    random[0] = unifdist(randeng);
    for ( int i = 1; i < size; ++i) {
        bool same = false;
        while(!same) {
            int rand = unifdist(randeng);
            same = true;
            for (int j = 0; j < i; ++j) {
                if (random[j] == rand){
                    same = false;
                    break;
                }
            }
            random[i] = rand;
        }
    }
}

void printer(int random[])
{
    const int size = 4;
    using namespace std;
    for (int i = 0; i < size; i++)
    cout << random[i] << "";
    cout << endl;
}




                









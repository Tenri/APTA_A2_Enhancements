#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
    
}

void MainMenu::printMainOptions()
{
    cout << "Menu" << endl;
    cout << "----" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Credits (Show student information)" << endl;
    cout << "4. Quit" << endl;
}

void MainMenu::startMenu()
{
    cout << "Welcome to Scrabble!" << std::endl;
    cout << "-------------------" << std::endl;

    bool gameEnd = false;
    string input;

    while (!gameEnd && !cin.eof())
    {
        printMainOptions();

        //getting input from user
        cout << "> ";
        getline(cin, input);

        //regex cases
        regex case1("1");
        regex case2("2");
        regex case3("3");
        regex case4("4");

        if (regex_match(input, case1)) {
            //dynamically assigning number of players based on user input
            string numPlayersInput;

            cout << "How many players(2-4)?" << endl;
            cout << "> ";
            getline(cin, numPlayersInput);

            regex validNumPlayers("^[2-4]$");

            //looping until valid number of players
            do {
                cout << "Invalid option. Please enter a number between 2 and 4!" << endl;
                cout << "> ";
                getline(cin, numPlayersInput);
            }while (!regex_match(numPlayersInput, validNumPlayers));

            int intNumPlayers = stoi(numPlayersInput);

            cout << "\nStarting New Game" << endl;
            cout << "-------------------";
            startGame(intNumPlayers);
            gameEnd = true;

        } else if (regex_match(input, case2)) {
            loadGame();
            gameEnd = true;

        } else if (regex_match(input, case3)) {
            credits();
            
        } else if (regex_match(input, case4)) {
            gameEnd = true;
            
        } else if (cin.eof()) {
            gameEnd = true;
        } else {
            cout << "Invalid option. Please enter a number between 1 and 4!" << endl;
        }
    }
    cout << "Quitting" << endl;
}

void MainMenu::startGame(int numPlayers)
{
    // TODO: Create new Game instance. Do not load anything into it.
    // NOTE: Can overload stream operator on Game instance to get access to all the information.
    game = new Game();
    game->startGameLoop(numPlayers);
}

void MainMenu::loadGame()
{
    //TODO load game using overloaded input operator

    cout << "Enter saved game location" << endl;
    cout << "> ";
    string input;
    getline(cin, input);

    //loading in file
    ifstream inFile(input);

    if(inFile.is_open()){
        game = new Game(inFile);
        inFile.close();
        game->startGameFromLoad();
    }
    else{
        cout<<"Unable to load save file " << input << endl;
    }

}

void MainMenu::credits() {
    cout << endl;
    cout << "Credits:" << endl;
    cout << "-------------------" << endl;
    cout << "Name: Hina Lee" << endl
         << "Student ID: 3910654" << endl
         << "Email: s3910654@student.rmit.edu.au" << endl;
    cout << "-------------------" << endl;
    cout << endl;
}
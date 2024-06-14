#include <iostream>
#include "header.h"
#include "source.cpp"

using namespace std;

int main()
{
    ListPlayer LP;
    ListMatch LM;
    createListPlayer(LP);
    createListMatch(LM);
    int option, number, matchDay;
    string name;
    InfoPlayer players[] = {
        {1, "Marc-Andre ter Stegen"},
        {2, "Joao Cancelo"},
        {3, "Alejandro Balde"},
        {4, "Ronald Araujo"},
        {5, "Inigo Martinez"},
        {6, "Gavi"},
        {7, "Ferran Torres"},
        {8, "Pedri"},
        {9, "Robert Lewandowski"},
        {11, "Raphinha"},
        {13, "Inaki Pena"},
        {14, "Joao Felix"},
        {15, "Andreas Christensen"},
        {16, "Fermin Lopez Marin"},
        {17, "Marcos Alonso"},
        {18, "Oriol Romeu"},
        {19, "Vitor Roque"},
        {20, "Sergi Roberto"},
        {21, "Frenkie De Jong"},
        {22, "Ilkay Gundogan"},
        {23, "Jules Kounde"},
        {26, "Ander Astralaga Aranguren"},
        {27, "Lamine Yamal Nasraqui Ebana"},
        {29, "Angel Alarcon"},
        {30, "Marc Casado Torras"},
        {31, "Diego Kochen"},
        {33, "Pau Cubarsi Paredes"},
        {34, "Aleix Garrido"},
        {35, "Unai Hernandez Lorenzo"},
        {36, "Aaron Yaakobisvili"},
        {37, "Pau Victor Delgado"},
        {38, "Marc Guiu"},
        {39, "Hector Fort Garcia"},
        {40, "Pau Prim Coma"},
        {41, "Mikayil Ngor Faye"},
    };

    for (int i = 0; i < 35; i++) {
        adr_player newPlayer = createElmPlayer(players[i]);
        insertPlayer(LP, newPlayer);
    }

    do
    {
        // system("cls");
        cout << "\033[33m";
        cout << "\n\nStarting Line Up Club Barcelona 23/24";
        viewPlayer(LP, LM);
        cout << endl;
        cout << endl;
        viewMatch(LM);
        cout << endl;
        cout << endl;
        viewClubMatches(LM);
        cout << "\033[33m";
        cout << endl;
        cout << endl
        << "1. Add a player" << endl
        << "2. Add a match" << endl
        << "3. Select matches for players" << endl
        << "4. Delete player" << endl
        << "5. Delete match" << endl
        << "6. View Players in Match" << endl
        << "7. View Matches by Player" << endl
        << "8. Delete Player in Match" << endl
        << "9. Sorting by Player's Jersey Number" << endl
        << "10. Sorting Matches by most Players" << endl
        << "11. Sorting Player by most Matches" << endl
        << "12. Exit" << endl
        << "Choose: ";
        cin >> option;

        switch(option)
        {
            case 1:
            {
                cout << "Enter the player's jersey number: ";
                cin >> number;
                cout << "Enter player name: ";
                cin >> name;
                InfoPlayer newPlayer = {number, name};
                adr_player newPLayerPtr = createElmPlayer(newPlayer);
                insertPlayer(LP, newPLayerPtr);
                break;
            }
            case 2: {
                cout << "Enter match matchday: ";
                cin >> matchDay;
                cout << "Enter opposing club: ";
                cin >> name;
                InfoMatch newMatch = {matchDay, name};
                adr_match newMatchPtr = createElmMatch(newMatch);
                insertMatch(LM, newMatchPtr);
                break;
            }
            case 3: {
                cout << "Enter the player's jersey number: ";
                cin >> number;
                cout << "Enter matchday: ";
                cin >> matchDay;
                addPlayer(LP, LM, number, matchDay);
                break;
            }
            case 4: {
                cout << "Enter the jersey number of the player you want to delete: ";
                cin >> number;
                deletePlayer(LP, LM, number);
                break;
            }
            case 5: {
                cout << "Enter the matchday of the match you want to delete: ";
                cin >> matchDay;
                deleteMatch(LM,matchDay);
                break;
            }
            case 6: {
                cout << "Enter matchday: ";
                cin >> matchDay;
                searchPlayerinMatch(LM, matchDay);
                break;
            }
            case 7: {
                cout << "Enter player jersey number: ";
                cin >> number;
                searchMatchbyPlayer(LM, LP, number);
                break;
            }
            case 8: {
                cout << "Enter matchday: ";
                cin >> matchDay;
                cout << "Enter player jersey number: ";
                cin >> number;
                deletePlayerinMatch(LM, LP, matchDay, number);
                break;
            }
            case 9: {
                sortingJerseyNumber(LP);
                break;
            }
            case 10: {
                sortingMatch(LM);
                break;
            }
            case 11: {
                sortingPlayer(LP);
                break;
            }
            case 12:
                cout << "Thank you for using this app." << endl;
                break;
            default:
                cout << "Invalid selection, please try again." << endl;
                break;
        }
    } while (option != 12);
    return 0;
}

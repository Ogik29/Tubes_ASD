#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string.h>
#include <iostream>
using namespace std;

typedef struct ElmMatch *adr_match;
typedef struct ElmPlayer *adr_player;

struct InfoMatch
{
    int matchDay;
    string nameMatch;
    int playerCount; // jumlah player dalam match
};

struct InfoPlayer
{
    int numberPlayer;
    string namePlayer;
    int matchCount; // jumlah match yang dimiliki player
};

struct ListMatch
{
    adr_match first_match;
};

struct ListPlayer
{
    adr_player first_player;
};

struct ElmMatch
{
    InfoMatch info;
    adr_match next_match;
    ListPlayer player;
};

struct ElmPlayer
{
    InfoPlayer info;
    adr_player next_player;
    // ListMatch match;
};

void createListPlayer(ListPlayer &LP);
void createListMatch(ListMatch &LM);
adr_player createElmPlayer(InfoPlayer info);
adr_match createElmMatch(InfoMatch info);
void insertPlayer(ListPlayer &LP, adr_player p);
void insertMatch(ListMatch &LM, adr_match m);
adr_player searchPlayer(ListPlayer LP, int numberPlayer);
adr_match searchMatch(ListMatch LM, int matchDay);
void addPlayer(ListPlayer &LP, ListMatch &LM, int numberPlayer, int matchDay);
void viewMatch(ListMatch &LM);
void viewPlayer(ListPlayer &LP, ListMatch &ListMatch);
void viewClubMatches(ListMatch &LM);
void deleteAfterMatch(ListMatch &LM, int matchDay);
void deleteMatch(ListMatch &LM, int matchDay);
void deleteAfterPlayer(ListPlayer &LP, int numberPlayer);
void deletePlayer(ListPlayer &LP, ListMatch &LM, int numberPlayer);

void searchPlayerinMatch(ListMatch LM, int matchday);
void searchMatchbyPlayer(ListMatch LM, ListPlayer LP, int numberPlayer);
void deletePlayerinMatch(ListMatch &LM, ListPlayer &LP, int matchDay, int numberPlayer);
void sortingJerseyNumber(ListPlayer LP);
void sortingMatchbyPlayerCount(ListMatch LM);
void sortingPlayer(ListPlayer LP);

#endif // HEADER_H_INCLUDED

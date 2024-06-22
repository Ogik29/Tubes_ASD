#include <string.h>
#include <iostream>
#include "header.h"

using namespace std;

void createListPlayer(ListPlayer &LP)
{
    LP.first_player = NULL;
}
void createListMatch(ListMatch &LM)
{
    LM.first_match = NULL;
}

adr_player createElmPlayer(InfoPlayer info)
{
    adr_player p = new ElmPlayer;
    p->info = info;
    p->next_player = NULL;
    // p->match.first_match = NULL;
    return p;
}

adr_match createElmMatch(InfoMatch info)
{
    adr_match m = new ElmMatch;
    m->info = info;
    m->next_match = NULL;
    m->player.first_player = NULL;
    return m;
}

void insertPlayer(ListPlayer &LP, adr_player p)
{
    if (LP.first_player == NULL)
    {
        LP.first_player = p;
    }
    else
    {
        adr_player q = LP.first_player;
        while (q->next_player != NULL)
        {
            q = q->next_player;
        }
        q->next_player = p;
    }
    p->next_player = NULL; 
}

void insertMatch(ListMatch &LM, adr_match m)
{
    if (LM.first_match == NULL)
    {
        LM.first_match = m;
    }
    else
    {
        adr_match q = LM.first_match;
        while (q->next_match != NULL)
        {
            q = q->next_match;
        }
        q->next_match = m;
    }
}

adr_player searchPlayer(ListPlayer LP, int numberPlayer)
{
    if (LP.first_player == NULL)
    {
        return NULL;
    }
    else
    {
        adr_player p = LP.first_player;
        while ((p->next_player != NULL) && (p->info.numberPlayer != numberPlayer))
        {
            p = p->next_player;
        }
        if (p->info.numberPlayer == numberPlayer)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}

adr_match searchMatch(ListMatch LM, int matchDay)
{
    if (LM.first_match == NULL)
    {
        return NULL;
    }
    else
    {
        adr_match m = LM.first_match;
        while ((m->next_match != NULL) && (m->info.matchDay != matchDay))
        {
            m = m->next_match;
        }
        if (m->info.matchDay == matchDay)
        {
            return m;
        }
        else
        {
            return NULL;
        }
    }
}

void addPlayer(ListPlayer &LP, ListMatch &LM, int numberPlayer, int matchDay)
{
    adr_player p, q;
    adr_match m;
    p = searchPlayer(LP, numberPlayer);
    m = searchMatch(LM, matchDay);

    if ((p != NULL) && (m != NULL))
    {
        q = createElmPlayer(p->info);
        insertPlayer(m->player, q);
        m->info.playerCount++;
        p->info.matchCount++;
    }
}

void viewMatch(ListMatch &LM)
{
    if (LM.first_match == NULL)
    {
        cout << "Empty";
    }
    else
    {
        adr_match m = LM.first_match;
        while (m->next_match != NULL)
        {
            cout << "\n[" << "matchDay " << m->info.matchDay << "," << m->info.nameMatch << "] ";
            m = m->next_match;
        }
        cout << "\n[" << "matchDay " << m->info.matchDay << "," << m->info.nameMatch << "]";
    }
}

void viewPlayer(ListPlayer &LP, ListMatch &LM)
{
    // cout << "\033[31m";
    // if (LP.first_player == NULL)
    // {
    //     cout << "Empty";
    // }
    // else
    // {
    //     adr_player p = LP.first_player;
    //     while (p->next_player != NULL)
    //     {
    //         cout << "\n[" << p->info.numberPlayer << "," << p->info.namePlayer << "] ";
    //         p = p->next_player;
    //     }
    //     cout << "\n[" << p->info.numberPlayer << "," << p->info.namePlayer << "]";
    // }
    // cout << "\033[34m";

    adr_player p = LP.first_player;
    while (p != NULL) { // perulangan player
        cout << "\033[31m";
        cout << "\n[" << p->info.numberPlayer << "," << p->info.namePlayer << "]";
        
        // Menampilkan pertandingan yang diikuti oleh pemain ini
        cout << "\033[34m";
        cout << " Matches: ";
        bool hasMatches = false;
        adr_match m = LM.first_match;
        while (m != NULL) { // perulangan match
            adr_player pm = m->player.first_player;
            while (pm != NULL) { // perulangan player dari match
                if (pm->info.numberPlayer == p->info.numberPlayer) { // mengecek player dari match apakah sama dengan player yg menjadi patokan
                    cout << "\033[34m";
                    cout << "Matchday " << m->info.matchDay << " vs " << m->info.nameMatch << "; ";
                    hasMatches = true;
                }
                pm = pm->next_player;
            }
            m = m->next_match;
        }

        if (!hasMatches) {
            cout << "\033[34m";
            cout << "Empty";
        }
        
        p = p->next_player;
    }
    cout << "\033[34m";
}

void viewClubMatches(ListMatch &LM)
{
    if (LM.first_match == NULL)
    {
        cout << "Empty";
    }
    else
    {
        adr_match m = LM.first_match;
        while (m->next_match != NULL)
        {
            cout << "\n[" << "matchDay " << m->info.matchDay << "," << m->info.nameMatch << " ( ";
            viewPlayer(m->player, LM);
            cout << " )] " << endl;
            m = m->next_match;
        }
        cout << "\n[" << "matchDay " << m->info.matchDay << "," << m->info.nameMatch << " ( ";
        viewPlayer(m->player, LM);
        cout << " )]" << endl;
    }
}

void deleteAfterMatch(ListMatch &LM, int matchDay)
{
    if (LM.first_match != NULL)
    {
        adr_match temp = LM.first_match;
        if (temp->next_match == NULL)
        {
            createListMatch(LM);
        }
        else
        {
            adr_match m;
            while ((temp->next_match != NULL) && (temp->info.matchDay != matchDay))
            {
                m = temp;
                temp = temp->next_match;
            }
            if (temp->info.matchDay == matchDay)
            {
                if (temp == LM.first_match)
                {
                    LM.first_match = temp->next_match;
                    temp->next_match = NULL;
                }
                else
                {
                    m->next_match = temp->next_match;
                    temp->next_match = NULL;
                }
            }
        }
    }
}

void deleteMatch(ListMatch &LM, int matchDay)
{
    adr_match m = searchMatch(LM, matchDay);
    if (m != NULL)
    {
        m->player.first_player = NULL;
        deleteAfterMatch(LM, matchDay);
    } else {
        cout << "Pertandingan tidak ada." << endl;
    }
}

void deleteAfterPlayer(ListPlayer &LP, int numberPlayer)
{
    if (LP.first_player != NULL)
    {
        adr_player temp = LP.first_player;
        if (temp->next_player == NULL)
        {
            createListPlayer(LP);
        }
        else
        {
            adr_player p;
            while ((temp->next_player != NULL) && (temp->info.numberPlayer != numberPlayer))
            {
                p = temp;
                temp = temp->next_player;
            }
            if (temp->info.numberPlayer == numberPlayer)
            {
                if (temp == LP.first_player)
                {
                    LP.first_player = temp->next_player;
                    temp->next_player = NULL;
                }
                else
                {
                    p->next_player = temp->next_player;
                    temp->next_player = NULL;
                }
            }
        }
    }
}

void deletePlayer(ListPlayer &LP, ListMatch &LM, int numberPlayer)
{
    adr_player p;
    adr_match m;

    p = searchPlayer(LP, numberPlayer);
    if (p != NULL) {
        m = LM.first_match;
        if (m == NULL) {
            deleteAfterPlayer(LP, numberPlayer);
        } else {
            while (m->next_match != NULL) {
                deleteAfterPlayer(m->player, numberPlayer);
                m->info.playerCount--;
                p->info.matchCount--;
                m = m->next_match;
            }
            deleteAfterPlayer(m->player, numberPlayer);
            m->info.playerCount--;
            p->info.matchCount--;
        }
        
    }
    deleteAfterPlayer(LP, numberPlayer);
    cout << "Player not found" << endl;
    
}

void searchPlayerinMatch(ListMatch LM, int matchdDay) {
    adr_match m = searchMatch(LM, matchdDay);

    if (m != NULL) {
        cout << "\nPlayers in Matchday " << m->info.matchDay << ":";
        if (m->player.first_player != NULL) 
        {
            // adr_player p = m->player.first_player;
            // while (p != NULL) {
            //     cout << "Player Jersey Number: " << p->info.numberPlayer << ", Player Name: " << p->info.namePlayer << endl;
            //     p = p->next_player;
            // }
            viewPlayer(m->player, LM);
        }
    } else {
        cout << "Match with Matchday " << matchdDay << "Not Found" << endl;
    }
}

void searchMatchbyPlayer(ListMatch LM, ListPlayer LP, int numberPlayer) {
    adr_match m = LM.first_match;
    adr_player p = searchPlayer(LP, numberPlayer);
    
    if (p != NULL) {
        cout << "\nMatches by " << p->info.namePlayer << ":" << endl;
        while (m != NULL) {
            adr_player pm = m->player.first_player;
            while (pm != NULL) {
                cout << "\033[34m";
                if (pm->info.numberPlayer == numberPlayer) {
                    cout << "Matchday: " << m->info.matchDay << ", Against: " << m->info.nameMatch << endl;
                    break;
                }
                pm = pm->next_player;
            }
            m = m->next_match;
        }
    }
    else {
        cout << "\033[34m";
        cout << "\nPlayer Not Found" << endl;
        return; 
    }
}

void deletePlayerinMatch(ListMatch &LM, ListPlayer &LP, int matchDay, int numberPlayer) {
    adr_match m = searchMatch(LM, matchDay);
    
    if (m == NULL) {
        cout << "MatchDay " << matchDay << " Not Found" << endl;
        return;
    }

    adr_player pm = m->player.first_player;
    adr_player temp = NULL;
    while ((pm != NULL) && (pm->info.numberPlayer != numberPlayer)) {
        temp = pm; // menyimpan player match sebelumnya (sebelum pm di assign dengan next_player pmnya)
        pm = pm->next_player;
    }

    if(pm == NULL) {
        cout << "Player with jersey number " << numberPlayer << " Not Found" << endl;
    } else {
        if(temp == NULL) { // jika player yg ingin dihapus adalah player pertama
            m->player.first_player = pm->next_player;
        } else {
            temp->next_player = pm->next_player;
        }
        pm = NULL; // hapus pm sebelumnya agar data tidak double
        m->info.playerCount--;
        pm->info.matchCount--;
    }
    
}

void sortingJerseyNumber(ListPlayer LP) {
    bool tukar;
    adr_player p;
    adr_player temp = NULL;

    do
    {
        tukar = false;
        p = LP.first_player;
        while (p->next_player != temp)
        {
            if (p->info.numberPlayer > p->next_player->info.numberPlayer)
            {
                // bubble sort
                InfoPlayer tempInfo = p->info;
                p->info = p->next_player->info;
                p->next_player->info = tempInfo;
                tukar = true;
            }
            p = p->next_player;
        }
        temp = p;
    } while (tukar);
}

void sortingMatchbyPlayerCount(ListMatch LM) {
    bool tukar;
    adr_match m;
    adr_match temp = NULL;

    do
    {
        tukar = false;
        m = LM.first_match; 

        while (m->next_match != temp)
        {
            if (m->info.playerCount < m->next_match->info.playerCount)
            {
                // tukar match
                InfoMatch tempInfo = m->info;
                m->info = m->next_match->info;
                m->next_match->info = tempInfo;

                // tukar player yg ada pada match
                ListPlayer tempPlayers = m->player;
                m->player = m->next_match->player;
                m->next_match->player = tempPlayers;
                tukar = true;
            }
            m = m->next_match;
        }
        temp = m;
    } while (tukar);
}

void sortingPlayerbyMatchCount(ListPlayer LP) {
    bool tukar;
    adr_player p;
    adr_player temp = NULL;

    do {
        tukar = false;
        p = LP.first_player;

        while (p->next_player != temp) {
            if (p->info.matchCount < p->next_player->info.matchCount) {
                InfoPlayer temp = p->info;
                p->info = p->next_player->info;
                p->next_player->info = temp;
                tukar = true;
            }
            p = p->next_player;
        }
        temp = p;
    } while (tukar);
}

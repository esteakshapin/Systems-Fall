#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "song.h"
#include "nodeList.h"

struct song *insert_front(struct song *songList, struct song *newSong)
{
    newSong->nextSong = songList;
    return newSong;
}

struct song *insert_in_order(struct song *songList, struct song *newSong)
{
    if (songList == NULL)
    {
        return insert_front(songList, newSong);
    }
    struct song *temp = songList;

    while (temp)
    {
        int comp = songcmp(newSong, temp);

        if (comp < 0)
        {

            struct song *prevSong = find_node(songList, NULL, NULL, temp);

            if (prevSong)
            {
                prevSong->nextSong = newSong;
            }

            newSong->nextSong = temp;

            if (temp == songList)
            {
                songList = newSong;
            }

            return songList;
        }

        temp = temp->nextSong;
    }

    // adding song to the end of the list
    struct song *lastNode = find_node(songList, NULL, NULL, temp);

    lastNode->nextSong = newSong;

    return songList;
}

struct song *remove_node(struct song *songList, struct song *oldSong)
{

    struct song *prevSong = NULL;
    struct song *currentSong = songList;

    while (currentSong)
    {

        if (strcmp(currentSong->name, oldSong->name) == 0 &&
            strcmp(currentSong->artist, oldSong->artist) == 0 &&
            currentSong->nextSong == oldSong->nextSong)
        {
            if (prevSong)
            {
                prevSong->nextSong = currentSong->nextSong;
            }
            if (currentSong == songList) //removing the node if its in the beginning
            {
                songList = currentSong->nextSong;
            }

            printf("removing ");
            printSong(currentSong);
            printf("\n");

            print_list(songList);
            free(currentSong);
            return songList;
        }
        prevSong = currentSong;
        currentSong = currentSong->nextSong;
    }
    return songList;
}

void print_list(struct song *songList)
{
    printf("[ ");
    int n = 0;
    while (songList)
    {
        printSong(songList);
        printf(" | ");
        songList = songList->nextSong;
        n++;
    }
    printf(" ]\n");
}

struct song *free_list(struct song *songList)
{
    struct song *temp;
    while (songList)
    {
        temp = songList->nextSong;
        free(songList);
        songList = temp;
    }

    return songList;
}

struct song *find_node(struct song *songList, char *artist, char *name, struct song *nextSong)
{
    if (artist && name)
    {
        while (songList->nextSong)
        {
            if (!strcmp(songList->artist, artist) && !strcmp(songList->name, name))
            {
                return songList;
            }

            songList = songList->nextSong;
        }

        return NULL;
    }

    // return first song by an authur
    if (artist)
    {
        while (songList->nextSong)
        {
            if (!strcmp(songList->artist, artist))
            {
                return songList;
            }

            songList = songList->nextSong;
        }

        return NULL;
    }

    while (songList)
    {
        if (songList->nextSong == nextSong)
        {
            return songList;
        }

        songList = songList->nextSong;
    }

    return NULL;
}

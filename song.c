#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
    char name[100];
    char artist[100];
    struct song *nextSong;
};

void printSong(struct song *song)
{
    printf("{%s, %s}", song->artist, song->name);
}

struct song *createSong(char *name, char *artist)
{
    struct song *newSong;

    newSong = malloc(sizeof(struct song));

    // why does the code break if name is declared first?
    strcpy(newSong->artist, artist);
    strcpy(newSong->name, name);
    newSong->nextSong = NULL;
}

int songcmp(struct song *firstSong, struct song *secondSong)
{

    int comp = strcmp(firstSong->artist, secondSong->artist);

    if (comp == 0)
    {
        return strcmp(firstSong->name, secondSong->name);
    }

    return comp;
}
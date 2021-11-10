#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#include "musicLibrary.h"
#include "nodeList.h"
#include "song.h"

struct song **createMusicLibrary()
{
    struct song **musicLibrary;
    musicLibrary = calloc(27, sizeof(struct song *));
    return musicLibrary;
}

char libraryIndex(char *artist)
{
    int first_letter = tolower(artist[0]);

    if (first_letter >= 97 && first_letter <= 122)
    {
        return first_letter - 97;
    }
    return 26;
}

void addSongToLibrary(struct song **library, struct song *newSong)
{
    char index = libraryIndex(newSong->artist);

    library[index] = insert_in_order(library[index], newSong);
}

struct song *find_song(struct song **library, char *artist, char *name)
{
    return find_node(library[libraryIndex(artist)], artist, name, NULL);
}

void print_letter(struct song **library, char *letter)
{

    int a = libraryIndex(letter);

    struct song *head = library[libraryIndex(letter)];

    printf("%s -> ", letter);
    print_list(head);
}

void print_artist(struct song **library, char *artist)
{
    find_artist(library[libraryIndex(artist)], artist);
}

void print_library(struct song **library)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        if (library[i])
        {
            printf("%c: ", i + 97);
            print_list(library[i]);
        }
    }
}

void shuffle(struct song **library)
{
    int i = 5;
    while (i)
    {
        // random library index
        int libraryIndex = rand() % 26;

        //if there are songs stored at index
        if (library[libraryIndex])
        {
            struct song *randomSong = get_random_node(library[libraryIndex]);

            //if a random song is found, print it and then subtract 1 from the count
            if (randomSong)
            {
                printSong(randomSong);
                printf("\n");
                i--;
            }
        }
    }
    printf("\n");
}

void remove_song(struct song **library, struct song *song)
{
    library[libraryIndex(song->artist)] = remove_node(library[libraryIndex(song->artist)], song->artist, song->name, NULL);
}

void clear_library(struct song **library)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        library[i] = free_list(library[i]);
    }
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    char first_letter = toLower(artist[0]);

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

struct song *search_song(struct song **library, char *name, char *artist)
{
    return find_node(library[libraryIndex(artist)], artist, name, NULL);
}

void print_by_letter(struct song **library, char letter)
{
    struct song *head = library[libraryIndex(letter)];

    print_list(head);
}

void print_by_artist(struct song **library, char *artist)
{
    char index = libraryIndex(artist);
    find_artist(library[index], artist);
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
    int i;
    for (i = 0; i < 27; i++)
    {
        int j;
        char num_songs = rand() % 100000 / 100000.0 * list_length(library[i]);
        for (j = 0; j < num_songs; j++)
        {
            struct song *random_song = get_random(library[i]);
            print_node(random_song);
            printf("\n");
        }
    }
    printf("\n");
}

void delete_song(struct song **library, struct song *song)
{
    char index = libraryIndex(song->artist);
    library[index] = remove_song(library[index], song->name, song->artist);
}

void clear_library(struct song **library)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        library[i] = free_list(library[i]);
    }
}

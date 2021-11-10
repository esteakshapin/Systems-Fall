#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "song.h"

#include "namegen.h"
#include "nodeList.h"
#include "musicLibrary.h"
#include <ctype.h>

#define NUM_OF_ARTISTS 26

void printBreak()
{
    printf("==================================== \n \n");
}

void printTab()
{
    printf("\t");
}

void printHeader(char *message)
{
    printBreak();
    printf("%s: \n", message);
    printTab();
}

void testFind(struct song *songList, char *artist, char *name)
{
    printf("looking for [%s: %s] \n", artist, name);
    printTab();

    struct song *node = find_node(songList, artist, name, NULL);
    if (node)
    {
        printf("node found! ");
        printSong(node);
        printf("\n");
        return;
    }

    printf("node not found \n");
}

void testLibrarySongFind(struct song **musicLibrary, char *artist, char *name)
{
    printf("looking for [%s: %s] \n", artist, name);
    printTab();

    struct song *node = find_song(musicLibrary, artist, name);
    if (node)
    {
        printf("node found! ");
        printSong(node);
        printf("\n");
        return;
    }

    printf("node not found \n");
}

int main()
{

    struct song *songList = NULL;

    //initializing random - setting constant to get the same value for testing purposes
    srand(2);

    int counter = 0;
    struct song *temporary;
    struct song *findNode;   // will use this node to test find_node function
    struct song *removeNode; // will use this node to test remove_node function

    while (counter < 7)
    {
        // get a random artist and generate up to 4 random songs for said artist
        char *artist = NameGen();
        int i;
        int number_of_songs = (rand() % 4);
        for (i = 0; i < number_of_songs; i++)
        {
            temporary = createSong(NameGen(), artist);
            //adding songs to list
            songList = insert_in_order(songList, temporary);
        }

        if (counter == 3)
        {
            findNode = temporary;
        }

        if (counter == 5)
        {
            removeNode = temporary;
        }

        counter++;
    }

    //printing Songs
    printf("LINKED LIST TESTS \n");

    printHeader("Testing print_list");
    print_list(songList);

    //printing single node
    printHeader("Testing print_node");
    printSong(songList);
    printf("\n");

    //finding node
    printHeader("Testing find_node");
    testFind(songList, findNode->artist, findNode->name);
    printf("\n");
    printTab();
    testFind(songList, "dasdasd", "dasdasd"); //should return not found

    printHeader("Testing finding first song by author");
    testFind(songList, findNode->artist, NULL);

    printHeader("Testing random node");
    int i;
    for (i = 0; i < 4; i++)
    {
        printSong(get_random_node(songList));
        printf("\n\t");
    }

    printf("\n");

    //testing songcmp (helper function)
    printHeader("Testing songcom (helper function");
    printf("\n");
    int songCmpCounter;
    for (songCmpCounter = 0; songCmpCounter < 4; songCmpCounter++)
    {
        struct song *rand1 = get_random_node(songList);
        struct song *rand2 = get_random_node(songList);

        printf("comparing ");
        printSong(rand1);
        printf(" to ");
        printSong(rand2);
        printf("\n \t %d \n", songcmp(rand1, rand2));
    }

    //testing finding artist
    printHeader("Testing find_artist");
    printf("\n");
    find_artist(songList, get_random_node(songList)->artist);

    //should not find an artist
    printf("\n");
    find_artist(songList, "Barak Obama");

    // //testing removing node
    printHeader("Testing removing node");
    songList = remove_node(songList, findNode->artist, findNode->name, NULL); //removing test node

    printTab();
    songList = remove_node(songList, "adasd", "Asdasd", NULL); //should not remove anything

    // //testing free list
    printHeader("Testing free_list");
    songList = free_list(songList);
    printf("list after free_list: \n");
    print_list(songList);

    //music library
    printHeader("MUSIC LIBRARY TEST");
    printf("\n");

    //creating music library
    struct song **musicLibrary;
    musicLibrary = createMusicLibrary();

    //testing print letter (empty)
    printHeader("Testing print_letter");
    print_letter(musicLibrary, "a");

    printHeader("Testing print_library");
    print_library(musicLibrary);
    printf("\n");

    // artists for find artist
    char *testArtist;
    struct song *testSong;
    //adding songs
    counter = 0;
    while (counter < NUM_OF_ARTISTS)
    {

        char letter = toupper(counter + 97);
        char *letterPointer = &letter;

        int c = 0;
        int number_of_artists = (rand() % 4);
        for (c = 0; c < number_of_artists; c++)
        {
            // get a random artist and generate up to 4 random songs for said artist
            char *randomArtist = NameGen();
            char artistName[25];

            strcpy(artistName, letterPointer);
            //for some reason, some letters are not copied onto the string
            switch (letter)
            {
            case 73:
                strcpy(artistName, "I");
                break;
            case 74:
                strcpy(artistName, "J");
                break;
            case 75:
                strcpy(artistName, "K");
                break;
            case 76:
                strcpy(artistName, "L");
                break;
            case 77:
                strcpy(artistName, "M");
                break;
            case 78:
                strcpy(artistName, "N");
                break;

            default:
                break;
            }
            strcat(artistName, ". ");
            strcat(artistName, randomArtist);

            int i;
            int number_of_songs = (rand() % 4);
            // printf("artist: %s \t number of songs: %d \n", artistName, number_of_songs); testing
            for (i = 0; i < number_of_songs; i++)
            {
                temporary = createSong(NameGen(), artistName);
                //adding songs to list
                addSongToLibrary(musicLibrary, temporary);
                // printf("\t artist: %s \t song: %s \n", temporary->artist, temporary->name);
            }

            if (counter == (NUM_OF_ARTISTS / 2))
            {
                testSong = temporary;
            }

            if (counter == NUM_OF_ARTISTS - 1)
            {
                testArtist = artistName;
            }
        }

        counter++;
    }
    printHeader("Testing print letter");
    print_letter(musicLibrary, "C");
    printHeader("Testing print_library");
    printf("\n");
    print_library(musicLibrary);

    printHeader("Testing find:");
    testLibrarySongFind(musicLibrary, testSong->artist, testSong->name); //should be found
    testLibrarySongFind(musicLibrary, "adsad", "Adasd");

    printHeader("Testing find artist");
    print_artist(musicLibrary, testArtist);

    printHeader("Testing Remove Song");
    remove_song(musicLibrary, testSong);

    printHeader("Testing clear_list");
    clear_library(musicLibrary);

    printHeader("Library after clear");
    print_library(musicLibrary);
    printf("\n");

    //adding songs to empty list
    addSongToLibrary(musicLibrary, createSong("thunderstruck", "ac/dc"));
    addSongToLibrary(musicLibrary, createSong("alive", "pearl jam"));
    addSongToLibrary(musicLibrary, createSong("even flow", "pearl jam"));
    addSongToLibrary(musicLibrary, createSong("yellow ledbetter", "pearl jam"));
    addSongToLibrary(musicLibrary, createSong("time", "pink floyd"));

    print_library(musicLibrary);

    printHeader("Testing print_artist");
    print_artist(musicLibrary, "pearl jam");
    printf("\n");
    print_artist(musicLibrary, "ac/dc");

    printHeader("Testing Shuffle");
    shuffle(musicLibrary);
    return 0;
}
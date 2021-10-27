#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "song.h"

#include "namegen.h"
#include "nodeList.h"

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

    return 0;
}
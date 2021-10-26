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
    testFind(songList, "dasdasd", "dasdasd"); //should return not found

    // //testing removing node
    songList = remove_node(songList, findNode); //removing test node
    print_list(songList);                       //printing new list

    // //testing free list
    songList = free_list(songList);
    print_list(songList);

    return 0;
}
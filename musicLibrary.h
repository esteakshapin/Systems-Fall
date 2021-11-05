#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "musicLibrary.h"
#include "nodeList.h"
#include "song.h"

struct song **createMusicLibrary();

char libraryIndex(char *artist);

void addSongToLibrary(struct song **library, struct song *newSong);

struct song *search_song(struct song **library, char *name, char *artist);

void print_letter(struct song **library, char letter);

void print_artist(struct song **library, char *artist);

void print_library(struct song **library);

void shuffle(struct song **library);

void delete_song(struct song **library, struct song *song);

void clear_library(struct song **library);

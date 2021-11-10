struct song
{
    char name[100];
    char artist[100];
    struct song *nextSong;
};

void printSong(struct song *song);
struct song *createSong(char *name, char *artist);
int songcmp(struct song *firstSong, struct song *secondSong);
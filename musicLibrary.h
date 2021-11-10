struct song **createMusicLibrary();

char libraryIndex(char *artist);

void addSongToLibrary(struct song **library, struct song *newSong);

struct song *find_song(struct song **library, char *artist, char *name);

void print_letter(struct song **library, char *letter);

void print_artist(struct song **library, char *artist);

void print_library(struct song **library);

void shuffle(struct song **library);

void remove_song(struct song **library, struct song *song);

void clear_library(struct song **library);

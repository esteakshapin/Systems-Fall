struct song *insert_front(struct song *songList, struct song *newTeacher);
struct song *remove_node(struct song *songList, char *artist, char *name, struct song *nextSong);

void print_list(struct song *songList);

struct song *free_list(struct song *songList);

struct song *insert_in_order(struct song *songList, struct song *newSong);

int songcmp(struct song *firstSong, struct song *secondSong);

struct song *find_node(struct song *songList, char *artist, char *name, struct song *nextSong);

struct song *get_random_node(struct song *songList);

void find_artist(struct song *songList, char *artist);
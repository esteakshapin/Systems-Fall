struct teacher *insert_front(struct teacher *teacherList, struct teacher *newTeacher);
struct teacher *remove_node(struct teacher *teacherList, struct teacher *oldTeacher);

void print_list(struct teacher *teacherList);

struct teacher *free_list(struct teacher *teacherList);

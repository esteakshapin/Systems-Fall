struct teacher
{
    char *name;
    int grade;
    int numberOfClasses;

    struct teacher *nextTeacher;
};
void printTeacher(struct teacher *teacher);
struct teacher *createTeacher(char *name, int grade, int numberOfClasses, struct teacher *nextTeacher);

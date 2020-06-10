#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char ID[11];
    char name[20];
    char *firstName;
    int score[4];
} Student;

int compare(Student *st1, Student *st2) {
    int result = strcmp(st1->ID, st2->ID);
    if (result) return result < 0 ? 1 : 0;
    result = strcmp(st1->name, st2->name);
    if (result) return result < 0 ? 1 : 0;
    for (int i = 0; i < 4; i++){
        if (st1->score[i] != st2->score[i])
            return st1->score[i] < st2->score[i] ? 1 : 0;
    }
    return 1;
}

int main(){
    int N;
    while (scanf("%d", &N) != EOF){
        Student *sts = (Student*)malloc(sizeof(Student) * N);
        Student **st_ptr = (Student**)malloc(sizeof(Student*) * N);
        for (int i = 0; i < N; i++){
            scanf("%s%s", sts[i].ID, sts[i].name);
            sts[i].firstName = sts[i].name + strlen(sts[i].name);
            *(sts[i].firstName - 1) = 0;
            scanf("%s", sts[i].firstName);
            for (int j = 0; j < 4; j++){
                scanf("%d", &sts[i].score[j]);
            }
            st_ptr[i] = &sts[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if(!compare(st_ptr[i], st_ptr[j])) {
                    Student* tmp = st_ptr[i];
                    st_ptr[i] = st_ptr[j];
                    st_ptr[j] = tmp;
                }
            }
        }
        
        for (int i = 0; i < N; i++){
            printf("%s %s, %s %d", st_ptr[i]->ID, st_ptr[i]->name, st_ptr[i]->firstName, st_ptr[i]->score[0]);
            for (int j = 1; j < 4; j++){
                printf(" %d", st_ptr[i]->score[j]);
            }
            printf("\n");
        }
    }
}


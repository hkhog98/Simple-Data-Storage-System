#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define NAME_SIZE 50
#define GRADES_SIZE 5

typedef struct student {
    char name[NAME_SIZE];
    int id;
    int grades[GRADES_SIZE];
} Student;

void new_record(FILE* fd, Student* student_data) {
    printf("Enter student name:\n");
    fscanf(fd, " %s", student_data->name);
    printf("Enter student grades:\n");
    for(int i = 0; i < GRADES_SIZE; ++i) {
        fscanf(fd, "%d", &student_data->grades[i]);
    }
    //++student_data->id;
}

void search_record(FILE* fd) {

}

void update_record(FILE* fd) {

}

void delete_record(FILE* fd) {

}

void sort_record(FILE* fd) {

}

int main() {
    FILE* fd = fopen("student_data.txt", "a");
    Student* student_data = NULL; 
    int opcode = 0;
    do {
        puts("Enter opcode for operation!");
        puts("Add a new record - 1.");
        puts("Search for a record (by name or ID) - 2.");
        puts("Update a record - 3.");
        puts("Delete a record - 4.");
        puts("Sort records - 5.");
        puts("Exit - 0.");
        scanf("%d", &opcode);
        if(opcode == 1) {
            new_record(fd, student_data);
        }
        if(opcode == 2) {
            search_record(fd);
        }
        if(opcode == 3) {
            update_record(fd);
        }
        if(opcode == 4) {
            delete_record(fd);
        }
        if(opcode == 5) {
            sort_record(fd);
        }
        if(opcode == 0) {
            exit(EXIT_SUCCESS);
        }
    } while(opcode != 0);
    return 0;
}
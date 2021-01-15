#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b);
void sort_message(struct message_info *m, int *total);

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++)
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);

    sort_message(m, &total);

    for(int i = 0; i < total; i++)
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    return 0;
}
// Your code goes here
void sort_message(struct message_info *m, int *total){
	for(int i = 0; i < *total; i++){
		m[i].time.hour = m[i].time.hour * 60 + m[i].time.minute;
	}
	qsort((void*)m, *total, sizeof(struct message_info), cmp);
	for(int i = 0; i < *total; i++){
		m[i].time.hour = (m[i].time.hour - m[i].time.minute) / 60;
	}

}
int cmp(const void *a, const void *b){
	int i = (*(struct message_info*)a).time.hour;
	int j = (*(struct message_info*)b).time.hour;
	if(i > j) return 1;
	else if(i == j) return 0;
	else return -1;
}

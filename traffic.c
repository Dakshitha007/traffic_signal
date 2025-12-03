#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
struct Signal {
    char name[10];
    int duration;
    char meaning[20];
};
void showSignal(struct Signal *s);
void saveLog(struct Signal *s);
void countdown(int sec);
int main() {
    struct Signal signals[3] = {
        {"RED", 3, "STOP"},
        {"YELLOW", 2, "READY"},
        {"GREEN", 3, "GO"}
    };
    printf("TRAFFIC SIGNAL SIMULATION\n");
    printf("-----------------------------\n");
    for (int i = 0; i < 3; i++) {
        showSignal(&signals[i]);
    }
    return 0;
}
void showSignal(struct Signal *s) {
    printf("\n=== %s LIGHT ===\n", s->name);
    printf("Meaning: %s\n", s->meaning);

    countdown(s->duration);
    saveLog(s);
}

void countdown(int sec) {
    for (int i = sec; i > 0; i--) {
        printf("Time left: %d\n", i);
        //fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void saveLog(struct Signal *s) {
    FILE *fp = fopen("signal_log.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%s | %d sec | %s \n",s->name, s->duration, s->meaning);

    fclose(fp);
}

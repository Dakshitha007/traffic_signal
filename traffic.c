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

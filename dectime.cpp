#include <cstdio>
#include <cstdlib>
#include <ctime>

/* With no options: print current time in Internet Time
   With one argument: convert Internet Time argument to ordinary time
*/

int main(int argc, char *argv[]) {
    const int DAY_SECONDS = 86400;

    if (argc == 1) {
        // No arguments
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int tm_seconds = tm.tm_sec + (60*tm.tm_min) + (3600*tm.tm_hour);

        int pct = (int)( (float)tm_seconds / DAY_SECONDS * 1000.0f );
        printf("%03d", pct);
    }
    else {
        // Convert decimal time to HH:MM:SS (24 hour)
        int input_it = atoi(argv[1]);
        int input_seconds = (input_it / 1000.0f) * DAY_SECONDS;

        struct tm tm;
        tm.tm_sec = input_seconds % 60;
        tm.tm_min = (input_seconds / 60) % 60;
        tm.tm_hour = (input_seconds / 3600);
        if (tm.tm_hour >= 24) {
            fprintf(stderr, "warning: time computation error\n");
            return 1;
        }

        const int OUT_BUF_SIZE = 256;
        char buf[OUT_BUF_SIZE];
        strftime(buf, OUT_BUF_SIZE, "%H:%M:%S", &tm);

        printf("%s\n", buf);
    }

    return 0;
}

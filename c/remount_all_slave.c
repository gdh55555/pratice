#include <unistd.h>
#include <stdio.h>
#include <string.h>

/*
 *  * skip @nfields spaces in @src
 *   */
static char *get_field(char *src, int nfields)
{
    char *p = src;
    int i;

    for (i = 0; i < nfields; i++) {
        while (*p && *p != ' ' && *p != '\t')
            p++;
        if (!*p)
            break;
        p++;
    }
    return p;
}

static void null_endofword(char *word)
{
    while (*word && *word != ' ' && *word != '\t')
        word++;
    *word = '\0';
}

int main()
{
    /* walk /proc/mounts and change any shared entries to slave */
    FILE *f = fopen("/proc/self/mountinfo", "r");
    char *line = NULL;
    size_t len = 0; 

    if (!f) {
        printf("Failed to open /proc/self/mountinfo to mark all shared");
        printf("Continuing container startup...");
        return;
    }
    printf("-------------------------\n");
    while (getline(&line, &len, f) != -1) {
        char *target, *opts;
        target = get_field(line, 4);
        printf("1-------------------------\n");
        if (!target)
            continue;
        opts = get_field(target, 2);
        printf("2-------------------------\n");
        if (!opts)
            continue;
        null_endofword(opts);
        printf("3-------------------------\n");
        if (!strstr(opts, "shared"))
            continue;
        null_endofword(target);
        printf("111\n");
        printf("%s %s \n", target, opts);
    }
}

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *usage_msg = "Usage:\nln [-s] source_name link_name\n-s\tCreate a symbolic link.\n\n";

    if (argc < 3 || argc > 4)
    {
        printf("%s", usage_msg);
        return 1;
    }

    /* Check for symbolic link. */
    if ((strcmp(argv[1], "-s") == 0) && (argc == 4))
    {
        // printf("Symbolic link.\n");
        if (symlink(argv[2], argv[3]) < 0)
        {
            fprintf(stderr, "Symbolic link failed.\n");
            return 1;
        }

        /* Success. */
        else
        {
            printf("Symbolic link created.\n");
        }
    }

    /* Hard link. */
    else if (argc == 3)
    {
        // printf("Hard link.\n");
        if (link(argv[1], argv[2]) < 0)
        {
            fprintf(stderr, "Hard link failed.\n");
            return 1;
        }

        /* Success. */
        printf("Hard link created.\n");
    }

    /* Improper usage. */
    else
    {
        printf("%s", usage_msg);
        return 1;
    }

    return 0;
}

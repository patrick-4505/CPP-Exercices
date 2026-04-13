#include <iostream>
#include <string>
#include <sys/inotify.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[])
{
    int fileStart = 1;
    int monitor = 0;

    if (argc < 2 || (strcmp(argv[1], "--monitor") == 0 && argc < 3)) {
        std::cout << "Usage: " << argv[0] << " [--monitor] dossier\n";
        return 1;
    }

    if (strcmp(argv[1], "--monitor") == 0) {
        monitor = 1;
        fileStart = 2;
    }


    int fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        return 1;
    }

    int wd = inotify_add_watch(fd, argv[fileStart], IN_CREATE | IN_MODIFY | IN_DELETE);
    if (wd == -1) {
        perror("inotify_add_watch");
        return 1;
    }

    std::cout << "Watching: " << argv[fileStart] << "\n";

    char buffer[1024];
    while (1) {
        int length = read(fd, buffer, sizeof(buffer));
        if (length < 0) {
            perror("read");
            break;
        }

        int i = 0;
        while (i < length) {
            struct inotify_event* event = (struct inotify_event*)&buffer[i];
            if (event->len) {
                if (event->mask & IN_CREATE)
                    std::cout << "CREATE: " << event->name << "\n";
                if (event->mask & IN_MODIFY)
                    std::cout << "MODIFY: " << event->name << "\n";
                if (event->mask & IN_DELETE)
                    std::cout << "DELETE: " << event->name << "\n";
                i += sizeof(struct inotify_event) + event->len;
            }
        }

        if (!monitor) break;
    }

    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;
}

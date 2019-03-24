extern char *my_realpath(const char *pathname, char *result, char* chroot_path);
#define MAXPATHLEN 46

#define HAVE_SYMLINK 1
#define HAVE_GETCWD 1
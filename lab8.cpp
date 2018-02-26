#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

void dfs()
{
    long long s = 0, c = 0, fcount = 0;
	DIR* dp = opendir(".");
	struct dirent *res;

	while ((res = readdir(dp)) != NULL) {
	if ((strcmp(res->d_name, ".")==0) || (strcmp(res->d_name, "..")==0))
       continue;
    struct stat info;
    stat(res->d_name, &info);
    if (S_ISDIR(info.st_mode))
        fcount++;
    else
    {
    s += info.st_size;
    c++;
    }
}
    closedir(dp);
    cout << c << " files, " << fcount << " dirs, " << s << " bytes.\n";
}
int main()
{
    dfs();
    return 0;
}


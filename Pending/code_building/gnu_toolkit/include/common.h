# ifndef COMMON_H
# define COMMON_H

# ifdef HP
        # include <sys/semaphore.h>
# elif AIX
        # include <pthread.h>
# else
        # include <semaphore.h>
# endif

# include <dirent.h>
# include <fcntl.h>
# include <fstream>
# include <iostream>
# include <queue>
# include <set>
# include <stdlib.h>
# include <sys/klog.h>
# include <syslog.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <vector>
# include <exception>
# include <sstream>
# include <stdio.h>
# include <map>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <string>
# include <errno.h>
# include <sys/time.h>
# include <assert.h>

# endif

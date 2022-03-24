#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_SIZE 255  //能存储的最多路径名长度
#define MAXROWLEN 100 //一行显示的最多字符数
#define LS_NONE 0     //无参数
#define LS_A 1        // a
#define LS_L 2        // l
#define LS_I 4        // i
#define LS_T 8        // t
#define LS_R 16       // r
#define LS_RR 32      // R
#define LS_S 64       // s # 在每个文件名左侧输出该文件的大小，以    1024   字节的块为单位。如果设置了   POSIXLY_CORRECT  # 的环境变量，除非用“ -k ”选项，块大小是 512 字节。

#define NORMAL 0
#define GREEN 1
#define BLUE 2
#define S_BLUE 3
#define YELLOW 4

int g_leavelen = MAXROWLEN;
int g_maxlen;

void display(int flag, char *pathname);

void display_dir(int flag_param, char *path);

void printfColor(char *name, int color);

void my_err(const char *err_string, int line);

void swap(char **x, char **y);

void display_none(char *name, int color);

void display_file(struct stat buf, char *name, int color);

int display_r(char *pathname1, int color);

int display_s(char *pathname1, int color);

int display_i(char *pathname1, int color);

int main(int argc, char *argv[])
{
  int flag_param = LS_NONE, ch;
  struct stat buf;
  int i = 1;
  opterr = 0;
  char path[PATH_MAX + 1];
  while ((ch = getopt(argc, argv, "alirtRs")) != -1)
  {
    switch (ch)
    {
    case 'a':
      flag_param += 1;
      break;
    case 'l':
      flag_param += 2;
      break;
    case 'i':
      flag_param += 4;
      break;
    case 't':
      flag_param += 8;
      break;
    case 'r':
      flag_param += 16;
      break;
    case 'R':
      flag_param += 32;
      break;
    case 's':
      flag_param += 64;
      break;
    default:
      printf("wrong option:%c\n", optopt);
      return -1;
    }
  }
  // printf("%d\n",flag_param);
  if (optind == argc) // ls .没有带参直接ls当前目录
  {
    strcpy(path, "./");
    path[2] = 0;
    display_dir(flag_param, path);
    return 0;
  }
  for (i = optind; i < argc; i++)
  {
    if (stat(argv[i], &buf) < 0)
    {
      perror("fail to stat!\n");
      return -1;
    }
    if (S_ISDIR(buf.st_mode))
    { // argv[i]是一个目录
      display_dir(flag_param, path);
      i++;
    }
    else
    {
      display(flag_param, path);
      i++;
    }
  }
  return 0;
}

void my_err(const char *err_string, int line)
{
  fprintf(stderr, "line: %d", line);
  perror(err_string);
  exit(1);
}

void swap(char **x, char **y)
{
  char *temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void display_dir(int flag_param, char *path)
{
  DIR *mydir;
  struct dirent *myitem;
  struct stat buf;
  char filenames[256][PATH_MAX + 1];
  char filetime[PATH_MAX + 1];
  int count = 0;
  int len = strlen(path);
  char temp[PATH_MAX];
  long timeTemp;
  if ((mydir = opendir(path)) == NULL)
  {
    perror("fail to opendir!\n");
    return;
  }
  while ((myitem = readdir(mydir)) != NULL)
  {
    if (g_maxlen < strlen(myitem->d_name))
      g_maxlen = strlen(myitem->d_name);
    count++;
  }

  closedir(mydir);

  if (count > 256)
    my_err("too many files under this directory", __LINE__);
  if ((flag_param & LS_L) == 0)
  {
    printf("\n");
  }

  mydir = opendir(path);
  for (int i = 0; i < count; i++)
  {
    myitem = readdir(mydir);
    if (myitem == NULL)
    {
      my_err("readdir", __LINE__);
    }
    strncpy(filenames[i], path, len);
    filenames[i][len] = 0;
    strcat(filenames[i], myitem->d_name);
    filenames[i][len + strlen(myitem->d_name)] = 0;
    lstat(filenames[i], &buf);
    filetime[i] = buf.st_mtime;
  }

  if (flag_param & LS_NONE)
  {
    for (int i = 0; i < count - 1; i++)
    {
      for (int j = 0; j < count - 1 - i; j++)
      {
        if (strcmp(filenames[j], filenames[j + 1]) > 0)
        {
          strcpy(temp, filenames[j]);
          strcpy(filenames[j], filenames[j + 1]);
          strcpy(filenames[j + 1], temp);
        }
      }
    }
  }
  if (flag_param & LS_T)

  {
    for (int i = 0; i < count - 1; i++)
    {
      for (int j = 0; j < count - 1 - i; j++)
      {
        if (filetime[j] < filetime[j + 1])
        {
          timeTemp = filetime[j];
          filetime[j] = filetime[j + 1];
          filetime[j + 1] = timeTemp;
          strcpy(temp, filenames[j]);
          strcpy(filenames[j], filenames[j + 1]);
          strcpy(filenames[j + 1], temp);
        }
      }
    }
  }

  if (flag_param & LS_R)
  {

    for (int i = count - 1; i >= 0; i--)
    {
      display(flag_param, filenames[i]);
    }
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      display(flag_param, filenames[i]);
    }
  }
}

void display(int flag, char *pathname)
{
  int i, j;
  struct stat buf;
  char name[NAME_MAX + 1];

  int color = NORMAL;

  for (i = 0, j = 0; i < strlen(pathname); i++)
  {
    if (pathname[i] == '/')
    {
      j = 0;
      continue;
    }
    name[j] = pathname[i];
    j++;
  }
  name[j] = 0;

  if (lstat(pathname, &buf) == -1)
  {
    my_err("stat", __LINE__);
  }

  lstat(pathname, &buf);

  if (S_ISDIR(buf.st_mode))
  {
    color = BLUE;
  }

  if ((buf.st_mode & S_IXUSR) && color != BLUE)
  {
    color = GREEN;
  }
  if (flag & LS_T)
  {
    flag -= LS_T;
  }
  if (flag & LS_RR)
  {
    flag -= LS_RR;
  }
  if (flag & LS_R)
  {
    flag -= LS_R;
  }

  switch (flag)
  {
  case LS_NONE:
    if (name[0] != '.')
    {
      display_none(name, color);
    }
    break;
  case LS_L:
    if (name[0] != '.')
    {
      display_file(buf, name, color);
    }
    break;
  case LS_A:
    display_none(name, color);
    break;
  case LS_I:
  display_i(name,color);
    break;
  case LS_S:
  display_s(name,color);

    break;
  case LS_A + LS_L:
    display_file(buf, name, color);
    break;
  case LS_A + LS_I:
  display_i(name,color);
    break;
  case LS_L + LS_I:
    if (name[0] != '.')
    {
      printf(" %ld", buf.st_ino);
      display_dir(flag, name);
    }
    break;
  case LS_A + LS_L + LS_I:
    printf("%ld ", buf.st_ino);
    display_dir(flag, name);
    break;
  default:
    break;
  }
}

void display_none(char *name, int color)
{
  int i;
  int len;

  if (g_leavelen < g_maxlen)
  {
    printf("\n");
    g_leavelen = MAXROWLEN;
  }

  len = strlen(name);
  len = g_maxlen - len;

  printfColor(name, color);

  for (i = 0; i < len; i++)
  {
    printf(" ");
  }
  printf(" ");

  g_leavelen -= (g_maxlen + 2);
}

void display_file(struct stat buf, char *name, int color)
{
  char buf_time[32];

  int i;
  struct tm *t;
  switch (buf.st_mode & S_IFMT) //用stat结构体中的st_mode与掩码S_IFMT相与，得到文件类型：
  {
  case S_IFSOCK:
    printf("s");
    break;
  case S_IFLNK:
    printf("l");
    break; //符号链接
  case S_IFREG:
    printf("-");
    break; //一般文件
  case S_IFBLK:
    printf("b");
    break; //块设备文件
  case S_IFDIR:
    printf("d");
    break; //目录文件
  case S_IFCHR:
    printf("c");
    break; //字符设备文件
  case S_IFIFO:
    printf("p");
    break;
  }

  for (i = 8; i >= 0; i--)
  {
    if (buf.st_mode & (1 << i))
    {
      switch (i % 3)
      {
      case 2:
        printf("r");
        break;
      case 1:
        printf("w");
        break;
      case 0:
        printf("x");
        break;
      }
    }
    else
      printf("-");
  }

  printf(" %ld ", buf.st_nlink);

  printf("%s ", getpwuid(buf.st_uid)->pw_name);
  printf("%s ", getgrgid(buf.st_gid)->gr_name);

  printf("%6ld ", buf.st_size);

  t = localtime(&buf.st_mtime);
  printf("%d-%02d-%02d  %02d:%02d ", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
         t->tm_hour, t->tm_min);
  strcpy(buf_time, ctime(&buf.st_mtime));
  buf_time[strlen(buf_time) - 1] = '\0';
  printf("  %s", buf_time);

  printfColor(name, color); //颜色打印
  printf("\n");
}

int display_r(char *pathname1, int color)
{
  struct stat buf;
  DIR *dir;
  struct dirent *ptr;

  printf("\n%s:\n", pathname1);
  dir = opendir(pathname1);
  while ((ptr = readdir(dir)) != NULL)
  {
    if (ptr->d_name[0] != '.')
    {
      display_none(ptr->d_name, color);
    }
  }
  closedir(dir);

  dir = opendir(pathname1);
  while ((ptr = readdir(dir)) != NULL)
  {
    if (ptr->d_name[0] != '.')
    {
      stat(ptr->d_name, &buf);
      if (S_ISDIR(buf.st_mode))
      {
        char *temp = pathname1;
        strcat(temp, "/");
        strcat(temp, ptr->d_name);
        display_r(temp, color);
      }
    }
  }
  closedir(dir);
  return 0;
}

int display_i(char *pathname1, int color)
{
  struct stat buf;
  DIR *dir;
  struct dirent *ptr;
  if (g_leavelen < g_maxlen)
  {
    printf("\n");
    g_leavelen = MAXROWLEN;
  }
   if(lstat(pathname1,&buf) == -1) {
        my_err("lstat",__LINE__);
    }


  int len = strlen(pathname1);
  len = g_maxlen - len;

  printf("%ld ", buf.st_ino);
  printfColor(pathname1, color);

  for (int i = 0; i < len; i++)
  {
    printf(" ");
  }
  printf(" ");
  return 0;
}

int display_s(char *pathname1, int color)
{ 
   struct stat buf;
  DIR *dir;
  struct dirent *ptr;

if (g_leavelen < g_maxlen)
  {
    printf("\n");
    g_leavelen = MAXROWLEN;
  }
    int len = strlen(pathname1);
  len = g_maxlen - len;
  if(lstat(pathname1,&buf) == -1) {
        my_err("lstat",__LINE__);
    }
  printf("%ld ", buf.st_blocks);
printfColor(pathname1, color);
for (int i = 0; i < len; i++)
  {
    printf(" ");
  }
  printf(" ");
  return 0;
}

void printfColor(char *name, int color)
{
  if (color == GREEN)
  {
    printf("\033[;32m %-s\033[0m"
           "",
           name);
  }
  else if (color == BLUE)
  {
    printf("\033[;36m %-s\033[0m"
           "",
           name);
  }
  else if (color == NORMAL)
  {
    printf(" %-s", name);
  }
}
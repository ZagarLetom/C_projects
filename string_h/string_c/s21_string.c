#include "s21_string.h"

#if defined(__linux__)
#define MAX_ERROR 133
char error_message[100] = "Unknown error ";
char *errors[] = {"Success\0",
                  "Operation not permitted\0",
                  "No such file or directory\0",
                  "No such process\0",
                  "Interrupted system call\0",
                  "Input/output error\0",
                  "No such device or address\0",
                  "Argument list too long\0",
                  "Exec format error\0",
                  "Bad file descriptor\0",
                  "No child processes\0",
                  "Resource temporarily unavailable\0",
                  "Cannot allocate memory\0",
                  "Permission denied\0",
                  "Bad address\0",
                  "Block device required\0",
                  "Device or resource busy\0",
                  "File exists\0",
                  "Invalid cross-device link\0",
                  "No such device\0",
                  "Not a directory\0",
                  "Is a directory\0",
                  "Invalid argument\0",
                  "Too many open files in system\0",
                  "Too many open files\0",
                  "Inappropriate ioctl for device\0",
                  "Text file busy\0",
                  "File too large\0",
                  "No space left on device\0",
                  "Illegal seek\0",
                  "Read-only file system\0",
                  "Too many links\0",
                  "Broken pipe\0",
                  "Numerical argument out of domain\0",
                  "Numerical result out of range\0",
                  "Resource deadlock avoided\0",
                  "File name too long\0",
                  "No locks available\0",
                  "Function not implemented\0",
                  "Directory not empty\0",
                  "Too many levels of symbolic links\0",
                  "Unknown error 41\0",
                  "No message of desired type\0",
                  "Identifier removed\0",
                  "Channel number out of range\0",
                  "Level 2 not synchronized\0",
                  "Level 3 halted\0",
                  "Level 3 reset\0",
                  "Link number out of range\0",
                  "Protocol driver not attached\0",
                  "No CSI structure available\0",
                  "Level 2 halted\0",
                  "Invalid exchange\0",
                  "Invalid request descriptor\0",
                  "Exchange full\0",
                  "No anode\0",
                  "Invalid request code\0",
                  "Invalid slot\0",
                  "Unknown error 58\0",
                  "Bad font file format\0",
                  "Device not a stream\0",
                  "No data available\0",
                  "Timer expired\0",
                  "Out of streams resources\0",
                  "Machine is not on the network\0",
                  "Package not installed\0",
                  "Object is remote\0",
                  "Link has been severed\0",
                  "Advertise error\0",
                  "Srmount error\0",
                  "Communication error on send\0",
                  "Protocol error\0",
                  "Multihop attempted\0",
                  "RFS specific error\0",
                  "Bad message\0",
                  "Value too large for defined data type\0",
                  "Name not unique on network\0",
                  "File descriptor in bad state\0",
                  "Remote address changed\0",
                  "Can not access a needed shared library\0",
                  "Accessing a corrupted shared library\0",
                  ".lib section in a.out corrupted\0",
                  "Attempting to link in too many shared libraries\0",
                  "Cannot exec a shared library directly\0",
                  "Invalid or incomplete multibyte or wide character\0",
                  "Interrupted system call should be restarted\0",
                  "Streams pipe error\0",
                  "Too many users\0",
                  "Socket operation on non-socket\0",
                  "Destination address required\0",
                  "Message too long\0",
                  "Protocol wrong type for socket\0",
                  "Protocol not available\0",
                  "Protocol not supported\0",
                  "Socket type not supported\0",
                  "Operation not supported\0",
                  "Protocol family not supported\0",
                  "Address family not supported by protocol\0",
                  "Address already in use\0",
                  "Cannot assign requested address\0",
                  "Network is down\0",
                  "Network is unreachable\0",
                  "Network dropped connection on reset\0",
                  "Software caused connection abort\0",
                  "Connection reset by peer\0",
                  "No buffer space available\0",
                  "Transport endpoint is already connected\0",
                  "Transport endpoint is not connected\0",
                  "Cannot send after transport endpoint shutdown\0",
                  "Too many references: cannot splice\0",
                  "Connection timed out\0",
                  "Connection refused\0",
                  "Host is down\0",
                  "No route to host\0",
                  "Operation already in progress\0",
                  "Operation now in progress\0",
                  "Stale file handle\0",
                  "Structure needs cleaning\0",
                  "Not a XENIX named type file\0",
                  "No XENIX semaphores available\0",
                  "Is a named type file\0",
                  "Remote I/O error\0",
                  "Disk quota exceeded\0",
                  "No medium found\0",
                  "Wrong medium type\0",
                  "Operation canceled\0",
                  "Required key not available\0",
                  "Key has expired\0",
                  "Key has been revoked\0",
                  "Key was rejected by service\0",
                  "Owner died\0",
                  "State not recoverable\0",
                  "Operation not possible due to RF-kill\0",
                  "Memory page has hardware error\0"};

#elif defined(__APPLE__)
#define MAX_ERROR 106
char error_message[100] = "Unknown error: ";
char *errors[] = {"Undefined error: 0\0",
                  "Operation not permitted\0",
                  "No such file or directory\0",
                  "No such process\0",
                  "Interrupted system call\0",
                  "Input/output error\0",
                  "Device not configured\0",
                  "Argument list too long\0",
                  "Exec format error\0",
                  "Bad file descriptor\0",
                  "No child processes\0",
                  "Resource deadlock avoided\0",
                  "Cannot allocate memory\0",
                  "Permission denied\0",
                  "Bad address\0",
                  "Block device required\0",
                  "Resource busy\0",
                  "File exists\0",
                  "Cross-device link\0",
                  "Operation not supported by device\0",
                  "Not a directory\0",
                  "Is a directory\0",
                  "Invalid argument\0",
                  "Too many open files in system\0",
                  "Too many open files\0",
                  "Inappropriate ioctl for device\0",
                  "Text file busy\0",
                  "File too large\0",
                  "No space left on device\0",
                  "Illegal seek\0",
                  "Read-only file system\0",
                  "Too many links\0",
                  "Broken pipe\0",
                  "Numerical argument out of domain\0",
                  "Result too large\0",
                  "Resource temporarily unavailable\0",
                  "Operation now in progress\0",
                  "Operation already in progress\0",
                  "Socket operation on non-socket\0",
                  "Destination address required\0",
                  "Message too long\0",
                  "Protocol wrong type for socket\0",
                  "Protocol not available\0",
                  "Protocol not supported\0",
                  "Socket type not supported\0",
                  "Operation not supported\0",
                  "Protocol family not supported\0",
                  "Address family not supported by protocol family\0",
                  "Address already in use\0",
                  "Can't assign requested address\0",
                  "Network is down\0",
                  "Network is unreachable\0",
                  "Network dropped connection on reset\0",
                  "Software caused connection abort\0",
                  "Connection reset by peer\0",
                  "No buffer space available\0",
                  "Socket is already connected\0",
                  "Socket is not connected\0",
                  "Can't send after socket shutdown\0",
                  "Too many references: can't splice\0",
                  "Operation timed out\0",
                  "Connection refused\0",
                  "Too many levels of symbolic links\0",
                  "File name too long\0",
                  "Host is down\0",
                  "No route to host\0",
                  "Directory not empty\0",
                  "Too many processes\0",
                  "Too many users\0",
                  "Disc quota exceeded\0",
                  "Stale NFS file handle\0",
                  "Too many levels of remote in path\0",
                  "RPC struct is bad\0",
                  "RPC version wrong\0",
                  "RPC prog. not avail\0",
                  "Program version wrong\0",
                  "Bad procedure for program\0",
                  "No locks available\0",
                  "Function not implemented\0",
                  "Inappropriate file type or format\0",
                  "Authentication error\0",
                  "Need authenticator\0",
                  "Device power is off\0",
                  "Device error\0",
                  "Value too large to be stored in data type\0",
                  "Bad executable (or shared library)\0",
                  "Bad CPU type in executable\0",
                  "Shared library version mismatch\0",
                  "Malformed Mach-o file\0",
                  "Operation canceled\0",
                  "Identifier removed\0",
                  "No message of desired type\0",
                  "Illegal byte sequence\0",
                  "Attribute not found\0",
                  "Bad message\0",
                  "EMULTIHOP (Reserved)\0",
                  "No message available on STREAM\0",
                  "ENOLINK (Reserved)\0",
                  "No STREAM resources\0",
                  "Not a STREAM\0",
                  "Protocol error\0",
                  "STREAM ioctl timeout\0",
                  "Operation not supported on socket\0",
                  "Policy not found\0",
                  "State not recoverable\0",
                  "Previous owner died\0",
                  "Interface output queue is full\0"};
#endif

// 1
void *s21_memchr(const void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    if (((char *)str)[i] == (char)c) {
      str += i;
      return (void *)str;
    }
  }
  return s21_NULL;
}

// 2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int dif = 0;
  for (s21_size_t i = 0; i < n; i++, s1++, s2++) {
    dif = *s1 - *s2;
    if (*s1 != *s2) {
      break;
    }
  }
  return dif;
}

// 3
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dcp = dest;
  char *scp = (char *)src;
  while (n--) {
    *dcp++ = *scp++;
  }
  return dest;
}

// 4
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *to = (char *)dest;
  char *from = (char *)src;
  char *buff = (char *)malloc(sizeof(char) * n);

  if (buff) {
    s21_memcpy(buff, from, n);
    s21_memcpy(to, buff, n);
    free(buff);
  }
  return dest;
}

// 5
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p = str;
  while (n--) {
    *p++ = (unsigned char)c;
  }
  return str;
}

// 6
char *s21_strcat(char *dest, const char *src) {
  char *p = dest + s21_strlen(dest);
  while (*src != '\0') {
    *p++ = *src++;
  }
  *p = '\0';
  return dest;
}

// 7
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest + s21_strlen(dest);
  while (n > 0) {
    if (*src == '\0') {
      break;
    }
    *p++ = *src++;
    n--;
  }
  *p = '\0';
  return dest;
}

// 8
char *s21_strchr(const char *str, int c) {
  s21_size_t i = 0;
  char *res = s21_NULL;
  while (str[i] && str[i] != c) {
    i++;
  }
  if (str[i] == c) {
    res = (char *)str + i;
  }
  return res;
}

// 9
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  while (*str1 == *str2) {
    if (*str1 == '\0') {
      break;
    }
    str1++;
    str2++;
  }
  res = *(char *)str1 - *(char *)str2;
  return res;
}

// 10
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  if (n == 0) {
    res = 0;
  } else {
    while (*str1 == *str2 && (n > 0)) {
      if (*str1 == '\0') {
        break;
      }
      n--;
      if (n > 0) {
        str1++;
        str2++;
      }
    }
    res = *(char *)str1 - *(char *)str2;
  }
  return res;
}

// 11
char *s21_strcpy(char *dest, const char *src) {
  char *tmp = dest;
  while (*src != '\0') {
    *dest++ = *src++;
  }
  *dest = '\0';
  return tmp;
}

// 12 Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (long unsigned int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

// 13
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int flag = 0;
  s21_size_t i = 0;
  while (str1[i] != '\0' && flag == 0) {
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag = -1;
      }
    }
    if (flag == 0) {
      i++;
    }
  }
  return i;
}

// 14
char *s21_strerror(int errnum) {
  int unknow = 1;
  static char message[128];
  if (errnum < 0 || errnum > MAX_ERROR) {
    s21_sprintf(message, "%s%d", error_message, errnum);
    unknow = 0;
  }
  return (unknow) ? errors[errnum] : message;
}

// 15
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; *(str + len); len++) {
  }
  return len;
}

// 16
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int flag = 0;
  int i = 0;
  int j = 0;
  while (str1[i] != '\0') {
    while (str2[j] != '\0' && flag == 0) {
      if (str1[i] == str2[j]) {
        result = (char *)str1 + i;
        flag = -1;
      }
      j++;
    }
    j = 0;
    i++;
  }
  return result;
}

// 17
char *s21_strrchr(const char *str, int c) {
  s21_size_t i = s21_strlen(str);
  char *res = s21_NULL;
  while ((i > 0) && str[i] != c) {
    i--;
  }
  if (str[i] == c) {
    res = (char *)str + i;
  }
  return res;
}

// 18 Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i;
  s21_size_t j;

  for (i = 0; str1[i]; i++) {
    for (j = 0; str2[j]; j++) {
      if (str2[j] == str1[i]) break;
    }
    if (!str2[j]) break;
  }

  return i;
}

// 19 Находит первое вхождение всей строки needle (не включая завершающий
// нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    int i = 0;
    while (haystack[i]) {
      int j = i;
      int k = 0;
      while (needle[k] && (haystack[j] == needle[k])) {
        j++;
        k++;
      }
      if (needle[k] == '\0') {
        result = (char *)haystack + i;
        break;
      }
      i++;
    }
  }

  return result;
}

// 20
char *s21_strtok(char *str, const char *delim) {
  static char *buffer;
  static int size;
  register int _match;
  char *token = s21_NULL;

  if (str) {
    size = s21_strlen(str);
    buffer = str;
    buffer[size] = 0;
    _match = 0;
  }
  if (buffer && *buffer) {
    int iter = 0;
    while (iter != 1) {
      iter++;
      // Цикл нужен для проверки: если первый элемент token'а равен концу
      // строки, то нужно искать заново
      _match = s21_strcspn(buffer, delim);
      size = size - _match;
      token = buffer;
      buffer = buffer + _match;
      if (*buffer == 0) {
        buffer = s21_NULL;
      } else {
        token[_match] = '\0';
        buffer++;
        if (token && *buffer) {
          if (token[0] == '\0') iter = 0;
        }
      }
    }
  }
  if (token && (token[0] == 0)) {
    token = s21_NULL;
  }
  return token;
}

// =================  C# ===================
// 1
void *s21_to_upper(const char *str) {
  char *upp = s21_NULL;

  if ((upp = malloc(s21_strlen(str) + 1 * sizeof(char)))) {
    int i = 0;
    while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
        upp[i] = str[i] - 32;
      } else {
        upp[i] = str[i];
      }
      i++;
    }
    upp[i] = '\0';
  }
  return upp;
}

// 2
void *s21_to_lower(const char *str) {
  char *low = s21_NULL;

  if ((low = malloc(s21_strlen(str) + 1 * sizeof(char)))) {
    int i = 0;
    while (str[i] != '\0') {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        low[i] = str[i] + 32;
      } else {
        low[i] = str[i];
      }
      i++;
    }
    low[i] = '\0';
  }
  return low;
}

// 3
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == NULL || str == NULL || start_index > s21_strlen(src)) {
    return NULL;
  }

  size_t src_len = s21_strlen(src);
  size_t str_len = s21_strlen(str);

  char *new_str = malloc(src_len + str_len + 1);
  if (new_str == NULL) {
    return NULL;
  }

  // Копируем начало исходной строки до start_index
  s21_memcpy(new_str, src, start_index);

  // Вставляем строку str
  s21_memcpy(new_str + start_index, str, str_len);
  // Копируем оставшуюся часть исходной строки после start_index
  s21_memcpy(new_str + start_index + str_len, src + start_index,
             src_len - start_index);

  new_str[src_len + str_len] = '\0';
  return new_str;
}
// 4
void *s21_trim(const char *src, const char *trim_set) {
  char *output_line = s21_NULL;
  if (!(src == s21_NULL || trim_set == s21_NULL)) {
    const char *tail_ptr;
    // Ставим указатели на начало и конец исходной строки src
    const char *head_ptr = src;
    tail_ptr = src + s21_strlen(src) - 1;
    // Проверяем символы из trim_set с начала исходной строки src
    while (*head_ptr && s21_strchr(trim_set, *head_ptr) != s21_NULL) {
      head_ptr++;
    }
    // Проверяем символы из trim_set с начала исходной строки src
    while (tail_ptr > head_ptr && s21_strchr(trim_set, *tail_ptr) != s21_NULL) {
      tail_ptr--;
    }
    // Задаём границы для копирования и вычисляем длину выходной строки
    s21_size_t new_head = 0, new_tail = 0, new_length_str = 0;
    new_head = head_ptr - src;
    new_tail = tail_ptr - src;
    new_length_str = new_tail - new_head + 1;
    // Выделение памяти по размеру
    output_line = (char *)malloc(new_length_str + 1);
    if (output_line != s21_NULL) {
      // Клонируем символы подстроки в выходную строку и ставим "точку" - нуль
      s21_memcpy(output_line, head_ptr, new_length_str);
      output_line[new_length_str] = '\0';
    }
  }
  return output_line;
}
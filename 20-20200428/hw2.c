#include <stdio.h>
#include <stdlib.h>

char *strcat (char *s1, char * s2) {
    char *ptr = s1;
    while (*ptr) ptr++;
    for (; *s2; s2++, ptr++) *ptr = *s2;
    *ptr = 0;
    return s1;
}

char *strncat (char *s1, char * s2, int n) {
    char *ptr = s1;
    while (*ptr) ptr++;
    for (int i = 0; *s2 && i < n; s2++, ptr++, i++) *ptr = *s2;
    *ptr = 0;
    return s1;
}

char *strcpy (char *s1, char * s2) {
    char *ptr = s1;
    for (; *s2; s2++, ptr++) *ptr = *s2;
    *ptr = 0;
    return s1;
}

char *strncpy (char *s1, char * s2, int n) {
    char *ptr = s1;
    for (int i = 0; *s2 && i < n; s2++, ptr++, i++) *ptr = *s2;
    *ptr = 0;
    return s1;
}

int strcmp (char *s1, char * s2) {
    for (; *s2 || *s1; s2++, s1++) {
        if (*s1 != *s2) {
            return *s1 < *s2 ? -1 : 1;
        }
    }
    return 0;
}

int strncmp (char *s1, char * s2, int n) {
    for (int i = 0; (*s2 || *s1) && i < n; s2++, s1++, i++) {
        if (*s1 != *s2) {
            return *s1 < *s2 ? -1 : 1;
        }
    }
    return 0;
}

size_t strlen(const char *s) {
    int count = 0;
    while (*s)
	{
		s++;
        count++;
	}
    return count;
}

char *strchr(char * s, char c) {
    for (; *s && *s != c; s++) {}
    return *s ? s : NULL;
}

char *strrchr(char * s, char c) {
    char *ptr = NULL;
    for (; *s; s++) {
        ptr = s;
    }
    for (; ptr != s && *ptr != c; ptr--) {}
    return ptr != s ? ptr : NULL;
}

char *strstr(char *s1, char* s2) {
    for (; *s1; s1++) {
        int found = 1;
        char *p1 = s1;
        for (char* p2 = s2; found && *p2; p2++, p1++)
            if (*p1 != *p2) found = 0;
        if (found) return s1;
    }
    return NULL;
}

size_t strspn(char *s1, char* s2) {
    int count = 0;
    for (; *s1; s1++, count++) {
        int found = 0;
        for (char* p2 = s2; !found && *p2; p2++)
            if (*s1 == *p2) found = 1;
        if (!found) break;
    }
    return count;
}

size_t strcspn(char *s1, char* s2) {
    int count = 0;
    for (; *s1; s1++, count++) {
        int found = 0;
        for (char* p2 = s2; !found && *p2; p2++)
            if (*s1 == *p2) found = 1;
        if (found) break;
    }
    return count;
}

char *strpbrk(char *s1, char* s2) {
    for (; *s1; s1++) {
        for (char* p2 = s2; *p2; p2++)
            if (*s1 == *p2) return s1;
    }
    return NULL;
}

int main (){
    char str1[] = "hello ";
    char str2[] = "aeiou";
    char ch = 'l';
    printf("%s\n", strcat(str1, str2));
    printf("%s\n", strpbrk(str1, str2));
}
#include <stddef.h>

int  w32stdc_memcmp(void const *p1, void const *p2, size_t cb)
{
	unsigned char const *p = p1;
	unsigned char const *q = p2;
	for (; cb-- > 0; ++p, ++q) {
		if (*p > *q) return 1;
		if (*p < *q) return -1;
	}
	return 0;
}

void * w32stdc_memcpy(void *p1, void const *p2, size_t cb)
{
	unsigned char *p = p1;
	unsigned char const *q = p2;
	for (; cb-- > 0; *p++ = *q++);
	return p1;
}

void *  w32stdc_memset(void *p, int a, size_t cb)
{
	for (; cb-- > 0; ((unsigned char*)p)[cb] = (unsigned char)a);
	return p;
}

int w32stdc_strcmp(const char *p1, const char *p2)
{
	for (; *p1 || *p2; ++p1, ++p2) {
		if (*p1 > *p2) return 1;
		if (*p1 < *p2) return -1;
	}
	return 0;
}

char *  w32stdc_strcpy(char *p, const char *q)
{
	char *ret = p;
	for (; *p = *q, *q; ++p, ++q);
	return ret;
}

char *  w32stdc_strcat(char *p, const char *q)
{
	char *ret = p;
	for (; *p; ++p);
	for (; *p = *q, *q; ++p, ++q);
	return ret;
}

size_t  w32stdc_strlen(const char *p)
{
	size_t n = 0; for (; p[n]; ++n); return n;
}

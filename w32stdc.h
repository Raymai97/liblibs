#define memcmp  w32stdc_memcmp
int  w32stdc_memcmp(void const *p1, void const *p2, size_t cb);

#define memcpy  w32stdc_memcpy
void * w32stdc_memcpy(void *p1, void const *p2, size_t cb);

#define memset  w32stdc_memset
void *  w32stdc_memset(void *p, int a, size_t cb);

#define strcmp w32stdc_strcmp
int w32stdc_strcmp(const char *p1, const char *p2);

#define strcpy  w32stdc_strcpy
char *  w32stdc_strcpy(char *p, const char *q);

#define strcat  w32stdc_strcat
char *  w32stdc_strcat(char *p, const char *q);

#define strlen  w32stdc_strlen
size_t  w32stdc_strlen(const char *p);

#undef stdin
#define stdin ((FILE*)1)
#undef stdout
#define stdout ((FILE*)2)
#undef stderr
#define stderr ((FILE*)3)

#define puts  w32stdc_puts
int w32stdc_puts(char const *psz);

#define fputs  w32stdc_fputs
int w32stdc_fputs(char const *psz, FILE *pf);

#define printf  w32stdc_printf
int _cdecl w32stdc_printf(char const *pszFmt, ...);

#define fprintf  w32stdc_fprintf
int _cdecl w32stdc_fprintf(FILE* pf, char const* pszFmt, ...);

#define vfprintf  w32stdc_vfprintf
int w32stdc_vfprintf(FILE *pf, char const *pszFmt, va_list ap);

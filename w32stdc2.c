#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include "w32stdc.h"

#define PRINTF_BUF_SIZE  (4096)

static HANDLE hFile_(FILE *pf)
{
	HANDLE hFile = 0;
	if (pf == stdout) hFile = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pf == stderr) hFile = GetStdHandle(STD_ERROR_HANDLE);
	return hFile;
}

int w32stdc_fputs(char const *pszStr, FILE *pf)
{
	int ret = -1;
	HANDLE hFile = 0;
	DWORD cbWri = 0;
	hFile = hFile_(pf);
	if (!hFile) goto eof;
	if (!WriteFile(hFile, pszStr, w32stdc_strlen(pszStr), &cbWri, NULL)) goto eof;
	ret = (int)cbWri;
	if (!WriteFile(hFile, "\n", 1, &cbWri, NULL)) goto eof;
	ret += 1;
eof:
	return ret;
}

int w32stdc_puts(char const *psz)
{
	return w32stdc_fputs(psz, stdout);
}

int w32stdc_vfprintf(FILE *pf, char const *pszFmt, va_list ap)
{
	int ret = -1;
	HANDLE hFile = 0;
	char szBuf[PRINTF_BUF_SIZE];
	DWORD cbWri = 0;
	hFile = hFile_(pf);
	if (!hFile) goto eof;
	if (!WriteFile(hFile, szBuf, (DWORD)wvsprintfA(szBuf, pszFmt, ap), &cbWri, NULL)) goto eof;
	ret = (int)cbWri;
eof:
	return ret;
}

int _cdecl w32stdc_fprintf(FILE *pf, char const *pszFmt, ...)
{
	int ret = 0;
	va_list ap;
	va_start(ap, pszFmt);
	ret = w32stdc_vfprintf(pf, pszFmt, ap);
	va_end(ap);
	return ret;
}

int _cdecl w32stdc_printf(char const *pszFmt, ...)
{
	int ret = 0;
	va_list ap;
	va_start(ap, pszFmt);
	ret = w32stdc_vfprintf(stdout, pszFmt, ap);
	va_end(ap);
	return ret;
}

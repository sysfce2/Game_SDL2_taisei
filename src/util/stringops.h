/*
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2018, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2018, Andrei Alexeyev <akari@alienslab.net>.
 */

#pragma once
#include "taisei.h"

#include <time.h>

#undef strlcat
#define strlcat SDL_strlcat

#undef strlcpy
#define strlcpy SDL_strlcpy

#undef strdup
#define strdup SDL_strdup

#undef strtok_r
#define strtok_r _ts_strtok_r

char* copy_segment(const char *text, const char *delim, int *size);
bool strendswith(const char *s, const char *e) attr_pure;
bool strstartswith(const char *s, const char *p) attr_pure;
bool strendswith_any(const char *s, const char **earray) attr_pure;
bool strstartswith_any(const char *s, const char **earray) attr_pure;
void stralloc(char **dest, const char *src);
char* strjoin(const char *first, ...) attr_sentinel;
char* vstrfmt(const char *fmt, va_list args);
char* strfmt(const char *fmt, ...) attr_printf(1,  2);
void strip_trailing_slashes(char *buf);
char* strtok_r(char *str, const char *delim, char **nextp);
char* strappend(char **dst, char *src);
char* strftimealloc(const char *fmt, const struct tm *timeinfo);

uint32_t* ucs4chr(const uint32_t *ucs4, uint32_t chr);
size_t ucs4len(const uint32_t *ucs4);
uint32_t* utf8_to_ucs4(const char *utf8);
char* ucs4_to_utf8(const uint32_t *ucs4);

uint32_t crc32str(uint32_t crc, const char *str);
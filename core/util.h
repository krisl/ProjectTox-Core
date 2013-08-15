/*
 * util.h -- Utilities.
 *
 * This file is donated to the Tox Project.
 * Copyright 2013  plutooo
 */

#ifndef UTIL_H_DPF9C9JF
#define UTIL_H_DPF9C9JF

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "DHT.h"
#include "packets.h"
#include "network.h"

enum LOG_LEVEL{ LOG_LEVEL_INFO };
typedef void (*logfn)(void * data, enum LOG_LEVEL log_level, char *fmt, va_list arg);
uint64_t now();
uint64_t random_64b();
bool ipp_eq(IP_Port a, IP_Port b);
bool id_eq(clientid_t* dest, clientid_t* src);
void id_cpy(clientid_t* dest, clientid_t* src);
void LOG(enum LOG_LEVEL log_level, char *fmt, ...);
void init_log(logfn, void * data);
void log_info(char *fmt, ...);

#endif /* end of include guard: UTIL_H_DPF9C9JF */


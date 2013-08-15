/*
 * util.c -- Utilities.
 *
 * This file is donated to the Tox Project.
 * Copyright 2013  plutooo
 */

#include <time.h>

#include "DHT.h"
#include "packets.h"
#include "util.h"

static logfn logger;
static void* data;
uint64_t now()
{
    return time(NULL);
}

uint64_t random_64b()
{
    uint64_t r;

    // This is probably not random enough?
    r = random_int();
    r <<= 32;
    r |= random_int();

    return r;
}

bool ipp_eq(IP_Port a, IP_Port b)
{
    return (a.ip.i == b.ip.i) && (a.port == b.port);
}

bool id_eq(clientid_t* dest, clientid_t* src)
{
    return memcmp(dest, src, sizeof(clientid_t)) == 0;
}

void id_cpy(clientid_t* dest, clientid_t* src)
{
    memcpy(dest, src, sizeof(clientid_t));
}

void init_log(logfn l, void * d) {
  logger = l;
  data = d;
}

void LOG(enum LOG_LEVEL log_level, char *fmt, ...) 
{
    //int ret;
    va_list args;
    va_start(args, fmt);
    //ret = vprintf(fmt, args);
    logger(data, log_level, fmt, args);
    va_end(args);
    //return ret;
}

void log_info(char *fmt, ...)
{
  //int ret;
  va_list args;
  va_start(args, fmt);
  //ret = vprintf(fmt, args);
  logger(data, LOG_LEVEL_INFO, fmt, args);
  va_end(args);
  //return ret;
  
}

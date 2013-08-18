/*
 * Toxic -- Tox Curses Client
 */
#ifndef _windows_h
#define _windows_h

#include <curses.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../core/Messenger.h"
#define MAX_WINDOWS_NUM 32
#define MAX_FRIENDS_NUM 100
#define MAX_STR_SIZE 256
#define KEY_SIZE_BYTES 32


#ifndef TOXICVER
#define TOXICVER "NOVER" //Use the -D flag to set this
#endif

typedef struct ToxWindow_ ToxWindow;

struct ToxWindow_ {
    void(*onKey)(ToxWindow *, Messenger *, int);
    void(*onDraw)(ToxWindow *);
    void(*onFriendRequest)(ToxWindow *, uint8_t *, uint8_t *, uint16_t);
    void(*onMessage)(ToxWindow *, Messenger *, int, uint8_t *, uint16_t);
    void(*onNickChange)(ToxWindow *, int, uint8_t *, uint16_t);
    void(*onStatusChange)(ToxWindow *, int, uint8_t *, uint16_t);
    void(*onAction)(ToxWindow *, Messenger *, int, uint8_t *, uint16_t);
    char title[256];

    void *x;
    bool blink;

    WINDOW *window;
};

void on_request(uint8_t *public_key, uint8_t *data, uint16_t length, void *userdata);
void on_message(Messenger *m, int friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_action(Messenger *m, int friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_nickchange(Messenger *m, int friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_statuschange(Messenger *m, int friendnumber, uint8_t *string, uint16_t length, void *userdata);
void on_friendadded(Messenger *m, int friendnumber);
ToxWindow *init_windows();
void draw_active_window(Messenger *m);
ToxWindow * new_window();
void del_window(ToxWindow *w);
void set_active_window(ToxWindow *w);
#endif


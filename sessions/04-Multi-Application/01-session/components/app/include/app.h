#ifndef APP_H
#define APP_H

#if(CONFIG_APP_IMPL_LEDS)
#include "app_leds.h"
#elif(CONFIG_APP_IMPL_RELAYS)
#include "app_relays.h"
#elif(CONFIG_APP_IMPL_KEYPAD)
#include "app_keypad.h"
#elif(CONFIG_APP_IMPL_HBRIDGE)
#include "app_hbridge.h"
#endif

void App_initAndStart(void);


#endif
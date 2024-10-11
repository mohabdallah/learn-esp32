#include <stdio.h>
#include "app.h"

void App_initAndStart(void)
{
#if(CONFIG_APP_IMPL_LEDS)
    App_initAndStart_leds();
#elif(CONFIG_APP_IMPL_RELAYS)
    App_initAndStart_relays();
#elif(CONFIG_APP_IMPL_KEYPAD)
    App_initAndStart_keypad();
#elif(CONFIG_APP_IMPL_HBRIDGE)
    App_initAndStart_hbridge();
#endif
}

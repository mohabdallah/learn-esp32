set(srcs "app.c")

if(CONFIG_APP_IMPL_LEDS)
    list(APPEND srcs "app_leds.c")
elseif(CONFIG_APP_IMPL_RELAYS)
    list(APPEND srcs "app_relays.c")
elseif(CONFIG_APP_IMPL_KEYPAD)
    list(APPEND srcs "app_keypad.c")
elseif(CONFIG_APP_IMPL_HBRIDGE)
    list(APPEND srcs "app_hbridge.c")
endif()

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS "include"
                    REQUIRES driver)

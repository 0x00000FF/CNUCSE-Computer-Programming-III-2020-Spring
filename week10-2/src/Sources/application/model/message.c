#include <app/message.h>

#include <app/message_kr.h>

const char** get_i18n_errormsg_db(i18n_locale locale_code)
{
    switch (locale_code) {
        case i18n_kr:
            return errormsg_kr;

        default:
            return (const char**) 0;
    }
}
#pragma once

typedef enum  {
    i18n_kr
} i18n_locale;

const char** get_i18n_errormsg_db(i18n_locale locale_code);
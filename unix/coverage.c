#include <stdio.h>

#include "py/obj.h"
#include "py/runtime.h"
#include "py/repl.h"

#if defined(MICROPY_UNIX_COVERAGE)

// function to run extra tests for things that can't be checked by scripts
void run_extra_coverage_tests(void);

void run_extra_coverage_tests(void) {
    // repl autocomplete
    {
        const char *str;
        mp_uint_t len = mp_repl_autocomplete("__", 2, &mp_plat_print, &str);
        printf("%.*s\n", (int)len, str);

        mp_store_global(MP_QSTR_sys, mp_import_name(MP_QSTR_sys, mp_const_none, MP_OBJ_NEW_SMALL_INT(0)));
        mp_repl_autocomplete("sys.", 4, &mp_plat_print, &str);
        len = mp_repl_autocomplete("sys.impl", 8, &mp_plat_print, &str);
        printf("%.*s\n", (int)len, str);
    }
}

#endif

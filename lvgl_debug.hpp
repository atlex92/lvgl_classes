#pragma once

#ifdef NATIVE_BUILD
    #include <iostream>
    using namespace std;
    #define LVGL_DBG_PRINT(arg) cout << arg << endl
#else
    #define LVGL_DBG_PRINT(arg) printf(arg)
#endif

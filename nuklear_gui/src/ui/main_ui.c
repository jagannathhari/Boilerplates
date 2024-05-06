
#include "ui/main_ui.h"
#include <stdio.h>

void main_ui(WinData *windata) {
    if (nk_begin(windata->ctx, "Hello world", nk_rect(0, 0, windata->w, windata->h),
                 NK_WINDOW_NO_SCROLLBAR)) {
        nk_layout_row_dynamic(windata->ctx, windata->h - 15, 1);
        if (nk_button_label(windata->ctx, "Hello world")) {
            puts("Hello world");
        }
    }
    nk_end(windata->ctx);
}

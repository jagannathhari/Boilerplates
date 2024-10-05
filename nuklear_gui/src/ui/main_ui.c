
#include "ui/main_ui.h"
#include <stdio.h>

void main_ui(WinData *windata) {

    SDL_Event evt;
    nk_input_begin(windata->ctx);
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT)
           windata->should_close = 1; 
        windata->handle_event(&evt);
    }

    nk_input_end(windata->ctx);

    if (nk_begin(windata->ctx, "Hello world", nk_rect(0, 0, windata->w, windata->h),
                 NK_WINDOW_NO_SCROLLBAR)) {
        nk_layout_row_dynamic(windata->ctx, windata->h - 15, 1);
        if (nk_button_label(windata->ctx, "Hello world")) {
            puts("Hello world");
        }
    }
    nk_end(windata->ctx);
}

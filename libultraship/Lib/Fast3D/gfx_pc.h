#ifndef GFX_PC_H
#define GFX_PC_H

#include <stdbool.h>
#include <stdint.h>

struct GfxRenderingAPI;
struct GfxWindowManagerAPI;

struct GfxDimensions
{
    uint32_t internal_mul;
    uint32_t width, height;
    float aspect_ratio;
};

#ifdef __cplusplus
extern "C" {
#endif
extern struct GfxDimensions gfx_current_dimensions;

void gfx_init(struct GfxWindowManagerAPI* wapi, struct GfxRenderingAPI* rapi, const char* game_name, bool start_in_fullscreen);
struct GfxRenderingAPI* gfx_get_current_rendering_api(void);
void gfx_start_frame(void);
void gfx_run(Gfx* commands);
void gfx_end_frame(void);
void gfx_set_framedivisor(int);
int gfx_create_framebuffer(uint32_t width, uint32_t height);
uint16_t gfx_get_pixel_depth(float x, float y);

#ifdef __cplusplus
}
#endif
#endif

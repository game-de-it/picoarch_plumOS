#include <SDL/SDL.h>
#include "libretro.h"
#include "libpicofe/plat.h"
#include "libpicofe/input.h"
#include "libpicofe/in_sdl.h"
#include "main.h"
#include "util.h"

#define MAX_SAMPLE_RATE 65536

static const struct in_default_bind in_sdl_defbinds[] = {
	{ SDLK_UP,        IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_UP },
	{ SDLK_DOWN,      IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_DOWN },
	{ SDLK_LEFT,      IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_LEFT },
	{ SDLK_RIGHT,     IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_RIGHT },
	{ SDLK_LCTRL,     IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_B },
	{ SDLK_SPACE,     IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_A },
	{ SDLK_LSHIFT,    IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_X },
	{ SDLK_LALT,      IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_Y },
	{ SDLK_RETURN,    IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_START },
	{ SDLK_RCTRL,     IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_SELECT },
	{ SDLK_TAB,       IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_L },
	{ SDLK_BACKSPACE, IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_R },
	{ SDLK_q,         IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_L2 },
	{ SDLK_BACKSLASH, IN_BINDTYPE_PLAYER12, RETRO_DEVICE_ID_JOYPAD_R2 },
	{ SDLK_BACKQUOTE,    IN_BINDTYPE_EMU, EACTION_MENU },
	{ 0, 0, 0 }
};

const struct menu_keymap in_sdl_key_map[] =
{
	{ SDLK_UP,        PBTN_UP },
	{ SDLK_DOWN,      PBTN_DOWN },
	{ SDLK_LEFT,      PBTN_LEFT },
	{ SDLK_RIGHT,     PBTN_RIGHT },
	{ SDLK_LALT,      PBTN_MA2 },
	{ SDLK_LSHIFT,    PBTN_MA3 },
	{ SDLK_TAB,       PBTN_L },
	{ SDLK_BACKSPACE, PBTN_R },
	{ SDLK_BACKQUOTE,    PBTN_MENU },
};

const struct menu_keymap in_sdl_joy_map[] =
{
    { SDLK_WORLD_13, PBTN_UP },
    { SDLK_WORLD_14, PBTN_DOWN },
    { SDLK_WORLD_15, PBTN_LEFT },
    { SDLK_WORLD_16, PBTN_RIGHT },
	{ SDLK_WORLD_1, PBTN_MOK },
	{ SDLK_WORLD_0, PBTN_MBACK },
	{ SDLK_WORLD_2, PBTN_MA2 },
	{ SDLK_WORLD_3, PBTN_MA3 },
};

static const struct mod_keymap in_sdl_mod_keymap[] = {
//	{ SDLK_TAB,       SDLK_q },          /* mod+L1 = L2 */
//	{ SDLK_BACKSPACE, SDLK_BACKSLASH },  /* mod+R1 = R2 */
	{ SDLK_RETURN, SDLK_BACKQUOTE },  /* SELECT+START = menu */
	{ SDLK_LSHIFT, SDLK_0 },  /* SELECT+R1 BTN = HotKey0 */
	{ SDLK_RSHIFT, SDLK_1 },  /* SELECT+L1 BTN = HotKey1 */
	{ SDLK_HOME,   SDLK_2 },  /* SELECT+R2 BTN = HotKey2 */
	{ SDLK_END,    SDLK_3 },  /* SELECT+L2 BTN = HotKey3 */
	{ SDLK_c,      SDLK_4 },  /* SELECT+X BTN  = HotKey4 */
};

static const struct in_pdata in_sdl_platform_data = {
	.defbinds     = in_sdl_defbinds,
	.key_map      = in_sdl_key_map,
	.kmap_size    = array_size(in_sdl_key_map),
	.joy_map      = in_sdl_joy_map,
	.jmap_size    = array_size(in_sdl_joy_map),
	.mod_key      = SDLK_ESCAPE,
	.mod_keymap   = in_sdl_mod_keymap,
	.modmap_size  = array_size(in_sdl_mod_keymap),
};

#include "plat_sdl.c"

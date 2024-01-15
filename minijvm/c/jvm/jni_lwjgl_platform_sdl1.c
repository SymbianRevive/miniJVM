#include "jvm.h"

#include "glut_keys.h"

#include <SDL/SDL.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_mouse.h>
#include <SDL/SDL_stdinc.h>
#include <SDL/SDL_video.h>
#include <assert.h>
#include <stdint.h>

Sint16 g_DX = 0, g_DY = 0;
Uint16 g_X = 0, g_Y = 0;
int g_mouseStatus;
Sint16 g_eventButton = -1;

static s32 org_lwjgl_input_Mouse_next_Z0(Runtime *runtime, JClass *clazz) {
  RuntimeStack *stack = runtime->stack;

  g_DX = 0;
  g_DY = 0;
  g_eventButton = -1;

  SDL_Event ev;
  int res = SDL_PeepEvents(&ev, 1, SDL_GETEVENT, SDL_MOUSEEVENTMASK);
  if (!res) {
    push_int(stack, 0);
    return 0;
  }

  switch (ev.type) {
  case SDL_MOUSEMOTION:
    g_X = ev.motion.x;
    g_Y = ev.motion.y;
    g_DX = ev.motion.xrel;
    g_DY = ev.motion.yrel;
    break;
  case SDL_MOUSEBUTTONDOWN:
    g_mouseStatus |= SDL_BUTTON(ev.button.button);
    g_eventButton = ev.button.button;
    break;
  case SDL_MOUSEBUTTONUP:
    g_mouseStatus &= ~SDL_BUTTON(ev.button.button);
    g_eventButton = ev.button.button;
    break;
  default:
    assert(0);
  }

  push_int(stack, 1);
  return 0;
}

static s32 org_lwjgl_input_Mouse_getDX_I0(Runtime *runtime, JClass *clazz) {
  push_int(runtime->stack, g_DX);
  return 0;
}

static s32 org_lwjgl_input_Mouse_getDY_I0(Runtime *runtime, JClass *clazz) {
  push_int(runtime->stack, g_DY);
  return 0;
}

static s32 org_lwjgl_input_Mouse_getEventButton_I0(Runtime *runtime,
                                                   JClass *clazz) {
  push_int(runtime->stack, g_eventButton);
  return 0;
}

static s32 org_lwjgl_input_Mouse_getEventButtonState_Z0(Runtime *runtime,
                                                        JClass *clazz) {
  if (g_eventButton == -1) {
    push_int(runtime->stack, 0);
  } else {
    push_int(runtime->stack, g_eventButton & SDL_BUTTON(g_eventButton));
  }
  return 0;
}

static s32 org_lwjgl_input_Mouse_setGrabbed_V1(Runtime *runtime,
                                               JClass *clazz) {
  int grab = localvar_getInt(runtime->localvar, 0);
  SDL_WM_GrabInput(grab ? SDL_GRAB_ON : SDL_GRAB_OFF);
  SDL_ShowCursor(!grab);
  return 0;
}

// ------------------------
// KEYBOARD
// ------------------------

static const short sdl2lwjgl[] = {
    [8] = KEY_BACK,         [27] = KEY_ESCAPE,     [' '] = KEY_SPACE,
    ['*'] = KEY_MULTIPLY,   ['+'] = KEY_ADD,       [','] = KEY_COMMA,
    ['-'] = KEY_MINUS,      ['.'] = KEY_PERIOD,    ['/'] = KEY_SLASH,
    ['0'] = KEY_0,          ['1'] = KEY_1,         ['2'] = KEY_2,
    ['3'] = KEY_3,          ['4'] = KEY_4,         ['5'] = KEY_5,
    ['6'] = KEY_6,          ['7'] = KEY_7,         ['8'] = KEY_8,
    ['9'] = KEY_9,          [':'] = KEY_COLON,     [';'] = KEY_SEMICOLON,
    ['='] = KEY_EQUALS,     ['@'] = KEY_AT,        ['a'] = KEY_A,
    ['b'] = KEY_B,          ['c'] = KEY_C,         ['d'] = KEY_D,
    ['e'] = KEY_E,          ['f'] = KEY_F,         ['g'] = KEY_G,
    ['h'] = KEY_H,          ['i'] = KEY_I,         ['j'] = KEY_J,
    ['k'] = KEY_K,          ['l'] = KEY_L,         ['m'] = KEY_M,
    ['n'] = KEY_N,          ['o'] = KEY_O,         ['p'] = KEY_P,
    ['q'] = KEY_Q,          ['r'] = KEY_R,         ['s'] = KEY_S,
    ['t'] = KEY_T,          ['u'] = KEY_U,         ['v'] = KEY_V,
    ['w'] = KEY_W,          ['x'] = KEY_X,         ['y'] = KEY_Y,
    ['z'] = KEY_Z,          ['['] = KEY_LBRACKET,  ['\''] = KEY_APOSTROPHE,
    ['\\'] = KEY_BACKSLASH, ['\r'] = KEY_RETURN,   ['\t'] = KEY_TAB,
    [']'] = KEY_RBRACKET,   ['_'] = KEY_UNDERLINE, ['`'] = KEY_GRAVE,
    [127] = KEY_DELETE,
};

#define SPARSE_GET(ARY, IDX) (ARY[(IDX) / 8] & (1 << (IDX % 8)))
#define SPARSE_TOGGLE(ARY, IDX) (ARY[(IDX) / 8] ^= (1 << (IDX % 8)))
Uint8 g_sparseKeyStatusMap[UINT8_MAX / 8] = {0};
Sint16 g_eventKey = -1;

static s32 org_lwjgl_input_Keyboard_next_Z0(Runtime *runtime, JClass *clazz) {
  RuntimeStack *stack = runtime->stack;

  SDL_Event ev;
  int res = SDL_PeepEvents(&ev, 1, SDL_GETEVENT, SDL_KEYEVENTMASK);
  if (!res) {
    g_eventKey = -1;
    push_int(stack, 0);
    return 0;
  }

  switch (ev.type) {
  case SDL_KEYDOWN:
  case SDL_KEYUP:
    SPARSE_TOGGLE(g_sparseKeyStatusMap, ev.key.type);
    g_eventKey = ev.key.keysym.sym;
    break;
  }

  push_int(stack, 1);
  return 0;
}

static s32 STUB_V0(Runtime *r, JClass *c) {
  (void)r;
  (void)c;
  return 0;
}

static s32 org_lwjgl_input_Keyboard_getEventKey_I0(Runtime *runtime,
                                                   JClass *clazz) {
  if (g_eventKey == -1) {
    push_int(runtime->stack, -1);
    return 0;
  }
  push_int(runtime->stack, sdl2lwjgl[g_eventKey]);
  return 0;
}

static s32 org_lwjgl_input_Keyboard_getEventCharacter_C0(Runtime *runtime,
                                                         JClass *clazz) {
  if (g_eventKey == -1) {
    push_int(runtime->stack, 0);
    return 0;
  }
  push_int(runtime->stack, g_eventKey);
  return 0;
}

static s32 org_lwjgl_input_Keyboard_getEventKeyState_Z0(Runtime *runtime,
                                                        JClass *clazz) {
  if (g_eventKey == -1) {
    push_int(runtime->stack, -1);
    return 0;
  }
  push_int(runtime->stack, SPARSE_GET(g_sparseKeyStatusMap, g_eventKey));
  return 0;
}

static s32 org_lwjgl_input_Keyboard_isKeyDown_Z1(Runtime *runtime,
                                                 JClass *clazz) {
  push_int(runtime->stack, SPARSE_GET(g_sparseKeyStatusMap,
                                      localvar_getInt(runtime->localvar, 0)));
  return 0;
}

int g_wnd = -1;
SDL_Surface *screen;

static s32 org_lwjgl_input_Display_create_V0(Runtime *runtime, JClass *clazz) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  screen = SDL_SetVideoMode(1024, 768, 0, SDL_OPENGL);

  return 0;
}

// ------------------------
// DISPLAY
// ------------------------

static s32 org_lwjgl_input_Display_update_V0(Runtime *runtime, JClass *clazz) {
  SDL_GL_SwapBuffers();

  SDL_Event ev;
  SDL_PumpEvents();
  while (SDL_PeepEvents(&ev, 1, SDL_GETEVENT,
                        ~(SDL_KEYEVENTMASK | SDL_MOUSEEVENTMASK))) {
    if (ev.type == SDL_QUIT) {
      push_int(runtime->stack, 0);
      execute_method(find_methodInfo_by_name_c("java.lang.System", "exit", "(I)V", NULL, runtime), runtime);
      return 0;
    }
  }

  return 0;
}

static java_native_method METHODS_LWJGL_PLATFORM_TABLE[] = {
    {"org/lwjgl/input/Mouse", "create", "()V", STUB_V0},
    {"org/lwjgl/input/Mouse", "destroy", "()V", STUB_V0},
    {"org/lwjgl/input/Mouse", "getDX", "()I", org_lwjgl_input_Mouse_getDX_I0},
    {"org/lwjgl/input/Mouse", "getDY", "()I", org_lwjgl_input_Mouse_getDY_I0},
    {"org/lwjgl/input/Mouse", "getEventButton", "()I",
     org_lwjgl_input_Mouse_getEventButton_I0},
    {"org/lwjgl/input/Mouse", "getEventButtonState", "()Z",
     org_lwjgl_input_Mouse_getEventButtonState_Z0},
    {"org/lwjgl/input/Mouse", "next", "()Z", org_lwjgl_input_Mouse_next_Z0},
    {"org/lwjgl/input/Mouse", "setGrabbed", "(Z)V",
     org_lwjgl_input_Mouse_setGrabbed_V1},

    {"org/lwjgl/input/Keyboard", "create", "()V", STUB_V0},
    {"org/lwjgl/input/Keyboard", "destroy", "()V", STUB_V0},
    {"org/lwjgl/input/Keyboard", "next", "()Z",
     org_lwjgl_input_Keyboard_next_Z0},
    {"org/lwjgl/input/Keyboard", "getEventKey", "()I",
     org_lwjgl_input_Keyboard_getEventKey_I0},
    {"org/lwjgl/input/Keyboard", "getEventKeyState", "()Z",
     org_lwjgl_input_Keyboard_getEventKeyState_Z0},
    {"org/lwjgl/input/Keyboard", "getEventCharacter", "()C",
     org_lwjgl_input_Keyboard_getEventCharacter_C0},
    {"org/lwjgl/input/Keyboard", "isKeyDown", "(I)Z",
     org_lwjgl_input_Keyboard_isKeyDown_Z1},

    {"org/lwjgl/opengl/Display", "update", "()V",
     org_lwjgl_input_Display_update_V0},
    {"org/lwjgl/opengl/Display", "create", "()V",
     org_lwjgl_input_Display_create_V0},
};

void reg_lwjgl_platform_native_lib(MiniJVM *jvm) {
  native_reg_lib(jvm, METHODS_LWJGL_PLATFORM_TABLE,
                 sizeof(METHODS_LWJGL_PLATFORM_TABLE) /
                     sizeof(java_native_method));
}

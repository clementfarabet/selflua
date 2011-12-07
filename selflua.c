
#include <stdlib.h>
#include <stdio.h>

#include <lua.h>
#include <luaT.h>
#include <lualib.h>
#include <lauxlib.h>

#define LIBNAME "luaworker"

static lua_State *L = NULL;
lua_State *sl_stack = NULL;

void sl_init(void)
{
  /* Set CWD before starting Lua */
  lua_executable_dir("./lua");

  /* Declare a Lua State, open the Lua State and load all libraries */
  L = lua_open();
  luaL_openlibs(L);
  sl_stack = L;
}

void sl_cleanup(void)
{
  /* Destroy the Lua State */
  lua_close(L);
}

int sl_dofile(const char *file)
{
  /* Then load user file */
  int err = luaL_dofile(L, file);

  /* Error ? */
  if (err) {
    printf("<%s> ERROR: %s could not be loaded\n", LIBNAME, file);
  }
  return err;
}

int sl_dostring(const char *string)
{
  /* Then load user file */
  int err = luaL_dostring(L, string);

  /* Error ? */
  if (err) {
    printf("<%s> ERROR: could not parse string\n", LIBNAME);
  }
  return err;
}

lua_State * sl_getstack(void)
{
  return L;
}

void sl_callfunc(const char *funcname, int nargs, int nouts)
{
  lua_getfield(L, LUA_GLOBALSINDEX, funcname);  /* push function on top of stack */
  lua_call(L, nargs, nouts);                    /* call: funcname() */
}

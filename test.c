
#include "selflua.h"
#include "mat.h"

int main(int argc, char *argv[])
{
  // init and load script
  sl_init();
  int err = sl_dofile("test.lua");
  if (err) return 1;

  // call a function that has 2 arguments, and return 1 result
  lua_getfield(sl_stack, LUA_GLOBALSINDEX, "concatenate");
  lua_pushstring(sl_stack, "this thread is number "); // push arg1
  lua_pushnumber(sl_stack, 413);                      // push arg2
  lua_call(sl_stack, 2, 1);                           // res = concatenate(arg1, arg2)
  const char *res = lua_tostring(sl_stack, -1);       // retrieve res
  lua_pop(sl_stack, 1);

  // print result
  printf("result from Lua is: %s\n", res);

  // cleanup
  sl_cleanup();
}


#include <lua.h>
#include <luaT.h>
#include <lualib.h>
#include <lauxlib.h>

#ifdef __cplusplus 
extern "C" {
#endif

extern lua_State *sl_stack;

void sl_init(void);
void sl_cleanup(void);
int sl_dofile(const char *file);
int sl_dostring(const char *string);
lua_State * sl_getstack(void);
void sl_callfunc(const char *funcname, int nargs, int nouts);

#ifdef __cplusplus 
}
#endif

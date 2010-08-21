#ifdef _MSC_VER
// POSIX open,read,write deprecated as of VC++ 2005.
// Use ISO conformant _open,_read,_write instead.
#include <io.h>
#define open _open
#define write _write
#define close _close
#define read _read
#define snprintf _snprintf
#else
#include <unistd.h> // for Solaris, e.g.
#endif


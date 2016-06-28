#ifdef __APPLE__
#  include <OpenAL/al.h>
#else
#  ifdef _WIN32
#    include <windows.h>
#  endif
#  include <AL/al.h>
#  include <AL/alut.h>
#endif

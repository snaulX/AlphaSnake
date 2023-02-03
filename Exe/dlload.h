#ifndef TGBUILD_DLLOAD_H
#define TGBUILD_DLLOAD_H

#ifdef __linux__
#include <dlfcn.h>
#define DLIB void*
#define dlload(libname) dlopen((libname), RTLD_LAZY)
#define dlfunc(lib, fn) dlsym((lib), (fn))
#elif WIN32
#include <windows.h>
#define DLIB HINSTANCE
#define dlload(libname) LoadLibraryW(L ## libname)
#define dlfunc(lib, fn) GetProcAddress((lib), (fn))
#endif


#endif //TGBUILD_DLLOAD_H

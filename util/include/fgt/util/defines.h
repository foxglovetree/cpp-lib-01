#pragma once
// TODO set to a smaller capacity, to see if memory decrease.
#define DELTA_BUF_CAP (16)
#define DELTA_STR_CAP (16)
#define SPACE (' ')
#define NEW_LINE ('\n')
#define fgt_MS_PER_SEC (1000)
#define fgt_US_PER_SEC (1000000)

#ifdef _WIN32
  #ifdef __FGT_UTIL_DLL_EXPORTS
    #define __FGT_UTIL_DLL __declspec(dllexport)
  #else
    #define __FGT_UTIL_DLL __declspec(dllimport)
  #endif
#else
  #define __FGT_UTIL_DLL
#endif

// 示例：导出一个函数
__FGT_UTIL_DLL int fgt_util_version();

namespace fgt::util {

typedef unsigned long TimeUs;

}

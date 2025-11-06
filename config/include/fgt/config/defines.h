#ifdef _WIN32
  #ifdef __FGT_CONFIG_DLL_EXPORTS
    #define __FGT_CONFIG_DLL __declspec(dllexport)
  #else
    #define __FGT_CONFIG_DLL __declspec(dllimport)
  #endif
#else
  #define __FGT_CONFIG_DLL
#endif

// 示例：导出一个函数
__FGT_CONFIG_DLL int fgt_config_version();

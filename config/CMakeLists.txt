# 定义库（静态库 STATIC / 动态库 SHARED）
set(FGT_SUB_LIB_NAME "fgtConfigLib")

file(GLOB SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

add_library(${FGT_SUB_LIB_NAME} SHARED ${SOURCES})
target_link_libraries(${FGT_SUB_LIB_NAME} PRIVATE fgtUtilLib)

# 设置公共头文件目录（供外部使用）
target_include_directories(${FGT_SUB_LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_options(${FGT_SUB_LIB_NAME} PRIVATE /utf-8)
target_compile_definitions(${FGT_SUB_LIB_NAME} PRIVATE __FGT_CONFIG_DLL_EXPORTS)

# 定义库（静态库 STATIC / 动态库 SHARED）
set(FGT_LIB_NAME "fgtUtilLib")

file(GLOB SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

add_library(${FGT_LIB_NAME} SHARED ${SOURCES})

# 设置公共头文件目录（供外部使用）
target_include_directories(${FGT_LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_options(${FGT_LIB_NAME} PRIVATE /utf-8)
target_compile_definitions(${FGT_LIB_NAME} PRIVATE __FGT_UTIL_DLL_EXPORTS)

# 安装规则（可选）
install(TARGETS ${FGT_LIB_NAME}
    EXPORT ${FGT_LIB_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
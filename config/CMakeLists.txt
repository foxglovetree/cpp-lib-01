# 定义库（静态库 STATIC / 动态库 SHARED）
set(FGT_LIB_NAME "fgtConfigLib")

file(GLOB SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

add_library(${FGT_LIB_NAME} ${SOURCES})
target_link_libraries(${FGT_LIB_NAME} PRIVATE fgtUtilLib)

# 设置公共头文件目录（供外部使用）
target_include_directories(${FGT_LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_compile_options(${FGT_LIB_NAME} PRIVATE /utf-8)
# 安装规则（可选）
install(TARGETS ${FGT_LIB_NAME}
    EXPORT MyProjectTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)
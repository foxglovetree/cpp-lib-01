# 定义库（静态库 STATIC / 动态库 SHARED）
set(FGT_LIB_NAME "fgt-util-lib")

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
    EXPORT ${FGT_LIB_NAME}-Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
#


install(DIRECTORY include/ DESTINATION include)


install(EXPORT ${FGT_LIB_NAME}-Targets
    FILE ${FGT_LIB_NAME}Targets.cmake
    NAMESPACE ${FGT_LIB_NAME}::
    DESTINATION share/${FGT_LIB_NAME}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-ConfigVersion.cmake"
    VERSION 0.2.2
    COMPATIBILITY SameMajorVersion
)
configure_package_config_file(
    "cmake/${FGT_LIB_NAME}-Config.cmake.in"   # 输入模板
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-Config.cmake"  # 输出文件
    INSTALL_DESTINATION "share/${FGT_LIB_NAME}"
)

# 安装所有 CMake 包文件
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-ConfigVersion.cmake"
    DESTINATION share/${FGT_LIB_NAME}
)
#
#
#
cmake_minimum_required(VERSION 3.15)
function(uppercase_first result_var input_str)
    if(input_str STREQUAL "")
        set(${result_var} "" PARENT_SCOPE)
        return()
    endif()

    # 提取第一个字符
    string(SUBSTRING "${input_str}" 0 1 first_char)
    # 提取剩余部分（从索引1到末尾）
    string(SUBSTRING "${input_str}" 1 -1 rest)

    # 将首字符转为大写
    string(TOUPPER "${first_char}" first_char_upper)

    # 拼接
    string(CONCAT result "${first_char_upper}" "${rest}")

    set(${result_var} "${result}" PARENT_SCOPE)
endfunction()

set(FGT_LIB_NAME "ftg-cpp-lib-01")
set(FGT_SUB_MODULES util;config)

project(${FGT_LIB_NAME} VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FGT_SUB_LIB_NAMES "")

foreach(entry IN LISTS FGT_SUB_MODULES)
    add_subdirectory(${entry})
endforeach()

foreach(entry IN LISTS FGT_SUB_MODULES)
    string(TOUPPER ${entry} ENTRY_UPPER)
    uppercase_first(ENTRY_UPPER_1 ${entry})
    set(FGT_SUB_LIB_NAME "fgt${ENTRY_UPPER_1}Lib")
    set(FGT_SUB_TARGETS "${FGT_SUB_LIB_NAME}-TARGETS")
    install(TARGETS ${FGT_SUB_LIB_NAME}
        EXPORT ${FGT_SUB_TARGETS}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )
    
    install(DIRECTORY ${entry}/include/ DESTINATION include)

    install(EXPORT ${FGT_SUB_TARGETS}
        FILE ${FGT_SUB_TARGETS}.cmake
        NAMESPACE ${FGT_LIB_NAME}::
        DESTINATION share/${FGT_LIB_NAME}
    )
endforeach()    

# 安装规则（可选）

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-ConfigVersion.cmake"
    VERSION 0.2.2
    COMPATIBILITY SameMajorVersion
)
configure_package_config_file(
    "cmake/Config.cmake.in"   # 输入模板
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-Config.cmake"  # 输出文件
    INSTALL_DESTINATION "share/${FGT_LIB_NAME}"
)

# 安装所有 CMake 包文件
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${FGT_LIB_NAME}-ConfigVersion.cmake"
    DESTINATION share/${FGT_LIB_NAME}
)
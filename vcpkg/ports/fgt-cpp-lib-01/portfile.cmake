#vcpkg_from_github(
#    OUT_SOURCE_PATH SOURCE_PATH
#    REPO foxglovetree/cpp-lib-01          # 你的 GitHub 用户名/仓库名
#    REF HEAD                     # Git tag 或 commit hash
#    SHA512 d0b0d24c6d76936a9afc16596e463b3eb176b5915130b6b4562866b6c4eeadf3dc6ab423fe06333ccf70456f144ae2fdbe14f4a372ed3c4c21b3997942758581               # 稍后生成
#    HEAD_REF main                  # 默认分支（用于计算 SHA512）
#)
vcpkg_from_git(
	OUT_SOURCE_PATH SOURCE_PATH
	URL D:/git/cpp-lib-01
	REF f92cc6f617426b28da979597551e6a2273ee0714
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_install()
vcpkg_cmake_config_fixup()

vcpkg_copy_pdbs()

file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE")

# The VRPN external project for ParaView
set(VRPN_source "${CMAKE_CURRENT_BINARY_DIR}/VRPN")
set(VRPN_binary "${CMAKE_CURRENT_BINARY_DIR}/VRPN-build")
set(VRPN_install "${CMAKE_CURRENT_BINARY_DIR}/VRPN-install")

ExternalProject_Add(VRPN
  DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}
  SOURCE_DIR ${VRPN_source}
  BINARY_DIR ${VRPN_binary}
  INSTALL_DIR ${VRPN_install}
  URL ${VRPN_URL}/${VRPN_GZ}
  URL_MD5 ${VRPN_MD5}
  CMAKE_CACHE_ARGS
    -DCMAKE_CXX_FLAGS:STRING=${pv_tpl_cxx_flags}
    -DCMAKE_C_FLAGS:STRING=${pv_tpl_c_flags}
    -DCMAKE_BUILD_TYPE:STRING=OFF
    ${pv_tpl_compiler_args}
    -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
  )

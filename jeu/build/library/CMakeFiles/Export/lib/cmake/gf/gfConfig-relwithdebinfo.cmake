#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "gf::gf0" for configuration "RelWithDebInfo"
set_property(TARGET gf::gf0 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(gf::gf0 PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libgf0.so.0.6.0"
  IMPORTED_SONAME_RELWITHDEBINFO "libgf0.so.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS gf::gf0 )
list(APPEND _IMPORT_CHECK_FILES_FOR_gf::gf0 "${_IMPORT_PREFIX}/lib/libgf0.so.0.6.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

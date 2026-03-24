# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rtdl_demo_webots_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rtdl_demo_webots_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rtdl_demo_webots_FOUND FALSE)
  elseif(NOT rtdl_demo_webots_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rtdl_demo_webots_FOUND FALSE)
  endif()
  return()
endif()
set(_rtdl_demo_webots_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rtdl_demo_webots_FIND_QUIETLY)
  message(STATUS "Found rtdl_demo_webots: 0.0.0 (${rtdl_demo_webots_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rtdl_demo_webots' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rtdl_demo_webots_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rtdl_demo_webots_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rtdl_demo_webots_DIR}/${_extra}")
endforeach()

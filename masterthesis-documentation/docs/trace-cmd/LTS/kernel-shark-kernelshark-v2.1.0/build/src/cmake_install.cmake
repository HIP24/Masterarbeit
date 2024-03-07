# Install script for directory: /home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib64/libkshark.so.2.1.0"
      "$ENV{DESTDIR}/usr/local/lib64/libkshark.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib64:$ORIGIN")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib64/libkshark.so.2.1.0;/usr/local/lib64/libkshark.so.2")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib64" TYPE SHARED_LIBRARY FILES
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib/libkshark.so.2.1.0"
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib/libkshark.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}/usr/local/lib64/libkshark.so.2.1.0"
      "$ENV{DESTDIR}/usr/local/lib64/libkshark.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/usr/local/lib64::::::::"
           NEW_RPATH "/usr/local/lib64:$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibkshark-develx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark.so"
         RPATH "/usr/local/lib64:$ORIGIN")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib64/libkshark.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib64" TYPE SHARED_LIBRARY FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib/libkshark.so")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark.so"
         OLD_RPATH "/usr/local/lib64::::::::"
         NEW_RPATH "/usr/local/lib64:$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib64/libkshark.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibkshark-develx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/kernelshark/libkshark.h;/usr/local/include/kernelshark/libkshark-model.h;/usr/local/include/kernelshark/libkshark-plugin.h;/usr/local/include/kernelshark/libkshark-tepdata.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/include/kernelshark" TYPE FILE FILES
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/src/libkshark.h"
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/src/libkshark-model.h"
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/src/libkshark-plugin.h"
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/src/libkshark-tepdata.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibkshark-develx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/x86_64-linux-gnu/pkgconfig/libkshark.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib/x86_64-linux-gnu/pkgconfig" TYPE FILE FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/libkshark.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibkshark-develx" OR NOT CMAKE_INSTALL_COMPONENT)
  message("-- Executing: ldconfig /usr/local/lib64")
              execute_process(COMMAND bash "-c" "ldconfig /usr/local"
                              ECHO_ERROR_VARIABLE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0"
         RPATH "/usr/local/lib64:$ORIGIN")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib64/libkshark-plot.so.2.1.0")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib64" TYPE SHARED_LIBRARY FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib/libkshark-plot.so.2.1.0")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0"
         OLD_RPATH "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib:/usr/local/lib64:"
         NEW_RPATH "/usr/local/lib64:$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib64/libkshark-plot.so.2.1.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/kernelshark" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/kernelshark")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/kernelshark"
         RPATH "/usr/local/lib64:$ORIGIN")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/kernelshark")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/bin/kernelshark")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/kernelshark" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/kernelshark")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/bin/kernelshark"
         OLD_RPATH "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib:/usr/local/lib64:"
         NEW_RPATH "/usr/local/lib64:$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/kernelshark")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/kshark-record" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/kshark-record")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/bin/kshark-record"
         RPATH "/usr/local/lib64:$ORIGIN")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/kshark-record")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/bin" TYPE EXECUTABLE FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/bin/kshark-record")
  if(EXISTS "$ENV{DESTDIR}/usr/local/bin/kshark-record" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/kshark-record")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/bin/kshark-record"
         OLD_RPATH "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib:/usr/local/lib64:"
         NEW_RPATH "/usr/local/lib64:$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/bin/kshark-record")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0"
         RPATH "/usr/local/lib64:$ORIGIN")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib64/libkshark-gui.so.2.1.0")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/lib64" TYPE SHARED_LIBRARY FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib/libkshark-gui.so.2.1.0")
  if(EXISTS "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0"
         OLD_RPATH "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/lib:/usr/local/lib64:"
         NEW_RPATH "/usr/local/lib64:$ORIGIN")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/lib64/libkshark-gui.so.2.1.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/applications/kernelshark.desktop")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/applications" TYPE FILE FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/kernelshark.desktop")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/icons/kernelshark/KS_icon_shark.svg;/usr/local/share/icons/kernelshark/KS_icon_fin.svg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/icons/kernelshark" TYPE FILE FILES
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/icons/KS_icon_shark.svg"
    "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/icons/KS_icon_fin.svg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xpolkit-policyx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/share/polkit-1/actions/org.freedesktop.kshark-record.policy")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/share/polkit-1/actions" TYPE FILE FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/org.freedesktop.kshark-record.policy")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xkernelsharkx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/kshark-su-record")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/bin" TYPE PROGRAM FILES "/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/bin/kshark-su-record")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/sigma_ibo/Desktop/Masterarbeit/documentation/trace-cmd/LTS/kernel-shark-kernelshark-v2.1.0/build/src/plugins/cmake_install.cmake")

endif()


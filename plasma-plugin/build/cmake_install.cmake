# Install script for directory: /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/qlogging-categories5" TYPE FILE FILES "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/thunderbird-plasma-integration.categories")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins" TYPE MODULE FILES "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/bin/plasmacalendarplugins/thunderbirdevents.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/CMakeFiles/thunderbirdevents.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars" TYPE SHARED_LIBRARY FILES "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/bin/libthunderbirdcalendarsplugin.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars/libthunderbirdcalendarsplugin.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/CMakeFiles/thunderbirdcalendarsplugin.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/qt/qml/org/kde/plasma/ThunderbirdCalendars" TYPE FILE FILES "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/qmldir")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "thunderbird-plasma-integration" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/qt/plugins/plasmacalendarplugins/thunderbirdevents" TYPE FILE FILES "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/ThunderbirdEventsConfig.qml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

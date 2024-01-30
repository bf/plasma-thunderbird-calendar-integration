# CMake generated Testfile for 
# Source directory: /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin
# Build directory: /home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/usr/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/build/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
set_tests_properties(appstreamtest PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;166;add_test;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;185;appstreamtest;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;0;;/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/CMakeLists.txt;50;include;/home/beni/src/2024-thunderbird-plasma-plugin/plasma-plugin/thunderbirdeventsplugin/CMakeLists.txt;0;")

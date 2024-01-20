cmake_minimum_required(VERSION 3.6)
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(mini_jvm C)
include("${VITASDK}/share/vita.cmake" REQUIRED)
#enable_language(CXX)
enable_language(C)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD 99)

#option(MINI_JVM_BUILD_LIB "Build the mini_jvm library" OFF)

IF (MSVC)
    add_compile_options("/utf-8")
ENDIF ()

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    ADD_DEFINITIONS(-D_DEBUG -D__JVM_DEBUG__)
    message("this is a debug compile")
endif ()

ADD_DEFINITIONS(-D__VITA__)

include_directories(jvm/ utils/ utils/sljit/ utils/https/ utils/https/mbedtls/include)

aux_source_directory(./jvm SOURCE_JVM)
aux_source_directory(./utils SOURCE_UTILS)
aux_source_directory(./utils/https SOURCE_HTTPS)
aux_source_directory(./utils/https/mbedtls/library SOURCE_TLS)
set(SOURCE_SLJIT ./utils/sljit/sljitLir.c)

SET(SOURCE_FILES ${SOURCE_JVM} ${SOURCE_UTILS} ${SOURCE_HTTPS} ${SOURCE_SLJIT})

MESSAGE(STATUS "platform: ${CMAKE_SYSTEM_NAME}")


add_library(mini_jvm_lib STATIC ${SOURCE_FILES})

IF (MSVC)
ELSE ()
TARGET_LINK_LIBRARIES(mini_jvm_lib pthread m)
ENDIF ()


IF (APPLE)
ELSEIF (UNIX)
    TARGET_LINK_LIBRARIES(mini_jvm_lib dl)
ELSEIF (MINGW)
    TARGET_LINK_LIBRARIES(mini_jvm_lib ws2_32)
    IF (CMAKE_SIZEOF_VOID_P EQUAL 4)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
    endif ()
ENDIF ()


add_executable(mini_jvm ${SOURCE_FILES} main.c)

IF (MSVC)
ELSE ()
TARGET_LINK_LIBRARIES(mini_jvm pthread m SDL libGL_stub libgpu_es4_ext_stub libIMGEGL_stub mbedtls mbedcrypto mbedx509 dl taihen_stub SceSysmodule_stub SceGxm_stub SceIme_stub SceTouch_stub SceAudio_stub SceCtrl_stub SceDisplay_stub SceCommonDialog_stub SceHid_stub)
ENDIF ()

#Set link library.
IF (APPLE)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/mac_x64)
ELSEIF (UNIX)
    TARGET_LINK_LIBRARIES(mini_jvm dl)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/centos_x64)
ELSEIF (MINGW)
    TARGET_LINK_LIBRARIES(mini_jvm ws2_32)
    IF (CMAKE_SIZEOF_VOID_P EQUAL 4)
        SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/win32)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
        SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/win_x64)
    endif ()
ENDIF ()

SET(EXECUTABLE_TMP_PATH ${PROJECT_SOURCE_DIR}/../../binary/tmp)
add_custom_command(TARGET mini_jvm COMMAND ${CMAKE_COMMAND} -E make_directory ${EXECUTABLE_TMP_PATH})


function(copyfile pathsrc pathtgt)
    if (EXISTS "${pathsrc}")
        #message("copy src:${pathsrc}   to :${pathtgt}")
        configure_file(${pathsrc} ${pathtgt} COPYONLY)
    endif ()
endfunction()

#copyfile("${PROJECT_SOURCE_DIR}/../java/target/minijvm_rt.jar" "${PROJECT_SOURCE_DIR}/../../binary/lib/minijvm_rt.jar")
#copyfile("${PROJECT_SOURCE_DIR}/../java/target/minijvm_rt.jar" "${PROJECT_SOURCE_DIR}/../../mobile/assets/resfiles/minijvm_rt.jar")
#copyfile("${PROJECT_SOURCE_DIR}/../../extlib/jni_gui/java/dist/glfw_gui.jar" "${PROJECT_SOURCE_DIR}/../../binary/libex/glfw_gui.jar")
#copyfile("${PROJECT_SOURCE_DIR}/../../extlib/luaj/dist/luaj.jar" "${PROJECT_SOURCE_DIR}/../../binary/libex/luaj.jar")
#copyfile("${PROJECT_SOURCE_DIR}/../../test/minijvm_test/target/minijvm_test.jar" "${PROJECT_SOURCE_DIR}/../../binary/libex/minijvm_test.jar")


set(VITA_APP_NAME "Rubydung")
set(VITA_TITLEID  "MINI00017")
set(VITA_VERSION  "01.00")

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME} UNSAFE)
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
)



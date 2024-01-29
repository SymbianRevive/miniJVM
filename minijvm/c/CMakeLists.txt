cmake_minimum_required(VERSION 3.6)

project(mini_jvm C)

set(CMAKE_C_STANDARD 99)

if (DEFINED ENV{VITASDK})
    include("${VITASDK}/share/vita.cmake" REQUIRED)
endif()

IF (MSVC)
    add_compile_options("/utf-8")
ENDIF ()

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    add_definitions(-D_DEBUG -D__JVM_DEBUG__)
    message("this is a debug compile")
endif ()

if (VITA)
    add_definitions(-D__VITA__ -D__vita__ -D__psp2__)
elseif (PSP)
endif()

include_directories(jvm/ utils/ utils/sljit/ utils/https/ utils/https/mbedtls/include)

aux_source_directory(./jvm SOURCE_JVM)
aux_source_directory(./utils SOURCE_UTILS)
aux_source_directory(./utils/https SOURCE_HTTPS)
if (NOT PSP AND NOT VITA)
    aux_source_directory(./utils/https/mbedtls/library SOURCE_TLS)
endif()
set(SOURCE_SLJIT ./utils/sljit/sljitLir.c)

SET(SOURCE_FILES ${SOURCE_JVM} ${SOURCE_UTILS} ${SOURCE_HTTPS} ${SOURCE_TLS} ${SOURCE_SLJIT})

MESSAGE(STATUS "platform: ${CMAKE_SYSTEM_NAME}")


add_library(${PROJECT_NAME}_lib STATIC ${SOURCE_FILES})

if (NOT MSVC)
target_link_libraries(${PROJECT_NAME}_lib pthread m SDL)
endif()


if (APPLE)
elseif (UNIX)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME}_lib dl)
elseif (MINGW)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME}_lib ws2_32)
    IF (CMAKE_SIZEOF_VOID_P EQUAL 4)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
    endif ()
endif ()


add_executable(${PROJECT_NAME} ${SOURCE_FILES} main.c)

if (APPLE)
    SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/mac_x64)
elseif (VITA)
    target_link_libraries(${PROJECT_NAME}
        SDL
        m
        pthread
        libGL_stub
        libgpu_es4_ext_stub
        libIMGEGL_stub
        mbedtls
        mbedcrypto
        mbedx509
        dl
        taihen_stub
        SceSysmodule_stub
        SceGxm_stub
        SceIme_stub
        SceTouch_stub
        SceAudio_stub
        SceCtrl_stub
        SceDisplay_stub
        SceCommonDialog_stub
        SceHid_stub
        SceSblSsMgr_stub
        kubridge_stub
    )

    set(VITA_APP_NAME "RubyDung Launcher")
    set(VITA_TITLEID  "MINI00017")
    set(VITA_VERSION  "01.00")
    set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")
    set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d ATTRIBUTE2=12")

    #set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/vita)

    vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME} UNSAFE)
    vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
      VERSION ${VITA_VERSION}
      NAME ${VITA_APP_NAME}
      FILE ${PROJECT_SOURCE_DIR}/../../binary/lib/minijvm_rt.jar minijvm_rt.jar
      #FILE $ENV{HOME}/Downloads/rd-132211-launcher.jar rd-132211-launcher_backup.jar
      FILE $ENV{HOME}/Downloads/in-20091231-2255.jar rd.jar
      FILE $ENV{HOME}/Downloads/libGL.suprx module/libGL.suprx
      #FILE $ENV{HOME}/Downloads/libGLESv2.suprx module/libGLESv2.suprx
      FILE $ENV{HOME}/Downloads/libGLESv1_CM.suprx module/libGLESv1_CM.suprx
      FILE $ENV{HOME}/Downloads/libgpu_es4_ext.suprx module/libgpu_es4_ext.suprx
      FILE $ENV{HOME}/Downloads/libIMGEGL.suprx module/libIMGEGL.suprx
      FILE $ENV{HOME}/Downloads/libpvrPSP2_WSEGL.suprx module/libpvrPSP2_WSEGL.suprx
    )
elseif (PSP)
    target_link_libraries(${PROJECT_NAME}
        SDL
        mbedtls
        mbedx509
        mbedcrypto
        GL
        GLU
        pspdisplay
        pspgu
        pspge
        pspvfpu
        pspirkeyb
        psppower
        pspctrl
        pspaudio
        psphprm
    )
    create_pbp_file(TARGET ${PROJECT_NAME} TITLE "RubyDung")
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/psp)
elseif (UNIX)
    target_link_libraries(${PROJECT_NAME} dl)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/centos_x64)
elseif (MINGW)
    target_link_libraries(${PROJECT_NAME} ws2_32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/win32)
    elseif (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../binary/win_x64)
    endif()
endif()

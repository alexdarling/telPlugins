cmake_minimum_required(VERSION 2.8)
set(target tel_chisquare)

include_directories(
../source
../../source
${THIRD_PARTY_INSTALL_FOLDER}/include
${CMAKE_INSTALL_PREFIX}/include
)

link_directories(
${CMAKE_INSTALL_PREFIX}/lib
)

set(sources
chisquare_doc.cpp
csChiSquare.cpp
csChiWorker.cpp
chisquare_doc.h
csChiSquare.h
csChiWorker.h
)

add_definitions(
-DPOCO_STATIC
-DEXPORT_TEL_PLUGIN
)

add_library(${target} MODULE ${sources})

target_link_libraries (${target}
telplugins_core
telplugins_common
telplugins_math
)

if(UNIX) 
    if(APPLE)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no_implicit_dylibs -undefined error")
    else()
        set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
    endif()

    set_property(TARGET ${target}
        PROPERTY  COMPILE_DEFINITIONS
        )

endif()

install (TARGETS ${target}
DESTINATION plugins
COMPONENT plugins
)

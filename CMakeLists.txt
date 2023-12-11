include(FetchContent)
cmake_minimum_required (VERSION 3.15)

project ("proj")

add_library(proj SHARED "DLLMain.cpp")
set_property(TARGET proj PROPERTY CXX_STANDARD 23)

#stole from loud
function(download NAME REPO TAG)
    FetchContent_Declare(
        ${NAME}
        GIT_REPOSITORY ${REPO}
        GIT_TAG ${TAG} 
    )
    FetchContent_MakeAvailable(${NAME})
endfunction()

download(minhook https://github.com/TsudaKageyu/minhook.git f5485b8454544c2f034c78f8f127c1d03dea3636)

target_link_libraries(proj PRIVATE minhook)
add_subdirectory(ImGui)
add_subdirectory(Kiero)

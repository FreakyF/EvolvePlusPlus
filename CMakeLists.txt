cmake_minimum_required(VERSION 3.28)
project(EvolvePlusPlus)

set(CMAKE_CXX_STANDARD 26)

add_executable(EvolvePlusPlus main.cpp
        src/Note.cpp
        include/Note.h
        include/Pitch.h
        include/Duration.h
        src/Individual.cpp
        include/Individual.h
        src/Utility.cpp
        include/Utility.h
        src/Duration.cpp
        src/SoundGenerator.cpp
        include/SoundGenerator.h
        include/Evaluator.cpp
        include/Evaluator.h
)

find_package(RtAudio CONFIG REQUIRED)
target_link_libraries(EvolvePlusPlus PRIVATE RtAudio::rtaudio)

find_package(unofficial-libstk CONFIG REQUIRED)
target_link_libraries(EvolvePlusPlus PRIVATE unofficial::libstk::libstk)
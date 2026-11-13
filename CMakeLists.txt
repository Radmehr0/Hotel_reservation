cmake_minimum_required(VERSION 3.16)

project(HotelReservation
    VERSION 1.0.0
    DESCRIPTION "Console hotel room reservation system in C++"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(hotel_reservation
    src/main.cpp
    src/Date.cpp
    src/Information.cpp
    src/Guests.cpp
    src/Guests_Res_Request.cpp
    src/Reservation_Manager.cpp
)

target_include_directories(hotel_reservation PRIVATE include)

if(MSVC)
    target_compile_options(hotel_reservation PRIVATE /W4)
else()
    target_compile_options(hotel_reservation PRIVATE -Wall -Wextra)
endif()

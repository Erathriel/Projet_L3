
set(GAME_DATA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/data")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/code/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

if (GF_SINGLE_COMPILTATION_UNIT)
  add_executable(game
    code/main.cc
    code/XUnityBuild.cc
  )
else()
  add_executable(game
    code/main.cc
    code/local/Level.cpp     #ajouter tout les .cpp ici
    code/local/Object.cpp
    code/local/Protagonist.cpp
  )
endif()

target_include_directories(game
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/code
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(game gf0)

install(
  TARGETS game
  RUNTIME DESTINATION games
)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/data/game"
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/game"
)

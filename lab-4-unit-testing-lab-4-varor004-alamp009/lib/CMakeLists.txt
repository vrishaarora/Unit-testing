
add_library(simpleLibrary
  Triangle.cpp
  Hailstone.cpp
  Awards.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})


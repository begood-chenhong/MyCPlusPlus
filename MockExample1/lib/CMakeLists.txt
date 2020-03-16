add_library(Order order.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(Order
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )


# install rules
install(TARGETS Order DESTINATION lib)
install(FILES order.hpp DESTINATION include)

ADD_LIBRARY(http_server_with_cappuccino STATIC 
  http_server_with_cappuccino.cpp
  cappuccino.hpp
)

target_link_libraries(http_server_with_cappuccino
  ssl
  logger
  datetime
  base64
  signature
  connection_with_grpc
  create_objects_helper
  asio
  json
)


TRIBITS_ADD_EXECUTABLE_AND_TEST(
  Example_00
  SOURCES example_00.cpp
  ARGS PrintItAll
  NUM_MPI_PROCS 1
  ADD_DIR_TO_NAME
  )

TRIBITS_ADD_EXECUTABLE_AND_TEST(
  Example_01
  SOURCES example_01.cpp
  ARGS PrintItAll
  NUM_MPI_PROCS 1
  ADD_DIR_TO_NAME
  )

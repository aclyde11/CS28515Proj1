file(GLOB TEST_NUM *.cpp *.h)

ADD_EXECUTABLE(testlibnumerical ${TEST_NUM})

TARGET_LINK_LIBRARIES(testlibnumerical numericallib libgtest)

add_test(NAME testlibnumerical COMMAND testlibnumerical)
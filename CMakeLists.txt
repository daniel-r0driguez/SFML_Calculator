cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SFML_Calculator)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Application.cpp src/Application.h SFMLComponents/SFMLObject.h SFMLComponents/Typing.cpp SFMLComponents/Typing.h Util/Font.h Util/Font.cpp Util/Position.h Util/Position.cpp SFMLComponents/TextBox.cpp Util/Bitmask.h Util/Bitmask.cpp Util/KeyInputComponent.h Util/KeyInputComponent.cpp Util/KeyChar.cpp Util/KeyChar.h Util/KeyMap.cpp Util/KeyMap.h SFMLComponents/Button.cpp SFMLComponents/Button.h SFMLComponents/AnimatedSpriteComponent.cpp Util/Images.cpp Util/Images.h Util/MouseEvents.cpp SFMLComponents/CalculatorButton.cpp SFMLComponents/CalculatorButton.h SFMLComponents/CalculatorClearButton.cpp SFMLComponents/CalculatorClearButton.h SFMLComponents/CalculatorCharButton.cpp SFMLComponents/CalculatorCharButton.h SFMLComponents/CalculatorEnterButton.cpp SFMLComponents/CalculatorEnterButton.h Util/Postfix.cpp Util/PostfixException.cpp Util/PostfixException.h SFMLComponents/Background.cpp SFMLComponents/CalculatorPad.cpp SFMLComponents/CalculatorPad.h Util/CalculatorButtonInstance.cpp Util/CalculatorButtonInstance.h SFMLComponents/Calculator.cpp SFMLComponents/Calculator.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
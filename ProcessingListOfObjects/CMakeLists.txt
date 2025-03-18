cmake_minimum_required (VERSION 3.11)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ProcessingListOfObjects" CXX)
set(CMAKE_CXX_STANDARD 17)

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core LinguistTools)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core LinguistTools)


if (UNIX)
    execute_process(COMMAND locale -a OUTPUT_VARIABLE LOCALES)
    if (LOCALES MATCHES "ru_RU.UTF-8")
        set(ENV{LC_COLLATE} "ru_RU.UTF-8")
    else()
        message(WARNING "Russian UTF-8 locale not found! Sorting may be incorrect.")
    endif()
endif()

# Добавьте источник в исполняемый файл этого проекта.
add_executable (ProcessingListOfObjects "main.cpp" "input_reader.h" "geo.h" "input_reader.cpp" "geo.cpp" "object.h" "group.h" "object.cpp" "group.cpp" "comparator.h" "comparator.cpp")


# TODO: Добавьте тесты и целевые объекты, если это необходимо.

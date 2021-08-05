set(APP
	ibt)
set(APP_SOURCES
	ibt.cpp
)

marsyas_app(${APP} "${APP_SOURCES}")
target_include_directories(${APP} PRIVATE ../../../../AudioFile/)
target_include_directories(${APP} PRIVATE ../../../../eigen/)
set_target_properties(${APP} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

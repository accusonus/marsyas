include(FindPackageHandleStandardArgs)

find_path(AUDIOFILE_INCLUDE_DIRS AudioFile.h)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(AudioFile DEFAULT_MSG 
              AUDIOFILE_INCLUDE_DIRS)

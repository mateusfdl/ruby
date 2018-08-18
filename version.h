#define RUBY_VERSION "2.5.2"
#define RUBY_RELEASE_DATE "2018-08-18"
#define RUBY_PATCHLEVEL 79

#define RUBY_RELEASE_YEAR 2018
#define RUBY_RELEASE_MONTH 8
#define RUBY_RELEASE_DAY 18

#include "ruby/version.h"

#ifndef TOKEN_PASTE
#define TOKEN_PASTE(x,y) x##y
#endif
#define ONLY_ONE_DIGIT(x) TOKEN_PASTE(10,x) < 1000
#define WITH_ZERO_PADDING(x) TOKEN_PASTE(0,x)
#define RUBY_BIRTH_YEAR_STR STRINGIZE(RUBY_BIRTH_YEAR)
#define RUBY_RELEASE_YEAR_STR STRINGIZE(RUBY_RELEASE_YEAR)
#if ONLY_ONE_DIGIT(RUBY_RELEASE_MONTH)
#define RUBY_RELEASE_MONTH_STR STRINGIZE(WITH_ZERO_PADDING(RUBY_RELEASE_MONTH))
#else
#define RUBY_RELEASE_MONTH_STR STRINGIZE(RUBY_RELEASE_MONTH)
#endif
#if ONLY_ONE_DIGIT(RUBY_RELEASE_DAY)
#define RUBY_RELEASE_DAY_STR STRINGIZE(WITH_ZERO_PADDING(RUBY_RELEASE_DAY))
#else
#define RUBY_RELEASE_DAY_STR STRINGIZE(RUBY_RELEASE_DAY)
#endif

#if !defined RUBY_LIB_VERSION && defined RUBY_LIB_VERSION_STYLE
# if RUBY_LIB_VERSION_STYLE == 3
#   define RUBY_LIB_VERSION STRINGIZE(RUBY_API_VERSION_MAJOR)"."STRINGIZE(RUBY_API_VERSION_MINOR)"."STRINGIZE(RUBY_API_VERSION_TEENY)
# elif RUBY_LIB_VERSION_STYLE == 2
#   define RUBY_LIB_VERSION STRINGIZE(RUBY_API_VERSION_MAJOR)"."STRINGIZE(RUBY_API_VERSION_MINOR)
# endif
#endif

#if RUBY_PATCHLEVEL == -1
#define RUBY_PATCHLEVEL_STR "dev"
#else
#define RUBY_PATCHLEVEL_STR "p"STRINGIZE(RUBY_PATCHLEVEL)
#endif

#ifndef RUBY_REVISION
# include "revision.h"
#endif
#ifndef RUBY_REVISION
# define RUBY_REVISION 0
#endif

#if RUBY_REVISION
# if RUBY_PATCHLEVEL == -1
#  ifndef RUBY_BRANCH_NAME
#   define RUBY_BRANCH_NAME "trunk"
#  endif
#  define RUBY_REVISION_STR " "RUBY_BRANCH_NAME" "STRINGIZE(RUBY_REVISION)
# else
#  define RUBY_REVISION_STR " revision "STRINGIZE(RUBY_REVISION)
# endif
#else
# define RUBY_REVISION_STR ""
#endif

# define RUBY_DESCRIPTION	    \
    "ruby "RUBY_VERSION		    \
    RUBY_PATCHLEVEL_STR		    \
    " ("RUBY_RELEASE_DATE	    \
    RUBY_REVISION_STR") "	    \
    "["RUBY_PLATFORM"]"
# define RUBY_COPYRIGHT		    \
    "ruby - Copyright (C) "	    \
    RUBY_BIRTH_YEAR_STR"-"   \
    RUBY_RELEASE_YEAR_STR" " \
    RUBY_AUTHOR

AC_PREREQ([2.69])
AC_INIT([sample3], [1.0], [your_email@your_domain.com])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Verify C compiller
AC_PROG_CC

# 1. search pg_config executabe in the system
AC_PATH_PROG([PG_CONFIG], [pg_config])
AS_IF([test "x$PG_CONFIG" = "x"], [
  AC_MSG_ERROR(['pg_config' tool not found. Make sure that PostgreSQL is installed and in PATH.])
])

# 2. Extract paths and flags using pg_config
AC_MSG_CHECKING([through the PostgreSQL flags via pg_config])

# Path to the headers (includes)
PG_INCLUDES="-I`$PG_CONFIG --includedir`"
# Path to libraries (libs)
PG_LDFLAGS="-L`$PG_CONFIG --libdir`"

# 3. search for ecpg directly on the system path
#    Ubuntu installs it on /usr/bin not on pg_config --bindir
AC_PATH_PROG([ECPG], [ecpg])

AC_MSG_RESULT([concluído])

# 4. Validate whether the ecpg file actually exists in the PostgreSQL path.
AS_IF([test "x$ECPG" = "x"], [
  ECPG_SUGGESTED="`$PG_CONFIG --bindir`/ecpg"
  AS_IF([test -x "$ECPG_SUGGESTED"], [
    ECPG="$ECPG_SUGGESTED"
  ], [
    AC_MSG_ERROR(['ecpg' not found in the system.])
  ])
])

# 5. Making variables available to Makefile.am
AC_SUBST([PG_INCLUDES])
AC_SUBST([PG_LDFLAGS])
AC_SUBST([ECPG])

# Generating the final Makefile
AC_CONFIG_FILES([Makefile])
AC_OUTPUT


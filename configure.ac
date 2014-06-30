dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.59)
AC_INIT([BoardConnetServer], [1.0], [sandeshghimire@outlook.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CANONICAL_TARGET
AC_CANONICAL_SYSTEM
AC_PROG_CC
AC_PROG_CXX
AC_PROG_SED 
AC_PROG_YACC 
AC_PROG_LEX
AC_PROG_RANLIB
AM_PROG_AR
AC_CHECK_LIB([efence], [malloc], [EFENCELIB=-lefence])
AC_SUBST([EFENCELIB])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES(Makefile src/Makefile src/lib/Makefile src/test/Makefile)
AC_OUTPUT


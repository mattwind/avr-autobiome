#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([avr-autobiome], [0.0.1], [pete@petenix.org])
AM_INIT_AUTOMAKE([avr-autobiome], [0.0.1], [pete@petenix.org])
AC_CONFIG_SRCDIR([src/biome.cxx])
AC_CONFIG_HEADERS([config.h])


# Normally the default prefix (root dir for most of the package installation) is "/usr/local".
# We want the default prefix to be whatever is defined in avr_defaults.m4
avr_DEFAULT_PREFIX

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB
AM_PROG_AS

# Check for the avr-ar and avr-objcopy programs
AVR_CHECK_AR
AVR_CHECK_LOADER
AVR_CHECK_OBJCOPY


# Substitute our default avr CFLAGS into AM_CFLAGS.  We do this so that we can
# create a set of default compilation flags in an "avr_defaults.m4" file and
# reuse them in all of our projects.  (See avr_defaults.m4)

# Here we test to make sure we don't have a value ALREADY inside MCU_FLAG before we set it.
# Only if we do NOT have a value in MCU_FLAG (MCU_FLAG is empty, x$MCU_FLAG = x) do we SUBST
# our default value
if test "x$MCU_FLAG" = "x" ; then
AC_SUBST([MCU_FLAG],      [avr_DEFAULT_MMCU])
fi

AC_SUBST([AM_CCASFLAGS],  [avr_DEFAULT_CFLAGS])
AC_SUBST([AM_CFLAGS],     [avr_DEFAULT_CFLAGS])
AC_SUBST([AM_CPPFLAGS],   [avr_DEFAULT_CPPFLAGS])
AC_SUBST([AM_CXXFLAGS],   [avr_DEFAULT_CFLAGS])
AC_SUBST([AM_LDFLAGS],    [avr_DEFAULT_LDFLAGS])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T


AC_CONFIG_FILES([Makefile])
AC_OUTPUT



dnl Our default C compiler arguments
AC_DEFUN([avr_DEFAULT_CFLAGS], ["-Wall -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char \$(MCU_FLAG)"])

dnl Our default MCU argument (-mmcu) for the avr-gcc assembler/compiler
AC_DEFUN([avr_DEFAULT_MMCU], [-mmcu=atmega32u4])

dnl This is where you set your LOCAL root AVR directory
AC_DEFUN([avr_LOCAL], [/usr/local/avr])

dnl Our default MCU argument (-mmcu) for the avr-gcc assembler/compiler
AC_DEFUN([avr_DEFAULT_CPPFLAGS], ["-I avr_LOCAL/include"])

dnl Our default MCU argument (-mmcu) for the avr-gcc assembler/compiler
AC_DEFUN([avr_DEFAULT_LDFLAGS], ["-L avr_LOCAL/lib"])

dnl This sets the prefix (default install root) for any package that calls avr_PREFIX_DEFAULT in
dnl configure.ac to avr_LOCAL.  You can override this default prefix pretty much anywhere
dnl in the configure/make/install process, this is just a default if nothing is supplied
AC_DEFUN([avr_DEFAULT_PREFIX], [AC_PREFIX_DEFAULT([avr_LOCAL])])

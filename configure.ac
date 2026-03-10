#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.64])
AC_INIT([reloadgtk2],[0.0.1],[https://github.com/evandrofisico/reloadgtk2])
AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign subdir-objects no-dist-gzip dist-xz])

# Support silent build rules. Disable by either passing --disable-silent-rules
# to configure or passing V=1 to make
AM_SILENT_RULES([yes])

# C compiler
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_CC_C_O
AC_PROG_CC_STDC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.


AC_ARG_ENABLE(more_warnings,
       [AS_HELP_STRING([--enable-more-warnings],
               [Add more warnings @<:@default=no@:>@])],
       [enable_more_warnings="${enableval}"],
       [enable_more_warnings=no]
)

PKG_CHECK_MODULES(XLIB, "x11")
AC_SUBST(XLIB_CFLAGS)
AC_SUBST(XLIB_LIBS)

gtk_modules="gtk+-2.0 >= 2.12.0 gthread-2.0"

PKG_CHECK_MODULES(GTK, [$gtk_modules])
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)


gmodule_modules="gmodule-export-2.0"
PKG_CHECK_MODULES(GMODULE, [$gmodule_modules])
AC_SUBST(GMODULE_CFLAGS)
AC_SUBST(GMODULE_LIBS)
AC_SUBST(gtk_modules)


if test x"$enable_more_warnings" = x"yes"; then
  ADDITIONAL_FLAGS="-Wall -Werror=all -Werror=format -Werror=implicit-function-declaration -Werror=implicit-int -Werror=missing-braces -Werror=parentheses -Werror=return-type -Werror=strict-aliasing -Werror=switch -Wuninitialized -Werror=unused-label -Werror=unused-value -Wextra -Wno-missing-field-initializers -Wno-unused-parameter -Werror=missing-declarations -Wredundant-decls -Wmissing-noreturn -Wpointer-arith -Wcast-align -Wwrite-strings -Werror=inline -Werror=format-nonliteral -Wformat-nonliteral -Werror=format-security -Wformat-security -Winit-self -Werror=missing-include-dirs -Werror=undef -Werror=aggregate-return -Wmissing-format-attribute -Werror=nested-externs -fno-strict-aliasing -fmessage-length=0 -Wp,-D_FORTIFY_SOURCE=2 -DG_DISABLE_DEPRECATED -DG_DISABLE_SINGLE_INCLUDES -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_DEPRECATED -DGTK_DISABLE_SINGLE_INCLUDES"
fi
AC_SUBST(ADDITIONAL_FLAGS)

AC_ARG_ENABLE(debug,
    [AC_HELP_STRING([--enable-debug],
        [build lxappearance with debug support @<:@default=no@:>@])],
    [enable_debug="${enableval}"],
    [enable_debug=no]
)

if test "$enable_debug" = "yes"; then
    # turn on debug and disable optimization
    CPPFLAGS="$CPPFLAGS -DG_ENABLE_DEBUG -O0 -g"
    case "$CC" in
    gcc*)
        CPPFLAGS="$CPPFLAGS -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers"
        ;;
    *)
        ;;
    esac
    dnl Be more strict on portability
    CPPFLAGS="$CPPFLAGS -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=700"
else
    # turn off glib debug checks
    CPPFLAGS="$CPPFLAGS -DG_DISABLE_ASSERT -DG_DISABLE_CHECKS -DG_DISABLE_CAST_CHECKS"
fi

AM_CONDITIONAL(ENABLE_MAN, test "x$enable_man" != "xno")

AC_CONFIG_FILES([
    Makefile
    src/Makefile
])

AC_OUTPUT

echo
echo reloadgtk2....................... : Version $VERSION
echo
echo Enable debug....................: "$enable_debug"
echo Prefix..........................: $prefix
echo
echo The binary will be installed in $prefix/bin
echo
echo https://github.com/evandrofisico/reloadgtk2
echo
echo "Ready to make reloadgtk2. Type 'make' to continue."
echo


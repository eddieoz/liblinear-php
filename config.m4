dnl $Id$
dnl config.m4 for extension liblinear

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(liblinear, for liblinear support,
dnl Make sure that the comment is aligned:
dnl [  --with-liblinear             Include liblinear support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(liblinear, whether to enable liblinear support,
Make sure that the comment is aligned:
[  --enable-liblinear           Enable liblinear support])

if test "$PHP_LIBLINEAR" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-liblinear -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/liblinear.h"  # you most likely want to change this
  dnl if test -r $PHP_LIBLINEAR/$SEARCH_FOR; then # path given as parameter
  dnl   LIBLINEAR_DIR=$PHP_LIBLINEAR
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for liblinear files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       LIBLINEAR_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$LIBLINEAR_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the liblinear distribution])
  dnl fi

  dnl # --with-liblinear -> add include path
  dnl PHP_ADD_INCLUDE($LIBLINEAR_DIR/include)

  dnl # --with-liblinear -> check for lib and symbol presence
  dnl LIBNAME=liblinear # you may want to change this
  dnl LIBSYMBOL=liblinear # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBLINEAR_DIR/lib, LIBLINEAR_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_LIBLINEARLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong liblinear lib version or lib not found])
  dnl ],[
  dnl   -L$LIBLINEAR_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(LIBLINEAR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(liblinear, liblinear.c, $ext_shared)
fi

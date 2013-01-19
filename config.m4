
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
  dnl PHP_ADD_INCLUDE($LIBLINEAR_DIR/blas)
  dnl # --with-liblinear -> check for lib and symbol presence
  dnl LIBNAME=liblinear 
  dnl LIBNAME=$PHP_LIBLINEAR/blas/blas.a
  dnl LIBSYMBOL=blas.a # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBLINEAR_DIR/lib, LIBLINEAR_SHARED_LIBADD)
  dnl AC_DEFINE(HAVE_LIBLINEARLIB,1,[ ])
  dnl ],[
  dnl AC_MSG_ERROR([cd blas; make before continuing])
  dnl ],[
  dnl -Lblas -lm
  dnl ])
  dnl PHP_SUBST(LIBLINEAR_SHARED_LIBADD)
  
  dnl  PHP_REQUIRE_CXX()
  dnl  PHP_SUBST(LIBLINEAR_SHARED_LIBADD)
  PHP_ADD_LIBRARY(stdc++, 1, LIBLINEAR_SHARED_LIBADD)
  PHP_SUBST(LIBLINEAR_SHARED_LIBADD) 

  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(liblinear, liblinear.c linear.cpp tron.cpp blas/daxpy.c  blas/ddot.c  blas/dnrm2.c  blas/dscal.c, $ext_shared)
  dnl PHP_INSTALL_HEADERS([liblinear], [ linear.h tron.h las/blas.h blas/blasp.h ] )
  PHP_ADD_BUILD_DIR([$ext_builddir/blas], 1)
  PHP_ADD_INCLUDE([$ext_builddir/lib])
fi

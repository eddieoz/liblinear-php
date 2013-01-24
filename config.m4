PHP_ARG_ENABLE(liblinear, whether to enable liblinear support,
Make sure that the comment is aligned:
[  --enable-liblinear           Enable liblinear support])

if test "$PHP_LIBLINEAR" != "no"; then
  PHP_ADD_LIBRARY(stdc++, 1, LIBLINEAR_SHARED_LIBADD)
  PHP_SUBST(LIBLINEAR_SHARED_LIBADD) 

  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(liblinear, liblinear.c linear.cpp, $ext_shared)
fi

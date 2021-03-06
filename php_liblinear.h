/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Edilson Osorio Junior (osorio dot edilson at eddieoz dot com)|
  +----------------------------------------------------------------------+
*/

/* $Id$ */

/*
BEGIN_EXTERN_C()
	extern struct model* train(const struct problem *prob, const struct parameter *param);
	extern void cross_validation(const struct problem *prob, const struct parameter *param, int nr_fold, double *target);
	extern double predict_values(const struct model *model_, const struct feature_node *x, double* dec_values);
	extern double predict(const struct model *model_, const struct feature_node *x);
	extern double predict_probability(const struct model *model_, const struct feature_node *x, double* prob_estimates);
	extern int save_model(const char *model_file_name, const struct model *model_);
	extern struct model *load_model(const char *model_file_name);
	extern int get_nr_feature(const struct model *model_);
	extern int get_nr_class(const struct model *model_);
	extern void get_labels(const struct model *model_, int* label);
	extern void free_model_content(struct model *model_ptr);
	extern void free_and_destroy_model(struct model **model_ptr_ptr);
	extern void destroy_param(struct parameter *param);
	extern const char *check_parameter(const struct problem *prob, const struct parameter *param);
	extern int check_probability_model(const struct model *model);
	extern void set_print_string_function(void (*print_func) (const char*));
END_EXTERN_C()
*/

#ifndef PHP_LIBLINEAR_H
#define PHP_LIBLINEAR_H

extern zend_module_entry liblinear_module_entry;
#define phpext_liblinear_ptr &liblinear_module_entry

#ifdef PHP_WIN32
#	define PHP_LIBLINEAR_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_LIBLINEAR_API __attribute__ ((visibility("default")))
#else
#	define PHP_LIBLINEAR_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(liblinear);
PHP_MSHUTDOWN_FUNCTION(liblinear);
PHP_RINIT_FUNCTION(liblinear);
PHP_RSHUTDOWN_FUNCTION(liblinear);
PHP_MINFO_FUNCTION(liblinear);

PHP_FUNCTION(confirm_liblinear_compiled);	/* For testing, remove later. */
PHP_FUNCTION(OZ_train);
PHP_FUNCTION(OZ_predict);
PHP_FUNCTION(OZ_save_model);
PHP_FUNCTION(OZ_load_model);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(liblinear)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(liblinear)
*/

/* In every utility function you add that needs to use variables 
   in php_liblinear_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as LIBLINEAR_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define LIBLINEAR_G(v) TSRMG(liblinear_globals_id, zend_liblinear_globals *, v)
#else
#define LIBLINEAR_G(v) (liblinear_globals.v)
#endif

#endif	/* PHP_LIBLINEAR_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

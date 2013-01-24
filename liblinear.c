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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_liblinear.h"
#include "linear.h"


zend_object_handlers liblinear_object_handlers;
zend_class_entry *liblinear_ce;

PHP_METHOD(Liblinear, __construct)
{

}

/* If you declare any globals in php_liblinear.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(liblinear)
*/

/* True global resources - no need for thread safety here */
static int le_liblinear;

/* {{{ liblinear_functions[]
 *
 * Every user visible function must have an entry in liblinear_functions[].
 */
const zend_function_entry liblinear_functions[] = {
	PHP_FE(confirm_liblinear_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(OZ_train,	NULL)
	PHP_FE(OZ_predict,	NULL	)
	PHP_FE(OZ_save_model,	NULL)
	PHP_FE(OZ_load_model,	NULL)
	PHP_FE_END	/* Must be the last line in liblinear_functions[] */
};
/* }}} */

/* {{{ liblinear_module_entry
 */
zend_module_entry liblinear_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"liblinear",
	liblinear_functions,
	PHP_MINIT(liblinear),
	PHP_MSHUTDOWN(liblinear),
	PHP_RINIT(liblinear),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(liblinear),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(liblinear),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LIBLINEAR
ZEND_GET_MODULE(liblinear)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("liblinear.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_liblinear_globals, liblinear_globals)
    STD_PHP_INI_ENTRY("liblinear.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_liblinear_globals, liblinear_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_liblinear_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_liblinear_init_globals(zend_liblinear_globals *liblinear_globals)
{
	liblinear_globals->global_value = 0;
	liblinear_globals->global_string = NULL;
}
*/
/* }}} */



/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(liblinear)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry ce;
	    INIT_CLASS_ENTRY(ce, "Liblinear", liblinear_functions);
	    liblinear_ce = zend_register_internal_class(&ce TSRMLS_CC);
	    /*liblinear_ce->create_object = liblinear_create_handler;
	    memcpy(&liblinear_object_handlers,
	    zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	    liblinear_object_handlers.clone_obj = NULL;*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(liblinear)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(liblinear)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(liblinear)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(liblinear)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "liblinear support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_liblinear_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_liblinear_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "liblinear", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto  OZ_train()
   const struct problem *prob, const struct parameter *param); */
PHP_FUNCTION(OZ_train)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_error(E_WARNING, "OZ_train: not yet implemented");
}
/* }}} */

/* {{{ proto  OZ_predict()
   const struct model *model_, const struct feature_node *x); */
PHP_FUNCTION(OZ_predict)
{
	char *arg = NULL;
	int arg_len, len, iReturn;
	char *strg;

	char *OZ_Input = NULL;
	char *OZ_Model = NULL;
	char *OZ_Prob = NULL;
	int i;
	int nr_class;
	static int (*info)(const char *fmt,...) = &printf;

	struct feature_node *x;
	int max_nr_attr = 64;

	struct model* model_;
	int flag_predict_probability=0;

	static char *line = NULL;
	static int max_line_len;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss", &OZ_Input, &arg_len, &OZ_Model, &arg_len, &OZ_Prob, &arg_len) == FAILURE) {
		return;
	}

	//len = spprintf(&strg, 0, "Input: %.78s. Output: %.78s. Model: %.78s\n", OZ_Input, OZ_Output, OZ_Model);

	if((model_=load_model(OZ_Model))==0)
	{
		fprintf(stderr,"can't open model file %s\n",OZ_Model);
		exit(1);
	}
	x = (struct feature_node *) malloc(max_nr_attr*sizeof(struct feature_node));

	// fprintf(stderr,"X: %a\n",x);



	/* {{{ do_predict
	 *
	 */
	int correct = 0;
	int total = 0;
	double error = 0;
	double sump = 0, sumt = 0, sumpp = 0, sumtt = 0, sumpt = 0;

	nr_class=get_nr_class(model_);

	double *prob_estimates=NULL;
	int j, n;
	int nr_feature=get_nr_feature(model_);
	if(model_->bias>=0)
		n=nr_feature+1;
	else
		n=nr_feature;

	//printf ("%s %s", OZ_Prob,flag_predict_probability );
	//return;

	if (atoi(OZ_Prob) == 1 ){
		flag_predict_probability = 1;
	}

	if(flag_predict_probability)
	{
		int *labels;

		if(!check_probability_model(model_))
		{
			fprintf(stderr, "probability output is only supported for logistic regression\n");
			exit(1);
		}

		labels=(int *) malloc(nr_class*sizeof(int));
		get_labels(model_,labels);
		prob_estimates = (double *) malloc(nr_class*sizeof(double));
		/* output to stderr */
		fprintf(stderr,"labels");
		for(j=0;j<nr_class;j++)
			fprintf(stderr," %d",labels[j]);
		fprintf(stderr,"\n");
		free(labels);
	}

	max_line_len = 1024;
	//line = (char *)malloc(max_line_len*sizeof(char));
	line = OZ_Input;

		i = 0;
		double target_label, predict_label;
		char *idx, *val, *label, *endptr;
		int inst_max_index = 0; // strtol gives 0 if wrong format

		label = strtok(line," \t\n");
		if(label == NULL) // empty line
			exit_input_error(total+1);

		target_label = strtod(label,&endptr);
		if(endptr == label || *endptr != '\0')
			exit_input_error(total+1);

		while(1)
		{
			if(i>=max_nr_attr-2)	// need one more for index = -1
			{
				max_nr_attr *= 2;
				x = (struct feature_node *) realloc(x,max_nr_attr*sizeof(struct feature_node));
			}

			idx = strtok(NULL,":");
			val = strtok(NULL," \t");

			if(val == NULL)
				break;
			errno = 0;
			x[i].index = (int) strtol(idx,&endptr,10);
			if(endptr == idx || errno != 0 || *endptr != '\0' || x[i].index <= inst_max_index)
				exit_input_error(total+1);
			else
				inst_max_index = x[i].index;

			errno = 0;
			x[i].value = strtod(val,&endptr);
			if(endptr == val || errno != 0 || (*endptr != '\0' && !isspace(*endptr)))
				exit_input_error(total+1);

			// feature indices larger than those in training are not used
			if(x[i].index <= nr_feature)
				++i;
		}

		if(model_->bias>=0)
		{
			x[i].index = n;
			x[i].value = model_->bias;
			i++;
		}
		x[i].index = -1;

		if(flag_predict_probability)
		{
			int j;
			predict_label = predict_probability(model_,x,prob_estimates);
			/* output to stderr */
			fprintf(stderr,"%g",predict_label);
			for(j=0;j<model_->nr_class;j++)
				fprintf(stderr," %g",prob_estimates[j]);
			fprintf(stderr,"\n");
		}
		else
		{
			predict_label = predict(model_,x);
			fprintf(stderr,"%g\n",predict_label);
		}

		if(predict_label == target_label)
			++correct;
		error += (predict_label-target_label)*(predict_label-target_label);
		sump += predict_label;
		sumt += target_label;
		sumpp += predict_label*predict_label;
		sumtt += target_label*target_label;
		sumpt += predict_label*target_label;
		++total;

	/*if(model_->param.solver_type==L2R_L2LOSS_SVR ||
	   model_->param.solver_type==L2R_L1LOSS_SVR_DUAL ||
	   model_->param.solver_type==L2R_L2LOSS_SVR_DUAL)
	{
		info("Mean squared error = %g (regression)\n",error/total);
		info("Squared correlation coefficient = %g (regression)\n",
			((total*sumpt-sump*sumt)*(total*sumpt-sump*sumt))/
			((total*sumpp-sump*sump)*(total*sumtt-sumt*sumt))
			);
        }
	else
		info("Accuracy = %g%% (%d/%d)\n",(double) correct/total*100,correct,total);
	*/ // just dont make sense

	if(flag_predict_probability)

		free(prob_estimates);

	/* do_predict end */




	free_and_destroy_model(&model_);

	//fclose(input);
	//fclose(output);

	//free(line);

	//free(x);
	return;
	//RETURN_STRINGL(strg, len, 0);



}
/* }}} */

/* {{{ proto  OZ_save_model()
   const char *model_file_name, const struct model *model_); */
PHP_FUNCTION(OZ_save_model)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_error(E_WARNING, "OZ_save_model: not yet implemented");
}
/* }}} */

/* {{{ proto  OZ_load_model()
   const char *model_file_name); */
PHP_FUNCTION(OZ_load_model)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
	php_error(E_WARNING, "OZ_load_model: not yet implemented");
}
/* }}} */



/* {{{ */
/* predict.c */
int print_null(const char *s,...) {}

static int (*info)(const char *fmt,...) = &printf;

struct feature_node *x;
int max_nr_attr = 64;

struct model* model_;
int flag_predict_probability=0;

void exit_input_error(int line_num)
{
	fprintf(stderr,"Wrong input format at line %d\n", line_num);
	exit(1);
}

static char *line = NULL;
static int max_line_len;



void exit_with_help()
{
	printf(
	"Usage: predict [options] test_file model_file output_file\n"
	"options:\n"
	"-b probability_estimates: whether to output probability estimates, 0 or 1 (default 0); currently for logistic regression only\n"
	"-q : quiet mode (no outputs)\n"
	);
	exit(1);
}


/* end of predict.c */
/* }}} */








/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

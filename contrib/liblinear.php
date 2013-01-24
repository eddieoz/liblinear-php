<?php

/***************
 * File: 	liblinear.php
 * Author: 	Edilson Osorio Junior (osorio dot edilson at eddieoz dot com || twttr: eddieoz)
 * Date: 	2013/01/24
 * Description: This script receives features from stdin and predicts line by line, using php liblinear module
 * Usage:	cat tests/test-predict.svm | php liblinear.php
 * Function	OZ_predict ( <predict_line>, <model>, <arg_probability 0|1> );
 * Copyright:	BSD
 **************/

$stdin = fopen('php://stdin', 'r');

while ($buffer = fgets($stdin)) {
	$result = OZ_predict( $buffer, "tests/test.model",0);

}

?>

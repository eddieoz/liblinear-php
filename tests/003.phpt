--TEST--
Test predicting with logistic regression
--SKIPIF--
<?php if (!extension_loaded("liblinear")) print "skip"; ?>
--FILE--
<?php
$features = "3 1:3.6 2:2.14 3:1.65 4:3.43 5:11.87 6:6.65 7:8.97 8:4.31 9:64 10:2.14 11:1.15";
$result = OZ_predict( $features, dirname(__FILE__) . "/test-s0.model",1);
?>
--EXPECT--
labels 6 5 4 7 1 3 2
3 0.0275284 0.269859 0.087462 0.0268987 0.0812416 0.495307 0.0117026


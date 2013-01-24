--TEST--
Test predicting
--SKIPIF--
<?php if (!extension_loaded("liblinear")) print "skip"; ?>
--FILE--
<?php
$features = "2 1:4.22 2:6.34 3:4.24 4:10.18 5:2.11 6:5.47 7:4.2 8:4.28 9:6.35";
$result = OZ_predict( $features, dirname(__FILE__) . "/test.model",0 );
echo $result;
?>
--EXPECT--
2


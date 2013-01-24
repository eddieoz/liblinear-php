--TEST--
Test predicting lines from a streaming
--SKIPIF--
<?php if (!extension_loaded("liblinear")) print "skip"; ?>
--FILE--
<?php
$stdin = fopen( dirname(__FILE__) . '/test-predict.svm', 'r');

while ($buffer = fgets($stdin)) {
        $result = OZ_predict( $buffer, dirname(__FILE__) . "/test.model",0);
}
?>
--EXPECT--
3
3
3
3
2
2
2
2
1
1
1
1
7
7
7
7
6
6
6
6
5
5
5
5
4
4
4
4

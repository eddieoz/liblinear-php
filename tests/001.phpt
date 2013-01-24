--TEST--
Check for liblinear presence
--SKIPIF--
<?php if (!extension_loaded("liblinear")) print "skip"; ?>
--FILE--
<?php 
echo "liblinear extension is available";
?>
--EXPECT--
liblinear extension is available

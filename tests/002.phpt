--TEST--
test1() Basic test
--EXTENSIONS--
glut
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension glut is loaded and working!
NULL

<?php

$stdin = fopen('php://stdin', 'r');

while ($buffer = fgets($stdin)) {
	$result = OZ_predict( $buffer, "model/data.model");
}

?>

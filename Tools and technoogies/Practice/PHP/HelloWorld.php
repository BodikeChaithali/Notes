
<?php
    echo "Hello World! This is my first PHP file.";
# This is a single line comment in PHP
// Another way to write a single line comment
/* 
This is a 
   multi-line comment in PHP 
*/
print <<<END
<h1>Welcome to PHP!</h1>
<p>This is a paragraph generated using the heredoc syntax.</p>  
END;
echo "<br>";
$greeting = "Hello, PHP!";
echo $greeting;
?>
<?php

require 'vendor/autoload.php';

$loader = new Twig_Loader_Filesystem('views');
$twig = new Twig_Environment($loader);


$md5Filter = new Twig_SimpleFilter('md5', function($string){
    return md5($string);
});

$twig->addFilter($md5Filter);

$lexer = new Twig_Lexer($twig, array(
    'tag_block' => array('{', '}'),
    'tag_variable' => array('{{','}}')
));

$twig-> setLexer($lexer);

echo $twig->render('hello.html',array(
    'name' => 'Junsu',
    'age' => 25,
    'users' => array(
    array('name'=>'kim', 'age'=>99),
    array('name'=>'jsk', 'age'=>11),
    array('name'=>'dev', 'age'=>33),
)
));
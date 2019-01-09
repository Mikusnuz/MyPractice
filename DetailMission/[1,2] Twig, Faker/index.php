<?php

require 'vendor/autoload.php';

$loader = new Twig_Loader_Filesystem('views');

$twig = new Twig_Environment($loader);

$md5Filter = new Twig_SimpleFilter('md5', function($string){
    return md5($string);
});

$faker = Faker\Factory::create();

$twig->addFilter($md5Filter);

$lexer = new Twig_Lexer($twig, array(
    'tag_block' => array('{', '}'),
    'tag_variable' => array('{{','}}')
));

$twig-> setLexer($lexer);

$users=array();

for($i=0;$i<100000;$i++){
    $users[$i]['name']=$faker->name;
    $users[$i]['age']=$faker->numberBetween($min = 1, $max = 90);
    $users[$i]['email']=$faker->email;
    
}

echo $twig->render('index.html',array('users'=>
    $users
));


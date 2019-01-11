<?php

function initSmarty(){

    require 'C:\Users\jooon\Desktop\php\includes\smarty\Smarty.class.php';
    $smarty = new Smarty();
    $smarty->template_dir = './templates';
    $smarty->compile_dir = './templates_complete';
    $smarty->cache_dir = './cache';
    $smarty->config_dir = './config';

    return $smarty;
}

function accessAPI($year, $month){

    $ch = curl_init();
    $url = 'http://apis.data.go.kr/B090041/openapi/service/SpcdeInfoService/getRestDeInfo';
    $queryParams = '?' . urlencode('ServiceKey') . '=c4a7c5MTcGaxJIzv3TprEsY3cehmLqdwsQO5oFy8HHEDGy7VMn6r2SD4klHscHZvseCm%2F0P8rDoEEhUvBuTpbQ%3D%3D';
    $queryParams .= '&' . urlencode('solYear') . '=' . urlencode($year);
    $queryParams .= '&' . urlencode('solMonth') . '=' . urlencode(($month<10)?'0'.$month:$month);

    curl_setopt($ch, CURLOPT_URL, $url . $queryParams);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_HEADER, FALSE);
    curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'GET');
    $response = curl_exec($ch);
    curl_close($ch);
    $xml=simplexml_load_string($response);
    
    
    return $xml;
}

function holidayReturn($year){

    $holiday_item=array();  

    for($month=1;$month<13;$month++){
        $xml = accessAPI($year,$month);
        foreach ($xml->body->items->item as $item) {
            $holiday_item[(string)$item->locdate]=$item->dateName;
        }
    }
    return $holiday_item;
}

function loopHoliday(){

    $holiday_items=array();
    for($year=2015;$year<2020;$year++){
        $holiday_items[(string)$year]=(holidayReturn($year));
    }
    return $holiday_items;
}

function renderSmarty(){
    
    $smarty=initSmarty();
    $holiday=loopHoliday();
    $smarty->assign('holiday', $holiday);
    $smarty->display('block.tpl');
}

renderSmarty();

?>

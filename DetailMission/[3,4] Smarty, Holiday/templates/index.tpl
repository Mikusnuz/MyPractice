<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Detail Mission</title>
    {block name=head}{/block}
</head>
<nav class="smarty__nav">
    <span class="faker__title">Detail Mission : Smarty / Holiday</span>
</nav>
<body>
    <select class="yearSelect" onchange="changeYear()" id="year">
        <option value="-">------</option>        
        <option value="2015">2015</option>
        <option value="2016">2016</option>
        <option value="2017">2017</option>
        <option value="2018">2018</option>
        <option value="2019">2019</option>
    </select>
    {foreach from=$holiday key=wrap item=array}
    <div class="smarty__wrap" id="{$wrap}">
        {foreach from=$array key=key item=value}
               <div> {$key} - {$value}</div>
        {/foreach}
    </div>
    <input type="hidden" id="hidden" value="null"></input>
    {/foreach}
    {block name=footer}{/block}
</body>
</html>
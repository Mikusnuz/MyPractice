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
    <select class="yearSelect" onchange="changeYear()">
        <option value="2015">2015</option>
        <option value="2016">2016</option>
        <option value="2017">2017</option>
        <option value="2018">2018</option>
        <option value="2019">2019</option>
    </select>
    {foreach $holiday as $array}
        {foreach from=$array key=key item=value}
               <div type="hidden"> {$key} - {$value}</div>
        {/foreach}
    {/foreach}
</body>
</html>
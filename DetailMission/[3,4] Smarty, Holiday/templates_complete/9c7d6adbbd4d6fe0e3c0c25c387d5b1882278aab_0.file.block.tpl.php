<?php
/* Smarty version 3.1.33, created on 2019-01-09 14:21:20
  from 'c:\Users\jooon\Desktop\Mofas_JSK\DetailMission\[3,4] Smarty, Holiday\templates\block.tpl' */

/* @var Smarty_Internal_Template $_smarty_tpl */
if ($_smarty_tpl->_decodeProperties($_smarty_tpl, array (
  'version' => '3.1.33',
  'unifunc' => 'content_5c3603602c33d5_77206888',
  'has_nocache_code' => false,
  'file_dependency' => 
  array (
    '9c7d6adbbd4d6fe0e3c0c25c387d5b1882278aab' => 
    array (
      0 => 'c:\\Users\\jooon\\Desktop\\Mofas_JSK\\DetailMission\\[3,4] Smarty, Holiday\\templates\\block.tpl',
      1 => 1547042995,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_5c3603602c33d5_77206888 (Smarty_Internal_Template $_smarty_tpl) {
$_smarty_tpl->_loadInheritance();
$_smarty_tpl->inheritance->init($_smarty_tpl, true);
?>

<?php 
$_smarty_tpl->inheritance->instanceBlock($_smarty_tpl, 'Block_4928010055c3603602c22e4_12054519', 'head');
?>

<?php 
$_smarty_tpl->inheritance->instanceBlock($_smarty_tpl, 'Block_15342921145c3603602c2e21_72610619', 'footer');
$_smarty_tpl->inheritance->endChild($_smarty_tpl, 'index.tpl');
}
/* {block 'head'} */
class Block_4928010055c3603602c22e4_12054519 extends Smarty_Internal_Block
{
public $subBlocks = array (
  'head' => 
  array (
    0 => 'Block_4928010055c3603602c22e4_12054519',
  ),
);
public function callBlock(Smarty_Internal_Template $_smarty_tpl) {
?>

  <link href="./templates/css/index.css" rel="stylesheet" type="text/css"/>
<?php
}
}
/* {/block 'head'} */
/* {block 'footer'} */
class Block_15342921145c3603602c2e21_72610619 extends Smarty_Internal_Block
{
public $subBlocks = array (
  'footer' => 
  array (
    0 => 'Block_15342921145c3603602c2e21_72610619',
  ),
);
public function callBlock(Smarty_Internal_Template $_smarty_tpl) {
?>

  <?php echo '<script'; ?>
 type="text/javascript" src="./templates/js/index.js"><?php echo '</script'; ?>
>
<?php
}
}
/* {/block 'footer'} */
}

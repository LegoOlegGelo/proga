<?php
    global $cart_g_id;
    global $item_id;

    $name = $names[$cart_g_id % $count_of_cards];
    $price = $prices[$cart_g_id % $count_of_cards];
    $image = $image_links[$cart_g_id % $count_of_cards];
?>

<div class='cart-item'>
    <img class='cart-item-image' src='<? echo $image; ?>'>

    <div class='cart-item-information'>
        <p><? echo $name; ?></p>
        <p><? echo $price; ?> ETH</p>
        <form action='/cart_delete_item.php' method='post'>
            <input type='hidden' name='item_id' value='<? echo $item_id; ?>'>
            <input class='cart-delete-item-btn' type='submit' value='Удалить из корзины'>
        </form>
    </div>
</div>
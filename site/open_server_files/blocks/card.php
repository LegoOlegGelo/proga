<?php
    require 'mocks.php';
    
    global $id;
?>

<div class='nft-card'>
    <a href='/card.php?id=<?php echo $id; ?>'>
        <img class='nft-card-image' src='<?php echo $image_links[$id % $count_of_cards]; ?>' />
        <h3 class='nft-card-text'><?php echo $names[$id % $count_of_cards]; ?></h2>
        <h3 class='nft-card-text'><?php echo $prices[$id % $count_of_cards]; ?> ETH</h2>
    </a>

    <form action='/put_to_cart.php' method='POST'>
        <input type='hidden' name='card_id' value='<?php echo $id; ?>'>
        <input type='submit' class='buy-btn' value='В корзину' />
    </form>
</div>

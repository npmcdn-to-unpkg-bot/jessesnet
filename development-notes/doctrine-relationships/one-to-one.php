<?php

use Doctrine\ORM\Tools\Setup;
use Doctrine\ORM\EntityManager;

require_once __DIR__ . "/Bootstrap.php";
Bootstrap::init();

$em = Bootstrap::entityManager();



// var_dump($FoodGroup->getName);

// repositories used to search specific entities
$Repo = $em->getRepository('Entity\\GroceryItem');
// to load all rows from a table (entity)
$items = $Repo->getGroceries(1);

foreach ($items as $Item) {
	var_dump($Item->getFoodGroup());
	break;
}
<?php

use Doctrine\ORM\Tools\Setup;
use Doctrine\ORM\EntityManager;

require_once __DIR__ . "/Bootstrap.php";
Bootstrap::init();

$em = Bootstrap::entityManager();


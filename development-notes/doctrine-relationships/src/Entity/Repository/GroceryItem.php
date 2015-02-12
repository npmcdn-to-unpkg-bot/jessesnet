<?php

namespace Entity\Repository;

use Doctrine\ORM\EntityRepository;

/**
 * GroceryItem
 */
class GroceryItem extends EntityRepository
{     
    public function getGroceryItem($name)
    {
        $query = $this->getEntityManager()
                      ->createQuery(
                        'SELECT gi, fg FROM Entity\GroceryItem gi
                         JOIN gi.foodGroup fg WHERE gi.name = :name'
                     )->setParameter('name', $name);
        
        return $query->getSingleResult();
    }
}

<?php

namespace Entity\Repository;

use Doctrine\ORM\EntityRepository;

/**
 * GroceryItem
 */
class GroceryItem extends EntityRepository
{
    public function getGroceries($id)
    {
        try {
        $query = $this->getEntityManager()
                      ->createQuery(
                        'SELECT gi, fg FROM Entity\GroceryItem gi
                         JOIN gi.foodGroup fg WHERE gi.id = :id'
                    )->setParameter('id', $id);
        
        return $query->getSingleResult();
        } catch (\Exception $e) {
            var_dump($e->getMessage());
        }
    }
}
